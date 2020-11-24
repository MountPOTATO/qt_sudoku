#ifndef __SELECTWINDOW_H__
#define __SELECTWINDOW_H__

#include <QWidget>

#include "ui_SelectWindow.h"

class SelectWindow : public QWidget
{
	Q_OBJECT

public:
	SelectWindow(QWidget *parent = Q_NULLPTR);
	~SelectWindow();


private:
	Ui::SelectWindow ui;


public slots:
	void on_pushButtonGenerate_clicked();


signals:
	void sendSudokuInitData(QString data1, QString data2, QString data3);
};


#endif //__SELECTWINDOW_H__