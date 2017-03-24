//
//  noise.cpp
//  bw
//
//  Created by Кирилл Рябинин on 23.03.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#include "noise.hpp"
#include <opencv2/opencv.hpp>

Noise::Noise(Mat& img): _img(img) {
    
}

Mat Noise::getNoiseImg() {
    return _img;
}
