#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QFileDialog>
#include<QRgb>
#include<iostream>
#include<QPainter>
#include<cmath>
#include <windows.h>
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("OliPic");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_select_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ",  tr("picturefile(*.jpg);;Allfile(*.*)"));
    if (fileName != "")
    {
        QPixmap pixmap = QPixmap(fileName);
        image1 = QImage(fileName);
        ui->display->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
        ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
    }
    imageS = image1;
}

void MainWindow::on_genHis_clicked()
{
    QImage temp = image1;
    his.clear();
    for (int j = 0; j<temp.width(); j++)
    {
        for (int k = 0; k<temp.height(); k++)
        {
            int c = qGray(image1.pixel(j,k));
            temp.setPixel(j, k, qRgb(c, c, c));
            his[c]++;
        }
    }
    QPixmap pixmap;
    imageS = temp;
    pixmap = pixmap.fromImage(imageS);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));

    if (!image1.isNull())
    {
        QPixmap pixmap2(256, 260);
        pixmap2.fill(Qt::white);
        QPainter p;
        p.begin(&pixmap2);
        map<int, int>::iterator it = his.begin();
        for (; it != his.end(); it++)
        {
            p.drawLine(it->first, 260, it->first, 260.0-float(it->second)/float(temp.height())/float(temp.width())*4000.0);
            //cout<<it->first<<" "<<it->second<<endl;
        }
        p.end();
        ui->histogram->setPixmap(pixmap2);
    }
}

void MainWindow::on_saveAs_clicked()
{
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this, tr("save file"), " ",  tr("picturefile(*.jpg);;Allfile(*.*)"));
    imageS.save(fileName);
}

void MainWindow::on_setThr_valueChanged(int value)
{
    ui->setThrM->setValue(value);
    QImage temp = image1;
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            if (qGray(image1.pixel(j, k)) < value)
                temp.setPixel(j, k, qRgb(0, 0, 0));
            else
                temp.setPixel(j, k, qRgb(255, 255, 255));

        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(imageS);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_setThrM_valueChanged(int arg1)
{
    ui->setThr->setValue(arg1);
}

void MainWindow::on_roberts_clicked()
{
    QImage temp1;
    QImage temp2;
    temp1 = image1;
    temp2 = image1;
    for (int j = 0; j<image1.width()-1; j++)
    {
        for (int k = 0; k<image1.height()-1; k++)
        {
            int c = abs( qRed(image1.pixel(j, k)) - qRed(image1.pixel(j+1, k+1)));
            temp1.setPixel(j, k, qRgb(c, c, c));
            c = abs( qRed(image1.pixel(j+1, k)) - qRed(image1.pixel(j, k+1)));
            temp2.setPixel(j, k, qRgb(c, c, c));
        }
    }
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            int c = qRed(temp1.pixel(j, k)) * qRed(temp1.pixel(j, k)) + qRed(temp2.pixel(j, k)) * qRed(temp2.pixel(j, k));
            c = sqrt(c);
            temp1.setPixel(j, k, qRgb(c, c, c));
        }
    }
    imageS = temp1;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(temp1);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_prewitt_clicked()
{
    QImage temp1;
    QImage temp2;
    temp1 = image1;
    temp2 = image1;
    for (int j = 1; j<image1.width()-1; j++)
    {
        for (int k = 1; k<image1.height()-1; k++)
        {
            int c = abs( qRed(image1.pixel(j+1, k-1))
                         + qRed(image1.pixel(j+1, k))
                         + qRed(image1.pixel(j+1, k+1))
                         - qRed(image1.pixel(j-1, k-1))
                         - qRed(image1.pixel(j-1, k))
                         - qRed(image1.pixel(j-1, k+1)));
            temp1.setPixel(j, k, qRgb(c, c, c));
            c = abs( qRed(image1.pixel(j-1, k-1))
                     + qRed(image1.pixel(j, k-1))
                     + qRed(image1.pixel(j+1, k-1))
                     - qRed(image1.pixel(j-1, k+1))
                     - qRed(image1.pixel(j, k+1))
                     - qRed(image1.pixel(j+1, k+1)));
            temp2.setPixel(j, k, qRgb(c, c, c));
        }
    }
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            int c = qRed(temp1.pixel(j, k)) * qRed(temp1.pixel(j, k)) + qRed(temp2.pixel(j, k)) * qRed(temp2.pixel(j, k));
            c = sqrt(c);
            temp1.setPixel(j, k, qRgb(c, c, c));
        }
    }
    imageS = temp1;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(temp1);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_sobel_clicked()
{
    QImage temp1;
    QImage temp2;
    temp1 = image1;
    temp2 = image1;
    for (int j = 1; j<image1.width()-1; j++)
    {
        for (int k = 1; k<image1.height()-1; k++)
        {
            int c = abs( qRed(image1.pixel(j+1, k-1))
                         + 2 * qRed(image1.pixel(j+1, k))
                         + qRed(image1.pixel(j+1, k+1))
                         - qRed(image1.pixel(j-1, k-1))
                         - 2 * qRed(image1.pixel(j-1, k))
                         - qRed(image1.pixel(j-1, k+1)));
            temp1.setPixel(j, k, qRgb(c, c, c));
            c = abs( qRed(image1.pixel(j-1, k-1))
                     + 2 * qRed(image1.pixel(j, k-1))
                     + qRed(image1.pixel(j+1, k-1))
                     - qRed(image1.pixel(j-1, k+1))
                     - 2 * qRed(image1.pixel(j, k+1))
                     - qRed(image1.pixel(j+1, k+1)));
            temp2.setPixel(j, k, qRgb(c, c, c));
        }
    }
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            int c = qRed(temp1.pixel(j, k)) * qRed(temp1.pixel(j, k)) + qRed(temp2.pixel(j, k)) * qRed(temp2.pixel(j, k));
            c = sqrt(c);
            temp1.setPixel(j, k, qRgb(c, c, c));
        }
    }
    imageS = temp1;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(temp1);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));

}

