#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QScrollArea>

#include <memory>

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = nullptr);
private:
    QImage image_;
    std::unique_ptr<QLabel> image_label_;
    std::unique_ptr<QScrollArea> scroll_area_;
};

#endif