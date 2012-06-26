#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<map>
using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QImage dilation(QImage image);

    QImage erosion(QImage image);

    QImage subtract(QImage imagea, QImage imageb);

    QImage setgray(QImage image, int gray);

    bool isempty(QImage image);

    QImage otsu();

private slots:
    void on_select_clicked();
    void on_genHis_clicked();
    void on_saveAs_clicked();
    void on_setThr_valueChanged(int value);
    void on_setThrM_valueChanged(int arg1);

    void on_roberts_clicked();

    void on_prewitt_clicked();

    void on_sobel_clicked();

    void on_gaus_clicked();

    void on_mean_clicked();

    void on_medi_clicked();

    void on_invert_clicked();

    void on_combine_clicked();

    void on_nearest_clicked();

    void on_bilinear_clicked();

    void on_otsu_clicked();

    void on_entropy_clicked();

    void on_bi_di_clicked();

    void on_bi_er_clicked();

    void on_bi_op_clicked();

    void on_bi_cl_clicked();

    void on_di_tr_clicked();


    void on_skel_clicked();

    void on_sk_re_clicked();

    void on_gr_di_clicked();

    void on_gr_er_clicked();

    void on_gr_op_clicked();

    void on_gr_cl_clicked();

private:
    Ui::MainWindow *ui;
    map<int, int> his;  //histogram
    QImage image1;  //source
    QImage imageS;  //final
    QImage imageT;  //temp
};

#endif // MAINWINDOW_H
