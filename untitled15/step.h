#ifndef STEP_H
#define STEP_H
#include<QVector>
#include<QImage>

class Step
{

private:

    int meancolor;


    int posX;
    int PosY;


public:

    Step(int M,int pX,int pY){
        meancolor=M;
        posX=pX;
        PosY=pY;
    }

   ~Step();

    QImage& Findmatch(QVector<int> MeanList);


};

#endif // STEP_H
