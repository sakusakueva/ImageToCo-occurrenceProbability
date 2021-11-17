#ifndef COP_HPP
#define COP_HPP

#include <iostream>

#define FNL 128
class CoP{

private:
    void Voting(cv::Mat *cop, cv::Point p);
public:
    int border;
    int quant;
    cv::Mat img;
    int width, height;
    
    std::vector<cv::Mat> all_cop;
    cv::Mat unit_cop; 

    void Make_CoP(cv::Mat img, std::vector<cv::Point> vec);
    void Output_CoP(std::vector<cv::Point> vec, bool image = true, bool text = true, bool window = true);

    CoP(int border, int quant);
    ~CoP();

};

#endif