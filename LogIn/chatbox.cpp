#include "chatbox.h"
#include "ui_chatbox.h"

Chatbox::Chatbox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chatbox)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    widget_1 = ui->chatList;
//    widget_1->addItem("chatPage");

    widget_2 = ui->contactList;
//    widget_2->addItem("contactPage");

//    ui->stackedWidget->addWidget(widget_1);
//    ui->stackedWidget->addWidget(widget_2);

    ui->stackedWidget->setCurrentWidget(widget_1);

    connect(ui->chatList, &QListWidget::itemClicked, this, &Chatbox::showChatWith);
}

Chatbox::~Chatbox()
{
    delete ui;
}

void Chatbox::on_currentChat_clicked()
{
    if(ui->stackedWidget->currentWidget() != ui->chatPage)
    {
        ui->stackedWidget->setCurrentWidget(ui->chatPage);
    }
}


void Chatbox::on_contacts_clicked()
{
    if(ui->stackedWidget->currentWidget() != ui->contactPage)
    {
        ui->stackedWidget->setCurrentWidget(ui->contactPage);
    }
}

void Chatbox::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton && e->pos().y() <= geometry().height()/10)
    {
        clickPos = e->pos();
    }
}

void Chatbox::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() == Qt::LeftButton
            && e->pos().x() >= 0
            && e->pos().y() >= 0
            && e->pos().x() <= geometry().width()
            && e->pos().y() <= geometry().height()/10)
    {
        move(e->pos() + pos() - clickPos);
    }
}


#if 0
在listWidget中创建自定义item
CItemWidget* pItemWidget = new CItemWidget(this)；
QListWidgetItem* pItem = new QListWidgetItem();
pItem->setSizeHint(QSize(350, 40));
ui->listWidget->addItem(pItem);
ui->listWidget->setItemWidget(pItem, pItemWidget);

//有两种方法在ListWidget中添加item
//一种在构造item的时候，指定其父Widget
QListWidgetItem *cubby_item = new QListWidgetItem(QIcon(":/res/pix/cubby.png"),
                                                  tr("Cubby"),list_widget);
//第二种方法是在构造完item后，使用QListWidget::additem()来添加item
QListWidgetItem *dropbox_item = new QListWidgetItem();
dropbox_item->setIcon(QIcon(":/res/pix/dropbox.png"));
dropbox_item->setText(tr("Dropbox"));
list_widget->addItem(dropbox_item);


//向QListWidget中指定的位置插入itemm，使用QListWidget::addItem()
QListWidgetItem *google_item = new QListWidgetItem(QIcon(":/res/pix/google.png"),
                                                     tr("Google"));
list_widget->insertItem(1,google_item);


//使用QListWidget::takeItem(int index)来删除表中的某一项
//list_widget->takeItem(0);

//删除item，必须要加上delete item，否则删不掉
//list_widget->removeItemWidget(add_item);
//delete add_item;

#endif


void Chatbox::on_xButton_clicked()
{
    this->close();
}


void Chatbox::on_minButton_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}

void Chatbox::showChatWith(QListWidgetItem *item)
{
    ui->chatWith->setText(item->text());
}
