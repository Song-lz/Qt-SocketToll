#include "tcpbindwidget.h"
#include "ui_tcpbindwidget.h"
#include <QApplication>
#include <QDebug>
tcpbindwidget::tcpbindwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tcpbindwidget)
{
    ui->setupUi(this);
    this->setWindowTitle("创建tcp server");
    bool ret = connect(this, SIGNAL(widgetClose()), this, SLOT(show_close()));
    qDebug()<<ret;
}

tcpbindwidget::~tcpbindwidget()
{
    delete ui;
}
int tcpbindwidget::getPort()
{
    return port;
}

void tcpbindwidget::on_sureBt_clicked()
{
    port = ui->portEdit->text().toInt();
    emit widgetClose();
    this->close();
}

void tcpbindwidget::on_cancelBt_clicked()
{
    emit widgetClose();
    this->close();
    port = -1;
}

void tcpbindwidget::show_close()
{
    qDebug()<< "show close";
}


void tcpbindwidget::closeEvent ( QCloseEvent * e )
{
    //qDebug()<< "child show close";
    //emit widgetClose();
}
