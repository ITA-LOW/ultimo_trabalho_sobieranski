#include "Score.h"
#include <QFont>
#include "Health.h"
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score: " + QString::number(score)));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Score::increase()
{
    Health health = &health;
    score++;
    setPlainText(QString("Score: " + QString::number(score)));
    if(health.getHealth() < 0)
    {
        int last_score = score;
        setPlainText(QString("Your score was: " + QString::number(last_score)));

    }
}

int Score::getScore()
{
    return score;
}
