#include "signup.h"
#include "ui_signup.h"

Signup::Signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    QMovie *movie = new QMovie(this);
    movie->setFileName(":/Image/1.gif");
    movie->start();
    ui->labTop->setMovie(movie);

    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(20);
    ui->labTop->setGraphicsEffect(blur);
}

Signup::~Signup()
{
    delete ui;
}

void Signup::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton && e->pos().y() <= geometry().height()/10)
    {
        clickPos = e->pos();
    }
}

void Signup::mouseMoveEvent(QMouseEvent *e)
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

void Signup::on_xButton_clicked()
{
    this->close();
}


void Signup::on_minButton_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}


//void Signup::on_backButton_clicked()
//{
//    this->parentWidget()->show();
//    delete this;
//}


void Signup::on_confirmButton_clicked()
{
    this->parentWidget()->show();
    delete this;
}

