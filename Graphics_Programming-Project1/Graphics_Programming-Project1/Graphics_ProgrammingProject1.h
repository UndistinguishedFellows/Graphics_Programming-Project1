#pragma once

#include <QtWidgets/QMainWindow>
#include <QColorDialog>
#include "ui_Graphics_ProgrammingProject1.h"

class Chart;

enum BAR_USED
{
	BAR_A = 1,
	BAR_B = 2
};

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
	void OnResolutionChanged(int index);
	void OnSave();
	void OnColorSelected(const QColor& color);

private:
	Ui::Graphics_ProgrammingProject1Class ui;

	int resolutionIndex = 0;
	QPoint resolutions[3];

	Chart* chart = nullptr;
	QColorDialog* colorDialog = nullptr;

	char barUsed = (char)BAR_USED::BAR_A;
};
