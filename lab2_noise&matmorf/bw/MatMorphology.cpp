//
//  MatMorphology.cpp
//  bw
//
//  Created by Кирилл Рябинин on 24.03.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#include "MatMorphology.hpp"
#include <iostream>

Mat Morphology::erosion(const Mat &img) {
    Mat result(img.rows, img.cols, img.type());
    int val = SIZE / 2;
    
    for (int x = val; x < img.rows - val; x++)
        for(int y = val; y < img.cols - val; y++) {
            
          Vec3b min(255,255,255);
            
          for (int i = -val; i <= val; i++)
            for (int j = -val; j <= val; j++) {
                Vec3b pixel = img.at<Vec3b>(x + i, y + j);
                    
                if (mask[i + val][j + val] != 0 && pixel.val[0] < min.val[0] && pixel.val[1] < min.val[1] && pixel.val[2] < min.val[2])
                    min = pixel;
            }
            result.at<Vec3b>(x,y) = min;
        }
    return result;
}

Mat Morphology::dilation(const Mat &img) {
    Mat result(img.rows, img.cols, img.type());
    int val = SIZE / 2;
    
    for (int x = val; x < img.rows - val; x++)
        for(int y = val; y < img.cols - val; y++) {
            
            Vec3b max(0,0,0);
            
            for (int i = -val; i <= val; i++)
                for (int j = -val; j <= val; j++) {
                    Vec3b pixel = img.at<Vec3b>(x + i, y + j);
                    
                    if (mask[i + val][j + val] != 0 && pixel.val[0] > max.val[0] && pixel.val[1] > max.val[1] && pixel.val[2] > max.val[2])
                        max = pixel;
                }
            result.at<Vec3b>(x,y) = max;
        }
    return result;
}

Mat Morphology::opening(const Mat &img) {
    Mat result = Morphology::erosion(img);
    return Morphology::dilation(result);
}

Mat Morphology::closing(const Mat &img) {
    Mat result = Morphology::dilation(img);
    return Morphology::erosion(result);
}
