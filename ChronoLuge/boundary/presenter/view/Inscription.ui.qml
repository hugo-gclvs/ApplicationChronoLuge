import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: pageInscription
    background: null

    Grid {
        columns: 1
        rows: 8
        anchors.fill: parent
        rowSpacing: 20

        Rectangle {
            id: recLogo
            color: "#00ffffff"
            width: parent.width
            height: parent.height/2.7

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
                width: parent.width/2
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
                id: champMail
                width: parent.width/2
                height: 50
                placeholderText: qsTr("MAIL")
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
                id: champNom
                width: parent.width/2
                height: 50
                placeholderText: qsTr("NOM")
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
                id: champPrenom
                width: parent.width/2
                height: 50
                placeholderText: qsTr("PRENOM")
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
                id: champAge
                width: parent.width/2
                height: 50
                placeholderText: qsTr("AGE")
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
                width: parent.width/2
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
            height: 110

            Button {
                id: boutonConnexion
                width: parent.width/2.5
                height: 50
                anchors.centerIn: parent
                font.pixelSize: 20
                font.bold: true
                text: "<font color='#EBEBEB'> S'INSCRIRE </font>"
                onClicked: {
                    stack.pop()
                }
                background: Rectangle {
                    color: "#6B6B6B"
                    opacity: 0.9
                    radius: 10
                }
            }
        }

    }

}



