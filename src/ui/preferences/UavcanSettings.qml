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
    Image {
        id:                 vehicleIcon
        source:             "/qmlimages/x500.png"
        mipmap:             true
        fillMode:           Image.PreserveAspectFit
        anchors.top:        parent.left
        // anchors.bottom:     parent.bottom
    }

    UavcanButton{
        id: statusBtn3
        anchors.leftMargin:     35 * ScreenTools.defaultFontPixelWidth
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: 4 * ScreenTools.defaultFontPixelHeight
    }

    UavcanButton{
        id: statusBtn1
        anchors.leftMargin:     87 * ScreenTools.defaultFontPixelWidth
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: 4 * ScreenTools.defaultFontPixelHeight
    }

    UavcanButton{
        id: statusBtn2
        anchors.leftMargin:     23 * ScreenTools.defaultFontPixelWidth
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: 18 * ScreenTools.defaultFontPixelHeight
    }

    UavcanButton{
        id: statusBtn4
        anchors.leftMargin:     90 * ScreenTools.defaultFontPixelWidth
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: 19 * ScreenTools.defaultFontPixelHeight
        complete: true
    }
}


