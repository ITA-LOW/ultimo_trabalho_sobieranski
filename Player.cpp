#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"
#include "Bullet_estrabica_1.h"
#include "Bullet_estrabica_2.h"

#include <QDebug>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/sounds/Images/player.png"));
    bulletsound = new QMediaPlayer();
    outputbullet = new QAudioOutput();
    bulletsound->setAudioOutput(outputbullet);
    outputbullet->setVolume(50);
    bulletsound->setSource(QUrl("qrc:/sounds/sounds/Laser.mp3"));


}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left)
    {
        if(pos().x() > 0)//quer dizer q soh vai mover pra esquerda se a coordenada x de rect for maior q zero (ele esta em 400 agora)
        {
            setPos(x()-20,y());
        }

    }
    else if(event->key()==Qt::Key_Right)
    {
        if(pos().x() + 100 < 800)
        {
            setPos(x()+20,y());
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
        Bullet * bullet_esquerda = new Bullet();
        //qDebug() << "bullet create";
        bullet_esquerda->setPos(x(),y());
        scene()->addItem(bullet_esquerda);

        Bullet * bullet_direita = new Bullet();
        //qDebug() << "bullet create";
        bullet_direita->setPos(x()+89,y());
        scene()->addItem(bullet_direita);

        Bullet * bullet_centro = new Bullet();
        //qDebug() << "bullet create";
        bullet_centro->setPos(x()+45,y());
        scene()->addItem(bullet_centro);

        Bullet_estrabica_1 * bullet_estrabica_1 = new Bullet_estrabica_1();
        bullet_estrabica_1->setPos(x(),y()-10);
        scene()->addItem(bullet_estrabica_1);

        Bullet_estrabica_2 * bullet_estrabica_2 = new Bullet_estrabica_2();
        bullet_estrabica_2->setPos(x()+89,y()-10);
        scene()->addItem(bullet_estrabica_2);

        if(bulletsound->playbackState()== QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
        }
        else if(bulletsound->playbackState() == QMediaPlayer::StoppedState)
        {
            bulletsound->play();
        }

    }
}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
