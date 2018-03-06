#pragma once

#include <QWidget>

class Chart : public QWidget
{
	Q_OBJECT

public:
	Chart(QWidget *parent);
	~Chart();

	void SetAColor(QColor col);
	void SetBColor(QColor col);
	
	void SetAValue(int val);
	void SetBValue(int val);
};
