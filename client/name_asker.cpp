#include "name_asker.h"

NameAsker::NameAsker(QWidget* parent)
{
    setParent(parent);
    setModal(true);
    setWindowTitle("Authorization");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    QObject::connect(nameField, &QLineEdit::returnPressed, this, &NameAsker::nameSent);
    QObject::connect(nameField, &QLineEdit::returnPressed, this, &QWidget::close);
    setLayout(mainLayout);
    mainLayout->addWidget(new QLabel("Enter your name:", this));
    mainLayout->addWidget(nameField);
}
QString NameAsker::getName()
{
    return nameField->text();
}
