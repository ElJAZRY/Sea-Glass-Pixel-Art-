#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"step.h"
#include <cassert>
#include<QPixmap>
#include<QImage>
#include<vector>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //void addStep(Step s, int i, int j){assert ( i <= n_row && j <= n_colom ); StepInfo[i][j] = s; }

    std::vector<std::vector<Step>> StepInfo; // vector to get the step data
    get_step_value (int i, int j)    { assert ( i < norm_i && j < norm_j ); return StepInfo[i][j]; }

private slots:

    void on_OPENButton_clicked();

    void on_PIXButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_Dir_Img_clicked();

private:
    Ui::MainWindow *ui;
    QString imagePath;
    QImage imageObj;
    QImage imageProc;
    QStringList ImagesFromDir;
    int stepsize;
    int norm_i;
    int norm_j;
    QVector<int> allimagemean;
    std :: vector < std :: vector < int > > StepInfo;


};

#endif // MAINWINDOW_H
