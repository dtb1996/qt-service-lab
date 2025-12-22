#include "AppController.h"

AppController::AppController(AppState* appState, FeedModel* feedModel, QObject* parent)
    : QObject(parent)
    , m_appState(appState)
    , m_feedModel(feedModel)
    , m_apiService(this)
{
    connect(&m_apiService, &FakeApiService::feedLoaded, this, &AppController::onFeedLoaded);

    connect(&m_apiService, &FakeApiService::requestFailed, this, &AppController::onRequestFailed);
}

void AppController::loadFeed()
{
    m_appState->setError(QString());
    m_appState->setLoading(true);
    m_feedModel->clear();

    m_apiService.fetchFeed();
}

void AppController::onFeedLoaded(const QList<FeedItem> &items)
{
    m_feedModel->setItems(items);
    m_appState->setLoading(false);
}

void AppController::onRequestFailed(const QString &error)
{
    m_appState->setError(error);
    m_appState->setLoading(false);
}
