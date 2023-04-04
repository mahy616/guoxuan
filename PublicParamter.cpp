#include "PublicParamter.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

string StrReader(string inStr, int nPos, bool isLeft)
{
	string returnStr;
	if (isLeft == true)
	{
		for (int i = nPos - 1; i >= 0; i--) //往左
		{
			if (inStr[i] == ' ')
			{
				break;
			}
			returnStr = returnStr + inStr[i];
		}
	}
	else
	{
		for (int i = nPos + 1; i < inStr.size() - 1; i++) //往左
		{
			if (inStr[i] == ' ')
			{
				break;
			}
			returnStr = returnStr + inStr[i];
		}
	}
	reverse(returnStr.begin(), returnStr.end());
	return returnStr;
}
std::vector<GpuInfos> GetResultFromCMD()
{
	std::vector<GpuInfos> returnVec;
	char MsgBuff[1024];
	int MsgLen = 1020;
	FILE * fp;
	if ((fp = _popen("nvidia-smi", "r")) == NULL)
	{
		return returnVec;
	}
	else
	{
		memset(MsgBuff, 0, MsgLen);
		//读取命令执行过程中的输出
		int Index = 0; int MaxIndex = 1000;
		while (fgets(MsgBuff, MsgLen, fp) != NULL)
		{
			Index++;
			string GetChar = MsgBuff;
			bool isEmpty = true;;
			for (int i = 0; i < GetChar.size() - 1; i++)
			{
				if (GetChar[i] != ' ')
				{
					isEmpty = false;
				}
			}
			if (isEmpty)
				MaxIndex = Index;
			if (Index >= 8 && Index < MaxIndex)
			{
				if ((Index - 10) % 4 == 0)
				{
					GpuInfos OneInfos;
					//printf("MsgBuff: %s\n", MsgBuff);
					string GetStr = MsgBuff; string FirstMibStr;
					//cout << "------------------------Start-------------------------------" << endl;
					for (int j = 0; j < GetStr.size() - 1; j++)
					{
						switch (GetStr[j])
						{
						case 'C':
							OneInfos.Temperature = StrReader(GetStr, j, true) + "C";
							//cout << "温度：" << StrReader(GetStr, j, true) << "C" << endl;
							break;
						case 'P':
							OneInfos.Performance = "P" + StrReader(GetStr, j, false);
							//cout << "性能：P" << StrReader(GetStr, j, false) << endl;
							break;
						case 'W':
							OneInfos.Power = StrReader(GetStr, j, true) + "W";
							//cout << "功率：" << StrReader(GetStr, j, true) << "W" << endl;
							break;
						case 'M':
							if (OneInfos.AvailableMemory == -1)
							{
								OneInfos.AvailableMemory = atoi(StrReader(GetStr, j, true).c_str());
								//cout << "可用显存：" << StrReader(GetStr, j, true) << "MiB" << endl;
							}
							else
							{
								OneInfos.MaxMemory = atoi(StrReader(GetStr, j, true).c_str());
								//cout << "最大显存：" << StrReader(GetStr, j, true) << "MiB" << endl;
							}
							break;
						case '%':
							OneInfos.Utilization = StrReader(GetStr, j, true) + "%";
							//cout << "利用率：" << StrReader(GetStr, j, true) << "%" << endl;
							break;
						default:
							break;
						}
					}
					returnVec.push_back(OneInfos);
					//cout << "------------------------End-------------------------------" << endl << endl;
				}
			}
		}
		//关闭执行的进程
		if (_pclose(fp) == -1)
		{
			//return returnVec;
		}
	}
	return returnVec;
}

std::string UTF8ToGBK(const std::string& strUTF8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8.c_str(), -1, NULL, 0);
	WCHAR* wszGBK = new WCHAR[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)(LPCTSTR)strUTF8.c_str(), -1, wszGBK, len);

	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char *szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
	std::string strTemp(szGBK);
	delete[]szGBK;
	delete[]wszGBK;
	return strTemp;
}

void ClearLayout(QLayout* m_pMainLayout)
{
	while (m_pMainLayout->count())
	{
		QWidget *pWidget = m_pMainLayout->itemAt(0)->widget();
		if (pWidget)
		{
			pWidget->setParent(NULL);

			m_pMainLayout->removeWidget(pWidget);
			delete pWidget;
		}
		else
		{
			QLayout *pLayout = m_pMainLayout->itemAt(0)->layout();
			if (pLayout)
			{
				while (pLayout->count())
				{
					QWidget *pTempWidget = pLayout->itemAt(0)->widget();
					if (pTempWidget)
					{
						pTempWidget->setParent(NULL);

						pLayout->removeWidget(pTempWidget);
						delete pTempWidget;
					}
					else
					{
						pLayout->removeItem(pLayout->itemAt(0));
					}
				}
			}

			m_pMainLayout->removeItem(m_pMainLayout->itemAt(0));
		}
	}
}

SdkModelType GetModelTypeFromString(string inStr)
{
	if (inStr == "segmentation")
		return Segmentation;
	else if (inStr == "detection")
		return Detection;
	else if (inStr == "classification")
		return Classification;
	else if (inStr == "ocr")
		return OCR;
	return Segmentation;
}

QString GetStringFromModelType(SdkModelType inType)
{
	switch (inType)
	{
	case Segmentation:
		return QString("Segmentation");
	case Detection:
		return QString("Detection");
	case Classification:
		return QString("Classification");
	case OCR:
		return QString("OCR");
	default:
		break;
	}
	return "error";
}

void DeleteOldWidget(std::vector<QLineEdit*> inParam)
{
	for (auto OnePtr : inParam)
	{
		delete OnePtr;
	}
	inParam.clear();
}

void DeleteOldWidget(std::vector<QPushButton*> inParam)
{
	for (auto OnePtr : inParam)
	{
		delete OnePtr;
	}
	inParam.clear();
}

bool isChineseLanguage()
{
	QFile fileWhitchPro(".//config//language.json");
	if (fileWhitchPro.exists())
	{
		fileWhitchPro.open(QIODevice::ReadOnly);
		auto dataWhitchPro = fileWhitchPro.readAll();
		fileWhitchPro.close();
		QJsonParseError jErrorWhitchPro;	//创建QJsonParseError对象
		QJsonDocument jsonDocWhitchPro = QJsonDocument::fromJson(dataWhitchPro, &jErrorWhitchPro);
		if (jErrorWhitchPro.error == QJsonParseError::NoError)
		{
			QJsonObject rootObjWhitchPro = jsonDocWhitchPro.object();
			QJsonValue valueArrayTypes = rootObjWhitchPro.value("Language");
			if (valueArrayTypes.toInt() == 1)
			{
				return true;
			}
		}
	}
	return false;
}

QImage MattoQImage(cv::Mat image)
{
	switch (image.type())
	{
	case CV_8UC1:
	{
		QImage img((const unsigned char *)(image.data), image.cols, image.rows, image.cols, QImage::Format_Grayscale8);
		return img;
	}
	break;
	case CV_8UC3:
	{
		QImage img((const unsigned char *)(image.data), image.cols, image.rows, image.cols * 3, QImage::Format_RGB888);
		return img.rgbSwapped();
	}
	break;
	default:
	{
		QImage img;
		return img;
	}
	break;
	}
}