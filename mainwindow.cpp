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
#include<QPainter>
#include<QPaintEngine>



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
    //get the main subject image

    imagePath = QFileDialog::getOpenFileName(
                this,tr("Open File"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));
    imageObj.load(imagePath);

     w = ui->label->width();
     h = ui->label->height();



    QPixmap im2pix = QPixmap::fromImage(imageObj); //chang from image to pixmap



    ui->label->setPixmap(im2pix.scaled(w,h,Qt::KeepAspectRatio));

}

void MainWindow::on_PIXButton_clicked()
{
    imageObj.load(imagePath);  //load the imgae from the file to image object

    int width = imageObj.width();  //image width and height
    int height = imageObj.height();

     heighCount=height/stepsize;  //the number of pixels in every image after pixlisation
     widthCount=width/stepsize;


    StepInfo.resize ( widthCount+1, vector <Step> (heighCount+1) );  //resize the stepinfo vector with the number
                                                                     //of the steps "the tail"

    imageProc=imageObj;

    if (false==imageProc.isNull())
    {


        for (int i=0; i<width; i+= stepsize )    //start loop throug the step size
        {

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

                //get the avrage colour for every step

                av_Blue=sum_of__blue_elems/(stepsize*stepsize); //avrage blue
                av_Red=sum_of__red_elems/(stepsize*stepsize); //avrage red
                av_Green=sum_of__green_elems/(stepsize*stepsize); //avrage green


                   //build the color for every step from the avrege color channale

                  mean_step_color = new QColor(av_Red,av_Green,av_Blue);


                  norm_i=i/stepsize; //the number of steps in the row
                  norm_j=j/stepsize; // the number of steps im col



               Step *step = new Step(*mean_step_color, norm_i, norm_j); // new step opject



                addStep(*step, norm_i, norm_j); //add step to the step vector





                delete (step);





                QColor av_val1=qRgb(av_Red,av_Green,av_Blue);  // constract the avrage color


                for(int m=i; m <(i+stepsize); m++){
                    for(int n=j; n <(j+stepsize); n++){


                        if ( m < width && n < height)
                            imageProc.setPixelColor(m,n,av_val1); //pixelize the image
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

void MainWindow::on_horizontalSlider_valueChanged(int value) //get the step size from the user with horizontal Slider
{
    stepsize=ui->horizontalSlider->value();  //the value of the step size
    QString tmp = QString::number(stepsize);

    ui->label_2->setText(tmp);


}



void MainWindow::on_Dir_Img_clicked()
{
    ImagesFromDir = QFileDialog::getOpenFileNames(
                this,tr("Open File"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));


    for(int i=0 ; i<ImagesFromDir.size();i++ ){
        QImage *tmp = new QImage();
        tmp->load(ImagesFromDir[i]);
        allimage.append(*tmp);  // add the images from dir to vector to use as element of drawing the new image



    }

    QVector< QImage> :: iterator it; // one iterator to span the container
    for (it = allimage.begin(); it != allimage.end(); it++)
    {

        int sum_of__blue_elems_in_image = 0 ;
        int sum_of__red_elems_in_image = 0   ;
        int sum_of__green_elems_in_image = 0 ;
        int av_Blue_small = 0;
        int av_Red_small = 0;
        int av_Green_small = 0;
        int totalmean = 0;

        for (int x = 0 ; x < it->width(); x++)
        {

            for (int y = 0; y < it->height(); y++)
            {

                //get the color value from the new images


                QColor small_color(it->pixel(x,y));

                sum_of__blue_elems_in_image  += small_color.blue();
                sum_of__red_elems_in_image   += small_color.red();
                sum_of__green_elems_in_image += small_color.green();

            }

        }

        av_Blue_small=sum_of__blue_elems_in_image/(it->width()*it->height());
        av_Red_small=sum_of__red_elems_in_image/(it->width()*it->height());
        av_Green_small=sum_of__green_elems_in_image/(it->width()*it->height());


        mean_image_color = new QColor(av_Red_small,av_Green_small,av_Blue_small); //build the small image mean color

        allimagemean.append(*mean_image_color); // vector for the small image mean color

    }
}


void MainWindow::on_pixel2pic_clicked()
{

    QPainter stepPainter;
    stepPainter.begin(&imageProc);


    StepInfo.resize ( widthCount, vector <Step> (heighCount) );


            for (std::vector<std::vector<Step>>::iterator row = StepInfo.begin(); row != StepInfo.end(); row++) {

                    for ( std::vector<Step>::iterator col = row->begin(); col != row->end(); col++) {



                        QImage MatchedImage=(*col).Findmatch(allimage,allimagemean); //get the matched image                                                                
                                                                                    // between the step and the new images

                        MatchedImage = MatchedImage.scaled(stepsize,stepsize); //scale the matched image to the step size


                        QPoint point; //point build in class for x,y position

                        point.setX((*col).get_posX()*stepsize);
                        point.setY((*col).get_posY()*stepsize);


                      stepPainter.drawImage(point,MatchedImage); //Draw the Photomosaics image




                    }

                }





     QPixmap FinalImage = QPixmap::fromImage(imageProc);

     ui->label->setPixmap(FinalImage.scaled(w,h,Qt::KeepAspectRatio));

          stepPainter.end();

}




void MainWindow::on_pushButton_clicked()
{
    QString Save = QFileDialog::getSaveFileName(this, tr("Save the picture"),
                                "",
                                tr("Images (*.png *.jpeg *.jpg)"));

    imageProc.save(Save);
}


