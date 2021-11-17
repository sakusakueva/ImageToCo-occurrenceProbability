#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <opencv2/opencv.hpp>
#include "Co-P.hpp"

#define FNL 128

int main(int argc,char **argv){
    cv::Mat i_img;
    char i_fname[FNL];
    int border;
    int quant = 64; // Quantization level (max:256)
    std::vector<cv::Point> vec;
    int d[] = {1, 2, 4, 8, 16}; // Must be in ascending order
    border = d[(sizeof(d) / sizeof(d[0])-1)]; // Set the last element


	for(int idx = 1 ; idx < argc ; idx++ ){
		if(!strcmp( argv[idx], "-i")) strcpy( i_fname, argv[++idx] );
        else if(!strcmp( argv[idx], "-q")) quant = atoi(argv[++idx]);
	}

    i_img = cv::imread(i_fname, cv::IMREAD_GRAYSCALE);
    if(i_img.empty())   return -1;

    for(int i : d){
        vec.push_back(cv::Point(i, 0)); // Horizontal
        vec.push_back(cv::Point(0, i)); // Vertical
    }

    CoP cop(border, quant);
    cop.Make_CoP(i_img, vec);
    cop.Output_CoP(vec, true, true, false);

    return 0;
}