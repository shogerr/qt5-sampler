#ifndef BARPANEL_H
#define BARPANEL_H

#include <QWidget>

namespace Ui
{
	class BarPanel;
}

class BarPanel : public QWidget
{
	Q_OBJECT
public:
	explicit BarPanel(QWidget* parent = nullptr);
	~BarPanel();
private:
	Ui::BarPanel* ui_;
};

#endif // !BARWINDOW_H


