//
// Created by zh on 10/19/17.
//
#include "feature.h"
#include "lib.h"
#include <Eigen/Dense>
#include "Eigen/Core"
#include "Eigen/Geometry"

//namespace mvo{
//
//    struct Feature;
//
//    typedef std::list<Feature*> Features;//特征list
//    typedef std::vector<cv::Mat> ImgPyr;//图像金字塔
//
//    /**	定义帧，保证帧的唯一性
//     */
//    class Frame : public Noncopyable
//    {
//    public:
//        /**	帧的实例化，通过传入相机参数，获得的当前帧，及时间戳来确定
//         */
//        Frame(AbstractCamera* cam, const cv::Mat& img, double timestamp);
//        ~Frame();
//        /// 初始化新的图像帧，创建图像金字塔
//        void initFrame(const cv::Mat& img);
//
//    private:
//        /// 通过半采用的方式创建图像金字塔
//        void createImgPyramid(const cv::Mat& img_level_0, int n_levels, ImgPyr& pyr);
//
//    public:
//        static int                    frame_counter_;         //!< 创建帧的计数器，用于设置帧的唯一id
//        int                           id_;                    //!< 帧的唯一id
//        double                        timestamp_;             //!< 帧被记录的时间戳
//        AbstractCamera                *cam_;                  //!< 相机模型
//        ImgPyr                        img_pyr_;               //!< 图像金字塔
//        Features                      fts_;                   //!< 图像中的特征List
//    };
//    typedef std::shared_ptr<Frame> FramePtr;
//}
//
//
//struct Feature
//{
//    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
//
//    ///特征类型,目前先只考虑角点，后续考虑其它特征的时候，再进行添加
//    enum FeatureType {
//        CORNER//角点
//    };
//    FeatureType type;     //!< 特征类型，角点
//    Frame* frame;         //!< 指针指向特征被检测到所对应的帧
//    Eigen::Vector2d px;          //!< 特征在金字塔等级为0时的像素坐标
//    int level;            //!< 特征被提取时，图像金字塔的等级
//
//    Feature(Frame* _frame, const Eigen::Vector2d& _px, int _level) :
//            type(CORNER),
//            frame(_frame),
//            px(_px),
//            level(_level)
//    {}
//
//    ~Feature(){}
//};
//
//AbstractDetector::AbstractDetector(
//        const int img_width,
//        const int img_height,
//        const int cell_size,
//        const int n_pyr_levels) :
//        cell_size_(cell_size),
//        n_pyr_levels_(n_pyr_levels),
//        grid_n_cols_(ceil(static_cast<double>(img_width) / cell_size_)),
//        grid_n_rows_(ceil(static_cast<double>(img_height) / cell_size_)),
//        grid_occupancy_(grid_n_cols_*grid_n_rows_, false)
//{}
//
//void AbstractDetector::resetGrid()
//{
//    std::fill(grid_occupancy_.begin(), grid_occupancy_.end(), false);
//}
