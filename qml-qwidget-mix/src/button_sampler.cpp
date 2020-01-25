#include "button_sampler.h"

#include <QHBoxLayout>
#include <QDebug>
#include <QTextStream>
#include <QProgressBar>


#include <iostream>
#include <stdio.h>
#include <string>

ButtonSampler::ButtonSampler(QWidget* parent) :
    QWidget(parent),
	mainwindow_(new MainWindow),
	form_(new Form),
	barpanel_(new BarPanel)
{
    button_group_ = new QButtonGroup(this);

    QHBoxLayout* layout = new QHBoxLayout;

    for (int i = 0; i < 10; i++)
    {
        buttons_.push_back(new QPushButton(tr("%1").arg(i), this));

        connect(buttons_.back(), &QPushButton::clicked, this, [this, i]() { HandleButton(i); });

        layout->addWidget(buttons_.back());
    }

    setLayout(layout);

	//connect(form_, &Form::verticalSlider::valueChanged(int), barpanel_, &QProgressBar::setValue(int));
}

// Try printing 11 ways from the sun.
void ButtonSampler::HandleButton(int i)
{
    qInfo() << i;
    switch (i)
    {
    case 0:
        mainwindow_->show();
        break;
    case 1:
        OutputTest();
        break;
    case 2:
        form_->show();
		break;
	case 3:
		barpanel_->show();
		break;
    }
}

void ButtonSampler::OutputTest()
{
    std::string msg = "This is my message";

    std::cout << "Cout test." << std::endl;

    printf("Printf test.\n");

    FILE* f;
    errno_t err = fopen_s(&f, "output.log", "a");
    fprintf(f, "%s\n", msg.c_str());
    fclose(f);

    qDebug() << "qDebug() test.";
    qInfo() << "qInfo() test.";

    QTextStream out(stdout, QIODevice::WriteOnly);
    out << "QTextStream test.\n";
    out.flush();

    QMessageLogger().debug() << "QMessageLogger.debug() test.";
}