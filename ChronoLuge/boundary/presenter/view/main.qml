import QtQuick 2.12
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.0
import ControllerVisualiserTempsVitesse 1.0

ApplicationWindow {
    id: window
    width: 520
    height: 800
    color: "#00ffffff"
    title: qsTr("Chrono'Luge")
    visible: true
    LinearGradient {
        id: fondApplication
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#4FC715" }
            GradientStop { position: 1.0; color: "#4476A8" }
        }

    }


    property int largeur: window.width
    property alias stack: stackView
    property bool connecte: true
    property bool inscrit: true

    header: ToolBar {
        id: toolBar
        height: 60
        visible: true
        state: "normal"
        background: Rectangle {
            color: "#EBEBEB"
            opacity: 0.9
        }

        Image {
            id: logo
            anchors.topMargin: 5
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.leftMargin: 5
            width: 60
            height: 50
            clip: true
            visible: true
            source: "../../../../image/image/logo.png"
        }

        Label {
            text: stackView.currentItem.title
            leftPadding: 70
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: Qt.application.font.pixelSize
            opacity: 0.5
            anchors.fill: parent
        }

        Image {
            id: img_profil
            width: 50
            height: 50
            anchors.topMargin: 5
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.rightMargin: 5
            clip: true
            visible: true
            //source: "https://chronoluge.000webhostapp.com/images/avatar/profil.png"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if(stackView.currentItem !== "VisualiserProfil.ui.qml") {
                        stackView.pop(StackView.Immediate)
                        stackView.push("VisualiserProfil.ui.qml")
                    }
                }
            }
            fillMode: Image.PreserveAspectCrop
            layer.enabled: true
            layer.effect: OpacityMask {
                maskSource: maskNavBar
            }
        }

        Rectangle {
            id: maskNavBar
            width: 500
            height: 500
            radius: 250
            visible: false
        }

        states: [

            State {
                name: "cacherHeader"
                PropertyChanges {target: toolBar; visible: false}
        },
            State {
                name: "normal"
                PropertyChanges {target: toolBar; visible: true}
            }
        ]

    }

    StackView {
        id: stackView
        anchors.top: parent.top
        initialItem: "VisualiserTempsVitesse.ui.qml"
        anchors.fill: parent
    }

    Component.onCompleted: {
        presenterVisualiserTempsVitesse.getControllerVisualiserTempsVitesse().onPostNewPP.connect(gestionPostNewPP)
        if(presenterVisualiserTempsVitesse.getControllerVisualiserTempsVitesse().getEtatConnexion() !== "connecte") {
            stack.push("Identification.ui.qml", StackView.Immediate)
            toolBar.state = "cacherHeader"
        }
    }

    function gestionPostConnexion(valeurReussite) {
        if (valeurReussite) {
            toolBar.state = "normal"
            stack.pop()
        } else {
            recChargement.state = "normal"
            popupConn.open()
        }
    }

    function gestionPostNewPP(valeurReussite, lienPP) {
        if(valeurReussite) {
            img_profil.source = lienPP
        }
    }


}
