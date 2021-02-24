import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import ControllerIdentification 1.0

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
                id: champMdp
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
            height: 40

            TextField {
                anchors.centerIn: parent
                id: champMail
                width: parent.width / 2
                height: 50
                selectByMouse: true
                maximumLength: 255
                inputMethodHints: Qt.ImhEmailCharactersOnly
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
                width: parent.width / 2
                height: 50
                maximumLength: 20
                selectByMouse: true
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
                maximumLength: 20
                width: parent.width / 2
                height: 50
                selectByMouse: true
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
                width: parent.width / 2
                height: 50
                placeholderText: qsTr("AGE")
                background: Rectangle {
                    color: "#EBEBEB"
                    anchors.fill: parent
                    radius: 7
                }
                validator: IntValidator {
                    bottom: 6
                    top: 120
                }
                focus: true
            }
        }

        Rectangle {
            width: parent.width
            color: "#00ffffff"
            height: 110

            Button {
                id: boutonInscription
                width: parent.width / 2.5
                height: 50
                anchors.centerIn: parent
                font.pixelSize: 20
                font.bold: true
                text: "<font color='#EBEBEB'> S'INSCRIRE </font>"
                onClicked: {
                    if ((!champPseudo.length > 3) || (!champMdp.length > 6)
                            || (!champMail.length > 6) || (!champNom.length > 2)
                            || (!champPrenom.length > 2)
                            || (!champAge.acceptableInput))
                        console.log("Un des champs est incorrecte.")
                    else
                        presenterIdentification.creerCompte(champPseudo.text,
                                                            champMdp.text,
                                                            champMail.text,
                                                            champNom.text,
                                                            champPrenom.text,
                                                            champAge.text)
                }
                background: Rectangle {
                    color: "#6B6B6B"
                    opacity: 0.9
                    radius: 10
                }
            }
        }
    }

    Component.onCompleted: {
        presenterIdentification.getMonController().onPostInscription.connect(
                    gestionPostInscription)
    }

    function gestionPostInscription(valeurReussite) {
        if (valeurReussite)
            stack.pop()
        else
            console.log("bg mon reuf")
    }
}
