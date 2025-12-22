#pragma once

#include <QObject>
#include "models/FeedItem.h"

class FakeApiService : public QObject
{
    Q_OBJECT

public:
    explicit FakeApiService(QObject* parent = nullptr);

    Q_INVOKABLE void fetchFeed();

signals:
    void feedLoaded(QList<FeedItem> items);
    void requestFailed(QString errorMessage);

private:
    void simulateResponse();
};
