#include "step.h"
#include <QDebug>
#include<iostream>
#include<vector>
#include<QPainter>
#include<math.h>
#include <algorithm>

Step :: Step(){

}
Step :: ~Step(){

}


QImage Step::Findmatch(QVector<QImage> Dirpic, QVector<QColor> Dirpicmean){


    QImage match;

    int Red_from_step=meancolor.red();
    int Green_from_step=meancolor.green();
    int Blue_from_step=meancolor.blue();

    int Red_from_image = 0;
    int Green_from_image = 0;
    int Blue_from_image = 0;

    int R_distance = 0;
    int G_distance = 0;
    int B_distance = 0;

    int tempmatch = 255*3;



    QVector<QColor>::iterator it = Dirpicmean.begin();
    QVector<QImage>::iterator itimg = Dirpic.begin();
    for(it, itimg; it != Dirpicmean.end(), itimg != Dirpic.end(); it++,itimg++) {  //this loop technic from by Antoin advice


        Red_from_image=it->red();
        Green_from_image=it->green();
        Blue_from_image=it->blue();



        R_distance = abs(Red_from_image-Red_from_step);
        G_distance = abs(Green_from_image-Green_from_step);
        B_distance = abs(Blue_from_image-Blue_from_step);

      ColorDistance=R_distance+G_distance+B_distance;


            if(ColorDistance<tempmatch){
                   tempmatch = ColorDistance;
                    match = *itimg;
                    tempmatch++;}
        }





    return match;


}

