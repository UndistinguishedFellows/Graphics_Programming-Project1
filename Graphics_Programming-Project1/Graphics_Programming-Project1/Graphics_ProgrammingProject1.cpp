#include "Graphics_ProgrammingProject1.h"

Graphics_ProgrammingProject1::Graphics_ProgrammingProject1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Some initialitzations -----------


	// Connects -----------

	// Value
	connect(ui.valueASpinBox, SIGNAL(valueChanged(int)), this, SLOT(OnAValueChanged(int)));
	connect(ui.valueBSpinBox, SIGNAL(valueChanged(int)), this, SLOT(OnBValueChanged(int)));
	// Color
	connect(ui.colorABtn, SIGNAL(clicked()), this, SLOT(OnAColor()));
	connect(ui.colorBBtn, SIGNAL(clicked()), this, SLOT(OnBColor()));
	// Save
	connect(ui.saveBtn, SIGNAL(clicked()), this, SLOT(OnSave()));
}

void Graphics_ProgrammingProject1::OnAValueChanged(int value)
{

}

void Graphics_ProgrammingProject1::OnBValueChanged(int value)
{

}

void Graphics_ProgrammingProject1::OnAColor()
{

}

void Graphics_ProgrammingProject1::OnBColor()
{

}

void Graphics_ProgrammingProject1::OnSave()
{
}
