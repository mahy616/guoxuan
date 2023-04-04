// Do not include this file directly. Please include "vimo_inference.h" instead.

#ifndef VIMO_INFERENCE_CXX_INLINE_H
#define VIMO_INFERENCE_CXX_INLINE_H

#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <typeindex>

#include "../any_response.h"
#include "../vimo_inference_declare.h"
#include "vimo_inference_c_api.h"
#include "vimo_inference_value_helper_inline.h"

namespace smartmore
{
namespace vimo
{

inline std::string Version() { return std::string(get_vimo_api()->get_version()); }

inline cv::Rect RoiAlign(cv::Rect roi, cv::Point shifting, cv::Size padding)
{
    internal::ViMoValue roi_handle(internal::CreateViMoValue(roi));
    internal::ViMoValue shifting_handle(internal::CreateViMoValue(shifting));
    internal::ViMoValue padding_handle(internal::CreateViMoValue(padding));
    internal::ViMoValue new_roi_handle;
    internal::ThrowOnError(get_vimo_api()->roi_align(roi_handle.ptr, shifting_handle.ptr,
                                                     padding_handle.ptr, &new_roi_handle.ptr));
    cv::Rect ret;
    internal::FromViMoValue(new_roi_handle.ptr, ret);
    return ret;
}

inline std::vector<std::pair<std::string, cv::Rect>> ConvertResponseToBoundingBox(
    const Response &rsp)
{
    internal::ViMoValue rsp_handle(internal::CreateViMoValue(rsp));
    internal::ViMoValue bb_handle;
    internal::ThrowOnError(
        get_vimo_api()->convert_response_to_bounding_box(rsp_handle.ptr, &bb_handle.ptr));
    std::vector<std::pair<std::string, cv::Rect>> ret;
    internal::FromViMoValue(bb_handle.ptr, ret);
    return ret;
}

inline void Visualize(const Response &rsp, cv::Mat &image)
{
    internal::ViMoValue rsp_handle(internal::CreateViMoValue(rsp));
    internal::ViMoValue img_handle(internal::CreateViMoValueShallow(image));
    internal::ViMoValue out_img_handle;
    internal::ThrowOnError(
        get_vimo_api()->visualize(rsp_handle.ptr, img_handle.ptr, &out_img_handle.ptr));
    internal::FromViMoValue(out_img_handle.ptr, image);
}

inline LoggerConfig GetLoggerConfig()
{
    LoggerConfig config;
    sm_vimo_logging_level level;
    const char *file_path = nullptr;
    internal::ThrowOnError(get_vimo_api()->get_logging_config(&level, &file_path));
    config.level = static_cast<LogLevel>(level);
    config.file_path = std::string(file_path);
    return config;
}

inline void SetLoggerConfig(const LoggerConfig &config)
{
    internal::ThrowOnError(get_vimo_api()->set_logging_config(
        static_cast<sm_vimo_logging_level>(config.level), config.file_path.c_str()));
}

inline void Solution::LoadFromFile(const std::string &config_path)
{
    sm_vimo_solution *ptr;
    internal::ThrowOnError(get_vimo_api()->create_solution_from_file(config_path.c_str(), &ptr));
    sln_.reset(ptr, get_vimo_api()->release_solution);
}

inline std::vector<Module::Info> Solution::GetModuleInfoList() const
{
    if (sln_ == nullptr)
    {
        throw VimoException(ErrorCode::kNotInit, "solution not init");
    }
    internal::ViMoValue v;
    internal::ThrowOnError(get_vimo_api()->get_module_info_list(sln_.get(), &v.ptr));
    std::vector<Module::Info> infos;
    internal::FromViMoValue(v.ptr, infos);
    return infos;
}

inline Module::Info Solution::GetModuleInfo(const std::string &module_id) const
{
    if (sln_ == nullptr)
    {
        throw VimoException(ErrorCode::kNotInit, "solution not init");
    }
    Module::Info info;
    sm_vimo_value *info_ptr;
    internal::ThrowOnError(
        get_vimo_api()->get_module_info_from_solution(sln_.get(), module_id.c_str(), &info_ptr));
    internal::FromViMoValue(info_ptr, info);
    return info;
}

inline std::vector<std::pair<std::string, std::string>> Solution::GetEdgeList() const
{
    if (sln_ == nullptr)
    {
        throw VimoException(ErrorCode::kNotInit, "solution not init");
    }
    std::vector<std::pair<std::string, std::string>> list;
    internal::ViMoValue v;
    internal::ThrowOnError(get_vimo_api()->get_edge_list(sln_.get(), &v.ptr));
    internal::FromViMoValue(v.ptr, list);
    return list;
}

template <typename T>
T Solution::CreateModule(const std::string &module_id, bool use_gpu, int device_id) const
{
    if (sln_ == nullptr)
    {
        throw VimoException(ErrorCode::kNotInit, "solution not init");
    }
    throw VimoException(ErrorCode::kValidateFailed, "unsupported type");
}

#define VIMO_INFERENCE_SOLUTION_CREATE_MODULE_IMPL(MODULE_TYPE, MODULE_ENUM)                  \
    template <>                                                                               \
    inline MODULE_TYPE Solution::CreateModule<MODULE_TYPE>(const std::string &module_id,      \
                                                           bool use_gpu, int device_id) const \
    {                                                                                         \
        if (sln_ == nullptr)                                                                  \
        {                                                                                     \
            throw VimoException(ErrorCode::kNotInit, "solution not init");                    \
        }                                                                                     \
        auto expected_type = GetModuleInfo(module_id).type;                                   \
        if (expected_type != MODULE_ENUM)                                                     \
        {                                                                                     \
            std::string message = "Solution::CreateModule type check failed, want: ";         \
            message += internal::EnumToString(expected_type) + ", got: ";                     \
            message += internal::EnumToString(MODULE_ENUM);                                   \
            throw VimoException(ErrorCode::kValidateFailed, message);                         \
        }                                                                                     \
        MODULE_TYPE module;                                                                   \
        sm_vimo_module *ptr;                                                                  \
        internal::ThrowOnError(get_vimo_api()->create_module(sln_.get(), module_id.c_str(),   \
                                                             use_gpu, device_id, &ptr));      \
        module.m_.reset(ptr, get_vimo_api()->release_module);                                 \
        return module;                                                                        \
    }

VIMO_INFERENCE_SOLUTION_CREATE_MODULE_IMPL(ClassificationModule, ModuleType::kClassification)
VIMO_INFERENCE_SOLUTION_CREATE_MODULE_IMPL(SegmentationModule, ModuleType::kSegmentation)
VIMO_INFERENCE_SOLUTION_CREATE_MODULE_IMPL(DetectionModule, ModuleType::kDetection)
VIMO_INFERENCE_SOLUTION_CREATE_MODULE_IMPL(OcrModule, ModuleType::kOcr)

inline Pipelines Solution::CreatePipelines(const std::string &module_id, bool use_gpu,
                                           int device_id) const
{
    if (sln_ == nullptr)
    {
        throw VimoException(ErrorCode::kNotInit, "solution not init");
    }
    Pipelines p;
    sm_vimo_pipelines *ptr;
    internal::ThrowOnError(
        get_vimo_api()->create_pipelines(sln_.get(), module_id.c_str(), use_gpu, device_id, &ptr));
    p.p_.reset(ptr, get_vimo_api()->release_pipelines);
    return p;
}

inline AnyResponse::AnyResponse(const Response &rsp)
{
    internal::ViMoValue rsp_handle(internal::CreateViMoValue(rsp));
    internal::ViMoValue any_rsp_handle;
    internal::ThrowOnError(
        get_vimo_api()->convert_to_any_response(rsp_handle.ptr, &any_rsp_handle.ptr));
    AnyResponse temp_rsp;
    internal::FromViMoValue(any_rsp_handle.ptr, temp_rsp);

    type = temp_rsp.type;
    annotations = temp_rsp.annotations;
}

inline Module::Info Module::GetInfo()
{
    if (m_ == nullptr)
    {
        throw VimoException(ErrorCode::kNotInit, "Module not init");
    }
    Module::Info info;
    sm_vimo_value *info_ptr;
    internal::ThrowOnError(get_vimo_api()->get_module_info_from_module(m_.get(), &info_ptr));
    internal::FromViMoValue(info_ptr, info);
    return info;
}

inline void Module::Run(const Request &req, Response &rsp) {}

#define VIMO_INFERENCE_MODULE_IMPL(MODULE_NAME, RESPONSE_TYPE)                                    \
    inline Module::Info MODULE_NAME::GetInfo()                                                    \
    {                                                                                             \
        return Module::GetInfo();                                                                 \
    }                                                                                             \
                                                                                                  \
    inline void MODULE_NAME::Run(const Request &req, RESPONSE_TYPE &rsp)                          \
    {                                                                                             \
        if (m_ == nullptr)                                                                        \
        {                                                                                         \
            throw VimoException(ErrorCode::kNotInit, "Module not init");                          \
        }                                                                                         \
        auto rsp_handle = internal::DoInfer(req, m_);                                             \
        internal::FromViMoValue(rsp_handle.ptr, rsp);                                             \
    }                                                                                             \
                                                                                                  \
    inline void MODULE_NAME::Run(const Request &req, Response &rsp)                               \
    {                                                                                             \
        auto type_index = std::type_index(typeid(rsp));                                           \
        if (type_index == std::type_index(typeid(RESPONSE_TYPE)))                                 \
        {                                                                                         \
            return Run(req, static_cast<RESPONSE_TYPE &>(rsp));                                   \
        }                                                                                         \
        if (type_index == std::type_index(typeid(AnyResponse)))                                   \
        {                                                                                         \
            RESPONSE_TYPE temp_rsp;                                                               \
            Run(req, temp_rsp);                                                                   \
            static_cast<AnyResponse &>(rsp) = AnyResponse(std::move(temp_rsp));                   \
        }                                                                                         \
        else                                                                                      \
        {                                                                                         \
            throw VimoException(ErrorCode::kValidateFailed, #RESPONSE_TYPE " type check failed"); \
        }                                                                                         \
    }

VIMO_INFERENCE_MODULE_IMPL(ClassificationModule, ClassificationResponse)
VIMO_INFERENCE_MODULE_IMPL(DetectionModule, DetectionResponse)
VIMO_INFERENCE_MODULE_IMPL(SegmentationModule, SegmentationResponse)
VIMO_INFERENCE_MODULE_IMPL(OcrModule, OcrResponse)

#define VIMO_INFERENCE_PIPELINES_RUN(TYPENAME, TYPE_ENUM)                                          \
    template <>                                                                                    \
    inline void Pipelines::Run(const Request &req,                                                 \
                               std::vector<std::pair<cv::Rect, TYPENAME>> &rsps)                   \
    {                                                                                              \
        if (p_ == nullptr)                                                                         \
        {                                                                                          \
            throw VimoException(ErrorCode::kNotInit, "Module not init");                           \
        }                                                                                          \
        sm_vimo_module_type expected_type;                                                         \
        internal::ThrowOnError(get_vimo_api()->get_pipelines_type(p_.get(), &expected_type));      \
        if (expected_type != TYPE_ENUM)                                                            \
        {                                                                                          \
            std::string message = "Pipelines::Run type check failed, want: ";                      \
            message += internal::EnumToString(static_cast<ModuleType>(expected_type)) + ", got: "; \
            message += internal::EnumToString(static_cast<ModuleType>(TYPE_ENUM));                 \
            throw VimoException(ErrorCode::kValidateFailed, message);                              \
        }                                                                                          \
                                                                                                   \
        internal::ViMoValue req_handle(internal::CreateViMoValue(req));                            \
        internal::ViMoValue rsps_handle;                                                           \
        internal::ThrowOnError(                                                                    \
            get_vimo_api()->run_pipelines(p_.get(), req_handle.ptr, &rsps_handle.ptr));            \
        internal::FromViMoValue(rsps_handle.ptr, rsps);                                            \
    }

VIMO_INFERENCE_PIPELINES_RUN(ClassificationResponse, SM_VIMO_MODULE_TYPE_CLASSIFICATION)
VIMO_INFERENCE_PIPELINES_RUN(DetectionResponse, SM_VIMO_MODULE_TYPE_DETECTION)
VIMO_INFERENCE_PIPELINES_RUN(SegmentationResponse, SM_VIMO_MODULE_TYPE_SEGMENTATION)
VIMO_INFERENCE_PIPELINES_RUN(OcrResponse, SM_VIMO_MODULE_TYPE_OCR)

template <>
inline void Pipelines::Run(const Request &req, std::vector<std::pair<cv::Rect, AnyResponse>> &rsps)
{
    if (p_ == nullptr)
    {
        throw VimoException(ErrorCode ::kNotInit, "Module not init");
    }
    internal ::ViMoValue req_handle(internal ::CreateViMoValue(req));
    internal ::ViMoValue rsps_handle;
    internal::ThrowOnError(
        get_vimo_api()->run_pipelines(p_.get(), req_handle.ptr, &rsps_handle.ptr));

    std::vector<std::pair<cv::Rect, sm_vimo_value *>> temp_rsps;
    internal::FromViMoValue(rsps_handle.ptr, temp_rsps);

    for (const auto &pair : temp_rsps)
    {
        internal::ViMoValue any_rsp_handle;
        internal::ThrowOnError(
            get_vimo_api()->convert_to_any_response(pair.second, &any_rsp_handle.ptr));
        AnyResponse any_rsp;
        internal::FromViMoValue(any_rsp_handle.ptr, any_rsp);
        rsps.push_back(std::make_pair(pair.first, any_rsp));
    }
}

#define VIMO_INFERENCE_MODULE_PARAMS(MODULE_NAME)                                                \
    inline MODULE_NAME::Params MODULE_NAME::GetParams() const                                    \
    {                                                                                            \
        if (m_ == nullptr)                                                                       \
        {                                                                                        \
            throw VimoException(ErrorCode::kNotInit, "Module not init");                         \
        }                                                                                        \
        internal::ViMoValue params_handle;                                                       \
        internal::ThrowOnError(get_vimo_api()->get_module_params(m_.get(), &params_handle.ptr)); \
        MODULE_NAME::Params params;                                                              \
        internal::FromViMoValue(params_handle.ptr, params);                                      \
        return params;                                                                           \
    }                                                                                            \
    inline void MODULE_NAME::SetParams(const MODULE_NAME::Params &params)                        \
    {                                                                                            \
        if (m_ == nullptr)                                                                       \
        {                                                                                        \
            throw VimoException(ErrorCode::kNotInit, "Module not init");                         \
        }                                                                                        \
        internal::ViMoValue params_handle(internal::CreateViMoValue(params));                    \
        internal::ThrowOnError(get_vimo_api()->set_module_params(m_.get(), params_handle.ptr));  \
    }

VIMO_INFERENCE_MODULE_PARAMS(ClassificationModule)
VIMO_INFERENCE_MODULE_PARAMS(DetectionModule)
VIMO_INFERENCE_MODULE_PARAMS(SegmentationModule)
VIMO_INFERENCE_MODULE_PARAMS(OcrModule)

}  // namespace vimo
}  // namespace smartmore

#endif
