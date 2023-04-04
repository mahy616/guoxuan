#pragma once
#include "ViMoAlgoBase.h"

class AlgoViMo
{
public:
	~AlgoViMo();
	// 传入的是一个module配置信息数组，可以串联多个模型
	bool InintAlgo(std::vector<ModelConfig> inConfig);  
	// 运行算法:: outRenderImage渲染图，outResultJson结果字符串，outMilliseconds算法运行时间，outIsOk输出Ok/Ng
	bool RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, QString &outResultJson, double &outMilliseconds, bool &outIsOk);   
	// 设置阈值 -> 传入的是所有类型阈值变量的结构体，函数里再把结构体对应的阈值赋值给子类m_Threshold
	void SetThresholdParam(std::vector<ThresholdParams> inParam); 
	// 显示设置
	void SetRenderShowParam(std::vector<RenderShowParams> inParam);
	// 获取当前阈值
	std::vector<AllThreshold> GetThresholdValue();
	// 获取当前模型信息
	std::vector<ViMoModelInfo> GetModelInfo();
private:
	std::vector<ViMoAlgoBase*> m_ViMoAlogVec; //module实例数组，对应串联的各个模型实例
};

