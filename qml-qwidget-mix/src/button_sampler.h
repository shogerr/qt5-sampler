#ifndef BUTTON_SAMPLER_H
#define BUTTON_SAMPLER_H

#include <QButtonGroup>
#include <QPushBUtton>
#include <QWidget>

#include "mainwindow.h"
#include "barpanel.h"
#include "form.h"

#include <vector>


class ButtonSampler : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonSampler(QWidget* parent = nullptr);

private slots:
    void HandleButton(int i);
    void OutputTest();

private:
    QButtonGroup* button_group_;
    std::vector<QPushButton*> buttons_;
    MainWindow* mainwindow_;
    Form* form_;
	BarPanel* barpanel_;
};

#endif