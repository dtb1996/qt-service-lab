#include "AppState.h"

AppState::AppState(QObject* parent) : QObject(parent)
{

}

bool AppState::loading() const
{
    return m_loading;
}

QString AppState::error() const
{
    return m_error;
}

void AppState::setLoading(bool loading)
{
    if (m_loading == loading)
        return;

    m_loading = loading;
    emit loadingChanged();
}

void AppState::setError(const QString &error)
{
    if (m_error == error)
        return;

    m_error = error;
    emit errorChanged();
}
