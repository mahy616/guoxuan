#ifndef VIMO_INFERENCE_ANY_RESPONSE_H
#define VIMO_INFERENCE_ANY_RESPONSE_H

#include <string>
#include <vector>

#include "vimo_inference_declare.h"

namespace smartmore
{
namespace vimo
{

struct Annotation
{
    float score{0};
    std::string label;

    /**
     * @brief

     Response::type detection, points represent bbox

     Response::type segmentation, points represent outline points

     Response::type ocr, points represent outline points

     Response::type classification, points will be empty

     start at left upper point, clockwise
     */
    std::vector<cv::Point2f> points;
    int id{0};
};

/**
 * @brief any infer response
 *
 */
struct AnyResponse : public Response
{
    AnyResponse() {}
    explicit AnyResponse(const Response &rsp);

    AnyResponse(const AnyResponse &rsp)
    {
        annotations = rsp.annotations;
        type = rsp.type;
    }

    std::vector<Annotation> annotations;
};

}  // namespace vimo
}  // namespace smartmore

#endif
