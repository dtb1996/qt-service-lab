#pragma once

#include <QObject>
#include "src/services/FakeApiService.h"
#include "src/models/FeedModel.h"
#include "src/app/AppState.h"

class AppController : public QObject
{
    Q_OBJECT

public:
    explicit AppController(AppState* appState, FeedModel* feedModel, QObject* parent = nullptr);

    Q_INVOKABLE void loadFeed();

private slots:
    void onFeedLoaded(const QList<FeedItem>& items);
    void onRequestFailed(const QString& error);

private:
    AppState* m_appState;
    FeedModel* m_feedModel;
    FakeApiService m_apiService;
};
