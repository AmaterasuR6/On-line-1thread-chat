#include "chat_section.h"

ChatSection::ChatSection(QWidget* parent)
{
	setParent(parent);
	setMinimumWidth(500);
	setMinimumHeight(500);
	QPalette* pal = new QPalette();
	pal->setColor(QPalette::Window, Qt::white);
	setAutoFillBackground(true);
	setPalette(*pal);
	delete pal;
	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
	setLayout(mainLayout);
	mainLayout->setAlignment(Qt::AlignTop);
	mainLayout->addWidget(chatOutput);
	chatOutput->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
	mainLayout->addWidget(chatInput);
	QObject::connect(chatInput, &ChatInput::messageSent, this, &ChatSection::receiveMessage);
	//
	chatOutputWidget->setLayout(chatOutputLayout);
	chatOutputLayout->setAlignment(Qt::AlignTop);
	chatOutputLayout->setSpacing(0);
	chatOutput->setWidget(chatOutputWidget);
	chatOutput->setWidgetResizable(true);
	//
	QObject::connect(nameAsking, &NameAsker::nameSent, this, &ChatSection::acceptName);
	nameAsking->show();
}

void ChatSection::addMessage(MessageBox* message)
{
	messages.push_back(message);
	chatOutputLayout->insertWidget(0, messages[messages.size() - 1]);
}

void ChatSection::receiveMessage()
{
	addMessage(new MessageBox(name, chatInput->getMessage(), this)); // пример добавления в рамках клиента, не добавляй
	/*
	тут получаешь сообщение chatInput->getMessage(), отправляешь его на сервер с именем name (переменная QString член класса)
	далее сервер рассылает всем клиентам сообщение, добавляешь его методом addMessage (см. выше)
	*/
}

void ChatSection::acceptName()
{
	name = nameAsking->getName();
}