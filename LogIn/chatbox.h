#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>
#include "header.h"

class QStackedWidget;
class QPushButton;
namespace Ui {
class Chatbox;
}

class Chatbox : public QWidget
{
    Q_OBJECT

public:
    explicit Chatbox(QWidget *parent = nullptr);
    ~Chatbox();

protected:
    void mousePressEvent(QMouseEvent *);

    void mouseMoveEvent(QMouseEvent *);

private slots:
    void on_currentChat_clicked();

    void on_contacts_clicked();

    void on_xButton_clicked();

    void on_minButton_clicked();

    void showChatWith(QListWidgetItem *);

private:
    Ui::Chatbox *ui;
    QListWidget *widget_1;
    QListWidget *widget_2;
    QPoint clickPos;
};

#endif // CHATBOX_H
