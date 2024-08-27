#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QAbstractListModel>
#include <QStringList>
#include <qqmlintegration.h>
//#include <m_data.h>

class TestModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    enum Roles {
        TextRole = Qt::UserRole + 1,
        //AvgRole = Qt::UserRole + 2
    };

    TestModel(QObject *parent = 0);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role);
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;

    Q_INVOKABLE void add(int val);
    double calcAvg();

public slots:
    void onItemSend(QVariant val);
    void onNSend(QVariant val);

private:
    std::vector<int> m_data;
    int n;
    double avg;
};
#endif // TESTMODEL_H
