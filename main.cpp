#include "bookinput.h"

#include <QDir>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bookInput w;
    w.show();
    return a.exec();
}

