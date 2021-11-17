#include <opencv2/opencv.hpp>
#include "Co-P.hpp"

CoP::CoP(int border, int quant){
    this->border = border;
    this->quant = quant;
}
CoP::~CoP(){

}

void CoP::Voting(cv::Mat *cop, cv::Point p){
    int iq, jq;
    int p_v, q_v; // value
    int count = 0;
    cv::Mat int_cop(cv::Size(quant, quant), CV_32S, cv::Scalar::all(0L));

    // Voting
    for(int jp = border; jp < (width-border); jp++){
        for(int ip = border; ip < (height-border); ip++){
            iq = ip + p.x;  jq = jp + p.y;
            if( 0<=iq && iq<width && 0<=jq && jq<height){
                p_v = (img.at<unsigned char>(jp,ip)) / (256/quant); 
                q_v = (img.at<unsigned char>(jq,iq)) / (256/quant);
                (int_cop.at<int>(p_v,q_v))++;
                count++;
            }
        }
    }

    // Normalization
    for(int j = 0; j < quant; j++){
        for(int i = 0; i < quant; i++){
            cop->at<double>(j,i) = (double)int_cop.at<int>(j,i) / (double)count;
        }
    }

    return;
}

void CoP::Make_CoP(cv::Mat img, std::vector<cv::Point> vec){
    this->img = img;
    this->width = img.cols; this->height = img.rows;

    for(cv::Point p : vec){
        cv::Mat cop(cv::Size(quant, quant), CV_64F, cv::Scalar::all(0.0)); // double
        Voting(&cop, p);
        all_cop.push_back(cop);
    }

    // Integrating co-occurrence probabilities
    unit_cop = cv::Mat(cv::Size(quant,quant), CV_64F, cv::Scalar::all(0.0));
    for(size_t i = 0; i < vec.size(); i++){
        unit_cop += all_cop.at((int)i);
    }

    return;
}

void CoP::Output_CoP(std::vector<cv::Point> vec, bool image, bool text, bool window){
    double max;
    
    if(image){
        int count = 0;
        for(cv::Point p : vec){
            cv::Mat uc_img(cv::Size(quant,quant), CV_8U);
            char o_fname[FNL];
            
            cv::minMaxLoc(all_cop.at(count), NULL, &max, NULL, NULL);
            all_cop.at(count).convertTo(uc_img, CV_8U, 255.0/max);
            sprintf(o_fname, "result/%d_%d.png", p.x, p.y);
            cv::imwrite(o_fname, uc_img);
            count++;
        }
        
        {
            cv::Mat uc_unit_img(cv::Size(quant,quant), CV_8U);
            
            cv::minMaxLoc(unit_cop, NULL, &max, NULL, NULL);
            unit_cop.convertTo(uc_unit_img, CV_8U, 255.0/max);
            cv::imwrite("result/res_gray.png", uc_unit_img);

            cv::Mat col_img;
            cv::applyColorMap(uc_unit_img, col_img, cv::COLORMAP_JET);
            cv::imwrite("result/res_col.png", col_img);
        }
    }
    if(text){
        FILE *fp;
        fp = fopen("result/1D.txt","w");
        if(fp == NULL)  return;

        for(int j = 0; j < quant; j++){
            for(int i = 0; i < quant; i++){
                fprintf(fp, "%f ", unit_cop.at<double>(j,i));
            }
        }

        fclose(fp);
    }

    if(window){
        cv::Mat preview(cv::Size(quant,quant), CV_32F);
        cv::Mat dst_preview;
        cv::minMaxLoc(unit_cop, NULL, &max, NULL, NULL);
        unit_cop.convertTo(preview, CV_32F, 1.0/max);
        cv::resize(preview, dst_preview, cv::Size(), 3.0, 3.0);

        cv::imshow("Unit Co-P", dst_preview);
        cv::waitKey(0);
    }

    return;
}