import QtQuick 2.15
import QtQuick.Window 2.15
import SP 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Life")

    LifeQuickItem {
        id: lifeQuickItem

        anchors.fill: parent
    }

    Timer {
        interval: 500
        repeat: true
        running: true
        onTriggered: {
            lifeQuickItem.tick();
        }
    }
}
