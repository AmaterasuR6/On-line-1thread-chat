#include "messagebox.h"

MessageBox::MessageBox(QString userName, QString message, QWidget* parent)
{
    setParent(parent);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    setLayout(mainLayout);
    mainLayout->setAlignment(Qt::AlignVCenter);
    QLabel* userNameLabel = new QLabel(userName, this);
    QFont font = userNameLabel->font();
    font.setBold(true);
    userNameLabel->setFont(font);
    mainLayout->addWidget(userNameLabel);
    QHBoxLayout* messageLayout = new QHBoxLayout(this);
    for (int i = 0; i < message.length(); ++i)
    {
        if (message[i] == '\n')
        {
            message[i] == ' ';
        }
    }
    QTextEdit* messageLabel = new QTextEdit(message, this);
    messageLabel->setReadOnly(true);
    messageLabel->setFrameStyle(QFrame::NoFrame);
    messageLabel->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    messageLabel->setFixedHeight(13 * (message.length() / 70) + 22);
    messageLabel->setAcceptRichText(true);
    messageLayout->addWidget(messageLabel);
    mainLayout->addLayout(messageLayout);
}
