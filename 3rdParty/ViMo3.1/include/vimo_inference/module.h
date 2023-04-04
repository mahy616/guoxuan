#ifndef VIMO_INFERENCE_MODULE_H
#define VIMO_INFERENCE_MODULE_H

#include <memory>
#include <opencv2/opencv.hpp>
#include <string>

#include "internal/vimo_inference_c_api.h"
#include "request.h"
#include "response.h"

namespace smartmore
{
namespace vimo
{
/**
 * @brief algo module base
 */
class Module
{
   public:
    /**
     * @brief module info
     */
    struct Info
    {
        /**
         * @brief module id
         *
         */
        std::string id;
        /**
         * @brief module type
         */
        ModuleType type;
        /**
         * @brief features
         */
        std::vector<std::string> features;
        /**
         * @brief model version
         */
        std::string model_version;

        cv::Point default_shifting;

        cv::Size default_padding;
    };

    virtual ~Module(){};

    /**
     * @brief get module info
     * @return Info
     */
    virtual Info GetInfo();
    virtual void Run(const Request &req, Response &rsp);

   protected:
    friend class Solution;
    std::shared_ptr<sm_vimo_module> m_;
};

/**
 * @brief classification module
 */
class ClassificationModule : public Module
{
   public:
    /**
     * @brief classification module params
     */
    struct Params
    {
        /**
         * @brief set score threshold by label, use default threshold if not set
         */
        std::map<std::string, float> score_thresholds;
    };

    ClassificationModule() {}
    ~ClassificationModule() override {}

    /**
     * @brief get current params
     * @return Params
     */
    Params GetParams() const;

    /**
     * @brief set params
     * @param params
     */
    void SetParams(const Params &params);

    /**
     * @brief do inference
     *
     * @param req
     * @param rsp
     */
    void Run(const Request &req, ClassificationResponse &rsp);

    void Run(const Request &req, Response &rsp) override;

    /**
     * @brief get module info
     * @return Info
     */
    Info GetInfo() override;
};

/**
 * @brief detection module
 *
 */
class DetectionModule : public Module
{
   public:
    /**
     * @brief detection module params
     */
    struct Params
    {
        /**
         * @brief set score threshold by label, use default threshold if not set
         */
        std::map<std::string, float> score_thresholds;
        float iou_threshold;
    };

    DetectionModule() {}
    ~DetectionModule() override {}

    /**
     * @brief get current params
     * @return Params
     */
    Params GetParams() const;

    /**
     * @brief set params
     * @param params
     */
    void SetParams(const Params &params);

    /**
     * @brief do inference
     *
     * @param req
     * @param rsp
     */
    void Run(const Request &req, DetectionResponse &rsp);

    void Run(const Request &req, Response &rsp) override;

    /**
     * @brief get module info
     * @return Info
     */
    Info GetInfo() override;
};

/**
 * @brief segmentation module
 *
 */
class SegmentationModule : public Module
{
   public:
    /**
     * @brief segmentation module params
     */
    struct Params
    {
        std::map<std::string, int> area_thresholds;
        std::map<std::string, int> width_thresholds;
        std::map<std::string, int> height_thresholds;
    };

    SegmentationModule() {}
    ~SegmentationModule() override {}

    /**
     * @brief get current params
     * @return Params
     */
    Params GetParams() const;

    /**
     * @brief set params
     * @param params
     */
    void SetParams(const Params &params);

    /**
     * @brief do inference
     *
     * @param req
     * @param rsp
     */
    void Run(const Request &req, SegmentationResponse &rsp);

    void Run(const Request &req, Response &rsp) override;
    /**
     * @brief Get module info
     *
     * @return Info
     */
    Info GetInfo() override;
};

/**
 * @brief ocr module
 *
 */
class OcrModule : public Module
{
   public:
    /**
     * @brief segmentation module params
     */
    struct Params
    {
        std::map<std::string, float> score_thresholds;
        float iou_threshold;
    };

    OcrModule() {}
    ~OcrModule() override {}

    /**
     * @brief get current params
     * @return Params
     */
    Params GetParams() const;

    /**
     * @brief set params
     * @param params
     */
    void SetParams(const Params &params);

    /**
     * @brief do inference
     *
     * @param req
     * @param rsp
     */
    void Run(const Request &req, OcrResponse &rsp);

    void Run(const Request &req, Response &rsp) override;

    /**
     * @brief get module info
     * @return Info
     */
    Info GetInfo() override;
};

}  // namespace vimo
}  // namespace smartmore

#endif
