#include "FakeApiService.h"
#include <QRandomGenerator>
#include <QTimer>
#include <QDateTime>

FakeApiService::FakeApiService(QObject *parent) : QObject(parent)
{

}

void FakeApiService::fetchFeed()
{
    simulateResponse();
}

void FakeApiService::simulateResponse()
{
    const int delayMs = QRandomGenerator::global()->bounded(800, 2000);
    const bool shouldFail = QRandomGenerator::global()->bounded(100) < 25;

    QTimer::singleShot(delayMs, this, [this, shouldFail]()
    {
        if (shouldFail)
        {
            emit requestFailed("Failed to load feed. Please try again.");
            return;
        }

        QList<FeedItem> items;

        const int itemCount = QRandomGenerator::global()->bounded(5, 12);
        for (int i = 0; i < itemCount; ++i)
        {
            FeedItem item;
            item.id = QString::number(i);
            item.title = QString("Feed Item %1").arg(i + 1);
            item.body = "This is a simulated backend response.";
            item.timestamp = QDateTime::currentDateTime().addSecs(-i * 60);

            items.append(item);
        }

        emit feedLoaded(items);
    });
}
