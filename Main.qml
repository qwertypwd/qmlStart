import QtQuick
import QtQuick.Controls
//import TestModelModule
import untitled3

Window {
    width: 360
    height: 600

    visible: true

    AvgViewer {
        id: avgViewer
    }

    Column {
        anchors.margins: 10
        anchors.fill: parent
        spacing: 10

        TextField {
            id: itemTf
            placeholderText: "item"
            //validator: IntValidator {bottom: 0}
        }
        Button{
            id: itemButton
            //Layout.alignment: Qt.AlignHCenter
            text: "Send"
            onClicked: {
                avgViewer.onItemSend(itemTf.text);
                itemTf.text = "";
            }
        }

        TextField {
            id: nTf
            //Layout.alignment: Qt.AlignHCenter
            placeholderText: "n"
            //validator: IntValidator {bottom: 0}

        }
        Button{
            id: nButton
            //Layout.alignment: Qt.AlignHCenter
            text: "Send"
            onClicked: {
                avgViewer.onNSend(nTf.text);
                nTf.text = "";
            }
        }

        ListView {
            id: avgRow

            width: parent.width
            height: 40
            spacing: 10
            model: dataModel

            Rectangle {
                width: parent.width
                height: 40
                color: "orange"

                Text {
                    id: avgRowText
                    text: avgViewer.avgP
                }
            }
        }
    }
}

/*
TestModel {
    id: dataModel
}
AvgViewer {
    id: avgViewer
}
Column {
    anchors.margins: 10
    anchors.fill: parent
    spacing: 10

    TextField {
        id: itemTf
        placeholderText: "item"
        //validator: IntValidator {bottom: 0}
    }
    Button{
        id: itemButton
        //Layout.alignment: Qt.AlignHCenter
        text: "Send"
        onClicked: {
            dataModel.onItemSend(itemTf.text);
            itemTf.text = "";
        }
    }

    TextField {
        id: nTf
        //Layout.alignment: Qt.AlignHCenter
        placeholderText: "n"
        //validator: IntValidator {bottom: 0}

    }
    Button{
        id: nButton
        //Layout.alignment: Qt.AlignHCenter
        text: "Send"
        onClicked: {
            dataModel.onNSend(nTf.text);
            nTf.text = "";
        }
    }

    ListView {
        id: avgRow

        width: parent.width
        height: 40
        spacing: 10
        model: dataModel
        //clip: true

        Rectangle {
            width: parent.width
            height: 40
            color: "orange"

            Text {
                id: avgRowText
                text: "avg"
            }

            Connections {
                target: itemButton
                function onClicked() {
                    //avgRowText.text = dataModel.updateAvg()
                }
            }
            Connections {
                target: nButton
                function onClicked() {
                    avgRowText.text = avgViewer.name
                    //dataModel.updateAvg(avgRowText.text)
                }
            }
        }
    }

    ListView {
        id: view

        width: parent.width
        height: 400
        spacing: 10
        model: dataModel
        //clip: true

        delegate: Rectangle {
            width: view.width
            height: 40
            //color: model.color

            Text {
                //anchors.centerIn: parent
                text: model.text || "old"
            }
        }
    }
}
*/
