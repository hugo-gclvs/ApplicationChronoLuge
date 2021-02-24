import QtQuick 2.12
import QtQuick.Controls 2.5
import QtMultimedia 5.9
import QZXing 3.1
import QtQuick.Controls 2.4

Page {
    id: pageAjouterDescente
    //anchors.fill: parent
    background: null
    title: qsTr("AJOUT D'UNE DESCENTE")

    Frame {
        id: zoneCamera
        anchors.fill: parent
        state: "normal"

        Camera {
            id: objectif
            focus {
                focusMode: CameraFocus.FocusContinuous
                focusPointMode: Camera.FocusPointAuto
            }
        }

        VideoOutput {
            id: visu
            source: objectif
            filters: [filtres]
            autoOrientation: true
            anchors.fill: parent
        }

        QZXingFilter {
            id: filtres
            decoder {
                enabledDecoders: QZXing.DecoderFormat_QR_CODE
                onTagFound: {
                    //reponse.text=decoder.foundedFormat()
                    reponse.append(tag)
                    presenterVisualiserTempsVitesse.lierDescente(tag)
                    objectif.stop()
                }
            }
            //onDecodingStarted: titreSucces.text="Scan..."
        }

        Button {
            anchors {
                top: parent.top
                topMargin: 20
                horizontalCenter: parent.horizontalCenter
            }
            width: 400
            height: 50
            font.pixelSize: 20
            font.bold: true
            text: "Scanner le QRCode de la Luge !"
            background: Rectangle {
                color: "ivory"
                radius: 7
            }
        }


        states: [

            State {
                name: "qrcodeDetecte"
                PropertyChanges {
                    target: zoneCamera
                    visible: false
                }
                PropertyChanges {
                    target: zoneEchec
                    visible: false
                }
                PropertyChanges {
                    target: zoneSucces
                    visible: true
                }
            },
            State {
                name: "qrcodeNonDetecte"
                PropertyChanges {
                    target: zoneCamera
                    visible: false
                }
                PropertyChanges {
                    target: zoneSucces
                    visible: false
                }
                PropertyChanges {
                    target: zoneEchec
                    visible: true
                }
            },
            State {
                name: "normal"
                PropertyChanges {
                    target: zoneCamera
                    visible: true
                }
                PropertyChanges {
                    target: zoneSucces
                    visible: false
                }
                PropertyChanges {
                    target: zoneEchec
                    visible: false
                }
            }
        ]
    }

    Frame {
        id: zoneSucces
        anchors.fill: parent
        visible: false
        Rectangle {
            id: fondSucces
            x: 20
            y: 20
            width: parent.width - 40
            height: parent.height - 100
            color: "white"
            radius: 15
            opacity: 0.7

            TextArea {
                id: reponse
                background: Rectangle {
                    color: "white"
                    radius: 7
                }
                text: "DESCENTE AJOUTEE !"
                readOnly: true
                //anchors.centerIn: parent
                font.pixelSize: 16
                font.bold: true
                width: parent.width - 40
                height: parent.height / 10
                horizontalAlignment: TextEdit.AlignHCenter
                wrapMode: Text.Wrap
                x: 20
                y: 20
            }

            Image {
                id: check
                anchors.centerIn: parent
                width: 350
                height: 350
                clip: true
                visible: true
                source: "../../../../image/image/check.png"
            }
        }
    }

    Frame {
        id: zoneEchec
        anchors.fill: parent
        Rectangle {
            id: fondEchec
            x: 20
            y: 20
            width: parent.width - 40
            height: parent.height - 100
            color: "white"
            radius: 15
            opacity: 0.7

            TextArea {
                id: echec
                background: Rectangle {
                    color: "white"
                    radius: 7
                }
                text: "ECHEC DE L'AJOUT ! REESSAYEZ"
                readOnly: true
                font.pixelSize: 16
                font.bold: true
                width: parent.width - 40
                height: parent.height / 10
                horizontalAlignment: TextEdit.AlignHCenter
                wrapMode: Text.Wrap
                x: 20
                y: 20
            }

            Image {
                id: uncheck
                anchors.centerIn: parent
                width: 350
                height: 350
                clip: true
                visible: true
                source: "../../../../image/image/uncheck.png"
            }
        }
    }

    Button {
        text: "Retour"
        display: AbstractButton.TextOnly
        height: 60
        width: parent.width
        anchors.bottom: parent.bottom
        onClicked: stackView.pop()
    }

    Component.onCompleted: presenterVisualiserTempsVitesse.getControllerVisualiserTempsVitesse().onPostLierDescente.connect(gestionPostLierDescente)

    function gestionPostLierDescente(etat) {
        if (etat) {
            zoneCamera.state = "qrcodeDetecte"
        } else
            zoneCamera.state = "qrcodeNonDetecte"
    }

}
