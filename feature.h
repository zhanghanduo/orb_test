//
// Created by zh on 10/19/17.
//

#ifndef FEATURE_TEST_FEATURE_H
#define FEATURE_TEST_FEATURE_H
#include <opencv2/features2d.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include <iomanip>


class feature_base
{
public:
    feature_base();
    void operations();

private:
    std::string video_path_;
    cv::VideoCapture source_;

    cv::Mat frame_;

    cv::Mat roi_;
    cv::Rect window_;

    uint32_t col, row, w, h;
    int sss_;

    cv::Ptr<cv::FeatureDetector> orb_detector_;
    cv::Ptr<cv::DescriptorExtractor> orb_extractor_;

    std::vector<cv::KeyPoint> keypoints_last_;

};


#endif //FEATURE_TEST_FEATURE_H
