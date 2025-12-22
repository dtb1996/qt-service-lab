#include "FeedModel.h"

FeedModel::FeedModel(QObject *parent) : QAbstractListModel(parent)
{

}

int FeedModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_items.size();
}

QVariant FeedModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_items.size())
        return {};

    const FeedItem& item = m_items.at(index.row());

    switch(role)
    {
    case IdRole:
        return item.id;
    case TitleRole:
        return item.title;
    case BodyRole:
        return item.body;
    case TimestampRole:
        return item.timestamp;
    default:
        return {};
    }
}

QHash<int, QByteArray> FeedModel::roleNames() const
{
    return
    {
        { IdRole, "id" },
        { TitleRole, "title" },
        { BodyRole, "body" },
        { TimestampRole, "timestamp" }
    };
}

void FeedModel::setItems(const QList<FeedItem> &items)
{
    beginResetModel();
    m_items = items;
    endResetModel();
}

void FeedModel::clear()
{
    beginResetModel();
    m_items.clear();
    endResetModel();
}
