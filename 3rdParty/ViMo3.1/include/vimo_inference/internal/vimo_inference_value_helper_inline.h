#ifndef VIMO_INFERENCE_VALUE_HELPER_INLINE_H
#define VIMO_INFERENCE_VALUE_HELPER_INLINE_H

#include <cstring>
#include <memory>
#include <string>
#include <typeindex>

#include "../any_response.h"
#include "../vimo_inference_declare.h"
#include "vimo_inference_c_api.h"

#ifndef SM_VIMO_ENFORCE_UTF_8
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#endif

#define VIMO_INFERENCE_FROM_VALUE_START             \
    std::map<std::string, sm_vimo_value *> val_map; \
    FromViMoValue(in, val_map);

#define VIMO_INFERENCE_FROM_VALUE(NAME) FromViMoValue(val_map[#NAME], out.NAME);

#define VIMO_INFERENCE_CREATE_VALUE_START(TYPE)             \
    inline sm_vimo_value *CreateViMoValue(const TYPE &item) \
    {                                                       \
        std::map<std::string, sm_vimo_value *> value_map;

#define VIMO_INFERENCE_CREATE_VALUE(NAME) value_map[#NAME] = CreateViMoValue(item.NAME);

#define VIMO_INFERENCE_CREATE_VALUE_END \
    return CreateViMoValue(value_map);  \
    }

