#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H
#include "mainwindow.h"

class MessageBox: public QFrame
{
public:
    MessageBox(QString, QString, QWidget*);
private:
   QVBoxLayout* mainLayout = new QVBoxLayout(this);
};

#endif // MESSAGEBOX_H
