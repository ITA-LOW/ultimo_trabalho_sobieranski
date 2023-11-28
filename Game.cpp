#include <QGraphicsScene>
#include "Player.h"
#include <QGraphicsView>
#include <QTimer>
#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
#include <QBrush>
#include "Game.h"


Game::Game(QWidget *parent)
{

    //QGraphicsScene * scene = new QGraphicsScene;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); //ajusta o tamanho do cenario com o tamanho da janela (assim as balas saem do cenario)
    scene->setBackgroundBrush(QBrush(QImage(":/sounds/Images/starBackground.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600); //ajusta o tamanho da tela

    player = new Player();
    //player->setRect(0, 0, 100, 100);
    player->setPos(400,500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    //score/health
    score = new Score();
    scene->addItem(score);
    health = new Health;
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);



    show();

}
