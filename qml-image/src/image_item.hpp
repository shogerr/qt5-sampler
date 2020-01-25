#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QImage>
#include <QObject>
#include <QPainter>
#include <QQuickPaintedItem>
#include <QQuickItem>

#include <filesystem>

class ImageItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ image NOTIFY imageChanged)
public:
    ImageItem(QQuickItem *parent = nullptr);

    QImage image() const { return content_; }

    Q_INVOKABLE void openImage(const QUrl path);
    void paint(QPainter *painter);
signals:
    void imageChanged();
private:
    QImage content_;

    void resizeContainer();
};
#endif
