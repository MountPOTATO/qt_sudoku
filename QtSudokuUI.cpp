#include "QtSudokuUI.h"
#include <QtWidgets/qaction.h>
#include <QtWidgets/qmenu.h>
#include <QtWidgets/qmenubar.h>
#include <QtWidgets/qkeysequenceedit.h>
#include <sstream>
#include "Board.h"

QtSudokuUI::QtSudokuUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

  
    selectWindow = new SelectWindow;

    connect(selectWindow, SIGNAL(sendSudokuInitData(QString, QString, QString)),
        this, SLOT(createSudokuWithData(QString, QString, QString)));
    
	
}
QtSudokuUI::~QtSudokuUI()
{
	
}

void QtSudokuUI::on_actionClose_triggered()
{
    
    this->close();
}

void QtSudokuUI::on_actionNewGame_triggered()
{
    
    selectWindow->show();
        

}

void QtSudokuUI::createSudokuWithData(QString data1, QString data2, QString data3)
{
    //退出时报错？
	if (currentSize != 0&&boardButton)
	{
		for (int i = 0; i < currentSize; i++)
		{
			for (int j = 0; j < currentSize; j++)
			{
				delete boardButton[i][j];
				
			}
			delete boardButton[i];
			
		}
	}
	delete boardButton;


	int sudokuSize = 0;
	if (data2 == '3') { sudokuSize = 9; currentSize = 9; }
	if (data2 == '4') { sudokuSize = 16; currentSize = 16; }
	if (data2 == '5') { sudokuSize = 25; currentSize = 25; }

	if (first_used == 0)
	{
		wgBoard = new QWidget();
		glBoard = new QGridLayout(this->wgBoard);
		first_used = 1;
	}

	boardButton = new QPushButton * *[sudokuSize];
	for (int i = 0; i < sudokuSize; i++)
	{
		boardButton[i] = new QPushButton * [sudokuSize];
		for (int j = 0; j < sudokuSize; j++)
		{
			boardButton[i][j] = new QPushButton;
			boardButton[i][j]->setFont(ft1);	
			glBoard->addWidget(boardButton[i][j], i, j);
			boardButton[i][j]->setAccessibleName(QString::number(i * (sudokuSize+1) + j));
			connect(boardButton[i][j], SIGNAL(clicked()), this, SLOT(tableButtonClicked()));
			boardButton[i][j]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			boardButton[i][j]->setMinimumSize(20, 20);
			
		}
	}

	glBoard->setSpacing(0);

	glBoard->setMargin(100);
	glBoard->setVerticalSpacing(1);
	glBoard->setHorizontalSpacing(1);
	glBoard->setContentsMargins(4, 0, 4, 4);
	

	for (int i = 0; i < sudokuSize; ++i)
	{
		glBoard->setColumnStretch(i, 1);
		glBoard->setRowStretch(i, 1);
	}

	this->centralWidget()->setLayout(glBoard);
    
	 
	//色彩选择器
	int sqrtSize = static_cast<double>(sqrt(sudokuSize));
	
	for (int i = 0; i < sudokuSize; ++i)
	{
		for (int j = 0; j < sudokuSize; ++j)
		{
			int floor1 = static_cast<double>(i / sqrtSize),
				floor2 = static_cast<double>(j / sqrtSize),
				colorIndex = floor1 * sqrtSize + floor2;

			boardButton[i][j]->setStyleSheet(colorSet.at(colorIndex));
			boardButton[i][j]->setText(std::to_string(colorIndex).c_str());
			
		}
	}


}
