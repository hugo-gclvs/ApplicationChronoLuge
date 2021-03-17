import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import ControllerIdentification 1.0

Page {
    id: pageInscription
    background: null

    Grid {
        columns: 1
        rows: 9
        anchors.fill: parent
        rowSpacing: 10

        Rectangle {
            id: recLogo
            color: "#00ffffff"
            width: parent.width
            height: parent.height / 2.7

            Image {
                id: logoIdentification
                anchors.centerIn: parent
                width: 170
                height: 130
                clip: true
                source: "../../../../image/image/logo.png"
            }
        }

        Rectangle {
            width: parent.width
            color: "#00ffffff"
            height: 40

            TextField {

                Image {
                    id: iconPseudoInsc
                    x: 10
                    y: 5
                    width: 30
                    height: 30
                    clip: true
                    source: "../../../../image/image/user.png"
                }

                anchors.centerIn: parent
                id: champPseudo
                width: parent.width / 1.3
                height: 40
                selectByMouse: true
                maximumLength: 15
                leftPadding: 50
                placeholderText: qsTr("Pseudo")
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

                Image {
                    id: iconMdpInsc
                    x: 10
                    y: 5
                    width: 30
                    height: 30
                    clip: true
                    source: "../../../../image/image/padlock.png"
                }

                anchors.centerIn: parent
                id: champMdp
                width: parent.width / 1.3
                height: 40
                leftPadding: 48
                echoMode: "Password"
                placeholderText: qsTr("Mot De Passe")
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

                Image {
                    id: iconMailInsc
                    x: 10
                    y: 5
                    width: 30
                    height: 30
                    clip: true
                    source: "../../../../image/image/mail.png"
                }

                anchors.centerIn: parent
                id: champMail
                width: parent.width / 1.3
                height: 40
                selectByMouse: true
                maximumLength: 255
                inputMethodHints: Qt.ImhEmailCharactersOnly
                leftPadding: 48
                placeholderText: qsTr("E-Mail")
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

                Image {
                    id: iconNomInsc
                    x: 10
                    y: 5
                    width: 30
                    height: 30
                    clip: true
                    source: "../../../../image/image/idcard.png"
                }

                anchors.centerIn: parent
                id: champNom
                width: parent.width / 1.3
                height: 40
                maximumLength: 20
                selectByMouse: true
                leftPadding: 48
                placeholderText: qsTr("Nom")
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

                Image {
                    id: iconPrenomInsc
                    x: 10
                    y: 5
                    width: 30
                    height: 30
                    clip: true
                    source: "../../../../image/image/idcard.png"
                }

                anchors.centerIn: parent
                id: champPrenom
                maximumLength: 20
                width: parent.width / 1.3
                height: 40
                selectByMouse: true
                leftPadding: 48
                placeholderText: qsTr("Prenom")
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

                Image {
                    id: iconAgeInsc
                    x: 10
                    y: 5
                    width: 30
                    height: 30
                    clip: true
                    source: "../../../../image/image/idcard.png"
                }

                anchors.centerIn: parent
                id: champAge
                width: parent.width / 1.3
                height: 40
                leftPadding: 48
                placeholderText: qsTr("Age")
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
            height: 80

            Button {
                id: boutonInscription
                width: parent.width / 1.5
                height: 40
                anchors.centerIn: parent
                font.pixelSize: 20
                font.bold: true

                Rectangle {
                    id: recChargementInsc
                    width: animationChargementInsc.width; height: animationChargementInsc.height
                    color: "transparent"
                    anchors.centerIn: parent
                    state: "normal"
                    visible: false
                    AnimatedImage { id: animationChargementInsc; source: "../../../../image/image/chargement.gif" }

                    states: [

                        State {
                            name: "chargement"
                            PropertyChanges {target: recChargementInsc; visible: true;}
                            PropertyChanges {target: boutonInscription; text: "";}
                    },
                        State {
                            name: "normal"
                            PropertyChanges {target: recChargementInsc; visible: false}
                            PropertyChanges {target: boutonInscription; text: "<font color='#EBEBEB'> S'INSCRIRE </font>";}
                        }
                    ]

                }

                text: "<font color='#EBEBEB'> S'INSCRIRE </font>"
                onClicked: {
                    if ((!champPseudo.length > 3) || (!champMdp.length > 6)
                            || (!champMail.length > 6) || (!champNom.length > 2)
                            || (!champPrenom.length > 2)
                            || (!champAge.acceptableInput))
                        console.log("Un des champs est incorrecte.")
                    else {
                        recChargementInsc.state = "chargement"
                        presenterIdentification.creerCompte(champPseudo.text,champMdp.text,champMail.text,champNom.text,champPrenom.text,champAge.text)
                    }
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
            height: 40

            Button {
                id: boutonDejaInscrit
                width: parent.width / 1.5
                height: 40
                anchors.centerIn: parent
                font.pixelSize: 20
                font.bold: true
                text: "<font color='#EBEBEB'> Déjà Inscrit ? </font>"
                onClicked: {
                    //presenterVisualiserTempsVitesse.getControllerVisualiserTempsVitesse().getEtatInscription().setValue("etatInscription", "inscrit");
                    stack.pop()
                }
                background: Rectangle {
                    color: "transparent"
                    opacity: 0.9
                    radius: 10
                }
            }
        }

    }

    Popup {
        id: popupInsc
        anchors.centerIn: parent
        width: parent.width/1.2
        height: 55
        modal: true
        focus: true
        background: Rectangle {
            border.color: "#f0c9cf"
            color: "#f2dede"
            radius: 5
            Text {
                anchors.centerIn: parent
                text: "ERREUR lors de l'inscription !"
                color: "#b94a48"
            }
        }

        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

    }

    Component.onCompleted: presenterIdentification.getMonController().onPostInscription.connect(gestionPostInscription)

    function gestionPostInscription(valeurReussite) {
        if (valeurReussite)
            stack.pop()
        else {
            recChargementInsc.state = "normal"
            popupInsc.open()
        }
    }
}
