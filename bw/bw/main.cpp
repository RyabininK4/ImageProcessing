//
//  main.cpp
//  bw
//
//  Created by Кирилл Рябинин on 18.02.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    float dec1;
    float dec2;
    
    //alg1 = standart lib
    Mat standartImg = imread("/Users/ryabinin_k/Desktop/Learning/Обработка изображений/bw/1.jpg", IMREAD_GRAYSCALE);
    Mat img = imread("/Users/ryabinin_k/Desktop/Learning/Обработка изображений/bw/1.jpg");
    
    //alg2 = vaue * pix
    Mat img2 = img.clone();
    for (int i = 0; i < img.rows; i++)
        for (int j = 0; j < img.cols; j++)
        {
            Vec3b color = img.at<Vec3b>(i, j);
            
            double blue = 0.11 * color.val[0];
            double green = 0.53 * color.val[1];
            double red = 0.36 * color.val[2];
            
            img2.at<Vec3b>(i, j) = Vec3b(blue + green + red, blue + green + red, blue + green + red);
        }
    
    //alg3 = method / 3
    Mat img3 = img.clone();
    for (int i = 0; i < img.rows; i++)
        for (int j = 0; j < img.cols; j++)
        {
           Vec3b color = img.at<Vec3b>(i, j);
            
           double blue = color.val[0];
           double green = color.val[1];
           double red = color.val[2];
            
           img3.at<Vec3b>(i, j) = Vec3b((blue + green + red)/3, (blue + green + red)/3, (blue + green + red)/3);
            
        }
    
    //alg4 = max{R,G,B} 
    Mat img4 = img.clone();
    for (int i = 0; i < img.rows; i++)
        for (int j = 0; j < img.cols; j++)
        {
            Vec3b color = img.at<Vec3b>(i, j);
            
            double blue = color.val[0];
            double green = color.val[1];
            double red = color.val[2];
            
            img4.at<Vec3b>(i, j) = Vec3b(blue, blue, blue);
            
        }
    /*
    for (int i = 0; i < img.rows; i++)
        for (int j = 0; j < img.cols; j++)
        {
            dec1 = img2.at<float>(i, j);
        }
    
    for (int i = 0; i < img.rows; i++)
        for (int j = 0; j < img.cols; j++)
        {
            dec2 = img3.at<float>(i, j);
        }
     */
    
    imshow("Black and White", img4);
    waitKey(0);
    return 0;
}
