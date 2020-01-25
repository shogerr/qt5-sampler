#ifndef WORKSPACE_HPP
#define WORKSPACE_HPP

#include <QObject>
#include <vector>

#include "image_item.hpp"

class Workspace : public QObject
{
    Q_OBJECT
public:
    explicit Workspace(QObject* parent = nullptr);

    Q_INVOKABLE void test();
};

#endif
