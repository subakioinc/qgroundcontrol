/****************************************************************************
 *
 *   (c) 2009-2016 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

import QtQuick                  2.3
import QtQuick.Controls         1.2
import QtQuick.Controls.Styles  1.4
import QtQuick.Dialogs          1.2
import QtQuick.Layouts          1.2

import QGroundControl                       1.0
import QGroundControl.FactSystem            1.0
import QGroundControl.FactControls          1.0
import QGroundControl.Controls              1.0
import QGroundControl.ScreenTools           1.0
import QGroundControl.MultiVehicleManager   1.0
import QGroundControl.Palette               1.0
import QGroundControl.Controllers           1.0
import QGroundControl.SettingsManager       1.0


QGCView {
    id:                 _qgcView
    viewPanel:          panel
    color:              qgcPal.window
    anchors.fill:       parent
    anchors.margins:    ScreenTools.defaultFontPixelWidth

    readonly property real                      _internalWidthRatio: 0.8
    property real _margins:                     ScreenTools.defaultFontPixelWidth
    property real _valueFieldWidth:             ScreenTools.defaultFontPixelWidth * 10

    QGCPalette { id: qgcPal }

    QGCViewPanel {
        id:             panel
        anchors.fill:   parent

        QGCFlickable {
            clip:               true
            anchors.fill:       parent
            contentHeight:      outerItem.height
            contentWidth:       outerItem.width

            Item {
                id:     outerItem
                width:  Math.max(panel.width, loginColumn.width)
                height: loginColumn.height

                ColumnLayout {
                    id:                     loginColumn
                    anchors.horizontalCenter:   parent.horizontalCenter

                    QGCLabel {
                        id:         loginLabel
                        text:       qsTr("Naver 지도 사용자 ")
                    }
                    Rectangle {
                        Layout.preferredHeight: loginCol.height + (_margins * 2)
                        Layout.preferredWidth:  loginCol.width + (_margins * 2)
                        color:                  qgcPal.windowShade
                        visible:                loginLabel.visible
                        Layout.fillWidth:       true

                        ColumnLayout {
                            id:                         loginCol
                            anchors.margins:            _margins
                            anchors.top:                parent.top
                            anchors.horizontalCenter:   parent.horizontalCenter
                            spacing:                    _margins

                            GridLayout {
                                columns: 2

                                QGCLabel { text: qsTr("ID                ") }
                                TextField {
                                    Layout.preferredWidth:  _valueFieldWidths
                                    placeholderText: qsTr("Enter your ID")
                                }

                                QGCLabel { text: qsTr("Password           ") }
                                TextField {
                                    Layout.preferredWidth:  _valueFieldWidth
                                    placeholderText: qsTr("Enter your passwords")
                                }

                                QGCButton {
                                    text: "Login"
                                }
                            }
                        }
                    }
                }
            }
        }//QGCFlickable
    }//QGCPanel
} //QGCView