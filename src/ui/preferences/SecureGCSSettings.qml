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

Rectangle {
    color:          qgcPal.window
    anchors.fill:   parent

    readonly property real _margins: ScreenTools.defaultFontPixelHeight

    QGCPalette { id: qgcPal; colorGroupEnabled: true }

    QGCFlickable {
        anchors.fill:   parent
        contentWidth:   column.width  + (_margins * 2)
        contentHeight:  column.height + (_margins * 2)
        clip:           true

        Column {
            id:                 settingsTitle
            spacing:            ScreenTools.defaultFontPixelHeight * 0.5
            QGCLabel {
                text:  qsTr("Setting for Secure QGS")
                font.pointSize: ScreenTools.mediumFontPointSize
            }
            Rectangle {
                height: 1
                width:  settingsRect.width
                color:  qgcPal.button
                }
        }

        ColumnLayout {
            id:                 column
            anchors.margins:    _margins
            anchors.top:        settingsTitle.bottom
            spacing:            ScreenTools.defaultFontPixelHeight

            QGCCheckBox {
                id:             sendStatusText
                text:           qsTr("Using Sercure QGS")
            }
        }

        Image {
            id:                 vehicleIcon
            source:             "/qmlimages/AwarenessAircraft.svg"
            mipmap:             true
            width:              size
            sourceSize.width:   size
            fillMode:           Image.PreserveAspectFit
            anchors.left:              parent.right
            transform: Rotation {
                origin.x:       vehicleIcon.width  / 2
                origin.y:       vehicleIcon.height / 2
                angle:          isNaN(heading) ? 0 : heading
            }
        }
    }
}
