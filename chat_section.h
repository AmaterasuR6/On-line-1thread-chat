#pragma once

#include "header.h"
#include "message_box.h"
#include "chat_input.h"
#include "name_asker.h"

class ChatSection :
    public QFrame
{
    Q_OBJECT
public:
    ChatSection(QWidget* = Q_NULLPTR);
    void addMessage(MessageBox*);
private:
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QScrollArea* chatOutput = new QScrollArea(this);
    QWidget* chatOutputWidget = new QWidget(this);
    QVBoxLayout* chatOutputLayout = new QVBoxLayout(this);
    ChatInput* chatInput = new ChatInput(this);
    NameAsker* nameAsking = new NameAsker(this);
    vector <MessageBox*> messages;
    void receiveMessage();
    QString name = "Unknown";
    void acceptName();
};

