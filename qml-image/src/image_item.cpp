#include "image_item.hpp"
#include <QDir>

ImageItem::ImageItem(QQuickItem* parent) : QQuickPaintedItem(parent)
{
    qDebug() << "ImageItem created.";

    content_ = QImage(":/images/assets/uv-grid-color.png");
    resizeContainer();
    update();
}

void ImageItem::paint(QPainter* painter)
{
    qDebug() << "In Lienzo->paint()";
    qDebug() << "content width: " << content_.width();

    painter->drawImage(QRectF{ 0.,0.,
                               static_cast<double>(content_.width()),
                               static_cast<double>(content_.height()) }
                       , content_);
}

void ImageItem::openImage(const QUrl path)
{
    qDebug() << "Current dir is:" << QDir::currentPath();
    qDebug() << "Opening path: " << path;

    content_.load(path.toLocalFile());
    resizeContainer();
    update();
}

void ImageItem::resizeContainer()
{
    setProperty("width", content_.width());
    setProperty("height", content_.height());
}