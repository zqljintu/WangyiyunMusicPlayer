import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.1

Item {
    id:mainWindow
    visible: true
    height: 600
    width: 1050
    Rectangle {
        width: mainWindow.width;
        height: mainWindow.height;
        color: "black";
        id: root;
        Component {
            id: rectDelegate;
            Item {
                id: wrapper;
                z: PathView.zOrder;
                opacity: PathView.itemAlpha;
                scale: PathView.itemScale;
                Rectangle {
                    width: 500;
                    height: 250;
                    color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
                    border.width: 2;
                    border.color: wrapper.PathView.isCurrentItem ? "red" : "lightgray";
                    Text {
                        anchors.centerIn: parent;
                        font.pixelSize: 28;
                        text: index;
                        color: Qt.lighter(parent.color, 2);
                    }
                }
            }
        }

        PathView {
            id: pathView;
            anchors.fill: parent;
            interactive: true;
            pathItemCount: 3;
            preferredHighlightBegin: 0.5;
            preferredHighlightEnd: 0.5;
            highlightRangeMode: PathView.StrictlyEnforceRange;

            delegate: rectDelegate;
            model: 3;

            path:Path {
                startX: -150;
                startY: 100;
                PathAttribute { name: "zOrder"; value: 0 }
                PathAttribute { name: "itemAlpha"; value: 0.1 }
                PathAttribute { name: "itemScale"; value: 0.8 }
                PathLine {
                    x:400;
                    y: 100;
                }
                PathAttribute { name: "zOrder"; value: 50}
                PathAttribute { name: "itemAlpha"; value: 0.8 }
                PathAttribute { name: "itemScale"; value: 1.2 }
                PathLine {
                    relativeX: root.width/2 - 40;
                    relativeY: 0;
                }
                PathAttribute { name: "zOrder"; value: 0 }
                PathAttribute { name: "itemAlpha"; value: 0.1 }
                PathAttribute { name: "itemScale"; value: 0.8 }
            }
            focus: true;
            Keys.onLeftPressed: decrementCurrentIndex();
            Keys.onRightPressed: incrementCurrentIndex();
            MouseArea{
                anchors.fill: mainWindow
                onClicked: {mainWindow.height=500}
            }
        }
    }
}
