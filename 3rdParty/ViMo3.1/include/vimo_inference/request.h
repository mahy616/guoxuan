#ifndef VIMO_INFERENCE_REQUEST_H
#define VIMO_INFERENCE_REQUEST_H

#include <opencv2/opencv.hpp>

namespace smartmore
{
namespace vimo
{

class Request
{
   public:
    /**
     * @brief construct with image
     * @param image
     */
    explicit Request(cv::Mat image)
        : image(image), roi(0, 0, image.size().width, image.size().height)
    {
    }
    /**
     * @brief construct with image and infer roi
     * @param image
     * @param roi
     */
    Request(cv::Mat image, cv::Rect roi) : image(image), roi(roi) {}

    /**
     * @brief infer image
     */
    cv::Mat image;

    /**
     * @brief infer roi
     */
    cv::Rect roi;
};

}  // namespace vimo
}  // namespace smartmore

#endif
