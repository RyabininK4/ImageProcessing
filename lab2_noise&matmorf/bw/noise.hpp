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

namespace Noise {
    //Mat impulseNoise(const Mat &mat, double noisePart, const Vec3b &color);
    Mat createNoise(const Mat &img, int amount);
};

#endif /* noise_hpp */
