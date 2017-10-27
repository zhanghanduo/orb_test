#include <iostream>
#include "lib.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main ( int argc, char** argv )
{
    if ( argc != 3 )
    {
        cout<<"usage: feature_extraction img1 img2"<<endl;
        return 1;
    }
    int cellsize = 40;
    //-- Read Image
    Mat img_1 = imread ( argv[1], CV_LOAD_IMAGE_COLOR );
    Mat img_2 = imread ( argv[2], CV_LOAD_IMAGE_COLOR );
    Mat img1_s,img2_s;
    img1_s = img_1;
    img2_s = img_2;
//    cv::Size rzSize(1260, 870);
//    cv::resize(img_1, img1_s, rzSize);
//    cv::resize(img_2, img2_s, rzSize);



    //-- Initialization
    std::vector<KeyPoint> keypoints_1, keypoints_2;
    Mat descriptors_1, descriptors_2;
    Ptr<FeatureDetector> detector = ORB::create();
    Ptr<DescriptorExtractor> descriptor = ORB::create();

    Ptr<DescriptorMatcher> matcher  = DescriptorMatcher::create ( "BruteForce-Hamming" );

    //-- 1. Detect corner position using Oriented FAST
    detector->detect ( img1_s,keypoints_1 );
    detector->detect ( img2_s,keypoints_2 );

    //-- 2. Calculate BRIEF descriptor according to the corner position
    descriptor->compute ( img1_s, keypoints_1, descriptors_1 );
    descriptor->compute ( img2_s, keypoints_2, descriptors_2 );

    Mat outimg1;
    drawKeypoints( img1_s, keypoints_1, outimg1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
    imshow("ORB feature",outimg1);

    //-- 3. Use Hamming Distance to match BRIEF descriptor
    vector<DMatch> matches;
    //BFMatcher matcher ( NORM_HAMMING );
    matcher->match ( descriptors_1, descriptors_2, matches );

    //-- 4. Filter matched points
    double min_dist=10000, max_dist=0;

    //找出所有匹配之间的最小距离和最大距离, 即是最相似的和最不相似的两组点之间的距离
    for ( int i = 0; i < descriptors_1.rows; i++ )
    {
        double dist = matches[i].distance;
        if ( dist < min_dist ) min_dist = dist;
        if ( dist > max_dist ) max_dist = dist;
    }

    printf ( "-- Max dist : %f \n", max_dist );
    printf ( "-- Min dist : %f \n", min_dist );

    //当描述子之间的距离大于两倍的最小距离时,即认为匹配有误.但有时候最小距离会非常小,设置一个经验值30作为下限.
    std::vector< DMatch > good_matches;
    for ( int i = 0; i < descriptors_1.rows; i++ )
    {
        if ( matches[i].distance <= max ( 2*min_dist, 30.0 ) )
        {
            good_matches.push_back ( matches[i] );
        }
    }
    std::cout << "Matches: " << matches.size() << " and Good matches: " << good_matches.size() << std::endl;

    //-- 第五步:绘制匹配结果
    Mat img_match;
    Mat img_goodmatch;
    drawMatches ( img1_s, keypoints_1, img2_s, keypoints_2, matches, img_match );
    drawMatches ( img1_s, keypoints_1, img2_s, keypoints_2, good_matches, img_goodmatch );
    imshow ( "all matches", img_match );
    imshow ( "matches after optimization", img_goodmatch );
    waitKey(0);

    return 0;
}