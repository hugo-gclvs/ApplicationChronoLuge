import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: pageIdentification
    background: null

    Grid {
        columns: 1
        rows: 4
        anchors.fill: parent
        rowSpacing: 20

        Rectangle {
            id: recLogo
            color: "#00ffffff"
            width: parent.width
            height: parent.height / 2.7

            Image {
                id: logoIdentification
                anchors.centerIn: parent
                width: 230
                height: 200
                clip: true
                source: "../../../../image/image/logo.png"
            }
        }

        Rectangle {
            width: parent.width
            color: "#00ffffff"
            height: 40

            TextField {
                anchors.centerIn: parent
                id: champPseudo
                width: parent.width / 2
                height: 50
                placeholderText: qsTr("PSEUDO")
                background: Rectangle {
                    color: "#EBEBEB"
                    anchors.fill: parent
                    radius: 7
                }
            }
        }

        Rectangle {
            width: parent.width
            color: "#00ffffff"
            height: 40

            TextField {
                anchors.centerIn: parent
                id: champMdp
                width: parent.width / 2
                height: 50
                placeholderText: qsTr("MDP")
                background: Rectangle {
                    color: "#EBEBEB"
                    anchors.fill: parent
                    radius: 7
                }
            }
        }

        Rectangle {
            width: parent.width
            color: "#00ffffff"
            height: 150

            Button {
                id: boutonConnexion
                width: parent.width / 2.5
                height: 50
                anchors.centerIn: parent
                font.pixelSize: 20
                font.bold: true
                text: "<font color='#EBEBEB'> CONNEXION </font>"
                onClicked: {
                    toolBar.state = "normal"
                    stack.pop()
                    stack.pop("test.ui.qml")
                }
                background: Rectangle {
                    color: "#6B6B6B"
                    opacity: 0.9
                    radius: 10
                }
            }
        }
    }

    Component.onCompleted: (inscrit == true) ? console.log(
                                                   "inscrit") : stack.push(
                                                   "Inscription.ui.qml")
}
