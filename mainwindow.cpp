#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"step.h"
#include<QFileDialog>
#include<QPixmap>
#include<QImage>
#include<iostream>
#include<QDir>
#include <QSlider>
#include<QDebug>



using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_OPENButton_clicked()
{

    imagePath = QFileDialog::getOpenFileName(
                this,tr("Open File"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));
    imageObj.load(imagePath);

    int w = ui->label->width();
    int h = ui->label->height();



    QPixmap im2pix = QPixmap::fromImage(imageObj); //chang from image to pixmap





    ui->label->setPixmap(im2pix.scaled(w,h,Qt::KeepAspectRatio));

}

void MainWindow::on_PIXButton_clicked()
{
    imageObj.load(imagePath);  //load the imgae from the file to image object

    int width = imageObj.width();  //image width and height
    int height = imageObj.height();

    int heighCount=height/stepsize;  //the number of pixels in every image after pixlisation
    int widthCount=width/stepsize;


    // qDebug() << heighCount << " " << widthCount <<"\n";


    imageProc=imageObj;

    if (false==imageProc.isNull())
    {


        for (int i=0; i<width; i+= stepsize )    //start loop throug the step size
        {
            //std::cout << i << "\n";
            for (int j=0; j<height; j+= stepsize )
            {
                //initilize the variable to get the color information

                int sum_of__blue_elems=0;
                int sum_of__red_elems=0;
                int sum_of__green_elems=0;
                int sum_of__alpha_elems=0;

                int av_Blue = 0;
                int av_Red = 0;
                int av_Green = 0;
                int av_Alpha = 0;
                int one_mean = 0;




                for (int x = i ; x < (i+stepsize); x++) // loop over the pixel in the step size  to get the color value
                {
                    for (int y = j; y < (j+stepsize); y++)
                    {


                        if ( x < width && y < height )
                        {
                            QColor color(imageProc.pixel(x,y));

                            sum_of__blue_elems  += color.blue();
                            sum_of__red_elems   += color.red();
                            sum_of__green_elems += color.green();
                            sum_of__alpha_elems += color.alpha();
                        }

                    }

                }

                av_Blue=sum_of__blue_elems/(stepsize*stepsize);
                av_Red=sum_of__red_elems/(stepsize*stepsize);
                av_Green=sum_of__green_elems/(stepsize*stepsize);
                av_Alpha=sum_of__alpha_elems/(stepsize*stepsize);

                one_mean=(av_Blue+av_Red+av_Green+av_Alpha)/4;

                qDebug()<<"the mean color in the step" << one_mean<<"\n";



                norm_i=i/stepsize;
                norm_j=j/stepsize;



              //  Step *step = new Step(one_mean,norm_i,norm_j);

               qDebug()<<"the pos of the step"<<norm_i<<" "<<norm_j<<"\n";

               // addStep(*step,norm_i,norm_j);
              //  StepInfo[norm_i][norm_j];
               get_step_value(norm_i,norm_j);


               // delete (step);










                QColor av_val1=qRgba(av_Red,av_Green,av_Blue,av_Alpha);  // constract the avrage color


                for(int m=i; m <(i+stepsize); m++){
                    for(int n=j; n <(j+stepsize); n++){


                        if ( m < width && n < height)
                            imageProc.setPixelColor(m,n,av_val1);
                    }
                }
            }
        }
    }


    int w = ui->label->width();
    int h = ui->label->height();




    QPixmap test2 = QPixmap::fromImage(imageProc); //chang from image to pixmap



    ui->label->setPixmap(test2.scaled(w,h,Qt::KeepAspectRatio));



}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    stepsize=ui->horizontalSlider->value();
}



void MainWindow::on_Dir_Img_clicked()
{
    ImagesFromDir = QFileDialog::getOpenFileNames(
                this,tr("Open File"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));

    QVector<QImage> allimage;


    for(int i=0 ; i<ImagesFromDir.size();i++ ){
        QImage *tmp = new QImage();
        tmp->load(ImagesFromDir[i]);
        allimage.append(*tmp);


    }

    QVector< QImage> :: iterator it; // one iterator to span the container
    for (it = allimage.begin(); it != allimage.end(); it++)
    {

        int sum_of__blue_elems_in_image  ;
        int sum_of__red_elems_in_image   ;
        int sum_of__green_elems_in_image ;
        int sum_of__alpha_elems_in_image ;
        int av_Blue_small ;
        int av_Red_small;
        int av_Green_small;
        int av_Alpha_small;
        int totalmean;

        for (int x = 0 ; x < it->width(); x++)
        {
            for (int y = 0; y < it->height(); y++)
            {




                QColor small_color(it->pixel(x,y));

                sum_of__blue_elems_in_image  += small_color.blue();
                sum_of__red_elems_in_image   += small_color.red();
                sum_of__green_elems_in_image += small_color.green();
                sum_of__alpha_elems_in_image += small_color.alpha();


            }

        }

        av_Blue_small=sum_of__blue_elems_in_image/(it->width()*it->height());
        av_Red_small=sum_of__red_elems_in_image/(it->width()*it->height());
        av_Green_small=sum_of__green_elems_in_image/(it->width()*it->height());
        av_Alpha_small=sum_of__alpha_elems_in_image/(it->width()*it->height());

        totalmean=(av_Alpha_small+av_Blue_small+av_Green_small+av_Red_small)/4;

        allimagemean.append(totalmean);

      //  qDebug()<<totalmean;


    }
}

