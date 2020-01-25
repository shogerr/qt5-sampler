#include <QDir>
#include <QDebug>
#include <QGuiApplication>
#include <QImageReader>
#include <QMessageBox>
#include <QPixmap>

#include "main_window.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , image_label_(std::make_unique<QLabel>())
    , scroll_area_(std::make_unique<QScrollArea>())
{
    qDebug() << "Visiting constructor.";

    image_label_.get()->setBackgroundRole(QPalette::Base);
    image_label_.get()->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    image_label_.get()->setScaledContents(true);

    scroll_area_.get()->setBackgroundRole(QPalette::Dark);
    scroll_area_.get()->setWidget(image_label_.get());
    scroll_area_.get()->setVisible(true);

    setCentralWidget(scroll_area_.get());

    const QString filename = "uv-grid-color.png";
    QImageReader reader(filename);

    image_ = reader.read();

    if (image_.isNull())
    {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(filename), reader.errorString()));
    }

    image_label_.get()->setPixmap(QPixmap::fromImage(image_));
    image_label_.get()->resize(1.0f * image_label_.get()->pixmap()->size());
    resize(image_label_.get()->size());
}