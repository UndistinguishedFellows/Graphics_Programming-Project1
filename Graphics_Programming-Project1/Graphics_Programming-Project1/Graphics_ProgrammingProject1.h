#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Graphics_ProgrammingProject1.h"

class Graphics_ProgrammingProject1 : public QMainWindow
{
	Q_OBJECT

public:
	Graphics_ProgrammingProject1(QWidget *parent = Q_NULLPTR);

public slots:
	void OnAValueChanged(int value);
	void OnBValueChanged(int value);
	void OnAColor();
	void OnBColor();
	void OnSave();

private:
	Ui::Graphics_ProgrammingProject1Class ui;
};
