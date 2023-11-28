#include "Bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game; //existe um objeto global chamado Game
Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Images/laserRed.png"));
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return; //depois de deletar a bala daria erro. return faz o ponteiro ir para o endereço de memoria guardado em return address
        }
    }

    setPos(x(),y()-10);
    if(pos().y() < -10)//esse trecho faz o gerenciamento de memoria, deletando a bala depois q sai do cenario
    {
        scene()->removeItem(this);
        delete this;
        //qDebug()<<"Bala deletada";
    }
}
