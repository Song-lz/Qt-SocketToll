#include "widget.h"
#include "ui_widget.h"
#include <QThread>
#include <QDebug>
#include <QTcpServer>
#include <QNetworkInterface>
#include "tcpbindwidget.h"
#include <QThread>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //添加顶层节点
    ui->socketTypeTw->header()->hide();

    treeTCPServer = new QTreeWidgetItem(ui->socketTypeTw);
    treeTCPServer->setText(0,"TCP Server");
    ui->socketTypeTw->addTopLevelItem(treeTCPServer);

    treeTCPClient = new QTreeWidgetItem(ui->socketTypeTw);
    treeTCPClient->setText(0,"TCP Client");
    ui->socketTypeTw->addTopLevelItem(treeTCPClient);

    treeUDPServer = new QTreeWidgetItem(ui->socketTypeTw);
    treeUDPServer->setText(0,"UDP Server");
    ui->socketTypeTw->addTopLevelItem(treeUDPServer);


    treeUDPClient = new QTreeWidgetItem(ui->socketTypeTw);
    treeUDPClient->setText(0,"UDP Client");
    ui->socketTypeTw->addTopLevelItem(treeUDPClient);

    treeUDPGroup = new QTreeWidgetItem(ui->socketTypeTw);
    treeUDPGroup->setText(0,"UDP Group");
    ui->socketTypeTw->addTopLevelItem(treeUDPGroup);
    tcpCreateWidget = new tcpbindwidget;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_createBt_clicked()
{

    if(ui->socketTypeTw->currentItem()->isSelected()){
        qDebug()<< ui->socketTypeTw->currentItem()->text(0);
        if(ui->socketTypeTw->currentItem()->text(0) == "TCP Server"){

            connect(tcpCreateWidget, SIGNAL(widgetClose()), this, SLOT(on_tcpCreateWidget_close()));
            tcpCreateWidget->show();
        }
    }
}

void Widget::on_tcpCreateWidget_close(){
    qDebug()<< "child show close";
    qDebug()<< tcpCreateWidget->getPort();
    if(tcpCreateWidget->getPort() != -1){
        QTcpServer *tcpServer = new QTcpServer;
        if(tcpServer->listen(QHostAddress::AnyIPv4, tcpCreateWidget->getPort()) == true){
            qDebug()<<QString::number(tcpServer->serverPort());
            ui->locatPortLa->setText(QString::number(tcpServer->serverPort()));
            QTreeWidgetItem *itemD = new QTreeWidgetItem;
            QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
            // use the first non-localhost IPv4 address
            QString ipAddress;
            for (int i = 0; i < ipAddressesList.size(); ++i) {
                qDebug()<<ipAddressesList.at(i);
                if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                    ipAddressesList.at(i).toIPv4Address()) {
                    ipAddress = ipAddressesList.at(i).toString();
                    break;
                }
            }
            if (ipAddress.isEmpty())
                ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
            ui->locaIpLa->setText(ipAddress);
            itemD->setText(0,ipAddress);
            ui->socketTypeTw->currentItem()->addChild(itemD);//插入在根节点下面
        }
        //ui->locatPortLa->setText(QString::number(tcpServer->serverPort()));
    }
    //delete tcpCreateWidget;
}

void Widget::on_socketTypeTw_itemClicked(QTreeWidgetItem *item, int column)
{
    if(item->parent())
    qDebug()<<"itemClicked " << item->text(column);
    qDebug()<<"column " << column;
}
