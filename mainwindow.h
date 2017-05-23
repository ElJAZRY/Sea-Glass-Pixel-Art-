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

    void addStep(Step s, int i, int j)   //add step object into the StepInfo vector
    {if ( i <= widthCount && j <= heighCount )  //[i][j] will be the position of every step from the main image
        {
            StepInfo[i][j] = s; }}



    void resize_StepInfo () { StepInfo.resize(widthCount, std::vector < Step > (heighCount)); } //resize the StepInfo vector

    Step *step = new Step(one_mean,norm_i,norm_j); //constract new step object

    QColor *mean_image_color;






private slots:

    void on_OPENButton_clicked();

    void on_PIXButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_Dir_Img_clicked();

    void on_pixel2pic_clicked();

    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    QString imagePath;       // main image path
    QImage imageObj;        // main image
    QImage imageProc;      //image used for proccesing
    QStringList ImagesFromDir;      //tail image path
    int w ;                 //label width to fit the image
    int h ;                //label hight to fit the image
    int stepsize;         //the step size for pixelisation
    int norm_i;          //position of the step in col
    int norm_j;         //position of the step in raw
    int heighCount;      //number of step
    int widthCount;     //number of step
    int one_mean;        //mean color value in step
    QColor *mean_step_color; //mean color in step

    QVector<QImage> allimage;   //vector have all the image in the dir
    QVector<QColor> allimagemean; //vector have all the mean color of the image from dir
    std::vector<std::vector<Step>> StepInfo; // vector to get the step data



};

#endif // MAINWINDOW_H
