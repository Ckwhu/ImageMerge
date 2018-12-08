#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"imageShotDialog.h"
#include"ImageMerge.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	imageShotDialog *pdialog;
	ImageMerge *imageMerge;
	QPixmap scaledPix;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	void displayImage(Mat img);

private:
    Ui::MainWindow *ui;

public slots:
	void ClickButton();
	void OpenImage();
	void changeImage();
	void cutImage();
	void concelCut();
	void changeDisplay();
	void getCuttedImage();
	void featureMatch();
	void imgMerge();
	void fastMerge();
	void saveImage();
};

#endif // MAINWINDOW_H
