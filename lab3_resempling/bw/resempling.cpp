//
//  resempling.cpp
//  bw
//
//  Created by Кирилл Рябинин on 07.04.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int Clamp(int value, int min, int max) {
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

class Resempling {
private:
    Mat image;
    Mat result;
    int coef;
public:
    Resempling(Mat *image, int coef){
        this->image = *image;
        this->coef = coef;
        this->result = Mat(coef * this->image.rows, coef * this->image.cols, CV_8UC3);
    }
    
    void resample(){
        int h, w;
        float tmp;
        float u, t;
        float d1, d2, d3, d4;
        Vec3b p1, p2, p3, p4;
        for (int j = 0; j < result.rows; j++){
            tmp = (float)(j) / (float)(result.rows - 1)*(image.rows - 1);
            h = Clamp((int)floor(tmp), 0, image.rows - 2);
            u = tmp - h;
            
            for (int i = 0; i < result.cols; i++){
                tmp = (float)(i) / (float)(result.cols - 1)*(image.cols - 1);
                w = Clamp((int)floor(tmp), 0, image.cols - 2);
                t = tmp - w;
                
                //coeff
                d1 = (1 - t) * (1 - u);
                d2 = t * (1 - u);
                d3 = t * u;
                d4 = (1 - t) * u;
                
                //near pixels
                p1 = (image.at<Vec3b>(Point(Clamp(w, 0, image.cols - 2), Clamp(h, 0, image.rows - 2))));
                p2 = (image.at<Vec3b>(Point(Clamp(w + 1, 0, image.cols - 2), Clamp(h, 0, image.rows - 2))));
                p3 = (image.at<Vec3b>(Point(Clamp(w + 1, 0, image.cols - 2), Clamp(h + 1, 0, image.rows - 2))));
                p4 = (image.at<Vec3b>(Point(Clamp(w, 0, image.cols - 2), Clamp(h + 1, 0, image.rows - 2))));
                
                //new pixel
                Vec3b component = p1 * d1 + p2 * d2 + p3 * d3 + p4 * d4;
                
                result.at<Vec3b>(Point(i, j)) = component;
            }
        }
    }
    
    void showResult() const {
        imshow("Result", result);
        cvWaitKey();
    }
};
