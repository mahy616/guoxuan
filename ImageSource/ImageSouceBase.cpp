#include "ImageSouceBase.h"

void ImageSourceBase::SetMyPtr(MyStation* inStation)
{
	m_Station = inStation;
}

MyStation* ImageSourceBase::GetMyPtr()
{
	return m_Station;
}

bool ImageSourceBase::isCameraSource()
{
	char *m_Temp = (char*)typeid(*this).name();
	string JudgeStr = m_Temp;
	JudgeStr = JudgeStr.substr(6, JudgeStr.size() - 6);
	if (JudgeStr == "ImageSourceCamera")
		return true;
	else
		return false;
}