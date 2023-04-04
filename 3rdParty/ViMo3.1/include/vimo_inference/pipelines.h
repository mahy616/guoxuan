#ifndef VIMO_INFERENCE_PIPELINES_H
#define VIMO_INFERENCE_PIPELINES_H

#include <memory>

#include "internal/vimo_inference_c_api.h"
#include "request.h"
#include "response.h"

namespace smartmore
{
namespace vimo
{
class Pipelines
{
   public:
    template <typename T>
    using ResponseList = std::vector<std::pair<cv::Rect, T> >;

    using ClassificationResponseList = ResponseList<ClassificationResponse>;
    using DetectionResponseList = ResponseList<DetectionResponse>;
    using SegmentationResponseList = ResponseList<SegmentationResponse>;
    using OcrResponseList = ResponseList<OcrResponse>;

    Pipelines() : p_(nullptr) {}

    ~Pipelines() {}
    /**
     * @brief do inferences
     *
     * @tparam T module type, support one of "ClassificationResponse", "DetectionResponse",
     * "OcrResponse", "SegmentationResponse"
     * @param req inference request
     * @param rsps response list
     *
     * @exception throw VimoException if actual type of response is not as expected
     */
    template <typename T>
    void Run(const Request &req, ResponseList<T> &rsps);

   private:
    friend class Solution;
    std::shared_ptr<sm_vimo_pipelines> p_;
};

}  // namespace vimo
}  // namespace smartmore

#endif
