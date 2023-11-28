#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

Enemy::Enemy()
{
    //inimigo aparece em posição randomica
    int random_number = rand() % 700; //maior que isso e os inimigos iam spawnar fora do cenario
    setPos(random_number, 0);

    setRect(0,0,100,100);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    setPos(x(),y()+5);

    if(pos().y() + rect().height() < 0)//esse trecho faz o gerenciamento de memoria, deletando a bala depois q sai do cenario
    {
        scene()->removeItem(this);
        delete this;
        //qDebug()<<"Bala deletada";
    }
}
