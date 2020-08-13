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

Button {
        id:                 uavcanButton
        height:             ScreenTools.defaultFontPixelHeight * 1.5
        autoExclusive:      true

        background: Rectangle {
            anchors.fill:   parent
            color:          qgcPal.button
            border.width:   0
            border.color:   qgcPal.buttonText
        }

        property bool   complete:   false

        contentItem: Row{
            anchors.centerIn:   parent
            anchors.margins:    ScreenTools.defaultFontPixelWidth
            Rectangle {
                width:   sizeLabel.height * 0.5
                height:  sizeLabel.height * 0.5
                radius:  width / 2
                color:   complete ? "#31f55b" : "#fc5656"
                opacity: sizeLabel.text.length > 0 ? 1 : 0
                anchors.verticalCenter: parent.verticalCenter
            }
            Item {
            width:  ScreenTools.defaultFontPixelWidth * 2
            height: 1
            }
            QGCLabel {
                id : sizeLabel
                color : complete ? "white" : "red"
                text:  complete ?  "정상" : "중지"
                width:  uavcanButton.width * 0.4
                anchors.verticalCenter: parent.verticalCenter
            }
        }
}
