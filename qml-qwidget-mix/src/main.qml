import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import com.usnr.qtsampler.quickpanel 1.0

Window {
    id: root
    width: 300
    height: 480
    visible: true

    QuickPanel {
        id: quickpanel
    }

    TextField {
        text: quickpanel.value
    }
    Window {
        id: first
        width: 400
        height: 200
        visible: true
    }
}
