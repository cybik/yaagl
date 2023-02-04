//
// Created by cybik on 23-02-03.
//

#include "process.h"

#include <QProcessEnvironment>

Process::Process(const QString& program, const QString& executable, const QString& cwd,
                 const QStringList& args, const QProcessEnvironment& qpe
) {
    _proc = std::make_shared<QProcess>();

    _proc->setProgram(program);

    _proc->setWorkingDirectory(cwd);

    _arguments = std::make_shared<QStringList>(args);
    _arguments->insert(0, executable);
    _proc->setArguments(*_arguments);

    _qpe = std::make_shared<QProcessEnvironment>(qpe);
}

qint64 Process::start(qint64* pid) {
    auto _env = QProcessEnvironment::systemEnvironment();
    _env.insert(*_qpe);
    _proc->setProcessEnvironment(_env);

    _proc->startDetached(pid);
    _proc->waitForStarted();
    return *pid;
}

std::shared_ptr<QProcess> Process::get() {
    return _proc;
}
#if defined(_DEBUG)
std::shared_ptr<QProcessEnvironment> Process::getQPE() {
    return _qpe;
}
#endif
