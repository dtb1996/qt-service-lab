#pragma once

#include <QString>
#include <QDateTime>

struct FeedItem
{
    QString id;
    QString title;
    QString body;
    QDateTime timestamp;
};
