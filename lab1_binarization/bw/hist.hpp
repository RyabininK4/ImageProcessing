//
//  hist.hpp
//  bw
//
//  Created by Кирилл Рябинин on 22.03.17.
//  Copyright © 2017 Кирилл Рябинин. All rights reserved.
//

#ifndef hist_hpp
#define hist_hpp

#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;

class Hist {
public:
    Hist(Mat grayImg);
    void getHist();
    void showHist(uint* arrHist);
    uint getMin() { return _min; }
    uint getMax() { return _max; }
private:
    uint findMin(uint max);
    uint findMax();
    uint findFirst();
    uint* normalize(uint* arrHist, uint min, uint max);
    uint* smooth(uint* arrHist);
    uint _first, _min, _max;
    uint *_arrHist;
    
};

#endif /* hist_hpp */
