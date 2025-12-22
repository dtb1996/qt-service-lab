#pragma once

#include <QAbstractListModel>
#include "FeedItem.h"

class FeedModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles
    {
        IdRole = Qt::UserRole + 1,
        TitleRole,
        BodyRole,
        TimestampRole
    };
    Q_ENUM(Roles)

    explicit FeedModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void setItems(const QList<FeedItem>& items);
    void clear();

private:
    QList<FeedItem> m_items;
};
