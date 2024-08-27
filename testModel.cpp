#include <iostream>
#include "testModel.h"

TestModel::TestModel(QObject *parent):
    QAbstractListModel(parent)
{
    //m_data.push_back(44);
    //m_data.push_back(45);
    avg = 666;
    n = 1;
}

int TestModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_data.size();
}

QVariant TestModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case TextRole:
        return m_data.at(index.row());
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> TestModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    //roles[ColorRole] = "color";
    roles[TextRole] = "text";
    //roles[AvgRole] = "avg";

    return roles;
}

void TestModel::add(int val)
{
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
    m_data.push_back(val);
    endInsertRows();

    //m_data[0] = QString("Size: %1").arg(m_data.size());
    //QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
    //emit dataChanged(index, index);
}

double TestModel::calcAvg() {
    double avg = 0;

    for (auto it = m_data.rbegin(); it < m_data.rbegin() + n; it++) {
        avg += *it;
    }
    avg /= n;
    //txt = QString::fromStdString("123");
    return avg;
}


bool TestModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid()) {
        return false;
    }

    switch (role) {
    case TextRole:
        m_data[index.row()] = value.toInt();
        break;
    default:
        return false;
    }

    emit dataChanged(index, index, QVector<int>() << role);

    return true;
}

Qt::ItemFlags TestModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

void TestModel::onItemSend(QVariant val)
{
    bool* validation = nullptr;
    int itemVal = val.toInt(validation);

    //TestModel::add();
    //std::cout << validation;

    if(val.canConvert<int>()) {
        if (val.toInt() >= 1) {
            TestModel::add(val.toInt());
        }
    }
}
void TestModel::onNSend(QVariant val)
{
    if(val.canConvert<int>()) {
        if (val.toInt() >= 1) {
            n = val.toInt();
        }
    }
}
