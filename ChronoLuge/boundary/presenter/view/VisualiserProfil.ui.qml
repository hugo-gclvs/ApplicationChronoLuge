import QtQuick 2.12
import QtQuick.Controls 2.5
import QtMultimedia 5.9
import ControllerVisualiserTempsVitesse 1.0

Page {
    id: pageProfil
    background: null
    title: qsTr("PROFIL")

    property string photoDeProfile: presenterVisualiserTempsVitesse.getMonUtilisateur(5)
    property string nom: presenterVisualiserTempsVitesse.getMonUtilisateur(1)
    property string prenom: presenterVisualiserTempsVitesse.getMonUtilisateur(2)
    property string age: presenterVisualiserTempsVitesse.getMonUtilisateur(3)
    property string pseudo: presenterVisualiserTempsVitesse.getMonUtilisateur(4)
    property string nmbrDescente: presenterVisualiserTempsVitesse.getMesStatistiques(1)
    property string vitMoy: presenterVisualiserTempsVitesse.getMesStatistiques(2)
    property string vitMin: presenterVisualiserTempsVitesse.getMesStatistiques(3)
    property string vitMax: presenterVisualiserTempsVitesse.getMesStatistiques(4)
    property string tempsMoy: presenterVisualiserTempsVitesse.getMesStatistiques(5)
    property string tempsMin: presenterVisualiserTempsVitesse.getMesStatistiques(6)
    property string tempsMax: presenterVisualiserTempsVitesse.getMesStatistiques(7)

    Grid {
        id: gridPrincipaleProfil
        columns: 1
        rows: 2
        anchors.fill: parent
        state: "normal"

        Rectangle {
            id: recLogo
            color: "#00ffffff"
            width: parent.width
            height: 210

            Image {
                id: pdp
                width: 160
                height: 160
                x: 20
                y: 20
                clip: true
                source: photoDeProfile
            }

            Label {
                text: "Modifier"
                color: "white"
                x: 70
                y: parent.height - 25
                MouseArea {
                    anchors.fill: parent
                    //onClicked: popupModifPdP.open()
                    onClicked: popupChoisirModePP.open()
                }

                Popup {
                    id: popupChoisirModePP
                    width: gridPrincipaleProfil.width/2
                    height: gridPrincipaleProfil.height/6.4
                    x: -60
                    modal: true
                    focus: true
                    background: Rectangle {
                        color: "transparent"
                        Grid {
                            id: gridChoixMode
                            columns: 1
                            rows: 2
                            anchors.fill: parent

                            Rectangle {
                                height: parent.height/2
                                width: parent.width

                                Button {
                                    id: boutonModeAvatar
                                    anchors.centerIn: parent
                                    width: parent.width
                                    height: 50
                                    font.pixelSize: 15
                                    font.bold: true
                                    text: "<font color='#EBEBEB'> Choisir Avatar </font>"
                                    onClicked: {
                                        popupModifPdP.open()
                                        popupChoisirModePP.close()
                                    }
                                    background: Rectangle {
                                        color: "#6B6B6B"
                                        opacity: 0.9
                                        radius: 10
                                    }
                                }
                            }

                            Rectangle {
                                height: parent.height/2
                                width: parent.width

                                Button {
                                    id: boutonModePrisePhoto
                                    anchors.centerIn: parent
                                    width: parent.width
                                    height: 50
                                    font.pixelSize: 15
                                    font.bold: true
                                    text: "<font color='#EBEBEB'> Prendre une Photo </font>"
                                    onClicked: {
                                        popupChoisirModePP.close()
                                        gridPrincipaleProfil.state = "prendrePhoto"
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

                    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

                }

            }

        }

        Rectangle {
            id: recStat
            color: "#00ffffff"
            width: parent.width
            height: parent.height - 270

            Rectangle {
                x: 20
                y: 10
                width: parent.width - 40
                height: parent.height - 30
                color: "white"
                radius: 15
                opacity: 0.7

                Grid {
                    columns: 1
                    rows: 2
                    anchors.fill: parent
                    rowSpacing: 20
                    leftPadding: 15
                    topPadding: 15

                    Rectangle {
                        id: fond4
                        color: "#f7f7f7"
                        opacity: 0.8
                        radius: 10
                        width: parent.width - 30
                        height: parent.height - 250

                        Grid {
                            id: gridProfil
                            columns: 2
                            rows: 2
                            anchors.fill: parent
                            anchors.topMargin: 10
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            columnSpacing: 5
                            rowSpacing: 5

                            Rectangle {
                                id: recNom
                                width: parent.width / 2 - 8
                                height: parent.height / 2 - 8
                                color: "#e3eee6"

                                Label {
                                    id: titreNom
                                    text: "NOM"
                                    color: "black"
                                    font.bold: false
                                }

                                Rectangle {
                                    id: ligneNom
                                    height: 2
                                    anchors.right: parent.right
                                    anchors.rightMargin: 40
                                    anchors.left: parent.left
                                    y: 17
                                    color: "#8A8A8A"
                                }

                                Label {
                                    id: idNom
                                    text: nom
                                    color: "#8A8A8A"
                                    font.bold: false
                                    y: 21
                                }
                            }

                            Rectangle {
                                id: recPrenom
                                width: parent.width / 2 - 8
                                height: parent.height / 2 - 8
                                color: "#e3eee6"

                                Label {
                                    id: titreDate
                                    text: "PRENOM"
                                    color: "black"
                                    font.bold: false
                                }

                                Rectangle {
                                    id: lignePrenom
                                    height: 2
                                    anchors.right: parent.right
                                    anchors.rightMargin: 40
                                    anchors.left: parent.left
                                    y: 17
                                    color: "#8A8A8A"
                                }

                                Label {
                                    id: idPrenom
                                    text: prenom
                                    color: "#8A8A8A"
                                    font.bold: false
                                    y: 21
                                }
                            }

                            Rectangle {
                                id: recAge
                                width: parent.width / 2 - 8
                                height: parent.height / 2 - 8
                                color: "#e3eee6"

                                Label {
                                    id: titreAge
                                    text: "AGE"
                                    color: "black"
                                    font.bold: false
                                }

                                Rectangle {
                                    id: ligneAge
                                    height: 2
                                    anchors.right: parent.right
                                    anchors.rightMargin: 40
                                    anchors.left: parent.left
                                    y: 17
                                    color: "#8A8A8A"
                                }

                                Label {
                                    id: idAge
                                    text: age
                                    color: "#8A8A8A"
                                    font.bold: false
                                    y: 21
                                }
                            }

                            Rectangle {
                                id: recPseudo
                                width: parent.width / 2 - 8
                                height: parent.height / 2 - 8
                                color: "#e3eee6"

                                Label {
                                    id: titrePseudo
                                    text: "PSEUDO"
                                    color: "black"
                                    font.bold: false
                                }

                                Rectangle {
                                    id: lignePseudo
                                    height: 2
                                    anchors.right: parent.right
                                    anchors.rightMargin: 40
                                    anchors.left: parent.left
                                    y: 17
                                    color: "#8A8A8A"
                                }

                                Label {
                                    id: idPseudo
                                    text: pseudo
                                    color: "#8A8A8A"
                                    font.bold: false
                                    y: 21
                                }
                            }
                        }
                    }

                    Rectangle {
                        id: fondBlanc
                        color: "#f7f7f7"
                        opacity: 0.8
                        radius: 10
                        width: parent.width - 30
                        height: parent.height - 160
                        x: 15
                        y: 15

                        Grid {
                            id: gridProfil2
                            columns: 2
                            rows: 4
                            anchors.fill: parent
                            anchors.topMargin: 10
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            columnSpacing: 5
                            rowSpacing: 5

                            Rectangle {
                                id: recDescente
                                width: parent.width / 2 - 8
                                height: parent.height / 4 - 8
                                color: "#e3eee6"

                                Label {
                                    id: titreDescente
                                    text: "DESCENTE"
                                    color: "black"
                                    font.bold: false
                                }

                                Rectangle {
                                    id: ligneDescente
                                    height: 2
                                    anchors.right: parent.right
                                    anchors.rightMargin: 40
                                    anchors.left: parent.left
                                    y: 17
                                    color: "#8A8A8A"
                                }

                                Label {
                                    id: idDescente
                                    text: nmbrDescente
                                    color: "#8A8A8A"
                                    font.bold: false
                                    y: 21
                                }
                            }

                            Rectangle {
                                id: recVitesseMoy
                                width: parent.width / 2 - 8
                                height: parent.height / 4 - 8
                                color: "#e3eee6"

                                Label {
                                    id: titreVitesseMoy
                                    text: "VITESSE MOYE"
                                    color: "black"
                                    font.bold: false
                                }

                                Rectangle {
                                    id: ligneVitesseMoy
                                    height: 2
                                    anchors.right: parent.right
                                    anchors.rightMargin: 40
                                    anchors.left: parent.left
                                    y: 17
                                    color: "#8A8A8A"
                                }

                                Label {
                                    id: idVitesseMoy
                                    text: vitMoy
                                    color: "#8A8A8A"
                                    font.bold: false
                                    y: 21
                                }
                            }

                            Rectangle {
                                id: recVitesseMin
                                width: parent.width / 2 - 8
                                height: parent.height / 4 - 8
                                color: "#e3eee6"

                                Label {
                                    id: titreVitesseMin
                                    text: "VITESSE MIN"
                                    color: "black"
                                    font.bold: false
                                }

                                Rectangle {
                                    id: ligneVitesseMin
                                    height: 2
                                    anchors.right: parent.right
                                    anchors.rightMargin: 40
                                    anchors.left: parent.left
                                    y: 17
                                    color: "#8A8A8A"
                                }

                                Label {
                                    id: idVitesseMin
                                    text: vitMin
                                    color: "#8A8A8A"
                                    font.bold: false
                                    y: 21
                                }
                            }

                            Rectangle {
                                id: recVitesseMax
                                width: parent.width / 2 - 8
                                height: parent.height / 4 - 8
                                color: "#e3eee6"

                                Label {
                                    id: titreVitesseMax
                                    text: "VITESSE MAX"
                                    color: "black"
                                    font.bold: false
                                }

                                Rectangle {
                                    id: ligneVitesseMax
                                    height: 2
                                    anchors.right: parent.right
                                    anchors.rightMargin: 40
                                    anchors.left: parent.left
                                    y: 17
                                    color: "#8A8A8A"
                                }

                                Label {
                                    id: idVitesseMax
                                    text: vitMax
                                    color: "#8A8A8A"
                                    font.bold: false
                                    y: 21
                                }
                            }

                            Rectangle {
                                id: recTempsMoy
                                width: parent.width / 2 - 8
                                height: parent.height / 4 - 8
                                color: "#e3eee6"

                                Label {
                                    id: titreTempsMoy
                                    text: "TEMPS MOYE"
                                    color: "black"
                                    font.bold: false
                                }

                                Rectangle {
                                    id: ligneTempsMoy
                                    height: 2
                                    anchors.right: parent.right
                                    anchors.rightMargin: 40
                                    anchors.left: parent.left
                                    y: 17
                                    color: "#8A8A8A"
                                }

                                Label {
                                    id: idTempsMoy
                                    text: tempsMoy
                                    color: "#8A8A8A"
                                    font.bold: false
                                    y: 21
                                }
                            }

                            Rectangle {
                                id: recTempsMin
                                width: parent.width / 2 - 8
                                height: parent.height / 4 - 8
                                color: "#e3eee6"

                                Label {
                                    id: titreTempsMin
                                    text: "TEMPS MIN"
                                    color: "black"
                                    font.bold: false
                                }

                                Rectangle {
                                    id: ligneTempsMin
                                    height: 2
                                    anchors.right: parent.right
                                    anchors.rightMargin: 40
                                    anchors.left: parent.left
                                    y: 17
                                    color: "#8A8A8A"
                                }

                                Label {
                                    id: idTempsMin
                                    text: tempsMin
                                    color: "#8A8A8A"
                                    font.bold: false
                                    y: 21
                                }
                            }

                            Rectangle {
                                id: recTempsMax
                                width: parent.width / 2 - 8
                                height: parent.height / 4 - 8
                                color: "#e3eee6"

                                Label {
                                    id: titreTempsMax
                                    text: "TEMPS MAX"
                                    color: "black"
                                    font.bold: false
                                }

                                Rectangle {
                                    id: ligneTempsMax
                                    height: 2
                                    anchors.right: parent.right
                                    anchors.rightMargin: 40
                                    anchors.left: parent.left
                                    y: 17
                                    color: "#8A8A8A"
                                }

                                Label {
                                    id: idTempsMax
                                    text: tempsMax
                                    color: "#8A8A8A"
                                    font.bold: false
                                    y: 21
                                }
                            }
                        }
                    }
                }
            }
        }

        states: [
            State {
                name: "normal"
                PropertyChanges {
                    target: gridPrincipaleProfil
                    visible: true
                }
                PropertyChanges {
                    target:  framePrendrePhoto
                    visible: false
                }
            },
            State {
                name: "prendrePhoto"
                PropertyChanges {
                    target: gridPrincipaleProfil
                    visible: false
                }
                PropertyChanges {
                    target: framePrendrePhoto
                    visible: true
                }
            }
        ]

    }


    Frame {
        id: framePrendrePhoto
        visible: false
        width: parent.width
        height: parent.height

        Camera{
            id:appareil
            position: Camera.FrontFace
            exposure{
                exposureMode: Camera.ExposureAction
                manualIso:800
            }
            focus{
                focusMode:CameraFocus.FocusContinuous
                focusPointMode:Camera.FocusPointAuto
            }
            imageProcessing{
                saturation:-1
                contrast:1
            }
            flash.mode:Camera.FlashAuto
            imageCapture.onImageCaptured:visu.source=preview
            captureMode:Camera.CaptureStillImage
            imageCapture {
                 onImageCaptured: {
                 var imgPath =  appareil.imageCapture.capturedImagePath
                     presenterVisualiserTempsVitesse.nouvellePP(imgPath)
                 }
            }
        }


        VideoOutput{
            id:vidéo
            source:appareil
            anchors.fill:parent
            orientation:appareil.orientation
        }

        Timer{
            id:temps
            interval:5000
            onTriggered: visu.visible=false
        }

        Image{
            id: visu
            fillMode:Image.PreserveAspectCrop
            anchors.fill:parent
        }

        ToolButton{
            anchors{
                bottom:parent.bottom
                bottomMargin:8
                horizontalCenter:parent.horizontalCenter
            }
            icon{
                source: "../../../../image/image/logo.png"
                color:"transparent"
                width:64
                height:64
            }
            onClicked:{
                visu.visible=true
                temps.start()
                appareil.imageCapture.capture()
            }
            background:Rectangle{color:"transparent"}
        }

    }


    Popup {
        id: popupModifPdP
        anchors.centerIn: parent
        width: parent.width/1.1
        height: parent.height/1.1
        modal: true
        focus: true
        closePolicy: Popup.CloseOnPressOutside
        background: Rectangle {
            border.color: "#b2b2b2"
            border.width: 2
            color: "#e3e3e3"
            radius: 5
        }

        Button {
            id: boutonValiderPdp
            width: parent.width
            height: 50
            font.pixelSize: 20
            font.bold: true
            text: "<font color='#EBEBEB'> VALIDER </font>"
            onClicked: {
                presenterVisualiserTempsVitesse.nouvellePPAvatar(maListeImgAvatar.get(maGrid.currentIndex).pp)
                popupModifPdP.close()
            }
            background: Rectangle {
                color: "#6B6B6B"
                opacity: 0.9
                radius: 10
            }
        }

        GridView {
            id: maGrid
            width: parent.width
            height: parent.height-60
            y: 60
            cellWidth: 101; cellHeight: 101
            Rectangle {
                anchors.fill: parent
                border.color: "#b2b2b2"
                border.width: 2
                radius: 5
                color: "transparent"
            }

            Component {
                id: ppDelegate
                Rectangle {
                    id: wrapper
                    width: 101
                    height: 101
                    radius: 5
                    color: GridView.isCurrentItem ? "lightsteelblue" : "transparent"
                    Image {
                        id: ppInfo
                        source: pp; width: 95; height: 95; anchors.horizontalCenter: parent.horizontalCenter; anchors.verticalCenter: parent.verticalCenter;
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: maGrid.currentIndex = index;

                    }

                }

            }

            model: ListeImgPP {id: maListeImgAvatar}
            delegate: ppDelegate
            property variant myData: model
            focus: true
            clip: true
        }

    }


    Button {
        Rectangle {
            color: "white"
            anchors.fill: parent
        }

        Image {
            id: flecheDroite2
            width: 30
            y: 10
            x: 10
            height: 30
            opacity: 0.5
            clip: true
            visible: true
            source: "../../../../image/image/arrow-left.png"
        }
        height: 50
        width: parent.width
        anchors.bottom: parent.bottom
        onClicked: stackView.pop()
    }

    Popup {
        id: popupErreurPP
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
                text: "ERREUR de modification !"
                color: "#b94a48"
            }
        }

        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

    }


    Component.onCompleted: {
        //maGrid.currentIndex = presenterIdentification.getMonController().getNumPdp()-1
        presenterVisualiserTempsVitesse.getControllerVisualiserTempsVitesse().onPostNewPP.connect(gestionPostNewProfil)
    }

    Component.onDestruction: {
        presenterVisualiserTempsVitesse.getControllerVisualiserTempsVitesse().onPostNewPP.disconnect(gestionPostNewProfil)
    }


    function gestionPostNewProfil(valeurReussite, lienPP) {
        if(valeurReussite === true)
            photoDeProfile = lienPP;
        else
            popupErreurPP.open()
    }

    /*function gestionPP() {
        var pdp.source = parseInt(presenterVisualiserTempsVitesse.getMonUtilisateur(5))-1;
        if(retourPP === 0)
            pdp.source = "../../../../pdp/image/avatar/profil.png"
        else
            pdp.source = "../../../../pdp/image/avatar/user-" + retourPP.toString() + ".png"
    }*/

}
