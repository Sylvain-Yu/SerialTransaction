#include "transaction.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Transaction w;
    w.show();
    return a.exec();
}
