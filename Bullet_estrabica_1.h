#ifndef BULLET_ESTRABICA_1_H
#define BULLET_ESTRABICA_1_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet_estrabica_1: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet_estrabica_1(QGraphicsItem * parent=0);
public slots:
    void move_estrabico();
};

#endif // BULLET_ESTRABICA_1_H
