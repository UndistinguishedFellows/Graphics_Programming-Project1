#include "Graphics_ProgrammingProject1.h"
#include "Chart.h"

#include <QFileDialog>
#include <iostream>

#define BACKGROUND_COLOR_STYLE_SHEET QString("background-color:")

Graphics_ProgrammingProject1::Graphics_ProgrammingProject1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Some initialitzations -----------

	// Actually creating the chart
	chart = new Chart(ui.frame);
	chart->show();

	// Create the color dialog
	colorDialog = new QColorDialog(this);

	// Set both color buttons style
	ui.colorABtn->setStyleSheet(BACKGROUND_COLOR_STYLE_SHEET + chart->aColor.name());
	ui.colorABtn->setStyleSheet(BACKGROUND_COLOR_STYLE_SHEET + chart->bColor.name());

	// Setting resolutions
	resolutions[0] = QPoint(640, 480);
	resolutions[1] = QPoint(800, 600);
	resolutions[2] = QPoint(1024, 760);

	// Fill the combobox --------------
	for(int i = 0; i < 3; ++i)
	{
		QString text;
		text.append(std::to_string(resolutions[i].x()).c_str());
		text.append("x");
		text.append(std::to_string(resolutions[i].y()).c_str());
		ui.resolutionCombo->addItem(text);
	}

	// Connects -----------

	// Value
	connect(ui.valueASpinBox, SIGNAL(valueChanged(int)), this, SLOT(OnAValueChanged(int)));
	connect(ui.valueBSpinBox, SIGNAL(valueChanged(int)), this, SLOT(OnBValueChanged(int)));
	// Color
	connect(ui.colorABtn, SIGNAL(clicked()), this, SLOT(OnAColor()));
	connect(ui.colorBBtn, SIGNAL(clicked()), this, SLOT(OnBColor()));
	// Resolution
	connect(ui.resolutionCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(OnResolutionChanged(int)));
	// Save
	connect(ui.saveBtn, SIGNAL(clicked()), this, SLOT(OnSave()));
	// Color picker
	connect(colorDialog, SIGNAL(colorSelected(const QColor&)), this, SLOT(OnColorSelected(const QColor&)));
}

void Graphics_ProgrammingProject1::OnAValueChanged(int value)
{
	std::cout << "A value changed: " << value << std::endl;
	chart->SetAValue(value);
}

void Graphics_ProgrammingProject1::OnBValueChanged(int value)
{
	std::cout << "B value changed: " << value << std::endl; 
	chart->SetBValue(value);
}

void Graphics_ProgrammingProject1::OnAColor()
{
	std::cout << "A color changed" << std::endl;

	barUsed = (char)BAR_USED::BAR_A;
	colorDialog->setCurrentColor(chart->aColor);
	colorDialog->show();
}

void Graphics_ProgrammingProject1::OnBColor()
{
	std::cout << "B color changed" << std::endl;

	barUsed = (char)BAR_USED::BAR_B;
	colorDialog->setCurrentColor(chart->bColor);
	colorDialog->show();
}

void Graphics_ProgrammingProject1::OnResolutionChanged(int index)
{
	if(index >= 0 && index < 3)
	{
		resolutionIndex = index;
		//std::cout << "Res index: " << index << std::endl;
	}
}

void Graphics_ProgrammingProject1::OnSave()
{
	// Get the file path
	QString path = QFileDialog::getSaveFileName(this, tr("Save chart"), tr("chart.png"), tr("PNG(*.png);;JPG(*.jpg)"));
	
	// Get the resolution and save the chart scaled
	QPoint res = resolutions[resolutionIndex];
	ui.frame->grab().scaled(res.x(), res.y()).save(path);
}

void Graphics_ProgrammingProject1::OnColorSelected(const QColor& color)
{
	if(barUsed & BAR_USED::BAR_A)
	{
		ui.colorABtn->setStyleSheet(BACKGROUND_COLOR_STYLE_SHEET + color.name());
		chart->SetAColor(color);
	}
	if(barUsed & BAR_USED::BAR_B)
	{
		ui.colorBBtn->setStyleSheet(BACKGROUND_COLOR_STYLE_SHEET + color.name());
		chart->SetBColor(color);
	}
}
