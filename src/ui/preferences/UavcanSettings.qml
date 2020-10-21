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

    property int    uavcan1: 0
    property int    uavcan2: 0 
    property int    uavcan3: 0
    property int    uavcan4: 0
    // property variant uavcanESC: uavcanESC

    // Connections {
    //     target : QGroundControl.vehicle
    //     onReceivedUAVCANESCStatus:statusBtn1.complete = uavcanESC;
    // }

    ColumnLayout {
        id: col
        spacing:            ScreenTools.defaultFontPixelHeight * 0.5
        Layout.fillWidth:   true

        QGCLabel {
            Layout.fillWidth:   true
            font.pointSize:     ScreenTools.largeFontPointSize
            text:               qsTr("UAVCAN")
            visible:            true
        }

        QGCLabel {
            Layout.fillWidth:   true
            wrapMode:           Text.WordWrap
            text:               qsTr("UAVCAN Setup is used to check the current status of UAVACAN devices.")
            visible:            true
        }
    }
    Image {
        id:                 vehicleIcon
        source:             "/qmlimages/x500.png"
        mipmap:             true
        fillMode:           Image.PreserveAspectFit
        anchors.top:        col.bottom
    }

    UavcanButton{
    id: statusBtn1
    anchors.leftMargin:     87 * ScreenTools.defaultFontPixelWidth
    anchors.left: parent.left
    anchors.top: col.bottom
    anchors.topMargin: 4 * ScreenTools.defaultFontPixelHeight
    complete: uavcan1
    }

    UavcanButton{
        id: statusBtn2
        anchors.leftMargin:     23 * ScreenTools.defaultFontPixelWidth
        anchors.left: parent.left
        anchors.top: col.bottom
        anchors.topMargin: 18 * ScreenTools.defaultFontPixelHeight
        complete: uavcan2
    }

    UavcanButton{
        id: statusBtn3
        anchors.leftMargin:     35 * ScreenTools.defaultFontPixelWidth
        anchors.left: parent.left
        anchors.top: col.bottom
        anchors.topMargin: 4 * ScreenTools.defaultFontPixelHeight
        complete: uavcan3
    }


    UavcanButton{
        id: statusBtn4
        anchors.leftMargin:     90 * ScreenTools.defaultFontPixelWidth
        anchors.left: parent.left
        anchors.top: col.bottom
        anchors.topMargin: 19 * ScreenTools.defaultFontPixelHeight
        complete: uavcan1
    }
}

