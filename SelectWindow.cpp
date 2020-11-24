#include "SelectWindow.h"

SelectWindow::SelectWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

SelectWindow::~SelectWindow()
{
	
}


void SelectWindow::on_pushButtonGenerate_clicked()
{
	QString mode = ui.comboBoxMode->currentText();
	QString gridSize = ui.comboBoxGridSize->currentText();
	QString needHint = ui.comboBoxHint->currentText();

	emit sendSudokuInitData(mode, gridSize, needHint);
	
		
	this->hide();
}