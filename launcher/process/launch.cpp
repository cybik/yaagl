//
// Created by cybik on 23-02-03.
//

#include "launch.h"

#if defined(_DEBUG)
#include <QMessageBox>
#endif

const QString _genpath = "/Depot/Games/Genshin/Game/drive_c/Program Files/Genshin Impact";
const QString _winepath = "/home/cybik/.steam/root/compatibilitytools.d/proton-latest/files/bin/wine";
const QString _executable = "GenshinImpact.exe";
const QString _winepfx = "/Depot/Games/Genshin/GameTrash2";

std::shared_ptr<Launch> Launch::_launch(nullptr);

std::shared_ptr<Launch> Launch::getLaunch() {
    if(_launch == nullptr) {
        _launch.reset(new Launch());
    }
    return _launch;
}

Launch::Launch() {
    auto qpe = QProcessEnvironment();
    qpe.insert("WINEPREFIX", _winepfx);

    _process = std::make_unique<Process>(_winepath, _executable, _genpath, QStringList(), qpe);
}

std::shared_ptr<Launch> Launch::LaunchIt(qint64* pid) {
#if defined(_DEBUG)
    QString _text = "Program being run\n\n";
    _text += (" * Program:\n  " + _process->get()->program() + "\n");
    _text += (" * cwd:\n  " + _process->get()->workingDirectory() + "\n");
    if(!_process->get()->arguments().empty()) {
        _text += (" * Arguments:\n");
        for(const auto& _argument:_process->get()->arguments()) {
            _text += ("  * Arg: " + _argument + "\r\n");
        }
    }
    if(!_process->getQPE()->isEmpty()) {
        _text += (" * Env:\n");
        for(const auto& _key:_process->getQPE()->keys()) {
            _text += ("  * " +_key + ": " + _process->getQPE()->value(_key) + "\r\n");
        }
    }
    QMessageBox * msg = new QMessageBox();
    msg->setWindowTitle("Launch Process");
    msg->setText(_text);
    msg->setTextFormat(Qt::TextFormat::PlainText);
    msg->standardButtons();
    msg->show();
#endif
    _process->start(pid);
    return getLaunch();
}
