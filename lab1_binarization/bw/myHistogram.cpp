//
//  myHistogram.cpp
//  bw
//
//  Created by Кирилл Рябинин on 03.03.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

Histogram(const Mat& mat);

const Vec3b Histogram::BLACK = Vec3b(0,0,0);
const Vec3b Histogram::WHITE = Vec3b(255,255,255);
