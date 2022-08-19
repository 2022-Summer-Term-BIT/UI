#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include "header.h"

namespace Ui {
class Signup;
}

class Signup : public QWidget
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

protected:
    void mousePressEvent(QMouseEvent *);

    void mouseMoveEvent(QMouseEvent *);

private slots:
    void on_xButton_clicked();

    void on_minButton_clicked();

//    void on_backButton_clicked();

    void on_confirmButton_clicked();

private:
    Ui::Signup *ui;
    QPoint clickPos;
};

#endif // SIGNUP_H
