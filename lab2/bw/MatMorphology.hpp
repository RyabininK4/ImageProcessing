//
//  MatMorphology.hpp
//  bw
//
//  Created by Кирилл Рябинин on 24.03.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#ifndef MatMorphology_hpp
#define MatMorphology_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

const size_t SIZE = 3;

namespace Morphology {
    Mat erosion(const Mat& img); //сужение
    Mat dilation(const Mat& img); //расширирение
    
    Mat opening(const Mat& img); //открытие
    Mat closing(const Mat& img); //закрытие
    
    static int mask[SIZE][SIZE] = {{1,1,1}, {1,1,1}, {1,1,1}};
    
};

#endif /* MatMorphology_hpp */
