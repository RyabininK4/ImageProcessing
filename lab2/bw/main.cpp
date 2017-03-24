//
//  main.cpp
//  bw
//
//  Created by Кирилл Рябинин on 18.02.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#include "gray.cpp"
#include "MatMorphology.cpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    
    Mat img = imread("/Users/ryabinin_k/Desktop/Learning/ImageProcessing/lab2/source2.jpg");
    Mat grayImg = method1(img);
    
    //Noise noiseImg(grayImg);
    
    //Mat erosion = Morphology::erosion(img);
    //Mat dil = Morphology::dilation(img);
    //Mat open = Morphology::opening(img);
    Mat close = Morphology::closing(img);

    //imshow("erosion", erosion);
    //imshow("dil", dil);
    //imshow("open", open);
    imshow("close", close);
    waitKey(0);
    return 0;
}
