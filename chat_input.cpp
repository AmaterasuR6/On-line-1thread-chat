#include "chat_input.h"

ChatInput::ChatInput(QWidget* parent)
{
	setParent(parent);
	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
	setFixedHeight(88);
}

void ChatInput::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == 16777220) 
	{
		messageToSend = toPlainText();
		clear();
		emit messageSent();
		return;
	}
	return QTextEdit::keyPressEvent(e);
}

QString ChatInput::getMessage()
{
	return messageToSend;
}
