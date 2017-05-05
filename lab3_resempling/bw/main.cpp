//
//  main.cpp
//  bw
//
//  Created by Кирилл Рябинин on 18.02.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "resempling.cpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat image = imread("/Users/ryabinin_k/Downloads/plus.jpg");
    imshow("standart", image);
    Resempling result = Resempling(&image, 16);
    result.resample();
    result.showResult();
    getchar();
    return 0;
}
