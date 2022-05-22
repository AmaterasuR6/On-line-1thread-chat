#ifndef CHAT_SECTION_H
#define CHAT_SECTION_H
#include "mainwindow.h"


class chat_section: public QFrame
{
    Q_OBJECT
public:
    chat_section(QWidget*=Q_NULLPTR);
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

#endif // CHAT_SECTION_H