namespace smartmore
{
namespace vimo
{
namespace internal
{
#ifndef SM_VIMO_ENFORCE_UTF_8
#ifdef _WIN32
inline std::string FromUTF16(const std::wstring &wide_string, int code_page)
{
    auto size =
        WideCharToMultiByte(code_page, 0, wide_string.data(), static_cast<int>(wide_string.size()),
                            nullptr, 0, nullptr, nullptr);
    std::vector<char> buffer(size);
    WideCharToMultiByte(code_page, 0, wide_string.data(), static_cast<int>(wide_string.size()),
                        buffer.data(), static_cast<int>(buffer.size()), nullptr, nullptr);
    return std::string(buffer.begin(), buffer.end());
}

inline std::wstring ToUTF16(const std::string &string, int code_page)
{
    auto size = MultiByteToWideChar(code_page, MB_ERR_INVALID_CHARS, string.c_str(),
                                    static_cast<int>(string.size()), nullptr, 0);
    std::vector<wchar_t> buffer(size);
    MultiByteToWideChar(code_page, MB_ERR_INVALID_CHARS, string.c_str(),
                        static_cast<int>(string.size()), buffer.data(),
                        static_cast<int>(buffer.size()));
    return std::wstring(buffer.begin(), buffer.end());
}
#endif
#endif

inline void ThrowOnError(sm_vimo_status *status)
{
    if (status)
    {
        std::string error_message = get_vimo_api()->get_error_message(status);
        sm_vimo_error_code code = get_vimo_api()->get_error_code(status);
        get_vimo_api()->release_status(status);
        throw VimoException(static_cast<ErrorCode>(code), error_message);
    }
}

inline std::string EnumToString(ModuleType type)
{
    switch (type)
    {
        case ModuleType::kClassification:
            return "classification";
        case ModuleType::kDetection:
            return "detection";
        case ModuleType::kOcr:
            return "ocr";
        case ModuleType::kSegmentation:
            return "segmentation";
        default:
            return "unknown";
    }
}

class ViMoValue
{
   public:
    ViMoValue() : ptr(nullptr) {}
    explicit ViMoValue(sm_vimo_value *in_ptr) : ptr(in_ptr) {}
    ViMoValue(const ViMoValue &) = delete;
    ViMoValue(ViMoValue &&v) noexcept : ptr(v.ptr) { v.ptr = nullptr; }
    ViMoValue &operator=(const ViMoValue &other) = delete;
    ViMoValue &operator=(ViMoValue &&other) noexcept
    {
        ptr = other.ptr;
        other.ptr = nullptr;
        return *this;
    }
    ~ViMoValue() { get_vimo_api()->release_value(ptr); }
    sm_vimo_value *ptr;
};

inline sm_vimo_value *CreateViMoValue(sm_vimo_value *in) { return in; }

sm_vimo_value *CreateViMoValue(const int &in);
sm_vimo_value *CreateViMoValue(const float &in);
sm_vimo_value *CreateViMoValue(const std::string &in);
sm_vimo_value *CreateViMoValue(const std::vector<int> &in);
sm_vimo_value *CreateViMoValue(const std::vector<float> &in);
sm_vimo_value *CreateViMoValue(const std::vector<uint8_t> &in);
sm_vimo_value *CreateViMoValue(const cv::Point &in);
sm_vimo_value *CreateViMoValue(const cv::Point2f &in);
sm_vimo_value *CreateViMoValue(const cv::Size &in);
sm_vimo_value *CreateViMoValue(const cv::Rect &in);
sm_vimo_value *CreateViMoValue(const Response &rsp);
sm_vimo_value *CreateViMoValue(const ClassLabel &block);
sm_vimo_value *CreateViMoValue(const DetBox &rsp);
sm_vimo_value *CreateViMoValue(const TextBlock &block);
sm_vimo_value *CreateViMoValue(const Annotation &anno);
sm_vimo_value *CreateViMoValue(const ClassificationResponse &rsp);
sm_vimo_value *CreateViMoValue(const DetectionResponse &rsp);
sm_vimo_value *CreateViMoValue(const SegmentationResponse &rsp);
sm_vimo_value *CreateViMoValue(const OcrResponse &rsp);
sm_vimo_value *CreateViMoValue(const AnyResponse &rsp);
sm_vimo_value *CreateViMoValue(const ModuleType &type);
sm_vimo_value *CreateViMoValue(const ClassificationModule::Params &type);
sm_vimo_value *CreateViMoValue(const DetectionModule::Params &type);
sm_vimo_value *CreateViMoValue(const SegmentationModule::Params &type);
sm_vimo_value *CreateViMoValue(const OcrModule::Params &type);
sm_vimo_value *CreateViMoValueShallow(const cv::Mat &in);
sm_vimo_value *CreateViMoValueDeep(const cv::Mat &in);

template <typename T>
sm_vimo_value *CreateViMoValue(const std::vector<T> &vec);

template <typename T, size_t N>
sm_vimo_value *CreateViMoValue(const std::array<T, N> &arr);

template <typename K, typename V>
sm_vimo_value *CreateViMoValue(const std::map<K, V> &map);

template <sm_vimo_tensor_data_type DataType, typename T>
sm_vimo_value *CreateViMoValueSeq(const std::vector<T> &in);

template <typename T>
inline sm_vimo_value *CreateViMoValue(const std::vector<T> &vec)
{
    std::vector<sm_vimo_value *> out_vec;
    for (int i = 0; i < vec.size(); ++i) out_vec.push_back(CreateViMoValue(vec[i]));

    sm_vimo_value *out;
    ThrowOnError(get_vimo_api()->create_value(out_vec.data(), out_vec.size(),
                                              SM_VIMO_VALUE_TYPE_SEQUENCE, &out));
    return out;
}

template <typename T, size_t N>
sm_vimo_value *CreateViMoValue(const std::array<T, N> &arr)
{
    return CreateViMoValue(std::vector<T>(arr.begin(), arr.end()));
}

template <typename K, typename V>
inline sm_vimo_value *CreateViMoValue(const std::map<K, V> &map)
{
    std::vector<sm_vimo_value *> keys;
    std::vector<sm_vimo_value *> values;

    for (typename std::map<K, V>::const_iterator it = map.begin(); it != map.end(); it++)
    {
        keys.push_back(CreateViMoValue(it->first));
        values.push_back(CreateViMoValue(it->second));
    }

    std::vector<sm_vimo_value *> vec(2);
    vec[0] = CreateViMoValue(keys);
    vec[1] = CreateViMoValue(values);
    return CreateViMoValue(vec);
}

template <sm_vimo_tensor_data_type DataType, typename T>
inline sm_vimo_value *CreateViMoValueSeq(const std::vector<T> &in)
{
    const int64_t size = static_cast<int64_t>(in.size());
    sm_vimo_value *out;
    ThrowOnError(get_vimo_api()->create_tensor_as_value(&size, 1, DataType, &out));
    T *ptr;
    ThrowOnError(get_vimo_api()->get_tensor_mutable_data(out, reinterpret_cast<void **>(&ptr)));
    std::memcpy(ptr, in.data(), size * sizeof(T));
    return out;
}

inline sm_vimo_value *CreateViMoValue(const int &in)
{
    std::vector<int> vec(1);
    vec[0] = in;
    return CreateViMoValue(vec);
}

inline sm_vimo_value *CreateViMoValue(const float &in)
{
    std::vector<float> vec(1);
    vec[0] = in;
    return CreateViMoValue(vec);
}

inline sm_vimo_value *CreateViMoValue(const std::string &in)
{
    std::string utf8_in = in;
#ifndef SM_VIMO_ENFORCE_UTF_8
#ifdef _WIN32
    //  ACP to UTF-8
    utf8_in = FromUTF16(ToUTF16(in, GetACP()), CP_UTF8);
    if (utf8_in.empty())
    {
        utf8_in = in;
    }
#endif
#endif
    int64_t size = utf8_in.size() + 1;  // with '\0'
    sm_vimo_value *out;
    ThrowOnError(
        get_vimo_api()->create_tensor_as_value(&size, 1, SM_VIMO_TENSOR_DATA_TYPE_STRING, &out));
    void *ptr;
    ThrowOnError(get_vimo_api()->get_tensor_mutable_data(out, &ptr));
    std::memcpy(ptr, utf8_in.data(), size);
    return out;
}

inline sm_vimo_value *CreateViMoValue(const std::vector<int> &in)
{
    return CreateViMoValueSeq<SM_VIMO_TENSOR_DATA_TYPE_INT32>(in);
}

inline sm_vimo_value *CreateViMoValue(const std::vector<float> &in)
{
    return CreateViMoValueSeq<SM_VIMO_TENSOR_DATA_TYPE_FLOAT32>(in);
}

inline sm_vimo_value *CreateViMoValue(const std::vector<uint8_t> &in)
{
    return CreateViMoValueSeq<SM_VIMO_TENSOR_DATA_TYPE_UINT8>(in);
}

inline sm_vimo_value *CreateViMoValue(const cv::Point &in)
{
    std::vector<int> vec(2);
    vec[0] = in.x;
    vec[1] = in.y;
    return CreateViMoValue(vec);
}

inline sm_vimo_value *CreateViMoValue(const cv::Point2f &in)
{
    std::vector<float> vec(2);
    vec[0] = in.x;
    vec[1] = in.y;
    return CreateViMoValue(vec);
}

inline sm_vimo_value *CreateViMoValue(const cv::Size &in)
{
    std::vector<int> vec(2);
    vec[0] = in.width;
    vec[1] = in.height;
    return CreateViMoValue(vec);
}

inline sm_vimo_value *CreateViMoValue(const cv::Rect &in)
{
    std::vector<int> vec(4);
    vec[0] = in.x;
    vec[1] = in.y;
    vec[2] = in.width;
    vec[3] = in.height;
    return CreateViMoValue(vec);
}

inline sm_vimo_value *CreateViMoValueShallow(const cv::Mat &in)
{
    if (!in.isContinuous())
    {
        return CreateViMoValueDeep(in.clone());
    }
    std::vector<int64_t> dims(3);
    dims[0] = in.rows;
    dims[1] = in.cols;
    dims[2] = in.channels();

    sm_vimo_tensor_data_type type;
    switch (in.depth())
    {
        case CV_8U:
            type = SM_VIMO_TENSOR_DATA_TYPE_UINT8;
            break;
        case CV_32F:
            type = SM_VIMO_TENSOR_DATA_TYPE_FLOAT32;
            break;
        case CV_32S:
            type = SM_VIMO_TENSOR_DATA_TYPE_INT32;
            break;
        default:
            throw VimoException(ErrorCode::kInternalError, "unsupported mat type");
    }
    sm_vimo_value *value;
    ThrowOnError(get_vimo_api()->create_tensor_with_data_as_value(in.data, dims.data(), dims.size(),
                                                                  type, &value));
    return value;
}

inline sm_vimo_value *CreateViMoValueDeep(const cv::Mat &in)
{
    std::vector<int64_t> dims(3);
    dims[0] = in.rows;
    dims[1] = in.cols;
    dims[2] = in.channels();

    sm_vimo_tensor_data_type type;
    switch (in.depth())
    {
        case CV_8U:
            type = SM_VIMO_TENSOR_DATA_TYPE_UINT8;
            break;
        case CV_32F:
            type = SM_VIMO_TENSOR_DATA_TYPE_FLOAT32;
            break;
        case CV_32S:
            type = SM_VIMO_TENSOR_DATA_TYPE_INT32;
            break;
        default:
            throw VimoException(ErrorCode::kInternalError, "unsupported mat type");
    }
    sm_vimo_value *value;
    ThrowOnError(get_vimo_api()->create_tensor_as_value(dims.data(), dims.size(), type, &value));
    void *ptr;
    ThrowOnError(get_vimo_api()->get_tensor_mutable_data(value, &ptr));
    std::memcpy(ptr, static_cast<void *>(in.data), in.total() * in.elemSize());
    return value;
}

inline sm_vimo_value *CreateViMoValue(const Request &req)
{
    sm_vimo_value *ptr;
    ViMoValue img_handle(CreateViMoValueShallow(req.image));
    ThrowOnError(get_vimo_api()->create_request(img_handle.ptr, req.roi.x, req.roi.y, req.roi.width,
                                                req.roi.height, &ptr));
    img_handle.ptr = nullptr;
    return ptr;
}

#define VIMO_INFERENCE_CREATE_RESPONSE(TYPE)                    \
    if (type_index == std::type_index(typeid(TYPE)))            \
    {                                                           \
        return CreateViMoValue(static_cast<const TYPE &>(rsp)); \
    }
inline sm_vimo_value *CreateViMoValue(const Response &rsp)
{
    auto type_index = std::type_index(typeid(rsp));
    VIMO_INFERENCE_CREATE_RESPONSE(AnyResponse)
    VIMO_INFERENCE_CREATE_RESPONSE(ClassificationResponse)
    VIMO_INFERENCE_CREATE_RESPONSE(DetectionResponse)
    VIMO_INFERENCE_CREATE_RESPONSE(SegmentationResponse)
    VIMO_INFERENCE_CREATE_RESPONSE(OcrResponse)

    throw VimoException(ErrorCode::kValidateFailed, "type check failed, unknown response type");
}

VIMO_INFERENCE_CREATE_VALUE_START(TextBlock)
VIMO_INFERENCE_CREATE_VALUE(id)
VIMO_INFERENCE_CREATE_VALUE(score)
VIMO_INFERENCE_CREATE_VALUE(label)
VIMO_INFERENCE_CREATE_VALUE(polygon)
VIMO_INFERENCE_CREATE_VALUE_END

VIMO_INFERENCE_CREATE_VALUE_START(ClassLabel)
VIMO_INFERENCE_CREATE_VALUE(id)
VIMO_INFERENCE_CREATE_VALUE(score)
VIMO_INFERENCE_CREATE_VALUE(label)
VIMO_INFERENCE_CREATE_VALUE_END

VIMO_INFERENCE_CREATE_VALUE_START(DetBox)
VIMO_INFERENCE_CREATE_VALUE(id)
VIMO_INFERENCE_CREATE_VALUE(score)
VIMO_INFERENCE_CREATE_VALUE(label)
VIMO_INFERENCE_CREATE_VALUE(bounding_box)
VIMO_INFERENCE_CREATE_VALUE_END

VIMO_INFERENCE_CREATE_VALUE_START(Annotation)
VIMO_INFERENCE_CREATE_VALUE(id)
VIMO_INFERENCE_CREATE_VALUE(score)
VIMO_INFERENCE_CREATE_VALUE(label)
VIMO_INFERENCE_CREATE_VALUE(points)
VIMO_INFERENCE_CREATE_VALUE_END

VIMO_INFERENCE_CREATE_VALUE_START(ClassificationResponse)
VIMO_INFERENCE_CREATE_VALUE(type)
VIMO_INFERENCE_CREATE_VALUE(labels)
VIMO_INFERENCE_CREATE_VALUE_END

VIMO_INFERENCE_CREATE_VALUE_START(DetectionResponse)
VIMO_INFERENCE_CREATE_VALUE(type)
VIMO_INFERENCE_CREATE_VALUE(boxes)
VIMO_INFERENCE_CREATE_VALUE_END

VIMO_INFERENCE_CREATE_VALUE_START(SegmentationResponse)
VIMO_INFERENCE_CREATE_VALUE(type)
VIMO_INFERENCE_CREATE_VALUE(label_map)
value_map["mask"] = CreateViMoValueShallow(item.mask);
VIMO_INFERENCE_CREATE_VALUE_END

VIMO_INFERENCE_CREATE_VALUE_START(OcrResponse)
VIMO_INFERENCE_CREATE_VALUE(type)
VIMO_INFERENCE_CREATE_VALUE(blocks)
VIMO_INFERENCE_CREATE_VALUE_END

VIMO_INFERENCE_CREATE_VALUE_START(AnyResponse)
VIMO_INFERENCE_CREATE_VALUE(type)
VIMO_INFERENCE_CREATE_VALUE(annotations)
VIMO_INFERENCE_CREATE_VALUE_END

VIMO_INFERENCE_CREATE_VALUE_START(ClassificationModule::Params)
VIMO_INFERENCE_CREATE_VALUE(score_thresholds)
VIMO_INFERENCE_CREATE_VALUE_END

VIMO_INFERENCE_CREATE_VALUE_START(DetectionModule::Params)
VIMO_INFERENCE_CREATE_VALUE(score_thresholds)
VIMO_INFERENCE_CREATE_VALUE(iou_threshold)
VIMO_INFERENCE_CREATE_VALUE_END

VIMO_INFERENCE_CREATE_VALUE_START(OcrModule::Params)
VIMO_INFERENCE_CREATE_VALUE(score_thresholds)
VIMO_INFERENCE_CREATE_VALUE(iou_threshold)
VIMO_INFERENCE_CREATE_VALUE_END

VIMO_INFERENCE_CREATE_VALUE_START(SegmentationModule::Params)
VIMO_INFERENCE_CREATE_VALUE(area_thresholds)
VIMO_INFERENCE_CREATE_VALUE(width_thresholds)
VIMO_INFERENCE_CREATE_VALUE(height_thresholds)
VIMO_INFERENCE_CREATE_VALUE_END

inline sm_vimo_value *CreateViMoValue(const ModuleType &type)
{
    return CreateViMoValue(static_cast<int>(type));
}

void FromViMoValue(const sm_vimo_value *in, int &out);
void FromViMoValue(const sm_vimo_value *in, float &out);
void FromViMoValue(const sm_vimo_value *in, std::string &out);
void FromViMoValue(sm_vimo_value *in, sm_vimo_value *&out);
void FromViMoValue(const sm_vimo_value *in, cv::Mat &out);
void FromViMoValue(const sm_vimo_value *in, cv::Rect &out);
void FromViMoValue(const sm_vimo_value *in, cv::Point2f &out);
void FromViMoValue(const sm_vimo_value *in, cv::Point &out);
void FromViMoValue(const sm_vimo_value *in, cv::Size &out);
void FromViMoValue(const sm_vimo_value *in, ModuleType &out);
void FromViMoValue(const sm_vimo_value *in, Module::Info &out);
void FromViMoValue(const sm_vimo_value *in, ClassLabel &out);
void FromViMoValue(const sm_vimo_value *in, DetBox &out);
void FromViMoValue(const sm_vimo_value *in, TextBlock &out);
void FromViMoValue(const sm_vimo_value *in, Annotation &out);
void FromViMoValue(const sm_vimo_value *in, Response &out);
void FromViMoValue(const sm_vimo_value *in, ClassificationResponse &out);
void FromViMoValue(const sm_vimo_value *in, DetectionResponse &out);
void FromViMoValue(const sm_vimo_value *in, SegmentationResponse &out);
void FromViMoValue(const sm_vimo_value *in, OcrResponse &out);
void FromViMoValue(const sm_vimo_value *in, AnyResponse &out);
void FromViMoValue(const sm_vimo_value *in, ClassificationModule::Params &out);
void FromViMoValue(const sm_vimo_value *in, DetectionModule::Params &out);
void FromViMoValue(const sm_vimo_value *in, OcrModule::Params &out);
void FromViMoValue(const sm_vimo_value *in, SegmentationModule::Params &out);

template <typename K, typename V>
void FromViMoValue(const sm_vimo_value *in, std::pair<K, V> &out);

template <typename T>
void FromViMoValue(const sm_vimo_value *in, std::vector<T> &out);

template <typename T, size_t N>
void FromViMoValue(const sm_vimo_value *in, std::array<T, N> &out);

template <typename K, typename V>
void FromViMoValue(const sm_vimo_value *in, std::map<K, V> &out);

template <typename T>
inline void FromViMoValueToSeq(const sm_vimo_value *in, std::vector<T> &out)
{
    sm_vimo_tensor_info info;
    ThrowOnError(get_vimo_api()->get_tensor_info(in, &info));

    int64_t size = *info.shape;
    out.resize(size);
    T *ptr;
    ThrowOnError(get_vimo_api()->get_tensor_mutable_data(in, reinterpret_cast<void **>(&ptr)));
    std::memcpy(out.data(), ptr, size * sizeof(T));
}

template <typename T, size_t N>
inline void FromViMoValue(const sm_vimo_value *in, std::array<T, N> &out)
{
    std::vector<T> vec;
    FromViMoValue(in, vec);
    for (size_t i = 0; i < N; ++i)
    {
        out[i] = vec.at(i);
    }
}

template <typename T>
inline void FromViMoValue(const sm_vimo_value *in, std::vector<T> &out)
{
    size_t size = {0};
    ThrowOnError(get_vimo_api()->get_value_count(in, &size));

    out.resize(size);

    for (size_t i = 0; i < size; ++i)
    {
        sm_vimo_value *val;
        ThrowOnError(get_vimo_api()->get_value(in, i, &val));
        FromViMoValue(val, out[i]);
    }
}

template <>
inline void FromViMoValue(const sm_vimo_value *in, std::vector<int> &out)
{
    return FromViMoValueToSeq<int>(in, out);
}

template <>
inline void FromViMoValue(const sm_vimo_value *in, std::vector<float> &out)
{
    return FromViMoValueToSeq<float>(in, out);
}

template <>
inline void FromViMoValue(const sm_vimo_value *in, std::vector<uchar> &out)
{
    return FromViMoValueToSeq<uchar>(in, out);
}

template <typename K, typename V>
inline void FromViMoValue(const sm_vimo_value *in, std::map<K, V> &out)
{
    sm_vimo_value *keys;
    sm_vimo_value *values;
    size_t cc = 0;
    get_vimo_api()->get_value_count(in, &cc);
    ThrowOnError(get_vimo_api()->get_value(in, 0, &keys));
    ThrowOnError(get_vimo_api()->get_value(in, 1, &values));

    size_t count = 0;
    ThrowOnError(get_vimo_api()->get_value_count(keys, &count));
    for (size_t i = 0; i < count; ++i)
    {
        sm_vimo_value *k_ptr;
        sm_vimo_value *v_ptr;
        ThrowOnError(get_vimo_api()->get_value(keys, i, &k_ptr));
        ThrowOnError(get_vimo_api()->get_value(values, i, &v_ptr));

        K key;
        FromViMoValue(k_ptr, key);
        FromViMoValue(v_ptr, out[key]);
    }
}

template <typename K, typename V>
inline void FromViMoValue(const sm_vimo_value *in, std::pair<K, V> &out)
{
    std::vector<sm_vimo_value *> ret;
    FromViMoValue(in, ret);
    FromViMoValue(ret[0], out.first);
    FromViMoValue(ret[1], out.second);
}

inline void FromViMoValue(const sm_vimo_value *in, int &out)
{
    int *val;
    ThrowOnError(get_vimo_api()->get_tensor_mutable_data(in, reinterpret_cast<void **>(&val)));
    out = *val;
}

inline void FromViMoValue(const sm_vimo_value *in, float &out)
{
    float *val;
    ThrowOnError(get_vimo_api()->get_tensor_mutable_data(in, reinterpret_cast<void **>(&val)));
    out = *val;
}

inline void FromViMoValue(const sm_vimo_value *in, std::string &out)
{
    char *chars;
    ThrowOnError(get_vimo_api()->get_tensor_mutable_data(in, reinterpret_cast<void **>(&chars)));
    out = chars;

    // UTF-8 to ACP
#ifndef SM_VIMO_ENFORCE_UTF_8
#ifdef _WIN32
    out = FromUTF16(ToUTF16(out, CP_UTF8), GetACP());
#endif
#endif
}

inline void FromViMoValue(sm_vimo_value *in, sm_vimo_value *&out) { out = in; }

inline void FromViMoValue(const sm_vimo_value *in, cv::Rect &out)
{
    std::vector<int> vec;
    FromViMoValue(in, vec);
    out.x = vec[0];
    out.y = vec[1];
    out.width = vec[2];
    out.height = vec[3];
}

inline void FromViMoValue(const sm_vimo_value *in, cv::Point &out)
{
    std::vector<int> vec;
    FromViMoValue(in, vec);
    out.x = vec[0];
    out.y = vec[1];
}

inline void FromViMoValue(const sm_vimo_value *in, cv::Point2f &out)
{
    std::vector<float> vec;
    FromViMoValue(in, vec);
    out.x = vec[0];
    out.y = vec[1];
}

inline void FromViMoValue(const sm_vimo_value *in, cv::Size &out)
{
    std::vector<int> vec;
    FromViMoValue(in, vec);
    out.width = vec[0];
    out.height = vec[1];
}

inline void FromViMoValue(const sm_vimo_value *in, ModuleType &out)
{
    int int_type;
    FromViMoValue(in, int_type);
    out = static_cast<ModuleType>(int_type);
}

inline void FromViMoValue(const sm_vimo_value *in, Module::Info &out)
{
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(id)
    VIMO_INFERENCE_FROM_VALUE(type);
    VIMO_INFERENCE_FROM_VALUE(model_version)
    VIMO_INFERENCE_FROM_VALUE(features)
    VIMO_INFERENCE_FROM_VALUE(default_shifting)
    VIMO_INFERENCE_FROM_VALUE(default_padding)
}

inline void FromViMoValue(const sm_vimo_value *in, ClassLabel &out)
{
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(id)
    VIMO_INFERENCE_FROM_VALUE(score)
    VIMO_INFERENCE_FROM_VALUE(label)
}

inline void FromViMoValue(const sm_vimo_value *in, DetBox &out)
{
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(id)
    VIMO_INFERENCE_FROM_VALUE(score)
    VIMO_INFERENCE_FROM_VALUE(label)
    VIMO_INFERENCE_FROM_VALUE(bounding_box)
}

inline void FromViMoValue(const sm_vimo_value *in, TextBlock &out)
{
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(id)
    VIMO_INFERENCE_FROM_VALUE(score)
    VIMO_INFERENCE_FROM_VALUE(label)
    VIMO_INFERENCE_FROM_VALUE(polygon)
}

inline void FromViMoValue(const sm_vimo_value *in, Annotation &out)
{
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(id)
    VIMO_INFERENCE_FROM_VALUE(score)
    VIMO_INFERENCE_FROM_VALUE(label)
    VIMO_INFERENCE_FROM_VALUE(points)
}

inline void FromViMoValue(const sm_vimo_value *in, Response &out)
{
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(type)
}

inline void FromViMoValue(const sm_vimo_value *in, ClassificationResponse &out)
{
    FromViMoValue(in, static_cast<Response &>(out));
    if (out.type != ModuleType::kClassification)
    {
        throw VimoException(ErrorCode::kValidateFailed, "cls rsp validate failed");
    }
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(labels)
}

inline void FromViMoValue(const sm_vimo_value *in, DetectionResponse &out)
{
    FromViMoValue(in, static_cast<Response &>(out));
    if (out.type != ModuleType::kDetection)
    {
        throw VimoException(ErrorCode::kValidateFailed, "det rsp validate failed");
    }
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(boxes)
}

inline void FromViMoValue(const sm_vimo_value *in, SegmentationResponse &out)
{
    FromViMoValue(in, static_cast<Response &>(out));
    if (out.type != ModuleType::kSegmentation)
    {
        throw VimoException(ErrorCode::kValidateFailed, "seg rsp validate failed");
    }
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(type)
    VIMO_INFERENCE_FROM_VALUE(label_map)
    VIMO_INFERENCE_FROM_VALUE(mask)
}

inline void FromViMoValue(const sm_vimo_value *in, OcrResponse &out)
{
    FromViMoValue(in, static_cast<Response &>(out));
    if (out.type != ModuleType::kOcr)
    {
        throw VimoException(ErrorCode::kValidateFailed, "ocr rsp validate failed");
    }
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(blocks)
}

inline void FromViMoValue(const sm_vimo_value *in, AnyResponse &out)
{
    FromViMoValue(in, static_cast<Response &>(out));
    VIMO_INFERENCE_FROM_VALUE_START
    if (val_map.count("annotations") == 0)
    {
        throw VimoException(ErrorCode::kValidateFailed, "any rsp validate failed");
    }
    VIMO_INFERENCE_FROM_VALUE(annotations)
}

inline void FromViMoValue(const sm_vimo_value *in, ClassificationModule::Params &out)
{
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(score_thresholds)
}

inline void FromViMoValue(const sm_vimo_value *in, DetectionModule::Params &out)
{
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(score_thresholds)
    VIMO_INFERENCE_FROM_VALUE(iou_threshold)
}

inline void FromViMoValue(const sm_vimo_value *in, OcrModule::Params &out)
{
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(score_thresholds)
    VIMO_INFERENCE_FROM_VALUE(iou_threshold)
}

inline void FromViMoValue(const sm_vimo_value *in, SegmentationModule::Params &out)
{
    VIMO_INFERENCE_FROM_VALUE_START
    VIMO_INFERENCE_FROM_VALUE(area_thresholds)
    VIMO_INFERENCE_FROM_VALUE(width_thresholds)
    VIMO_INFERENCE_FROM_VALUE(height_thresholds)
}

inline void FromViMoValue(const sm_vimo_value *in, cv::Mat &out)
{
    sm_vimo_tensor_info info;
    ThrowOnError(get_vimo_api()->get_tensor_info(in, &info));

    int mat_type;
    if (info.type == SM_VIMO_TENSOR_DATA_TYPE_UINT8 && info.shape_len == 3 && info.shape[2] == 3)
    {
        mat_type = CV_8UC3;
    }
    else if (info.type == SM_VIMO_TENSOR_DATA_TYPE_UINT8 &&
                 (info.shape_len == 3 && info.shape[2] == 1) ||
             info.shape_len == 2)
    {
        mat_type = CV_8UC1;
    }
    else
    {
        throw VimoException(ErrorCode::kInternalError, "unsupported tensor type");
    }
    void *data;
    ThrowOnError(get_vimo_api()->get_tensor_mutable_data(in, &data));
    out = cv::Mat(static_cast<int>(info.shape[0]), static_cast<int>(info.shape[1]), mat_type, data)
              .clone();
}

inline ViMoValue DoInfer(const Request &req, std::shared_ptr<sm_vimo_module> &m)
{
    if (m == nullptr)
    {
        throw VimoException(ErrorCode::kNotInit, "Module not init");
    }

    ViMoValue req_handle(CreateViMoValue(req));
    ViMoValue rsp_handle;
    ThrowOnError(get_vimo_api()->run_module(m.get(), req_handle.ptr, &rsp_handle.ptr));
    return rsp_handle;
}

}  // namespace internal
}  // namespace vimo
}  // namespace smartmore

#endif