void MainWindow::on_gaus_clicked()
{
    QImage temp;
    temp = image1;
    for (int j = 3; j<image1.width()-3; j++)
    {
        for (int k = 3; k<image1.height()-3; k++)
        {
            int r = int(0.0751 * double(qRed(image1.pixel(j-1, k-1)))
                    + 0.1238 * double(qRed(image1.pixel(j, k-1)))
                    + 0.0751 * double(qRed(image1.pixel(j+1, k-1)))
                    + 0.1238 * double(qRed(image1.pixel(j-1, k)))
                    + 0.2043 * double(qRed(image1.pixel(j, k)))
                    + 0.1238 * double(qRed(image1.pixel(j+1, k)))
                    + 0.0751 * double(qRed(image1.pixel(j-1, k+1)))
                    + 0.1238 * double(qRed(image1.pixel(j, k+1)))
                    + 0.0751 * double(qRed(image1.pixel(j+1, k+1))));
            int g = int(0.0751 * double(qGreen(image1.pixel(j-1, k-1)))
                    + 0.1238 * double(qGreen(image1.pixel(j, k-1)))
                    + 0.0751 * double(qGreen(image1.pixel(j+1, k-1)))
                    + 0.1238 * double(qGreen(image1.pixel(j-1, k)))
                    + 0.2043 * double(qGreen(image1.pixel(j, k)))
                    + 0.1238 * double(qGreen(image1.pixel(j+1, k)))
                    + 0.0751 * double(qGreen(image1.pixel(j-1, k+1)))
                    + 0.1238 * double(qGreen(image1.pixel(j, k+1)))
                    + 0.0751 * double(qGreen(image1.pixel(j+1, k+1))));
            int b = int(0.0751 * double(qBlue(image1.pixel(j-1, k-1)))
                    + 0.1238 * double(qBlue(image1.pixel(j, k-1)))
                    + 0.0751 * double(qBlue(image1.pixel(j+1, k-1)))
                    + 0.1238 * double(qBlue(image1.pixel(j-1, k)))
                    + 0.2043 * double(qBlue(image1.pixel(j, k)))
                    + 0.1238 * double(qBlue(image1.pixel(j+1, k)))
                    + 0.0751 * double(qBlue(image1.pixel(j-1, k+1)))
                    + 0.1238 * double(qBlue(image1.pixel(j, k+1)))
                    + 0.0751 * double(qBlue(image1.pixel(j+1, k+1))));
            temp.setPixel(j, k, qRgb(r, g, b));
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(temp);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_mean_clicked()
{
    QImage temp;
    temp = image1;
    for (int j = 3; j<image1.width()-3; j++)
    {
        for (int k = 3; k<image1.height()-3; k++)
        {
            int r = int(1.0/9 * double(qRed(image1.pixel(j-1, k-1)))
                    + 1.0/9* double(qRed(image1.pixel(j, k-1)))
                    + 1.0/9 * double(qRed(image1.pixel(j+1, k-1)))
                    + 1.0/9 * double(qRed(image1.pixel(j-1, k)))
                    + 1.0/9 * double(qRed(image1.pixel(j, k)))
                    + 1.0/9 * double(qRed(image1.pixel(j+1, k)))
                    + 1.0/9 * double(qRed(image1.pixel(j-1, k+1)))
                    + 1.0/9 * double(qRed(image1.pixel(j, k+1)))
                    + 1.0/9 * double(qRed(image1.pixel(j+1, k+1))));
            int g = int(0.0751 * double(qGreen(image1.pixel(j-1, k-1)))
                    + 1.0/9 * double(qGreen(image1.pixel(j, k-1)))
                    + 1.0/9 * double(qGreen(image1.pixel(j+1, k-1)))
                    + 1.0/9 * double(qGreen(image1.pixel(j-1, k)))
                    + 1.0/9 * double(qGreen(image1.pixel(j, k)))
                    + 1.0/9 * double(qGreen(image1.pixel(j+1, k)))
                    + 1.0/9 * double(qGreen(image1.pixel(j-1, k+1)))
                    + 1.0/9 * double(qGreen(image1.pixel(j, k+1)))
                    + 1.0/9 * double(qGreen(image1.pixel(j+1, k+1))));
            int b = int(1.0/9 * double(qBlue(image1.pixel(j-1, k-1)))
                    + 1.0/9 * double(qBlue(image1.pixel(j, k-1)))
                    + 1.0/9 * double(qBlue(image1.pixel(j+1, k-1)))
                    + 1.0/9 * double(qBlue(image1.pixel(j-1, k)))
                    + 1.0/9 * double(qBlue(image1.pixel(j, k)))
                    + 1.0/9 * double(qBlue(image1.pixel(j+1, k)))
                    + 1.0/9 * double(qBlue(image1.pixel(j-1, k+1)))
                    + 1.0/9 * double(qBlue(image1.pixel(j, k+1)))
                    + 1.0/9 * double(qBlue(image1.pixel(j+1, k+1))));
            temp.setPixel(j, k, qRgb(r, g, b));
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(temp);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));

}

void MainWindow::on_medi_clicked()
{
    QImage temp;
    temp = image1;
    for (int j = 3; j<image1.width()-3; j++)
    {
        for (int k = 3; k<image1.height()-3; k++)
        {
            int r[9];
            int i = 0;
            for (int m = -1; m < 2; m++)
            {
                for (int n = -1; n < 2; n++)
                    r[i++] = qRed(image1.pixel(j+m, k+n));
            }
            for (int m = 0; m < 9; m++)
            {
                for (int n = 0; n < 9; n++)
                {
                    if (r[m] > r[n])
                    {
                        int x = r[m];
                        r[m] = r[n];
                        r[n] = x;
                    }
                }
            }
            int g[9];
            i = 0;
            for (int m = -1; m < 2; m++)
            {
                for (int n = -1; n < 2; n++)
                    g[i++] = qGreen(image1.pixel(j+m, k+n));
            }
            for (int m = 0; m < 9; m++)
            {
                for (int n = 0; n < 9; n++)
                {
                    if (g[m] > g[n])
                    {
                        int x = g[m];
                        g[m] = g[n];
                        g[n] = x;
                    }
                }
            }

            int b[9];
            i = 0;
            for (int m = -1; m < 2; m++)
            {
                for (int n = -1; n < 2; n++)
                    b[i++] = qBlue(image1.pixel(j+m, k+n));
            }
            for (int m = 0; m < 9; m++)
            {
                for (int n = 0; n < 9; n++)
                {
                    if (b[m] > b[n])
                    {
                        int x = b[m];
                        b[m] = b[n];
                        b[n] = x;
                    }
                }
            }
            temp.setPixel(j, k, qRgb(r[5], g[5], b[5]));
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(temp);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));

}

void MainWindow::on_invert_clicked()
{
    QImage temp;
    temp = image1;
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            int r = 255 - qRed(image1.pixel(j, k));
            int g = 255 - qGreen(image1.pixel(j, k));
            int b = 255 - qBlue(image1.pixel(j, k));
            temp.setPixel(j, k, qRgb(r, g, b));
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(temp);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_combine_clicked()
{

    QString fileName;
    QImage temp1;
    QImage temp2;
    fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ",  tr("picturefile(*.jpg);;Allfile(*.*)"));
    if (fileName != "")
    {
        QPixmap pixmap = QPixmap(fileName);
        temp1 = QImage(fileName);
        ui->display3->setPixmap(pixmap.scaled(QSize(310, 200), Qt::KeepAspectRatio));
    }
    temp2 = image1;
    for (int j = 0; j<temp1.width() && j<temp2.width(); j++)
    {
        for (int k = 0; k<temp1.height() && k<temp2.height(); k++)
        {
            temp2.setPixel(j, k, temp1.pixel(j, k) + temp2.pixel(j, k));
        }
    }
    imageS = temp2;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(temp2);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_nearest_clicked()
{
    QImage temp(image1.width()*3, image1.height()*3, QImage::Format_RGB888);
    for (int j = 0; j<temp.width(); j++)
    {
        for (int k = 0; k<temp.height(); k++)
        {
            temp.setPixel(j, k, image1.pixel(int(j/3.0+0.5), int(k/3.0+0.5)));
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(temp);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_bilinear_clicked()
{
    QImage temp(image1.width()*3, image1.height()*3, QImage::Format_RGB888);
    for (int m = 0; m<temp.width(); m++)
    {
        for (int n = 0; n<temp.height(); n++)
        {
            int i, j;
            i = int(m/3.0);
            j = int(n/3.0);
            double u, v;
            u = m/3.0 - i;
            v = n/3.0 - j;
            int r;
            r = (1-u)*(1-v)*qRed(image1.pixel(i,j))
                    + (1-u)*v*qRed(image1.pixel(i,j+1))
                    + u*(1-v)*qRed(image1.pixel(i+1,j))
                    + u*v*qRed(image1.pixel(i+1,j+1));
            int g;
            g = (1-u)*(1-v)*qGreen(image1.pixel(i,j))
                    + (1-u)*v*qGreen(image1.pixel(i,j+1))
                    + u*(1-v)*qGreen(image1.pixel(i+1,j))
                    + u*v*qGreen(image1.pixel(i+1,j+1));
            int b;
            b = (1-u)*(1-v)*qBlue(image1.pixel(i,j))
                    + (1-u)*v*qBlue(image1.pixel(i,j+1))
                    + u*(1-v)*qBlue(image1.pixel(i+1,j))
                    + u*v*qBlue(image1.pixel(i+1,j+1));

            temp.setPixel(m, n, qRgb(r ,g ,b));
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(temp);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_otsu_clicked()
{
    if (image1.isNull()) return;
    his.clear();
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            int c = qGray(image1.pixel(j,k));
            his[c]++;
        }
    }
    int t = 0;
    double value = 0;
    for (int j = 0; j<256; j++)
    {
        int sum = 0;
        double count = 0;
        for (int m = 0; m<=j; m++)
        {
            sum += his[m] * m;
            count += his[m];
        }
        double avg = sum/count;

        int sum1 = 0;
        double count1 = 0;
        for (int m = j+1; m<=255; m++)
        {
            sum1 += his[m] * m;
            count1 += his[m];
        }
        double avg1 = sum1/count1;

        double tempvalue = count * count1 * (avg-avg1) * (avg-avg1);
        if (tempvalue > value)
        {
            value = tempvalue;
            t = j;
        }
    }
    ui->setThr->setValue(t);
}

void MainWindow::on_entropy_clicked()
{
    if (image1.isNull()) return;
    his.clear();
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            int c = qGray(image1.pixel(j,k));
            his[c]++;
        }
    }
    int t = 0;
    double value = 0;
    for (int j = 0; j<256; j++)
    {
        double h1 = 0;
        for (double m = 0; m<=j; m++)
        {
            double temp = double(his[m]) / image1.width() / image1.height();
            if (temp != 0)
                h1 -= temp * log(temp);
        }
        double h2 = 0;
        for (double m = j+1; m<=255; m++)
        {
            double temp = double(his[m]) / image1.width() / image1.height();
            if (temp != 0)
                h2 -= temp * log(temp);
        }
        double tempvalue = h1 + h2;
        if (tempvalue > value)
        {
            value = tempvalue;
            t = j;
        }
    }
    ui->setThr->setValue(t);
}

void MainWindow::on_bi_di_clicked()
{
    if (image1.isNull()) return;
    his.clear();
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            int c = qGray(image1.pixel(j,k));
            his[c]++;
        }
    }
    int t = 0;
    double value = 0;
    for (int j = 0; j<256; j++)
    {
        int sum = 0;
        double count = 0;
        for (int m = 0; m<=j; m++)
        {
            sum += his[m] * m;
            count += his[m];
        }
        double avg = sum/count;

        int sum1 = 0;
        double count1 = 0;
        for (int m = j+1; m<=255; m++)
        {
            sum1 += his[m] * m;
            count1 += his[m];
        }
        double avg1 = sum1/count1;

        double tempvalue = count * count1 * (avg-avg1) * (avg-avg1);
        if (tempvalue > value)
        {
            value = tempvalue;
            t = j;
        }
    }
    QImage temp = image1;
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            if (qGray(image1.pixel(j, k)) < t)
                temp.setPixel(j, k, qRgb(0, 0, 0));
            else
                temp.setPixel(j, k, qRgb(255, 255, 255));

        }
    }
    imageS = temp;
    for (int j = 1; j<imageS.width()-1; j++)
    {
        for (int k = 1; k<imageS.height()-1; k++)
        {
            if (qRed(imageS.pixel(j, k)) == 0)
            {
                temp.setPixel(j-1, k-1, qRgb(0, 0, 0));
                temp.setPixel(j-1, k, qRgb(0, 0, 0));
                temp.setPixel(j-1, k+1, qRgb(0, 0, 0));
                temp.setPixel(j, k-1, qRgb(0, 0, 0));
                temp.setPixel(j, k+1, qRgb(0, 0, 0));
                temp.setPixel(j+1, k-1, qRgb(0, 0, 0));
                temp.setPixel(j+1, k, qRgb(0, 0, 0));
                temp.setPixel(j+1, k+1, qRgb(0, 0, 0));
            }
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(imageS);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_bi_er_clicked()
{
    if (image1.isNull()) return;
    his.clear();
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            int c = qGray(image1.pixel(j,k));
            his[c]++;
        }
    }
    int t = 0;
    double value = 0;
    for (int j = 0; j<256; j++)
    {
        int sum = 0;
        double count = 0;
        for (int m = 0; m<=j; m++)
        {
            sum += his[m] * m;
            count += his[m];
        }
        double avg = sum/count;

        int sum1 = 0;
        double count1 = 0;
        for (int m = j+1; m<=255; m++)
        {
            sum1 += his[m] * m;
            count1 += his[m];
        }
        double avg1 = sum1/count1;

        double tempvalue = count * count1 * (avg-avg1) * (avg-avg1);
        if (tempvalue > value)
        {
            value = tempvalue;
            t = j;
        }
    }
    QImage temp = image1;
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            if (qGray(image1.pixel(j, k)) < t)
                temp.setPixel(j, k, qRgb(0, 0, 0));
            else
                temp.setPixel(j, k, qRgb(255, 255, 255));

        }
    }
    imageS = temp;
    for (int j = 1; j<imageS.width()-1; j++)
    {
        for (int k = 1; k<imageS.height()-1; k++)
        {
            if (qRed(imageS.pixel(j, k)) == 255)
            {
                temp.setPixel(j-1, k-1, qRgb(255, 255, 255));
                temp.setPixel(j-1, k, qRgb(255, 255, 255));
                temp.setPixel(j-1, k+1, qRgb(255, 255, 255));
                temp.setPixel(j, k-1, qRgb(255, 255, 255));
                temp.setPixel(j, k+1, qRgb(255, 255, 255));
                temp.setPixel(j+1, k-1, qRgb(255, 255, 255));
                temp.setPixel(j+1, k, qRgb(255, 255, 255));
                temp.setPixel(j+1, k+1, qRgb(255, 255, 255));
            }
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(imageS);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_bi_op_clicked()
{
    if (image1.isNull()) return;
    his.clear();
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            int c = qGray(image1.pixel(j,k));
            his[c]++;
        }
    }
    int t = 0;
    double value = 0;
    for (int j = 0; j<256; j++)
    {
        int sum = 0;
        double count = 0;
        for (int m = 0; m<=j; m++)
        {
            sum += his[m] * m;
            count += his[m];
        }
        double avg = sum/count;

        int sum1 = 0;
        double count1 = 0;
        for (int m = j+1; m<=255; m++)
        {
            sum1 += his[m] * m;
            count1 += his[m];
        }
        double avg1 = sum1/count1;

        double tempvalue = count * count1 * (avg-avg1) * (avg-avg1);
        if (tempvalue > value)
        {
            value = tempvalue;
            t = j;
        }
    }
    QImage temp = image1;
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            if (qGray(image1.pixel(j, k)) < t)
                temp.setPixel(j, k, qRgb(0, 0, 0));
            else
                temp.setPixel(j, k, qRgb(255, 255, 255));

        }
    }
    imageS = temp;
    for (int j = 1; j<imageS.width()-1; j++)
    {
        for (int k = 1; k<imageS.height()-1; k++)
        {
            if (qRed(imageS.pixel(j, k)) == 255)
            {
                temp.setPixel(j-1, k-1, qRgb(255, 255, 255));
                temp.setPixel(j-1, k, qRgb(255, 255, 255));
                temp.setPixel(j-1, k+1, qRgb(255, 255, 255));
                temp.setPixel(j, k-1, qRgb(255, 255, 255));
                temp.setPixel(j, k+1, qRgb(255, 255, 255));
                temp.setPixel(j+1, k-1, qRgb(255, 255, 255));
                temp.setPixel(j+1, k, qRgb(255, 255, 255));
                temp.setPixel(j+1, k+1, qRgb(255, 255, 255));
            }
        }
    }
    imageS = temp;
    for (int j = 1; j<imageS.width()-1; j++)
    {
        for (int k = 1; k<imageS.height()-1; k++)
        {
            if (qRed(imageS.pixel(j, k)) == 0)
            {
                temp.setPixel(j-1, k-1, qRgb(0, 0, 0));
                temp.setPixel(j-1, k, qRgb(0, 0, 0));
                temp.setPixel(j-1, k+1, qRgb(0, 0, 0));
                temp.setPixel(j, k-1, qRgb(0, 0, 0));
                temp.setPixel(j, k+1, qRgb(0, 0, 0));
                temp.setPixel(j+1, k-1, qRgb(0, 0, 0));
                temp.setPixel(j+1, k, qRgb(0, 0, 0));
                temp.setPixel(j+1, k+1, qRgb(0, 0, 0));
            }
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(imageS);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_bi_cl_clicked()
{
    if (image1.isNull()) return;
    his.clear();
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            int c = qGray(image1.pixel(j,k));
            his[c]++;
        }
    }
    int t = 0;
    double value = 0;
    for (int j = 0; j<256; j++)
    {
        int sum = 0;
        double count = 0;
        for (int m = 0; m<=j; m++)
        {
            sum += his[m] * m;
            count += his[m];
        }
        double avg = sum/count;

        int sum1 = 0;
        double count1 = 0;
        for (int m = j+1; m<=255; m++)
        {
            sum1 += his[m] * m;
            count1 += his[m];
        }
        double avg1 = sum1/count1;

        double tempvalue = count * count1 * (avg-avg1) * (avg-avg1);
        if (tempvalue > value)
        {
            value = tempvalue;
            t = j;
        }
    }
    QImage temp = image1;
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            if (qGray(image1.pixel(j, k)) < t)
                temp.setPixel(j, k, qRgb(0, 0, 0));
            else
                temp.setPixel(j, k, qRgb(255, 255, 255));

        }
    }
    imageS = temp;
    for (int j = 1; j<imageS.width()-1; j++)
    {
        for (int k = 1; k<imageS.height()-1; k++)
        {
            if (qRed(imageS.pixel(j, k)) == 0)
            {
                temp.setPixel(j-1, k-1, qRgb(0, 0, 0));
                temp.setPixel(j-1, k, qRgb(0, 0, 0));
                temp.setPixel(j-1, k+1, qRgb(0, 0, 0));
                temp.setPixel(j, k-1, qRgb(0, 0, 0));
                temp.setPixel(j, k+1, qRgb(0, 0, 0));
                temp.setPixel(j+1, k-1, qRgb(0, 0, 0));
                temp.setPixel(j+1, k, qRgb(0, 0, 0));
                temp.setPixel(j+1, k+1, qRgb(0, 0, 0));
            }
        }
    }
    imageS = temp;
    for (int j = 1; j<imageS.width()-1; j++)
    {
        for (int k = 1; k<imageS.height()-1; k++)
        {
            if (qRed(imageS.pixel(j, k)) == 255)
            {
                temp.setPixel(j-1, k-1, qRgb(255, 255, 255));
                temp.setPixel(j-1, k, qRgb(255, 255, 255));
                temp.setPixel(j-1, k+1, qRgb(255, 255, 255));
                temp.setPixel(j, k-1, qRgb(255, 255, 255));
                temp.setPixel(j, k+1, qRgb(255, 255, 255));
                temp.setPixel(j+1, k-1, qRgb(255, 255, 255));
                temp.setPixel(j+1, k, qRgb(255, 255, 255));
                temp.setPixel(j+1, k+1, qRgb(255, 255, 255));
            }
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(imageS);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

QImage MainWindow::erosion(QImage image)   //2-value needed
{
    QImage temp;
    temp = image;
    for (int j = 0; j<image.width(); j++)
    {
        for (int k = 0; k<image.height(); k++)
        {
            if (qRed(image.pixel(j, k)) == 255)
            {
                //temp.setPixel(j-1, k-1, qRgb(255, 255, 255));
                temp.setPixel(j-1, k, qRgb(255, 255, 255));
                //temp.setPixel(j-1, k+1, qRgb(255, 255, 255));
                temp.setPixel(j, k-1, qRgb(255, 255, 255));
                temp.setPixel(j, k+1, qRgb(255, 255, 255));
                //temp.setPixel(j+1, k-1, qRgb(255, 255, 255));
                temp.setPixel(j+1, k, qRgb(255, 255, 255));
                //temp.setPixel(j+1, k+1, qRgb(255, 255, 255));
            }
        }
    }
    return temp;
}

QImage MainWindow::dilation(QImage image)   //2-value needed
{
    QImage temp;
    temp = image;
    for (int j = 0; j<image.width(); j++)
    {
        for (int k = 0; k<image.height(); k++)
        {
            if (qRed(image.pixel(j, k)) == 0)
            {
                //temp.setPixel(j-1, k-1, qRgb(0, 0, 0));
                temp.setPixel(j-1, k, qRgb(0, 0, 0));
                //temp.setPixel(j-1, k+1, qRgb(0, 0, 0));
                temp.setPixel(j, k-1, qRgb(0, 0, 0));
                temp.setPixel(j, k+1, qRgb(0, 0, 0));
                //temp.setPixel(j+1, k-1, qRgb(0, 0, 0));
                temp.setPixel(j+1, k, qRgb(0, 0, 0));
                //temp.setPixel(j+1, k+1, qRgb(0, 0, 0));
            }
        }
    }
    return temp;
}

QImage MainWindow::setgray(QImage image, int gray)   //2-value needed
{
    QImage temp;
    temp = image;
    for (int j = 0; j<image.width(); j++)
    {
        for (int k = 0; k<image.height(); k++)
        {
            if (qRed(image.pixel(j, k)) != 255)
            {
                temp.setPixel(j, k, qRgb(gray, gray, gray));
            }
            else
                temp.setPixel(j, k, qRgb(0, 0, 0));
        }
    }
    return temp;
}

QImage MainWindow::subtract(QImage imagea, QImage imageb)   //2-value and same size needed
{
    QImage temp;
    temp = imagea;
    for (int j = 0; j<imagea.width(); j++)
    {
        for (int k = 0; k<imagea.height(); k++)
        {
            if (qRed(imagea.pixel(j, k)) == 0 && qRed(imageb.pixel(j, k)) == 255)
                temp.setPixel(j, k, qRgb(0, 0, 0));
            else
                temp.setPixel(j,k,qRgb(255,255,255));
        }
    }
    return temp;
}

bool MainWindow::isempty(QImage image)  //2-value needed
{
    int count = 0;
    for (int j = 0; j<image.width(); j++)
    {
        for (int k = 0; k<image.height(); k++)
        {
            if (qRed(image.pixel(j, k)) != 255)
            {
//                count++;
//                if (count > image.width()*image.height()/10)
                    return false;
            }
        }
    }
    return true;
}

QImage MainWindow::otsu()
{
    his.clear();
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            int c = qGray(image1.pixel(j,k));
            his[c]++;
        }
    }
    int t = 0;
    double value = 0;
    for (int j = 0; j<256; j++)
    {
        int sum = 0;
        double count = 0;
        for (int m = 0; m<=j; m++)
        {
            sum += his[m] * m;
            count += his[m];
        }
        double avg = sum/count;

        int sum1 = 0;
        double count1 = 0;
        for (int m = j+1; m<=255; m++)
        {
            sum1 += his[m] * m;
            count1 += his[m];
        }
        double avg1 = sum1/count1;

        double tempvalue = count * count1 * (avg-avg1) * (avg-avg1);
        if (tempvalue > value)
        {
            value = tempvalue;
            t = j;
        }
    }
    QImage temp = image1;
    for (int j = 0; j<image1.width(); j++)
    {
        for (int k = 0; k<image1.height(); k++)
        {
            if (qGray(image1.pixel(j, k)) < t)
                temp.setPixel(j, k, qRgb(0, 0, 0));
            else
                temp.setPixel(j, k, qRgb(255, 255, 255));

        }
    }
    return temp;
}

void MainWindow::on_di_tr_clicked()
{
    vector<QImage> images;
    bool flag = true;
    QImage temp;
    QImage temp1;
    temp = otsu();
    int count = 0;
    while (flag)
    {
        temp1 = subtract(temp, subtract(temp, erosion(temp)));
        temp = erosion(temp);
        if (isempty(temp))
            flag = false;
        images.push_back(temp1);
        count++;
    }
    temp1 = images[0];
    temp1 = setgray(temp1, 255/count);
    temp = temp1;
    for (int i = 1; i<images.size(); i++)
    {
        temp1 = images[i];
        temp1 = setgray(temp1, 255/count);
        for (int j = 0; j<temp.width(); j++)
        {
            for (int k = 0; k<temp.height(); k++)
            {
                int gr = qRed(temp1.pixel(j, k)) + qRed(temp.pixel(j, k));
                gr = gr>255 ? 255:gr;
                temp.setPixel(j,k, qRgb(gr,gr,gr));
            }
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(imageS);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_skel_clicked()
{
    vector<QImage> images;
    bool flag = true;
    QImage temp;
    QImage temp1;
    temp = otsu();
    while (flag)
    {
        temp1 = subtract(temp, dilation(erosion(temp)));
        temp = erosion(temp);
        if (isempty(temp))
            flag = false;
        images.push_back(temp1);
    }
    temp1 = images[0];
    temp = temp1;
    for (int i = 1; i<images.size(); i++)
    {
        temp1 = images[i];
        for (int j = 0; j<temp.width(); j++)
        {
            for (int k = 0; k<temp.height(); k++)
            {
                if (qRed(temp1.pixel(j, k)) == 0 || qRed(temp.pixel(j, k)) == 0)
                {
                    temp.setPixel(j,k, qRgb(0,0,0));
                }
                else
                    temp.setPixel(j,k, qRgb(255,255,255));
            }
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(imageS);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));

}

void MainWindow::on_sk_re_clicked()
{
    vector<QImage> images;
    bool flag = true;
    QImage temp;
    QImage temp1;
    temp = otsu();
    while (flag)
    {
        temp1 = subtract(temp, dilation(erosion(temp)));
        temp = erosion(temp);
        if (isempty(temp))
            flag = false;
        images.push_back(temp1);
    }
    temp1 = images[images.size()-1];
    temp = temp1;
    for (int i = images.size()-2; i >= 0; i--)
    {
        temp1 = images[i];
        temp = dilation(temp);
        for (int j = 0; j<temp.width(); j++)
        {
            for (int k = 0; k<temp.height(); k++)
            {
                if (qRed(temp1.pixel(j, k)) == 0 || qRed(temp.pixel(j, k)) == 0)
                {
                    temp.setPixel(j,k, qRgb(0,0,0));
                }
                else
                    temp.setPixel(j,k, qRgb(255,255,255));
            }
        }
        imageS = temp;
        QPixmap pixmap;
        pixmap = pixmap.fromImage(imageS);
        ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
        ui->display2->repaint();
        Sleep(100);
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(imageS);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_gr_di_clicked()
{
    QImage temp;
    temp = image1;
    for (int j = 0; j<temp.width(); j++)
    {
        for (int k = 0; k<temp.height(); k++)
        {
            int c = qGray(image1.pixel(j,k));
            temp.setPixel(j, k, qRgb(c, c, c));
        }
    }
    for (int j = 1; j<image1.width()-1; j++)
    {
        for (int k = 1; k<image1.height()-1; k++)
        {
            int max = 0;
            for (int m = -1; m<2; m++)
            {
                for (int n = -1; n<2; n++)
                {
                    max = qRed(image1.pixel(j+m, k+n))>max ? qRed(image1.pixel(j+m, k+n)):max;
                }
            }
            temp.setPixel(j, k, qRgb(max, max, max));
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(imageS);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_gr_er_clicked()
{
    QImage temp;
    temp = image1;
    for (int j = 0; j<temp.width(); j++)
    {
        for (int k = 0; k<temp.height(); k++)
        {
            int c = qGray(image1.pixel(j,k));
            temp.setPixel(j, k, qRgb(c, c, c));
        }
    }
    for (int j = 1; j<image1.width()-1; j++)
    {
        for (int k = 1; k<image1.height()-1; k++)
        {
            int min = 255;
            for (int m = -1; m<2; m++)
            {
                for (int n = -1; n<2; n++)
                {
                    min = qRed(image1.pixel(j+m, k+n))<min ? qRed(image1.pixel(j+m, k+n)):min;
                }
            }
            temp.setPixel(j, k, qRgb(min, min, min));
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(imageS);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_gr_op_clicked()
{
    QImage temp;
    temp = image1;
    for (int j = 0; j<temp.width(); j++)
    {
        for (int k = 0; k<temp.height(); k++)
        {
            int c = qGray(image1.pixel(j,k));
            temp.setPixel(j, k, qRgb(c, c, c));
        }
    }
    for (int j = 1; j<image1.width()-1; j++)
    {
        for (int k = 1; k<image1.height()-1; k++)
        {
            int min = 255;
            for (int m = -1; m<2; m++)
            {
                for (int n = -1; n<2; n++)
                {
                    min = qRed(image1.pixel(j+m, k+n))<min ? qRed(image1.pixel(j+m, k+n)):min;
                }
            }
            temp.setPixel(j, k, qRgb(min, min, min));
        }
    }
    for (int j = 1; j<image1.width()-1; j++)
    {
        for (int k = 1; k<image1.height()-1; k++)
        {
            int max = 0;
            for (int m = -1; m<2; m++)
            {
                for (int n = -1; n<2; n++)
                {
                    max = qRed(image1.pixel(j+m, k+n))>max ? qRed(image1.pixel(j+m, k+n)):max;
                }
            }
            temp.setPixel(j, k, qRgb(max, max, max));
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(imageS);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}

void MainWindow::on_gr_cl_clicked()
{
    QImage temp;
    temp = image1;
    for (int j = 0; j<temp.width(); j++)
    {
        for (int k = 0; k<temp.height(); k++)
        {
            int c = qGray(image1.pixel(j,k));
            temp.setPixel(j, k, qRgb(c, c, c));
        }
    }
    for (int j = 1; j<image1.width()-1; j++)
    {
        for (int k = 1; k<image1.height()-1; k++)
        {
            int max = 0;
            for (int m = -1; m<2; m++)
            {
                for (int n = -1; n<2; n++)
                {
                    max = qRed(image1.pixel(j+m, k+n))>max ? qRed(image1.pixel(j+m, k+n)):max;
                }
            }
            temp.setPixel(j, k, qRgb(max, max, max));
        }
    }
    for (int j = 1; j<image1.width()-1; j++)
    {
        for (int k = 1; k<image1.height()-1; k++)
        {
            int min = 255;
            for (int m = -1; m<2; m++)
            {
                for (int n = -1; n<2; n++)
                {
                    min = qRed(image1.pixel(j+m, k+n))<min ? qRed(image1.pixel(j+m, k+n)):min;
                }
            }
            temp.setPixel(j, k, qRgb(min, min, min));
        }
    }
    imageS = temp;
    QPixmap pixmap;
    pixmap = pixmap.fromImage(imageS);
    ui->display2->setPixmap(pixmap.scaled(QSize(300, 450), Qt::KeepAspectRatio));
}
