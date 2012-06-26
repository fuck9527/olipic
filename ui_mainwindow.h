/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Jun 12 12:17:16 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *select;
    QLabel *display;
    QLabel *display2;
    QFrame *line;
    QLabel *label;
    QPushButton *saveAs;
    QFrame *line_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_2;
    QPushButton *genHis;
    QLabel *histogram;
    QSlider *setThr;
    QSpinBox *setThrM;
    QLabel *label_3;
    QPushButton *otsu;
    QPushButton *entropy;
    QLabel *label_9;
    QWidget *widget;
    QPushButton *roberts;
    QPushButton *prewitt;
    QPushButton *sobel;
    QPushButton *gaus;
    QPushButton *mean;
    QPushButton *medi;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *tab_3;
    QPushButton *invert;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *combine;
    QLabel *display3;
    QLabel *label_8;
    QPushButton *nearest;
    QPushButton *bilinear;
    QWidget *tab_2;
    QPushButton *bi_di;
    QPushButton *bi_er;
    QPushButton *bi_op;
    QPushButton *bi_cl;
    QPushButton *di_tr;
    QPushButton *skel;
    QPushButton *sk_re;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *gr_di;
    QPushButton *gr_er;
    QPushButton *gr_op;
    QPushButton *gr_cl;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(1130, 540);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1130, 540));
        MainWindow->setMaximumSize(QSize(1130, 540));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        select = new QPushButton(centralWidget);
        select->setObjectName(QString::fromUtf8("select"));
        select->setGeometry(QRect(80, 30, 191, 31));
        display = new QLabel(centralWidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(30, 70, 300, 450));
        display->setMinimumSize(QSize(300, 450));
        display->setMaximumSize(QSize(300, 450));
        display2 = new QLabel(centralWidget);
        display2->setObjectName(QString::fromUtf8("display2"));
        display2->setGeometry(QRect(390, 70, 300, 450));
        display2->setMinimumSize(QSize(300, 450));
        display2->setMaximumSize(QSize(300, 450));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(350, 10, 20, 521));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(450, 50, 181, 20));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        label->setFont(font);
        saveAs = new QPushButton(centralWidget);
        saveAs->setObjectName(QString::fromUtf8("saveAs"));
        saveAs->setGeometry(QRect(460, 10, 141, 31));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(710, 10, 20, 521));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(730, 10, 391, 521));
        tabWidget->setMouseTracking(false);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 390, 311, 16));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        genHis = new QPushButton(tab);
        genHis->setObjectName(QString::fromUtf8("genHis"));
        genHis->setGeometry(QRect(40, 20, 171, 51));
        histogram = new QLabel(tab);
        histogram->setObjectName(QString::fromUtf8("histogram"));
        histogram->setGeometry(QRect(40, 110, 261, 261));
        setThr = new QSlider(tab);
        setThr->setObjectName(QString::fromUtf8("setThr"));
        setThr->setGeometry(QRect(40, 420, 261, 16));
        setThr->setMaximum(255);
        setThr->setOrientation(Qt::Horizontal);
        setThrM = new QSpinBox(tab);
        setThrM->setObjectName(QString::fromUtf8("setThrM"));
        setThrM->setGeometry(QRect(310, 410, 55, 31));
        setThrM->setMaximum(255);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 90, 91, 16));
        label_3->setFont(font1);
        otsu = new QPushButton(tab);
        otsu->setObjectName(QString::fromUtf8("otsu"));
        otsu->setGeometry(QRect(90, 450, 84, 31));
        entropy = new QPushButton(tab);
        entropy->setObjectName(QString::fromUtf8("entropy"));
        entropy->setGeometry(QRect(190, 450, 84, 31));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 454, 41, 21));
        label_9->setFont(font1);
        tabWidget->addTab(tab, QString());
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        roberts = new QPushButton(widget);
        roberts->setObjectName(QString::fromUtf8("roberts"));
        roberts->setGeometry(QRect(40, 70, 141, 41));
        prewitt = new QPushButton(widget);
        prewitt->setObjectName(QString::fromUtf8("prewitt"));
        prewitt->setGeometry(QRect(40, 120, 141, 41));
        sobel = new QPushButton(widget);
        sobel->setObjectName(QString::fromUtf8("sobel"));
        sobel->setGeometry(QRect(40, 170, 141, 41));
        gaus = new QPushButton(widget);
        gaus->setObjectName(QString::fromUtf8("gaus"));
        gaus->setGeometry(QRect(40, 260, 141, 41));
        mean = new QPushButton(widget);
        mean->setObjectName(QString::fromUtf8("mean"));
        mean->setGeometry(QRect(40, 310, 141, 41));
        medi = new QPushButton(widget);
        medi->setObjectName(QString::fromUtf8("medi"));
        medi->setGeometry(QRect(40, 360, 141, 41));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 50, 101, 16));
        label_4->setFont(font1);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 240, 51, 16));
        label_5->setFont(font1);
        tabWidget->addTab(widget, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        invert = new QPushButton(tab_3);
        invert->setObjectName(QString::fromUtf8("invert"));
        invert->setGeometry(QRect(40, 30, 141, 41));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 10, 59, 15));
        label_6->setFont(font1);
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 90, 81, 16));
        label_7->setFont(font1);
        combine = new QPushButton(tab_3);
        combine->setObjectName(QString::fromUtf8("combine"));
        combine->setGeometry(QRect(40, 110, 141, 41));
        display3 = new QLabel(tab_3);
        display3->setObjectName(QString::fromUtf8("display3"));
        display3->setGeometry(QRect(40, 160, 311, 201));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 380, 241, 16));
        label_8->setFont(font1);
        nearest = new QPushButton(tab_3);
        nearest->setObjectName(QString::fromUtf8("nearest"));
        nearest->setGeometry(QRect(40, 400, 141, 41));
        bilinear = new QPushButton(tab_3);
        bilinear->setObjectName(QString::fromUtf8("bilinear"));
        bilinear->setGeometry(QRect(210, 400, 141, 41));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        bi_di = new QPushButton(tab_2);
        bi_di->setObjectName(QString::fromUtf8("bi_di"));
        bi_di->setGeometry(QRect(30, 40, 141, 41));
        bi_er = new QPushButton(tab_2);
        bi_er->setObjectName(QString::fromUtf8("bi_er"));
        bi_er->setGeometry(QRect(200, 40, 141, 41));
        bi_op = new QPushButton(tab_2);
        bi_op->setObjectName(QString::fromUtf8("bi_op"));
        bi_op->setGeometry(QRect(30, 100, 141, 41));
        bi_cl = new QPushButton(tab_2);
        bi_cl->setObjectName(QString::fromUtf8("bi_cl"));
        bi_cl->setGeometry(QRect(200, 100, 141, 41));
        di_tr = new QPushButton(tab_2);
        di_tr->setObjectName(QString::fromUtf8("di_tr"));
        di_tr->setGeometry(QRect(30, 160, 311, 41));
        skel = new QPushButton(tab_2);
        skel->setObjectName(QString::fromUtf8("skel"));
        skel->setGeometry(QRect(30, 220, 311, 41));
        sk_re = new QPushButton(tab_2);
        sk_re->setObjectName(QString::fromUtf8("sk_re"));
        sk_re->setGeometry(QRect(30, 280, 311, 41));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 20, 101, 16));
        label_10->setFont(font1);
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 340, 101, 16));
        label_11->setFont(font1);
        gr_di = new QPushButton(tab_2);
        gr_di->setObjectName(QString::fromUtf8("gr_di"));
        gr_di->setGeometry(QRect(30, 360, 141, 41));
        gr_er = new QPushButton(tab_2);
        gr_er->setObjectName(QString::fromUtf8("gr_er"));
        gr_er->setGeometry(QRect(200, 360, 141, 41));
        gr_op = new QPushButton(tab_2);
        gr_op->setObjectName(QString::fromUtf8("gr_op"));
        gr_op->setGeometry(QRect(30, 420, 141, 41));
        gr_cl = new QPushButton(tab_2);
        gr_cl->setObjectName(QString::fromUtf8("gr_cl"));
        gr_cl->setGeometry(QRect(200, 420, 141, 41));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        select->setText(QApplication::translate("MainWindow", "select a picture", 0, QApplication::UnicodeUTF8));
        display->setText(QString());
        display2->setText(QString());
        label->setText(QApplication::translate("MainWindow", "preview of the changed:", 0, QApplication::UnicodeUTF8));
        saveAs->setText(QApplication::translate("MainWindow", "save as...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "set the threshold and change to 2-value:", 0, QApplication::UnicodeUTF8));
        genHis->setText(QApplication::translate("MainWindow", "change to gray &&\n"
" generate histogram", 0, QApplication::UnicodeUTF8));
        histogram->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "histogram:", 0, QApplication::UnicodeUTF8));
        otsu->setText(QApplication::translate("MainWindow", "otsu", 0, QApplication::UnicodeUTF8));
        entropy->setText(QApplication::translate("MainWindow", "entropy", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "auto:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "gray && 2-value", 0, QApplication::UnicodeUTF8));
        roberts->setText(QApplication::translate("MainWindow", "Roberts operator ", 0, QApplication::UnicodeUTF8));
        prewitt->setText(QApplication::translate("MainWindow", "Prewitt operator", 0, QApplication::UnicodeUTF8));
        sobel->setText(QApplication::translate("MainWindow", "Sobel operator", 0, QApplication::UnicodeUTF8));
        gaus->setText(QApplication::translate("MainWindow", "Gaussian", 0, QApplication::UnicodeUTF8));
        mean->setText(QApplication::translate("MainWindow", "mean", 0, QApplication::UnicodeUTF8));
        medi->setText(QApplication::translate("MainWindow", "median", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "edge detect:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "fliter:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(widget), QApplication::translate("MainWindow", "edge detect && filter", 0, QApplication::UnicodeUTF8));
        invert->setText(QApplication::translate("MainWindow", "invert", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "point:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "algebraic:", 0, QApplication::UnicodeUTF8));
        combine->setText(QApplication::translate("MainWindow", "combine...", 0, QApplication::UnicodeUTF8));
        display3->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "geometric(3 times the size):", 0, QApplication::UnicodeUTF8));
        nearest->setText(QApplication::translate("MainWindow", "nearest neighbour", 0, QApplication::UnicodeUTF8));
        bilinear->setText(QApplication::translate("MainWindow", "bilinear", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "basic operation", 0, QApplication::UnicodeUTF8));
        bi_di->setText(QApplication::translate("MainWindow", "dilation", 0, QApplication::UnicodeUTF8));
        bi_er->setText(QApplication::translate("MainWindow", "erosion", 0, QApplication::UnicodeUTF8));
        bi_op->setText(QApplication::translate("MainWindow", "opening", 0, QApplication::UnicodeUTF8));
        bi_cl->setText(QApplication::translate("MainWindow", "closing", 0, QApplication::UnicodeUTF8));
        di_tr->setText(QApplication::translate("MainWindow", "morphological distance transform", 0, QApplication::UnicodeUTF8));
        skel->setText(QApplication::translate("MainWindow", "morphological skeleton", 0, QApplication::UnicodeUTF8));
        sk_re->setText(QApplication::translate("MainWindow", "morphological skeleton restoration", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "binary:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "grayscale:", 0, QApplication::UnicodeUTF8));
        gr_di->setText(QApplication::translate("MainWindow", "dilation", 0, QApplication::UnicodeUTF8));
        gr_er->setText(QApplication::translate("MainWindow", "erosion", 0, QApplication::UnicodeUTF8));
        gr_op->setText(QApplication::translate("MainWindow", "opening", 0, QApplication::UnicodeUTF8));
        gr_cl->setText(QApplication::translate("MainWindow", "closing", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "morphology", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
