#include "QtSudokuUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtSudokuUI w;
    w.show();
    return a.exec();
}
