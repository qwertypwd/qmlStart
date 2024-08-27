#include "avgViewer.h"

AvgViewer::AvgViewer(QObject* parent)
    : QObject(parent), n(1),  avg(0)
{
}

double AvgViewer::avgP() {
    return avg;
}

void AvgViewer::setAvgP(double val) {
    avg = calcAvg();
    emit avgPChanged();
}

void AvgViewer::add(int val)
{
    m_data.push_back(val);
}

double AvgViewer::calcAvg() {
    double avg = 0;

    for (auto it = m_data.rbegin(); it < m_data.rbegin() + n; it++) {
        avg += *it;
    }
    avg /= n;

    return avg;
}

void AvgViewer::onItemSend(QVariant val) {
    if(val.canConvert<int>()) {
        if (val.toInt() >= 1) {
            AvgViewer::add(val.toInt());
        }
    }
    setAvgP(0);
}

void AvgViewer::onNSend(QVariant val)
{
    if(val.canConvert<int>()) {
        if (val.toInt() >= 1 and val.toInt() <= m_data.size()) {
            n = val.toInt();
        }
    }
    setAvgP(0);
}
