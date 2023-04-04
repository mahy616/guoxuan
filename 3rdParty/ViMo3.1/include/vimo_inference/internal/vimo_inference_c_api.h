// Warning: C API is unstable, Do not include this file directly.
//          Please include "vimo_inference.h" instead.

#ifndef VIMO_INFERENCE_C_API_H
#define VIMO_INFERENCE_C_API_H

// NOLINTBEGIN(readability-identifier-naming)

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "vimo_inference_export.h"

#ifdef _WIN32
#define VIMO_API_CALL _stdcall
#else
#define VIMO_API_CALL
#endif

#ifdef VIMO_INFERENCE_EXPORT
#define API_EXPORT VIMO_INFERENCE_EXPORT
#else
#define API_EXPORT
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#define VIMO_CLASS_RELEASE(X) void(VIMO_API_CALL * release_##X)(sm_vimo_##X * input)

#define DECLARE_VIMO_CLASS(X) \
    struct sm_vimo_##X;       \
    typedef struct sm_vimo_##X sm_vimo_##X;

    DECLARE_VIMO_CLASS(api)
    DECLARE_VIMO_CLASS(status)
    DECLARE_VIMO_CLASS(value)
    DECLARE_VIMO_CLASS(tensor_info)
    DECLARE_VIMO_CLASS(solution)
    DECLARE_VIMO_CLASS(module)
    DECLARE_VIMO_CLASS(pipelines)

    typedef enum sm_vimo_error_code
    {
        SM_VIMO_STATUS_SUCCESS = 0,
        SM_VIMO_STATUS_INVALID_ARGUMENT = 10000,
        SM_VIMO_STATUS_FILE_NOT_EXISTS = 10001,
        SM_VIMO_STATUS_INVALID_IMAGE_DATA = 10002,
        SM_VIMO_STATUS_NOT_INIT = 10003,
        SM_VIMO_STATUS_VALIDATE_FAILED = 10004,
        SM_VIMO_STATUS_SOLUTION_LOAD_FAILED = 20000,
        SM_VIMO_STATUS_MODULE_CREATE_FAILED = 20100,
        SM_VIMO_STATUS_PIPELINES_CREATE_FAILED = 20200,
        SM_VIMO_STATUS_INTERNAL_ERROR = 30000
    } sm_vimo_error_code;

    typedef enum sm_vimo_tensor_data_type
    {
        SM_VIMO_TENSOR_DATA_TYPE_UNDEFINED,
        SM_VIMO_TENSOR_DATA_TYPE_UINT8,
        SM_VIMO_TENSOR_DATA_TYPE_INT32,
        SM_VIMO_TENSOR_DATA_TYPE_FLOAT32,
        SM_VIMO_TENSOR_DATA_TYPE_STRING
    } sm_vimo_tensor_data_type;

    typedef enum sm_vimo_value_type
    {
        SM_VIMO_VALUE_TYPE_UNKNOWN,
        SM_VIMO_VALUE_TYPE_TENSOR,
        SM_VIMO_VALUE_TYPE_SEQUENCE
    } sm_vimo_value_type;

    typedef enum sm_vimo_module_type
    {
        SM_VIMO_MODULE_TYPE_UNKNOWN,
        SM_VIMO_MODULE_TYPE_CLASSIFICATION,
        SM_VIMO_MODULE_TYPE_DETECTION,
        SM_VIMO_MODULE_TYPE_OCR,
        SM_VIMO_MODULE_TYPE_SEGMENTATION,
    } sm_vimo_module_type;

    typedef enum sm_vimo_logging_level
    {
        SM_VIMO_LOGGING_LEVEL_ERROR,
        SM_VIMO_LOGGING_LEVEL_WARNING,
        SM_VIMO_LOGGING_LEVEL_INFO,
        SM_VIMO_LOGGING_LEVEL_DEBUG,
        SM_VIMO_LOGGING_LEVEL_TRACE,
    } sm_vimo_logging_level;

    struct sm_vimo_tensor_info
    {
        sm_vimo_tensor_data_type type;
        const int64_t* shape;
        size_t shape_len;
    };

