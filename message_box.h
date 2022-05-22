#pragma once

#include "header.h"

class MessageBox :
    public QFrame
{
public:
    MessageBox(QString, QString, QWidget*);
private:
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
};

