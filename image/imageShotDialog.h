#pragma once
#include <QWidget>
#include "cutdialog.h"

class CutDialog;

class imageShotDialog :public QWidget
{
	Q_OBJECT
private:
	CutDialog *dialog;

public:
	explicit imageShotDialog(QWidget *parent = 0);

	~imageShotDialog(void);
	QRect getShotGeometry() { return dialog->geometry(); }

protected:
	void paintEvent(QPaintEvent *e);
};
