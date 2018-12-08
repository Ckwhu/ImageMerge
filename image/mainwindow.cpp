#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include"CutDialog.h"

#include <QFileDialog>
#include <QtWidgets/qlabel.h>
#include<qmessagebox.h>
#include<iostream>

Mat zoom(Mat image,int scale);//声明缩放函数
int flag = -1;//用于追踪哪个ratiobutton被选中
//QPixmap scaledPix;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	imageMerge = new ImageMerge();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::ClickButton()
{
	std::cout << "hello";
}

void MainWindow::OpenImage() {
	static int count = 1;
	QString filename = QFileDialog::getOpenFileName(this,
		tr("open image"),
		".",
		tr("Image file(*.png *.jpg *.bmp)"));
	if (filename == NULL)return;//如果只点击了打开图像并没有做任何打开操作。
	if (count == 1) {
		Mat left = imread(filename.toLocal8Bit().data(), CV_LOAD_IMAGE_UNCHANGED);
		this->imageMerge->leftImage = left;
		ui->radioButton->setChecked(true);
		ui->pushButton_2->setDisabled(false);
		ui->label->setText(QStringLiteral("提示：点击打开图像打开右图......"));
		flag = 1;
		displayImage(left);
		count++;
	}
	else {
		Mat right = imread(filename.toLocal8Bit().data(), CV_LOAD_IMAGE_UNCHANGED);
		this->imageMerge->rightImage = right;
		ui->radioButton_2->setChecked(true);
		ui->pushButton_4->setDisabled(false);
		ui->pushButton_5->setDisabled(false);
		ui->pushButton_6->setDisabled(false);
		flag = 2;
		displayImage(right);
		ui->pushButton->setDisabled(true);
	}
}
void MainWindow::displayImage(Mat img) {
	Mat rgb;
	QImage image;
	if (img.channels() == 3)    // RGB image
	{
		cvtColor(img, rgb, CV_BGR2RGB);
		image = QImage((const uchar*)(rgb.data), 
			rgb.cols, rgb.rows,
			rgb.cols*rgb.channels(),
			QImage::Format_RGB888);
	}
	else                     // gray image
	{
		image = QImage((const uchar*)(img.data),
			img.cols, img.rows,
			img.cols*img.channels(),
			QImage::Format_Indexed8);
	}
	QLabel *label = new QLabel();
	scaledPix = QPixmap::fromImage(image);
	label->setPixmap(scaledPix);
	label->resize(QSize(img.rows, img.cols));
	ui->scrollArea->setWidget(label);
}
Mat zoom(Mat image,int scale) {
	Mat dst;
	if (scale < 0) {
		double s = scale * 0.1 + 1.1;
		Size ResImgSiz = Size(image.cols*s, image.rows*s);
		dst = Mat(ResImgSiz, image.type());
		cv::resize(image, dst, ResImgSiz, CV_INTER_CUBIC);
	}
	else if (scale == 0) {
		dst = image;
	}
	else {
		double s = fabs(scale)*0.1 + 1;
		Size ResImgSiz = Size(image.cols*s, image.rows*s);
		dst = Mat(ResImgSiz, image.type());
		cv::resize(image, dst, ResImgSiz, CV_INTER_LINEAR);
	}
	return dst;
}

void MainWindow::changeImage()
{
	Mat dst;
	int scale=ui->spinBox->value();
	switch (flag) {
	case 1:
		dst = zoom(this->imageMerge->leftImage, scale);
		break;
	case 2:
		dst = zoom(this->imageMerge->rightImage, scale);
		break;
	case 3:
		dst = zoom(this->imageMerge->cuttedImage, scale);
		break;
	case 4:
		dst = zoom(this->imageMerge->FeatureMatchImage, scale);
		break;
	case 5:
		dst = zoom(this->imageMerge->mergedImage, scale);
		break;
	}
	displayImage(dst);
}


void MainWindow::cutImage()
{
	ui->pushButton_7->setDisabled(false);
	ui->pushButton_8->setDisabled(false);
	pdialog = new imageShotDialog(ui->scrollArea);
	pdialog->show();
	ui->pushButton_2->setDisabled(true);
	//QPushButton *cancelCut;
	//cancelCut = new QPushButton(ui->centralWidget);
	//cancelCut->setObjectName(QStringLiteral("cancel"));
	//cancelCut->setGeometry(QRect(570, 420, 75, 23));
	//cancelCut->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210\351\200\211\346\241\206", nullptr));
	//QObject::connect(cancelCut, SIGNAL(clicked()), this, SLOT(cutImage()));
	//cancelCut->show();
	//ui->scrollArea->setWidget(pdialog);
}

void MainWindow::concelCut()
{
	ui->pushButton_7->setDisabled(true);
	ui->pushButton_8->setDisabled(true);
	this->pdialog->hide();
	ui->pushButton_2->setDisabled(false);
}

