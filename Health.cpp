#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 3;
    setPlainText(QString("Health: " + QString::number(health)));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: " + QString::number(health)));
    if(health < 0)
    {
        setPlainText(QString("Game Over"));
        setDefaultTextColor(Qt::red);
        setFont(QFont("times", 40));
    }
}

int Health::getHealth()
{
    return health;
}
