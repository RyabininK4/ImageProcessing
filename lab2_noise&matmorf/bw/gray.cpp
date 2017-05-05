//
//  gray.cpp
//  bw
//
//  Created by Кирилл Рябинин on 02.03.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

//Method 1 = standart lib
//Mat standartImg = imread("/Users/ryabinin_k/Desktop/Learning/Обработка изображений/bw/1.jpg", IMREAD_GRAYSCALE);

//Method 1 = value * pix
Mat method1(Mat& img) {
    Mat result = img.clone();

        for (int i = 0; i < img.rows; i++)
            for (int j = 0; j < img.cols; j++)
            {
                Vec3b color = img.at<Vec3b>(i, j);
    
                double blue = 0.11 * color.val[0];
                double green = 0.53 * color.val[1];
                double red = 0.36 * color.val[2];
    
                result.at<Vec3b>(i, j) = Vec3b(blue + green + red, blue + green + red, blue + green + red);
            }
    return result;
}

//Method 2 = method / 3
Mat method2(Mat& img) {
    Mat result = img.clone();
    for (int i = 0; i < img.rows; i++)
        for (int j = 0; j < img.cols; j++)
        {
            Vec3b color = img.at<Vec3b>(i, j);
    
            double blue = color.val[0];
            double green = color.val[1];
            double red = color.val[2];
    
            result.at<Vec3b>(i, j) = Vec3b((blue + green + red)/3, (blue + green + red)/3, (blue + green + red)/3);
        }
    return result;
}

//Method 3 = max{R,G,B}
Mat method3(Mat& img) {
    Mat result = img.clone();
    for (int i = 0; i < img.rows; i++)
        for (int j = 0; j < img.cols; j++)
        {
            Vec3b color = img.at<Vec3b>(i, j);
            double blue = color.val[0];
    
            result.at<Vec3b>(i, j) = Vec3b(blue, blue, blue);
        }
    return result;
}

