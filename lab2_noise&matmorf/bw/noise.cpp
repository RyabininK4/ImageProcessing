//
//  noise.cpp
//  bw
//
//  Created by Кирилл Рябинин on 23.03.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#include "noise.hpp"
#include <opencv2/opencv.hpp>
#include <random>

double erlang() {
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::gamma_distribution<double> distribution(2.0,4.0);
    double val = distribution(generator);
    return val;
}

Mat Noise::createNoise(const Mat &img, int amount) {
    Mat result(img.rows, img.cols, img.type());
    //Mat result = img.clone();
    for (int x = 0; x < img.rows; x++)
    {
        for(int y = 0; y < img.cols; y++)
        {
            std::cout << erlang() << std::endl;
            //std::cout << img.at<Vec3b>(x, y) << " - uchar" <<std::endl;
            //double randomValue = (int)((erlang()) * amount);
            //if (img.at<uint>(x,y) <= 255) {
            Vec3b pixel = img.at<Vec3b>(x, y);
            double coef = erlang();
            
            double blue = pixel.val[0] + coef;
            double green = pixel.val[1] + coef;
            double red = pixel.val[2] + coef;
            
            result.at<Vec3b>(x,y) = Vec3b(blue,green,red);
            //std::cout << result.at<Vec3b>(x,y) << std::endl;
            //}
        }
    }
    return result;
}

//Mat Noise::createNoise(const Mat &img) {
//    
//}

//void generateRand(int *vec, const int dim, const int size) {
//    srand((unsigned int) time(NULL));
//    int in, im;
//    im = 0;
//    
//    for (in = 0; in < dim && im < size; ++in) {
//        int rn = dim - in;
//        int rm = size - im;
//        if (rand() % rn < rm)
//            vec[im++] = in + 1;
//    }
//    assert(im == size);
//}
//
//Mat Noise::impulseNoise(const Mat &img, double noisePart, const Vec3b &color) {
//    cv::Mat result = img.clone();
//    int dim = result.rows*result.cols;
//    int sizePart = (int)(noisePart*dim);
//    int* indexs = new int [sizePart];
//    //std::default_random_engine generator;
//    //std::gamma_distribution<int> distribution(*indexs, dim);
//    //double number = distribution(generator);
//    generateRand(indexs, dim, sizePart);
//    for (int i = 0; i < sizePart; i++)
//    result.at<cv::Vec3b>(indexs[i]%result.rows, indexs[i]%(result.cols)) = color;
//    
//    delete[] indexs;
//    return result;
//}
