#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "header.h"
#include "qrdialog.h"
#include "signup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

protected:
    void mousePressEvent(QMouseEvent *);

    void mouseMoveEvent(QMouseEvent *);

private slots:
    void on_xButton_clicked();

    void on_minButton_clicked();

    void on_QRcodeButton_clicked();

    void on_signButton_clicked();

private:
    Ui::Login *ui;
    QPoint clickPos;
    Signup *sign = new Signup;
};
#endif // LOGIN_H
