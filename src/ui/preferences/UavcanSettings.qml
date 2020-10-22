/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/
import QtQuick          2.3
import QtQuick.Dialogs  1.2
import QtQuick.Layouts  1.2

import QGroundControl.Controls      1.0
import QGroundControl.ScreenTools   1.0
import QGroundControl.FactSystem    1.0
import QGroundControl.FactControls  1.0
import QGroundControl.Controllers   1.0
import QGroundControl.Palette       1.0
import QGroundControl               1.0


Item {

    property var    _activeVehicle: QGroundControl.multiVehicleManager.activeVehicle ? QGroundControl.multiVehicleManager.activeVehicle : QGroundControl.multiVehicleManager.offlineEditingVehicle
    property var    factGroup:     _activeVehicle.getFactGroup("UAVCAN")

    property int    uavcan1: (factGroup.getFact("esc1")).value
    property int    uavcan2: (factGroup.getFact("esc2")).value
    property int    uavcan3: (factGroup.getFact("esc3")).value
    property int    uavcan4: (factGroup.getFact("esc4")).value


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
        complete: uavcan4
    }
}

