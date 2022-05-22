#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket=new QTcpSocket(this);
    connect(socket,&QTcpSocket::readyRead,this,&MainWindow::slotReadyRead);
    connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);
    nextBlockSize=0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    socket->connectToHost(ui->IPAdress->text(),ui->Port->text().toInt());
}

void MainWindow::SendToServer(QString str)
{
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);
    out<<quint16(0)<<QTime::currentTime()<<name<<str;
    out.device()->seek(0);
    out<<quint16(Data.size()-sizeof(quint16));
    socket->write(Data);
    ui->lineEdit->clear();
}

void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_12);
    if(in.status()==QDataStream::Ok)
    {
        /*QString str;
        in>>str;
        ui->textBrowser->append(str);*/
        for(;;)
        {
            if (nextBlockSize==0)
            {
                if(socket->bytesAvailable()<2)
                {
                    break;
                }
                in>>nextBlockSize;
            }
            if(socket->bytesAvailable()<nextBlockSize)
            {
                break;
            }
            QString str;
            QString nameSender;
            QTime time;
            in>>time>>nameSender>>str;
            nextBlockSize=0;
            ui->textBrowser->append(nameSender+"\n"+time.toString()+" "+str);
        }
    }
    else
    {
        ui->textBrowser->append("read error");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    SendToServer(ui->lineEdit->text());
}

void MainWindow::on_lineEdit_returnPressed()
{
      SendToServer(ui->lineEdit->text());
}
void MainWindow::changeName(QString s)
{
    name.clear();
    name=s;
}

void MainWindow::on_nicknamechange_clicked()
{
    changeName(ui->nicknamechanger->text());
}
