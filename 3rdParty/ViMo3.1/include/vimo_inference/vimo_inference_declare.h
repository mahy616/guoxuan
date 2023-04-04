#ifndef VIMO_INFERENCE_DECLARE_H
#define VIMO_INFERENCE_DECLARE_H

#include <exception>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

#include "internal/vimo_inference_c_api.h"
#include "request.h"
#include "response.h"
#include "solution.h"

namespace smartmore
{
namespace vimo
{
enum class ErrorCode
{
    kSuccess = 0,

    kInvalidArgument = 10000,

    kFileNotExists = 10001,

    kInvalidImageData = 10002,

    kNotInit = 10003,

    kValidateFailed = 10004,

    kSolutionLoadFailed = 20000,

    kModuleCreateFailed = 20100,

    kPipelinesCreateFailed = 20200,

    kInternalError = 30000,
};

class VimoException : public std::exception
{
   public:
    VimoException(ErrorCode code, const std::string &message) : code_(code), message_(message) {}
    ~VimoException() {}
    ErrorCode Code() const noexcept { return code_; }

    const char *what() const noexcept override { return message_.c_str(); }

   private:
    ErrorCode code_;
    std::string message_;
};

enum class LogLevel
{
    kError,
    kWarning,
    kInfo,
    kDebug,
    kTrace
};
struct LoggerConfig
{
    LogLevel level = LogLevel::kWarning;
    std::string file_path;
};

LoggerConfig GetLoggerConfig();
void SetLoggerConfig(const LoggerConfig &config);

/**
 * @brief Draw response to image
 *
 * @param rsp
 * @param image
 */
void Visualize(const Response &rsp, cv::Mat &image);

/**
 * @brief get SDK version
 *
 * @return const std::string&
 */
std::string Version();

std::vector<std::pair<std::string, cv::Rect> > ConvertResponseToBoundingBox(const Response &rsp);

/**
 * @brief roi align
 *
 * impl:
 * new_x      = roi.x + shifting.x - padding.x;
 * new_y      = roi.y + shifting.y - padding.y;
 * new_width  = roi.width + 2 * padding.x;
 * new_height = roi.height + 2 * padding.y;
 *
 * @param roi
 * @param shifting
 * @param padding
 * @return cv::Rect
 */
cv::Rect RoiAlign(cv::Rect roi, cv::Point shifting, cv::Size padding);

}  // namespace vimo
}  // namespace smartmore

#endif
