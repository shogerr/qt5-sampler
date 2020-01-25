#include <QtWidgets>
#include "mainwindow.h"

MainWindow::MainWindow()
{
    CreateActions();
}

void MainWindow::CreateActions()
{
    QMenu* file_menu = menuBar()->addMenu(tr("&File"));

    const QIcon exit_icon = style()->standardIcon(QStyle::SP_TrashIcon);
    QAction* exit_action = file_menu->addAction(exit_icon, tr("E&xit"), this, &QWidget::close);
    exit_action->setShortcuts(QKeySequence::Quit);
    exit_action->setStatusTip(tr("Exit the application"));

    QMenu* help_menu = menuBar()->addMenu(tr("&Help"));
    help_menu->addAction(tr("Theme Path"), this, []() {
        qDebug() << QIcon::themeSearchPaths()
                 << QIcon::themeName() << endl;
    });
}