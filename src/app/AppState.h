#pragma once

#include <QObject>

class AppState : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool loading READ loading NOTIFY loadingChanged)
    Q_PROPERTY(QString error READ error NOTIFY errorChanged)

public:
    explicit AppState(QObject* parent = nullptr);

    bool loading() const;
    QString error() const;

    void setLoading(bool loading);
    void setError(const QString& error);

signals:
    void loadingChanged();
    void errorChanged();

private:
    bool m_loading = false;
    QString m_error;
};
