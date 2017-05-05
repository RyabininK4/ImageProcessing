//
//  main.cpp
//  bw
//
//  Created by Кирилл Рябинин on 18.02.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#include "gray.cpp"
#include "histogram.cpp"
#include "transferBW.cpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    
    Mat img = imread("/Users/ryabinin_k/Desktop/Learning/Обработка изображений/Triangle Method (lab1)/vova.jpg");
    Mat grayImg = method1(img);
    Mat mynew;
    
    //GaussianBlur(grayImg, mynew, Size(7,7), 0);
    //medianBlur(grayImg, mynew, 5);
    //bilateralFilter(grayImg, mynew, 3, 6, 1);

    Mat hist = getHist(grayImg);
    
    Mat_<uchar> ptr = hist;
    Mat_<uchar> GrayPtr = grayImg;
    
    uint *histArr = new uint[255];
    
    // init arr and filling from gray image
    initHistArr(histArr);
    fillArrayWithValuesFromGI(histArr, grayImg);
    
    // the declaration of the flags of the describing min an max
    uint leftFlag = 256, rightFlag = 0;
    findMaxValueInHistArrayAndFixIndex(histArr, &leftFlag);
    findMinValueInHistArrayAndFixIndex(histArr, &rightFlag);
    
    // declarate
    ushort barrierObtainedByTheMethodOfTheTriangle = -1;
    ushort SimpleBarrier = (rightFlag+leftFlag)/2;
    
    cout << rightFlag << " - right flag" << endl;
    cout << leftFlag << " - left flag" <<endl;
    cout << SimpleBarrier << " - simple barrier" << endl;

    
    barrierObtainedByTheMethodOfTheTriangle = findMaxDistanceFromLineToSomePoint(leftFlag, rightFlag, histArr);
    
    if ( checkCorrect(barrierObtainedByTheMethodOfTheTriangle,0,255)) {
        cout<<barrierObtainedByTheMethodOfTheTriangle<<" - unknownBarrier"<<endl;
    }
    else {
        cout<<"Wrong barrier"<<endl;
    }
    // declarate new mat to save new binary images
    Mat CoolBlackAndWhiteImage,SimpleBlackAndWhiteImage;
    
    grayImg.copyTo(CoolBlackAndWhiteImage);
    grayImg.copyTo(SimpleBlackAndWhiteImage);
    Mat_<uchar> blackAndWhiteImagePtr = CoolBlackAndWhiteImage;
    Mat_<uchar> SimpleBlackAndWhiteImagePtr = SimpleBlackAndWhiteImage;
    
    ConvertImageToBinaryWithBarrier(CoolBlackAndWhiteImage,barrierObtainedByTheMethodOfTheTriangle);
    ConvertImageToBinaryWithBarrier(SimpleBlackAndWhiteImage,SimpleBarrier);
    
    
    // show the pixels of the difference in 2 different methods
    compareTwoMat(CoolBlackAndWhiteImage,SimpleBlackAndWhiteImage);
    
    imshow("hist", hist);
    imshow("TriangleMethod", CoolBlackAndWhiteImage);
    imshow("StandartThresholdFilter",SimpleBlackAndWhiteImage);
    waitKey(0);
    return 0;
}