#define SM_VIMO_API_STATUS(NAME, ...) sm_vimo_status*(VIMO_API_CALL * NAME)(__VA_ARGS__)
#define SM_VIMO_STATUS_FUNC(NAME, ...) sm_vimo_status* VIMO_API_CALL NAME(__VA_ARGS__)

    struct sm_vimo_api
    {
        /**
         * @brief get version
         *
         */
        const char*(VIMO_API_CALL* get_version)(void);

        // sm_vimo_status

        /**
         * @brief get error code
         * nullptr will return SM_VIMO_STATUS_INVALID_ARGUMENT
         */
        sm_vimo_error_code(VIMO_API_CALL* get_error_code)(const sm_vimo_status* status);

        /**
         * @brief get error message
         * nullptr will return nullptr
         * do not release return value
         */
        const char*(VIMO_API_CALL* get_error_message)(const sm_vimo_status* status);

        /**
         * @brief create status
         * release with `release_status`
         */
        sm_vimo_status*(VIMO_API_CALL* create_status)(sm_vimo_error_code code, const char* msg);
        VIMO_CLASS_RELEASE(status);

        // sm_vimo_value
        SM_VIMO_API_STATUS(create_tensor_as_value, const int64_t* shape, size_t shape_len,
                           sm_vimo_tensor_data_type type, sm_vimo_value** out);

        SM_VIMO_API_STATUS(create_tensor_with_data_as_value, void* p_data, const int64_t* shape,
                           size_t shape_len, sm_vimo_tensor_data_type type, sm_vimo_value** out);

        SM_VIMO_API_STATUS(is_tensor, const sm_vimo_value* value, int* out);

        /**
         * @brief Construct a new sm vimo api status object
         *
         * @param value
         * @param out do not release this value
         */
        SM_VIMO_API_STATUS(get_tensor_mutable_data, const sm_vimo_value* value, void** out);
        /**
         * @brief get tensor type and shape info
         *
         * @param value
         * @param info
         */
        SM_VIMO_API_STATUS(get_tensor_info, const sm_vimo_value* value, sm_vimo_tensor_info* info);
        /**
         * @brief construct a new sm_vimo_value object
         *
         *
         * @param in
         * @param num_values
         * @param type must be either SM_VIMO_VALUE_TYPE_SEQUENCE or SM_VIMO_VALUE_TYPE_MAP
         * @param out newly created sm_vimo_value. must be freed with release_value
         */
        SM_VIMO_API_STATUS(create_value, sm_vimo_value* const* in, size_t num_values,
                           sm_vimo_value_type type, sm_vimo_value** out);
        /**
         * @brief Construct a new sm vimo api status object
         *
         * @param value
         * @param index
         * @param out do not release this value
         */
        SM_VIMO_API_STATUS(get_value, const sm_vimo_value* value, size_t index, sm_vimo_value** out);
        SM_VIMO_API_STATUS(get_value_count, const sm_vimo_value* value, size_t* out);
        VIMO_CLASS_RELEASE(value);

        /**
         * @brief Construct a new sm vimo api status object
         *
         * @param config_path
         * @param out release with `release_solution`
         */
        SM_VIMO_API_STATUS(create_solution_from_file, const char* config_path,
                           sm_vimo_solution** out);
        SM_VIMO_API_STATUS(create_solution_from_memory, const char* buffer, sm_vimo_solution** out);

        /**
         * @brief create_module
         *
         * @param solution
         * @param id
         * @param use_gpu
         * @param device_id
         * @param out release with get_vimo_api()->release_module();
         */
        SM_VIMO_API_STATUS(create_module, const sm_vimo_solution* solution, const char* id,
                           bool use_gpu, int device_id, sm_vimo_module** out);

        SM_VIMO_API_STATUS(create_pipelines, const sm_vimo_solution* solution, const char* id,
                           bool use_gpu, int device_id, sm_vimo_pipelines** out);

        /**
         * @brief Construct a new sm vimo api status object
         *
         * @param solution
         * @param out release with `release_value`
         */
        SM_VIMO_API_STATUS(get_module_info_list, const sm_vimo_solution* solution,
                           sm_vimo_value** out);

        /**
         * @brief Construct a new sm vimo api status object
         *
         * @param solution
         * @param out release with `release_value`
         */
        SM_VIMO_API_STATUS(get_edge_list, const sm_vimo_solution* solution, sm_vimo_value** out);

        /**
         * @brief Construct a new sm vimo api status object
         *
         * @param solution
         * @param id
         * @param out release with `release_value`
         */
        SM_VIMO_API_STATUS(get_module_info_from_solution, const sm_vimo_solution* solution,
                           const char* id, sm_vimo_value** out);
        VIMO_CLASS_RELEASE(solution);

        /**
         * @brief Construct a new sm vimo api status object
         *
         * @param module
         * @param out release with `release_value`
         */
        SM_VIMO_API_STATUS(get_module_info_from_module, const sm_vimo_module* module,
                           sm_vimo_value** out);
        /**
         * @brief Construct a new sm vimo api status object
         *
         * @param module
         * @param params release with `release_value`
         */
        SM_VIMO_API_STATUS(get_module_params, const sm_vimo_module* module, sm_vimo_value** params);
        SM_VIMO_API_STATUS(set_module_params, sm_vimo_module* module, const sm_vimo_value* params);

        /**
         * @brief Construct a new sm vimo api status object
         *
         * @param module
         * @param req
         * @param rsp release with `release_value`
         */
        SM_VIMO_API_STATUS(run_module, sm_vimo_module* module, const sm_vimo_value* req,
                           sm_vimo_value** rsp);
        VIMO_CLASS_RELEASE(module);

        // sm_vimo_pipelines
        SM_VIMO_API_STATUS(run_pipelines, sm_vimo_pipelines* pipelines, const sm_vimo_value* req,
                           sm_vimo_value** rsp_list);
        SM_VIMO_API_STATUS(get_pipelines_type, sm_vimo_pipelines* pipelines,
                           sm_vimo_module_type* type);
        VIMO_CLASS_RELEASE(pipelines);

        // utils
        /**
         * @brief Construct a new sm vimo api status object
         *
         * @param image
         * @param x
         * @param y
         * @param width
         * @param height
         * @param out release with `release_value`
         */
        SM_VIMO_API_STATUS(create_request, sm_vimo_value* image, int x, int y, int width,
                           int height, sm_vimo_value** out);

        SM_VIMO_API_STATUS(convert_to_any_response, const sm_vimo_value* rsp, sm_vimo_value** out);

        SM_VIMO_API_STATUS(visualize, const sm_vimo_value* rsp, sm_vimo_value* image,
                           sm_vimo_value** out);
        SM_VIMO_API_STATUS(convert_response_to_bounding_box, const sm_vimo_value* rsp,
                           sm_vimo_value** out);

        SM_VIMO_API_STATUS(roi_align, const sm_vimo_value* roi, const sm_vimo_value* shifting,
                           const sm_vimo_value* padding, sm_vimo_value** out);

        // logging
        SM_VIMO_API_STATUS(get_logging_config, sm_vimo_logging_level* level,
                           const char** file_path);
        SM_VIMO_API_STATUS(set_logging_config, sm_vimo_logging_level level, const char* file_path);
    };

    API_EXPORT const sm_vimo_api* VIMO_API_CALL get_vimo_api();

#ifdef __cplusplus
}
#endif

// NOLINTEND(readability-identifier-naming)

#endif
