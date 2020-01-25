#ifndef QUICKPANEL_H
#define QUICKPANEL_H

#include <QObject>

class QuickPanel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ Value NOTIFY ValueChanged)
public:
    explicit QuickPanel(QObject* parent = nullptr);

    int Value() { return value_; }
signals:
    void ValueChanged();
private:
    int value_;
};

#endif // !QUICKPANEL_H