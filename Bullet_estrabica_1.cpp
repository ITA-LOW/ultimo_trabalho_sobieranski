#include "Bullet_estrabica_1.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include "Game.h"
#include "Enemy.h"

extern Game * game; //existe um objeto global chamado Game
Bullet_estrabica_1::Bullet_estrabica_1(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/sounds/Images/laserRed.png"));
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(move_estrabico()));

    timer->start(50);
}


void Bullet_estrabica_1::move_estrabico()
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

    setPos(x()+10,y()-10);
    if(pos().y() < -10)//esse trecho faz o gerenciamento de memoria, deletando a bala depois q sai do cenario
    {
        scene()->removeItem(this);
        delete this;
        //qDebug()<<"Bala deletada";
    }
}
