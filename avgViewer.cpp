#include "avgViewer.h"

int AvgViewer::name() {
    return TestModel::calcAvg();
}
void AvgViewer::setName(int val) {
    emit nameChanged();
}
