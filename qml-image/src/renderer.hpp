#ifndef RENDERER_HPP
#define RENDERER

#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QQuickWindow>
#include <memory>

class Renderer : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    Renderer() : program_(nullptr) {}
    ~Renderer();
    void setViewportSize(const QSize &size) { viewport_size_ = size; }
    void setWindow(QQuickWindow *window) { window_.reset(window); }

    public slots:
        void init();
        void paint();

private:
    std::unique_ptr<QOpenGLShaderProgram> program_;
    QSize viewport_size_;
    std::unique_ptr<QQuickWindow> window_;
};

#endif