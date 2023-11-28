#include "MyRect.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"

#include <QDebug>

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left)
    {
        if(pos().x() > 0)//quer dizer q soh vai mover pra esquerda se a coordenada x de rect for maior q zero (ele esta em 400 agora)
        {
            setPos(x()-10,y());
        }

    }
    else if(event->key()==Qt::Key_Right)
    {
        if(pos().x() + 100 < 800)
        {
            setPos(x()+10,y());
        }
    }
    else if(event->key()==Qt::Key_Up)
    {
        setPos(x(),y()-10);
    }
    else if(event->key()==Qt::Key_Down)
    {
        setPos(x(),y()+10);
    }
    else if(event->key()==Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        //qDebug() << "bullet create";
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}

void MyRect::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
