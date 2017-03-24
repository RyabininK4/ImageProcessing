//
//  hist.cpp
//  bw
//
//  Created by Кирилл Рябинин on 22.03.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include "hist.hpp"

using namespace cv;

Hist::Hist(Mat grayImg) {
    _arrHist = new uint[256];
    
    for (int i = 0; i < 256; i++) {
        *(_arrHist + i) = 0;
    }
    
    Mat_<uchar> imgPtr = grayImg;
    for (int i =0; i < grayImg.rows; i++) {
        for (int j = 0; j < grayImg.cols; j++) {
            *(_arrHist + imgPtr(i,j))+=1;
        }
    }
    uint max = findMax();
    uint min = findMin(max);
    
    normalize(_arrHist, min, max);
    smooth(_arrHist);
    
    _first = findFirst();
    _max = findMax();
}

uint* Hist::normalize(uint* arrHist, uint min, uint max) {
    uint* result = new uint[256];
    
    for (int i = 0; i < 256; i++)
        *(result + i) = (*(arrHist + i ) - min) / (max - min);
    
    return result;
}

uint* Hist::smooth(uint* arrHist) {
    uint* result = new uint[256];
    
    for (int i = 1; i < 255; i++)
        *(result + i) = (*(arrHist + i) + *(arrHist + (i+1)) + *(arrHist + (i-1))) / 3;
    return result;
}

uint Hist::findMin(uint max) {
    uint min = 256;
    for (int i = 0; i < min; i++) {
        if (*(_arrHist + i) <= min) {
            min = *(_arrHist + i);
        }
    }
    return min;
}

uint Hist::findMax() {
    uint max = 0;
    for (int i = 0; i < 256; i++) {
        if (*(_arrHist + i) >= max) {
            max = *(_arrHist + i);
        }
    }
    return max;
}

uint Hist::findFirst() {
    uint first = 0;
    for (int i = 0; i < 256; i++)
        if (*(_arrHist + i) != 0)
            first = *(_arrHist + i);
    return first;
}

//void Hist::showHist(uint* arrHist) {
//    int lenght = 256;
//   Mat imgHist(_max, lenght, CV_8U);
//    for (int i = 0; i < 256; i++)
//        line(imgHist, Point(i, hist_h - height), Point(i, hist_h), Scalar::all(255));
//}


