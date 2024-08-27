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

    int name();
    void setName(int val);
signals:
    void nameChanged();
};

#endif // AVGVIEWER_H
