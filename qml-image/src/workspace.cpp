#include "workspace.hpp"

#include <QDebug>

Workspace::Workspace(QObject* parent) : QObject(parent) {
    qDebug() << "Workspace Created.";
}

void Workspace::test() {
    qDebug() << "Signal seen.";
}
