#ifndef BULLET_ESTRABICA_2_H
#define BULLET_ESTRABICA_2_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet_estrabica_2: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet_estrabica_2(QGraphicsItem * parent=0);
public slots:
    void move_estrabico();
};

#endif // BULLET_ESTRABICA_2_H
