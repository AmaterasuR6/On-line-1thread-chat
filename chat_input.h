#pragma once

#include "header.h"

class ChatInput :
    public QTextEdit
{
    Q_OBJECT
public:
    ChatInput(QWidget*);
    QString getMessage();
signals:
    void messageSent();
private:
    void keyPressEvent(QKeyEvent*);
    QString messageToSend;
};

