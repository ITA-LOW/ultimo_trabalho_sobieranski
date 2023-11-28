#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene;
    MyRect * player = new MyRect;
    player->setRect(0, 0, 100, 100);

    //add rect item into the scene
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add a view
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800,600); //ajusta o tamanho da tela
    scene->setSceneRect(0,0,800,600); //ajusta o tamanho do cenario com o tamanho da janela (assim as balas saem do cenario)

    player->setPos(view->width()/2, view->height() - player->rect().height());

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);


    return a.exec();
}
