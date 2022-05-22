#pragma once

#include "header.h"

class NameAsker :
    public QDialog
{
    Q_OBJECT
public:
    NameAsker(QWidget*);
    QString getName();
signals:
    void nameSent();
private:
    QLineEdit* nameField = new QLineEdit(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
};

