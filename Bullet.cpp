#include "Bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"

Bullet::Bullet()
{
    setRect(0,0,10,50);
    QTimer * timer = new QTimer();
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
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return; //depois de deletar a bala daria erro. return faz o ponteiro ir para o endereço de memoria guardado em return address
        }
    }

    setPos(x(),y()-10);
    if(pos().y() + rect().height() < 0)//esse trecho faz o gerenciamento de memoria, deletando a bala depois q sai do cenario
    {
        scene()->removeItem(this);
        delete this;
        //qDebug()<<"Bala deletada";
    }
}
