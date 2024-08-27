#ifndef AVGVIEWER_H
#define AVGVIEWER_H
#include <QAbstractListModel>
#include <QStringList>
#include <testModel.h>

class AvgViewer : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(int name READ name WRITE setName NOTIFY nameChanged FINAL)

    int name() {
        return TestModel::calcAvg();
    }
    void setName(int val) {
        emit nameChanged();
    }

    //Q_INVOKABLE void add();
    //static int calcAvg();

signals:
    void nameChanged();
};

#endif // AVGVIEWER_H
