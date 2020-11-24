#ifndef __QTSUDOKUUI_H__
#define __QTSUDOKUUI_H__

#include <QtWidgets/QMainWindow>
#include <qgridlayout.h>
#include "ui_QtSudokuUI.h"
#include "SelectWindow.h"
#include <vector>
#include "colorVector.h"

class QtSudokuUI : public QMainWindow
{
    Q_OBJECT

public:
    QtSudokuUI(QWidget *parent = Q_NULLPTR);
    ~QtSudokuUI();

private:
    Ui::QtSudokuUIClass ui;
    
    SelectWindow* selectWindow;

    QWidget* wgBoard;

    QGridLayout* glBoard;

    QPushButton*** boardButton;

    int currentSize = 0;
    bool first_used = 0;
public slots:
    void on_actionNewGame_triggered();
    //void on_actionRestartGame_triggered();
    void on_actionClose_triggered();
   
private slots:
    void createSudokuWithData(QString, QString, QString);




};


#endif //__QTSUDOKUUI_H__