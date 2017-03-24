//
//  histogram.cpp
//  bw
//
//  Created by Кирилл Рябинин on 02.03.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;



Mat getHist(Mat& img) {
    Mat hist;
    
    int bins = 256;
    int histSize[] = {bins};
    int channels[] = {0};
    float lranges[] = {0, 256};
    const float* ranges[] = {lranges};
    
    calcHist(&img, 1, channels, Mat(), hist, 1, histSize, ranges);
    
    double max_val = 0;
    minMaxLoc(hist, 0, &max_val);
    
    int hist_h = 256;
    Mat imgHist(hist_h, bins, CV_8U);
    
    for(int b = 0; b < bins; b++) {
        const float binVal = hist.at<float>(b);
        const int height = cvRound(binVal * hist_h / max_val);
        
        line(imgHist, Point(b, hist_h - height), Point(b, hist_h), Scalar::all(255));
    }
    
    return imgHist;
}
