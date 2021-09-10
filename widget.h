#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeWidget>
#include <QTcpSocket>
#include <QUdpSocket>
#include "tcpbindwidget.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_createBt_clicked();

    void on_socketTypeTw_itemClicked(QTreeWidgetItem *item, int column);
    void on_tcpCreateWidget_close();
private:
    //QTcpSocket *TCPServer;
    //QTcpSocket *TCPClient;
    //QUdpSocket *UDPServer;
    //QUdpSocket *UDPClient;
    //QUdpSocket *UDPGroup;

    QTreeWidgetItem *treeTCPServer;
    QTreeWidgetItem *treeTCPClient;
    QTreeWidgetItem *treeUDPServer;
    QTreeWidgetItem *treeUDPClient;
    QTreeWidgetItem *treeUDPGroup;
    tcpbindwidget *tcpCreateWidget;
    Ui::Widget *ui;
};

#endif // WIDGET_H
