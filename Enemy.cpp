#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"

extern Game * game;
Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //inimigo aparece em posição randomica
    int random_number = rand() % 700; //maior que isso e os inimigos iam spawnar fora do cenario
    setPos(random_number, 0);

    setPixmap(QPixmap(":/sounds/Images/enemyShip.png"));
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    setPos(x(),y()+5);

    if(pos().y() > 600)//esse trecho faz o gerenciamento de memoria, deletando o inimigo depois q sai do cenario
    {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
        //qDebug()<<"inimigo deletado";
    }
}
