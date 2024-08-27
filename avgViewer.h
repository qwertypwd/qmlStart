#ifndef AVGVIEWER_H
#define AVGVIEWER_H
#include <QAbstractListModel>
#include <QStringList>
#include <qqmlintegration.h>
#include <testModel.h>

class AvgViewer : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(double avgP READ avgP WRITE setAvgP NOTIFY avgPChanged)

public:
    AvgViewer(QObject* parent = nullptr);

    double avgP();
    void setAvgP(double val);

    void add(int val);
    double calcAvg();
    Q_INVOKABLE void onItemSend(QVariant val);
    Q_INVOKABLE void onNSend(QVariant val);

signals:
    void avgPChanged();
private:
    std::vector<int> m_data;
    int n;
    double avg;
};

#endif // AVGVIEWER_H
