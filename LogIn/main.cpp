#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    QFont font("family");
    QApplication::setFont(font);
    w.show();
    return a.exec();
}
