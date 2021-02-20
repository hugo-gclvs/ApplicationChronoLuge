import QtQuick 2.12
import QtQuick.Controls 2.5
import Historique 1.0

Page {
    id: pageVisualiserTempsVitesse
    background: null
    title: qsTr("HISTORIQUE DE DESCENTE")

    Button {
        id: boutonVersAjouterCourse
        width: parent.width - 40
        height: 50
        x: 20
        y: 20
        font.pixelSize: 20
        font.bold: true
        text: "<font color='#EBEBEB'> AJOUTER UNE DESCENTE </font>"
        onClicked: stack.push("AjouterDescente.ui.qml")
        background: Rectangle {
            color: "#6B6B6B"
            opacity: 0.9
            radius: 10
        }
    }

    Rectangle {
        id: fond1
        x: 20
        y: 90
        width: parent.width - 40
        height: parent.height - 110
        color: "white"
        radius: 15
        opacity: 0.7

        ScrollView {
            width: parent.width - 40
            height: parent.height - 110
            anchors.fill: parent
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn
            ScrollBar.vertical.interactive: true

            ListView {

                property int nmbrDescente: 4

                id: listView
                model: controleur.liste
                clip: true

                delegate: ItemDelegate {

                    property double vitesse: 12//controleur.liste[0].vitesse
                    property string date: "ffff"//controleur.liste[0].date
                    property string temps: "aaa"//controleur.liste[0].temps

                    id: maDescente
                    width: parent.width
                    height: 55
                    text: "<font color='#FFFFFF'>" + date + " / " + temps + "</font>"
                    font.bold: true
                    //highlighted: ListView.isCurrentItem
                    onClicked:
                        listView.currentIndex = index
                        //console.log("clicked:", modelData)

                    background: Rectangle {
                        id: fond2
                        color: "#D4D4D4"
                        border.color: "#888888"
                        state: "normal"

                        Rectangle {
                            id: ligne
                            visible: false
                            height: 2
                            anchors.right: parent.right
                            anchors.rightMargin: 70
                            anchors.left: parent.left
                            anchors.leftMargin: 25
                            y: 25
                            color: "#C2C2C2"
                        }

                        Image {
                            id: flecheDroite
                            anchors.topMargin: 10
                            anchors.top: parent.top
                            anchors.right: parent.right
                            anchors.rightMargin: 15
                            opacity: 1
                            width:  35
                            height:  35
                            clip: true
                            visible: true
                            source: "../../../../image/image/arrow-right.png"
                        }

                        Image {
                            id: flecheBas
                            anchors.topMargin: 10
                            anchors.top: parent.top
                            anchors.right: parent.right
                            anchors.rightMargin: 15
                            opacity: 0
                            width: 35
                            height: 35
                            clip: true
                            visible: true
                            source: "../../../../image/image/arrow-down.png"
                        }

                        Rectangle {
                            id: fond3
                            color: "#eeeeee"
                            radius: 5
                            width: parent.width-40
                            height: parent.height-70
                            x: 20
                            y: 50

                            Rectangle {
                                id: fond4
                                color: "#f7f7f7"
                                radius: 10
                                width: parent.width-30
                                height: parent.height-30
                                x: 15
                                y: 15

                                Grid {
                                    id: gridDescente
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
                                        id: recTemps
                                        width: parent.width/2-8
                                        height: parent.height/2-8
                                        color: "#f2f3f2"

                                        Label {
                                            id: titreTemps
                                            text: "TEMPS"
                                            color: "black"
                                            font.bold: false
                                        }

                                        Rectangle {
                                            id: ligneTemps
                                            height: 2
                                            anchors.right: parent.right
                                            anchors.rightMargin: 40
                                            anchors.left: parent.left
                                            y: 22
                                            color: "#8A8A8A"
                                        }

                                        Label {
                                            id: tempsDescente
                                            text: temps
                                            color: "#8A8A8A"
                                            font.bold: false
                                            y: 25
                                        }

                                    }

                                    Rectangle {
                                        id: recDate
                                        width: parent.width/2-8
                                        height: parent.height/2-8
                                        color: "#f2f3f2"

                                        Label {
                                            id: titreDate
                                            text: "DATE"
                                            color: "black"
                                            font.bold: false
                                        }

                                        Rectangle {
                                            id: ligneDate
                                            height: 2
                                            anchors.right: parent.right
                                            anchors.rightMargin: 40
                                            anchors.left: parent.left
                                            y: 22
                                            color: "#8A8A8A"
                                        }

                                        Label {
                                            id: dateDescente
                                            text: date
                                            color: "#8A8A8A"
                                            font.bold: false
                                            y: 25
                                        }

                                    }

                                    Rectangle {
                                        id: recVitesse
                                        width: parent.width/2-8
                                        height: parent.height/2-8
                                        color: "#f2f3f2"

                                        Label {
                                            id: titreVitesse
                                            text: "VITESSE"
                                            color: "black"
                                            font.bold: false
                                        }

                                        Rectangle {
                                            id: ligneVitesse
                                            height: 2
                                            anchors.right: parent.right
                                            anchors.rightMargin: 40
                                            anchors.left: parent.left
                                            y: 22
                                            color: "#8A8A8A"
                                        }

                                        Label {
                                            id: vitesseDescente
                                            text: vitesse + " km/h"
                                            color: "#8A8A8A"
                                            font.bold: false
                                            y: 25
                                        }

                                    }

                                }

                            }

                        }

                        MouseArea {
                           id: mouseArea
                           anchors.fill: parent
                           onClicked: {
                               if (fond2.state === "normal")
                                   fond2.state = "resized"
                               else
                                   fond2.state = "normal"
                           }
                        }

                        states: [

                            State {
                                name: "resized"
                                PropertyChanges {target: ligne; visible: true}
                                PropertyChanges {target: maDescente; height: 220; text: null}
                                PropertyChanges {target: fond3; visible: true}
                                PropertyChanges {target: fond4; visible: true}
                                PropertyChanges {target: flecheDroite; opacity:0}
                                PropertyChanges {target: flecheBas; opacity:1}
                        },
                            State {
                                name: "normal"
                                PropertyChanges {target: maDescente; height: 55}
                                PropertyChanges {target: fond3; visible: false}
                                PropertyChanges {target: fond4; visible: false}
                                PropertyChanges {target: flecheDroite; opacity:1}
                                PropertyChanges {target: flecheBas; opacity:0}
                            }
                        ]
                    }
                }
            }
        }
    }
}



/*transitions: [
    Transition {
        from: "normal"
        to: "resized"
        NumberAnimation {
            targets: [flecheBas, flecheDroite]
            properties: "opacity"
            duration: 500
        }
    },
    Transition {
        from: "resized"
        to: "normal"
        NumberAnimation {
            targets: [flecheBas, flecheDroite]
            properties: "opacity"
            duration: 500
        }
    }
]*/
