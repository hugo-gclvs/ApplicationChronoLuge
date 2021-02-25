import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import ControllerIdentification 1.0

Page {
    id: pageIdentification
    background: null

    Grid {
        columns: 1
        rows: 5
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
                id: champPseudoConnexion
                width: parent.width / 2
                height: 50
                selectByMouse: true
                maximumLength: 15
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
                id: champMdpConnexion
                width: parent.width / 2
                height: 50
                echoMode: "Password"
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
                    if((champPseudoConnexion.length < 3) || (champMdpConnexion.length < 2))
                        console.log("Un des champs est incorrecte.")
                    else
                        presenterIdentification.rechercherCompte(champPseudoConnexion.text, champMdpConnexion.text)
                }
                background: Rectangle {
                    color: "#6B6B6B"
                    opacity: 0.9
                    radius: 10
                }
            }
        }

        Rectangle {
            width: parent.width
            color: "#00ffffff"
            height: 1

            Button {
                id: boutonConnexionADMIN
                width: parent.width / 2.5
                height: 50
                anchors.centerIn: parent
                font.pixelSize: 20
                font.bold: true
                text: "<font color='#EBEBEB'> ADMIN </font>"
                onClicked: presenterIdentification.rechercherCompte("admin", "Azerty*123")
                background: Rectangle {
                    color: "#970000"
                    opacity: 0.9
                    radius: 10
                }
            }
        }

    }

    Component.onCompleted: {
        presenterIdentification.getMonController().onPostConnexion.connect(gestionPostConnexion)
        if(presenterVisualiserTempsVitesse.getControllerVisualiserTempsVitesse().getEtatInscription() != "inscrit")
            stack.push("Inscription.ui.qml", StackView.Immediate)
    }

    function gestionPostConnexion(valeurReussite) {
        if (valeurReussite) {
            toolBar.state = "normal"
            stack.pop()
        } else
            console.log("Erreur lors de la connexion")
    }
}
