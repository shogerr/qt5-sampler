#include "barpanel.h"
#include "ui_barpanel.h"

BarPanel::BarPanel(QWidget* parent) : QWidget(parent), ui_(new Ui::BarPanel)
{
	ui_->setupUi(this);
	ui_->verticalSlider->setValue(20);
	ui_->progressBar->setValue(ui_->verticalSlider->value());
	connect(ui_->verticalSlider, &QSlider::valueChanged, ui_->progressBar, &QProgressBar::setValue);
}

BarPanel::~BarPanel()
{
	delete ui_;
}
