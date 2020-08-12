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
        source:             "/qmlimages/x500.svg"
        mipmap:             true
        fillMode:           Image.PreserveAspectFit
        anchors.top:        parent.left
        // anchors.bottom:     parent.bottom
    }

    UavcanButton{
    id: cbutton
    anchors.leftMargin:     35 * ScreenTools.defaultFontPixelWidth
    anchors.left: parent.left
    anchors.top: parent.top
    anchors.topMargin: 8.5 * ScreenTools.defaultFontPixelHeight
    
}
}


