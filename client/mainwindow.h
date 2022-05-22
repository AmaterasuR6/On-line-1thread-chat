#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTime>
#include <QWidget>
#include <QLayout>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTabWidget>
#include <QScrollArea>
#include <QFrame>
#include <QString>
#include <QEvent>
#include <QFont>
#include <QTextEdit>
#include <QSpacerItem>
#include <QSize>
#include <string>
#include <vector>
#include <tuple>
#include <QKeyEvent>
#include <QScrollBar>
#include <QDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

    void on_nicknamechange_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QByteArray Data;
    void SendToServer(QString str);
    quint16 nextBlockSize;
    QString name="unknown";
    void changeName(QString s);
public slots:
    void slotReadyRead();

};


#endif // MAINWINDOW_H
