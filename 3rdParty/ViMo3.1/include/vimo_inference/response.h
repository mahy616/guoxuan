#ifndef VIMO_INFERENCE_RESPONSE_H
#define VIMO_INFERENCE_RESPONSE_H

#include <map>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

namespace smartmore
{
namespace vimo
{

/**
 * @brief algo module type
 *
 */
enum class ModuleType
{
    kNone,
    kClassification,
    kDetection,
    kOcr,
    kSegmentation
};

struct Response
{
    Response(){};
    explicit Response(ModuleType type) : type(type) {}
    virtual ~Response(){};

    ModuleType type = ModuleType::kNone;
};

struct ClassLabel
{
    int id;

    std::string label;

    /**
     * @brief score, [0-1]
     */
    float score;
};

struct ClassificationResponse : public Response
{
    ClassificationResponse() : Response(ModuleType::kClassification) {}

    std::vector<ClassLabel> labels;
};

struct DetBox
{
    int id;

    std::string label;

    /**
     * @brief score, [0-1]
     */
    float score;

    /**
     * @brief bounding box
     *
     * start at left upper point, clockwise
     */
    std::array<cv::Point2f, 4> bounding_box;
};

struct DetectionResponse : public Response
{
    DetectionResponse() : Response(ModuleType::kDetection) {}

    std::vector<DetBox> boxes;
};

struct SegmentationResponse : public Response
{
    SegmentationResponse() : Response(ModuleType::kSegmentation) {}

    cv::Mat mask;

    std::map<std::string, int> label_map;
};

struct TextBlock
{
    int id;

    std::string label;

    /**
     * @brief score, [0-1]
     */
    float score;

    /**
     * @brief polygon
     *
     * start at left upper point, clockwise
     */
    std::vector<cv::Point2f> polygon;
};

struct OcrResponse : public Response
{
    OcrResponse() : Response(ModuleType::kOcr) {}

    std::vector<TextBlock> blocks;
};

}  // namespace vimo
}  // namespace smartmore

#endif
