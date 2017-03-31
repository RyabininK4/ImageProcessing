//
//  main.cpp
//  bw
//
//  Created by Кирилл Рябинин on 18.02.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#include "gray.cpp"
#include "MatMorphology.cpp"
#include "noise.cpp"
#include "histogram.cpp"
#include <random>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    
    Mat img = imread("/Users/ryabinin_k/Desktop/Learning/ImageProcessing/lab2/test.jpg");
    //Mat grayImg = method1(noise);
    
    //Noise noiseImg(grayImg);
    //Mat out = Noise::impulseNoise(grayImg, 0.3, cv::Vec3b(0,0,0));
    
    //Mat hist = getHist(img);
    
    Mat noise = Noise::createNoise(img, 255);
    Mat grayImg = method1(noise);
    Mat hist = getHist(grayImg);
    //Mat erosion = Morphology::erosion(img);
    //Mat dil = Morphology::dilation(img);
    //Mat open = Morphology::opening(img);
    //Mat close = Morphology::closing(img);

    //imshow("out", out);
    //imshow("erosion", erosion);
    //imshow("dil", dil);
    //imshow("open", open);
    imshow("hist", hist);
    //imshow("close", close);
    imshow("standart", img);
    imshow("noise", noise);
    waitKey(0);
    return 0;
}
