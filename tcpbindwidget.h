#ifndef TCPBINDWIDGET_H
#define TCPBINDWIDGET_H

#include <QWidget>

namespace Ui {
class tcpbindwidget;
}

class tcpbindwidget : public QWidget
{
    Q_OBJECT

public:
    explicit tcpbindwidget(QWidget *parent = 0);
    ~tcpbindwidget();
    int getPort();
private slots:
    void on_sureBt_clicked();

    void on_cancelBt_clicked();

    void show_close();
protected:
    void closeEvent(QCloseEvent *event);
private:
    Ui::tcpbindwidget *ui;
    int port;

signals:
    void widgetClose();
};

#endif // TCPBINDWIDGET_H
