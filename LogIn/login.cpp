#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    QMovie *movie = new QMovie(this);
    movie->setFileName(":/Image/1.gif");
    movie->start();
    ui->labTop->setMovie(movie);

    ui->accountPix->hide();
    ui->userBox->hide();
    ui->pwdPix->hide();
    ui->pwdEdit->hide();
    ui->autoButton->hide();
    ui->saveButton->hide();
    ui->keyboardButton->hide();
    ui->findButton->hide();
    ui->signButton->hide();
    ui->QRcodeButton->hide();
    ui->loginButton->hide();

    QTimer::singleShot(2000, this, [&]()
    {
        QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
        blur->setBlurRadius(20);
        ui->labTop->setGraphicsEffect(blur);
        ui->accountPix->show();
        ui->userBox->show();
        ui->pwdPix->show();
        ui->pwdEdit->show();
        ui->autoButton->show();
        ui->saveButton->show();
        ui->keyboardButton->show();
        ui->findButton->show();
        ui->signButton->show();
        ui->QRcodeButton->show();
        ui->loginButton->show();
    });
    ui->pwdEdit->setEchoMode(QLineEdit::Password);
    ui->userBox->lineEdit()->setPlaceholderText("Username");

}

Login::~Login()
{
    delete ui;
}

void Login::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton && e->pos().y() <= geometry().height()/10)
    {
        clickPos = e->pos();
    }
}

void Login::mouseMoveEvent(QMouseEvent *e)
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

void Login::on_xButton_clicked()
{
    this->close();
}


void Login::on_minButton_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}

void Login::on_QRcodeButton_clicked()
{
    QRDialog *qrd = new QRDialog;
    qrd->show();
}


void Login::on_signButton_clicked()
{
//    this->hide();
    sign->show();
}

