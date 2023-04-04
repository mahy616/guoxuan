#ifndef VIMO_INFERENCE_SOLUTION_H
#define VIMO_INFERENCE_SOLUTION_H

#include <memory>
#include <string>

#include "internal/vimo_inference_c_api.h"
#include "module.h"
#include "pipelines.h"

namespace smartmore
{
namespace vimo
{
class Solution
{
   public:
    Solution() {}
    ~Solution() {}

    /**
     * @brief load config from file
     *
     * @param config_path
     */
    void LoadFromFile(const std::string &config_path);

    /**
     * @brief create module
     *
     * @tparam T module type，support: "ClassificationModule", "DetectionModule",
     * "SegmentationModule" or "OcrModule"
     * @param module_id module id
     * @param use_gpu whether to use gpu
     * @param device_id gpu device id, ignore if use_gpu is false
     * @return T
     */
    template <typename T>
    T CreateModule(const std::string &module_id, bool use_gpu, int device_id) const;

    /**
     * @brief create pipelines
     *
     * @param module_id module id
     * @param use_gpu whether to use gpu
     * @param device_id gpu device id, ignore if use_gpu is false
     * @return Pipelines
     */
    Pipelines CreatePipelines(const std::string &module_id, bool use_gpu, int device_id) const;

    /**
     * @brief get module info from id
     *
     * @return Module::Info
     */
    Module::Info GetModuleInfo(const std::string &module_id) const;

    /**
     * @brief get module info list
     *
     * @return std::vector<Module::Info>
     */
    std::vector<Module::Info> GetModuleInfoList() const;

    /**
     * @brief get edge list
     *
     * @return std::vector<std::pair<std::string, std::string>>
     */
    std::vector<std::pair<std::string, std::string> > GetEdgeList() const;

   private:
    std::shared_ptr<sm_vimo_solution> sln_;
};

}  // namespace vimo
}  // namespace smartmore

#endif
