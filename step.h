#ifndef STEP_H
#define STEP_H
#include<QVector>
#include<QImage>

class Step
{

private:

    int posX; //the step  X position for constract the step object
    int posY; //the step  Y position for constract the step object


public:

    Step();

    Step(QColor C,int pX,int pY){  //constructor with input the mean color and the X,Y position
        meancolor=C;
        posX=pX;
        posY=pY;
    }

   ~Step(); //destructor

    QColor getmean(Step s) //this function to get the mean color for step "s"
    {

         return meancolor;
    }

    /*
    matching function with input the tail images
    and the mean value of those image and it will
    access the mean color form the step object and
    mathch from the main color vector the matched
    value position will be the position for the matched image
    */
    QImage Findmatch(QVector<QImage> Dirpic, QVector<QColor> Dirpicmean);



     QColor meancolor;  //step -tail- main color
     int get_posX(){return posX;} //get the X postion from the privet attribute of the class
     int get_posY(){return posY;} //get the Y postion from the privet attribute of the class

     int ColorDistance; // the Euclidean RGB color distance


};

#endif // STEP_H
