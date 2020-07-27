/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


import QtQuick          2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts  1.11

import QGroundControl               1.0
import QGroundControl.Controls      1.0
import QGroundControl.Palette       1.0
import QGroundControl.ScreenTools   1.0

Item {
    Rectangle {
        color:          qgcPal.window
        anchors.fill:   parent

        QGCPalette { id: qgcPal; colorGroupEnabled: true }

        QGCFlickable {
            anchors.fill:   parent
            clip:           true

            Column {
                id:                 settingsTitle
                spacing:            ScreenTools.defaultFontPixelHeight * 0.5
                QGCLabel {
                    text:  qsTr("Setting for secure GCS")
                    font.pointSize: ScreenTools.mediumFontPointSize
                }
            }

            ColumnLayout {
                id:                 column
                anchors.top:        settingsTitle.bottom
                spacing:            ScreenTools.defaultFontPixelHeight
                anchors.margins:    15

                property bool security: QGroundControl.settingsManager.appSettings.security.rawValue

                QGCCheckBox {
                    text:               qsTr("Using Sercure QGS")
                    checked:            column.security
                    onClicked: {
                        if(checked) {
                            QGroundControl.settingsManager.appSettings.security.rawValue = true
                        }else {
                            QGroundControl.settingsManager.appSettings.security.rawValue = false
                        }
                        
                    }
                }
            }

        }
    }

    Image {
        id:                 vehicleIcon
        source:             "/qmlimages/AwarenessAircraft.svg"
        mipmap:             true
        fillMode:           Image.PreserveAspectFit
        anchors.right:      parent.right
        anchors.bottom:     parent.bottom
    }
}


