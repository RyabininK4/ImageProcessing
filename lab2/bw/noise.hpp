//
//  noise.hpp
//  bw
//
//  Created by Кирилл Рябинин on 23.03.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#ifndef noise_hpp
#define noise_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

class Noise {
public:
    Noise(Mat& img);
    Mat getNoiseImg();
    Mat createNoise(Mat &mat, double n, Vec3b &color);
private:
    Mat _img;
};

#endif /* noise_hpp */