void MainWindow::changeDisplay()
{
	//static int flag = -1;//用于记录是哪个radioButton被选中
	if (sender() == ui->radioButton) {
		if ((this->imageMerge->leftImage).data==NULL) {
			ui->label->setText(QStringLiteral("提示：未导入左图！"));
		}
		else {
			flag = 1;
			ui->spinBox->setValue(0);
			ui->pushButton_2->setDisabled(false);
			displayImage(this->imageMerge->leftImage);
		}
	}
	else if (sender() == ui->radioButton_2) {
		if ((this->imageMerge->rightImage).data == NULL) {
			ui->label->setText(QStringLiteral("提示：未导入右图！"));
		}
		else {
			flag = 2;
			ui->spinBox->setValue(0);
			ui->pushButton_2->setDisabled(false);
			displayImage(this->imageMerge->rightImage);
		}
	}
	else if (sender() == ui->radioButton_3) {
		if ((this->imageMerge->cuttedImage).data == NULL) {
			ui->label->setText(QStringLiteral("提示：不存在裁剪图！"));
		}
		else {
			flag = 3;
			ui->spinBox->setValue(0);
			ui->pushButton_2->setDisabled(true);
			displayImage(this->imageMerge->cuttedImage);
		}
	}
	else if (sender() == ui->radioButton_4) {
		if ((this->imageMerge->FeatureMatchImage).data == NULL) {
			ui->label->setText(QStringLiteral("提示：不存在特征匹配图！"));
		}
		else {
			flag = 4;
			ui->spinBox->setValue(0);
			displayImage(this->imageMerge->FeatureMatchImage);
		}
	}
	else if (sender() == ui->radioButton_5) {
		if ((this->imageMerge->mergedImage).data == NULL) {
			ui->label->setText(QStringLiteral("提示：不存在合并图！"));
		}
		else {
			flag = 5;
			ui->spinBox->setValue(0);
			displayImage(this->imageMerge->mergedImage);
		}
	}
}

void MainWindow::getCuttedImage()
{
	QScreen *screen = QGuiApplication::primaryScreen();
	//getShotGeometry（）方法取出剪切后的图像区域
	QRect rect = pdialog->getShotGeometry();
	int v = ui->scrollArea->verticalScrollBar()->value();
	int h = ui->scrollArea->horizontalScrollBar()->value();
	QRect *changedRect=new QRect(rect.left()+h,rect.top()+v,rect.width(),rect.height());
	QPixmap pix = (scaledPix).copy(*changedRect);
	concelCut();//裁剪完后取消裁剪窗口
	pix.save("cuttedTempImage.png", "png");//剪切出的图片的临时保存
	Mat cuttedImage = imread("cuttedTempImage.png", CV_LOAD_IMAGE_UNCHANGED);
	this->imageMerge->cuttedImage = cuttedImage;
	ui->radioButton_3->setChecked(true);
	ui->pushButton_2->setDisabled(true);
	displayImage(cuttedImage);
}

void MainWindow::featureMatch()
{
	ui->label->setText(QStringLiteral("提示：正在进行匹配，请稍后......"));
	Mat image1, image2;
	cvtColor(imageMerge->rightImage, image1, CV_BGR2GRAY);
	cvtColor(imageMerge->leftImage, image2, CV_RGB2GRAY);
	imageMerge->imagePoints =imageMerge->detectKeyPoint(image1, image2);
	displayImage(imageMerge->FeatureMatchImage);
	ui->radioButton_4->setChecked(true);
	ui->label->setText(QStringLiteral("提示：匹配成功！"));
}

void MainWindow::imgMerge()
{
	imageMerge->registrat(imageMerge->rightImage, imageMerge->imagePoints[0], imageMerge->leftImage, imageMerge->imagePoints[1]);
	ui->label->setText(QStringLiteral("提示：拼接成功！"));
}

void MainWindow::fastMerge()
{
	featureMatch();//特征匹配
	imgMerge();//图像拼接
}

void MainWindow::saveImage()
{
	QString fileName = QFileDialog::getSaveFileName(this,
		QString::fromLocal8Bit("文件另存为"),
		"",
		tr("Config Files (*.png)"));
	switch (flag) {
	case -1:
		QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("保存失败！没有任何图片导入！"));
		break;
	case 1:
		if ((this->imageMerge->leftImage).data == NULL) {
			QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("保存失败！没有左图导入！"));
			return;
		}
		imwrite(fileName.toLocal8Bit().data(), this->imageMerge->leftImage);
		ui->label->setText(QStringLiteral("提示：左图已保存！"));
		break;
	case 2:
		if ((this->imageMerge->rightImage).data == NULL) {
			QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("保存失败！没有右图导入！"));
			return;
		}
		imwrite(fileName.toLocal8Bit().data(), this->imageMerge->rightImage);
		ui->label->setText(QStringLiteral("提示：右图已保存！"));
		break;
	case 3:
		if ((this->imageMerge->cuttedImage).data == NULL) {
			QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("保存失败！没有裁剪图！"));
			return;
		}
		imwrite(fileName.toLocal8Bit().data(), this->imageMerge->cuttedImage);
		ui->label->setText(QStringLiteral("提示：裁剪图已保存！"));
		break;
	case 4:
		if ((this->imageMerge->FeatureMatchImage).data == NULL) {
			QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("保存失败！没有特征匹配图！"));
			return;
		}
		imwrite(fileName.toLocal8Bit().data(), this->imageMerge->FeatureMatchImage);
		ui->label->setText(QStringLiteral("提示：特征匹配图已保存！"));
		break;
	case 5:
		if ((this->imageMerge->mergedImage).data == NULL) {
			QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("保存失败！没有拼接图！"));
			return;
		}
		imwrite(fileName.toLocal8Bit().data(), this->imageMerge->mergedImage);
		ui->label->setText(QStringLiteral("提示：拼接图已保存！"));
		break;
	}
}
