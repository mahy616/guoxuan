#include "JsonReader.h"
#include <QMessageBox>
//#pragma execution_character_set("utf-8")

// ******************************************** ����Config.json���solutionID���ID��ģ������������****************************************************
ConfigResult JsonReader::GetConfigResult(QString configPath)
{
	// -------------------------------- ��ȡcongig.json�ļ� --------------------------------
	QFile FileConfig(configPath+"/config.json");
	FileConfig.open(QIODevice::ReadOnly | QIODevice::Text);
	if (!FileConfig.isOpen())
	{
		qDebug() << configPath + "�ļ���ʧ��";
	}
	QString value = FileConfig.readAll();
	FileConfig.close();
	QJsonParseError parseJsonErr;
	QJsonDocument document = QJsonDocument::fromJson(value.toStdString().c_str(), &parseJsonErr);
	if (parseJsonErr.error != QJsonParseError::NoError) 
	{
		qDebug() << "json error:" << /*parseJsonErr.to <<*/ ";error path:" << configPath;
		qDebug() << parseJsonErr.errorString();
	}
	qDebug() << document;

	// --------------------------------------Json����-----------------------------------------
	ConfigResult AnayliszeResult;
	if (parseJsonErr.error == QJsonParseError::NoError)
	{
		if (document.isObject())
		{
			QJsonObject rootObj = document.object();
			QString rootpath;
			//�Ƿ���key  Types
			if (rootObj.contains("Version"))
			{
				QJsonValue valueJsonVersion = rootObj.value("Version");
				if (valueJsonVersion.isString())
				{
					std::string tempShow = UTF8ToGBK(valueJsonVersion.toString().toStdString());
					cout << "VersionN�ֶΣ�" << tempShow << std::endl;
					//TargetJson.VersionValue = tempShow;
				}
			}
			if (rootObj.contains("Types"))
			{
				QJsonValue valueArrayTypes = rootObj.value("Types");
				qDebug() << "";
				qDebug() << "valueArray: " << valueArrayTypes;
				//�ж������Ƿ�Ϊarray�����ҽ�array��������
				if (valueArrayTypes.isArray())
				{
					QJsonArray jsonArray = valueArrayTypes.toArray();
					for (int i = 0; i < jsonArray.count(); i++) //Types�ı���
					{
						QJsonValue childValue = jsonArray[i];
						if (childValue.isObject())
						{
							QString child_depid;
							QJsonObject  childObject = childValue.toObject();
							if (childObject.contains("Name"))
							{
								QJsonValue valueJsonName = childObject.value("Name");
								if (valueJsonName.isString())
								{
									std::string ModeName = valueJsonName.toString().toStdString();
									cout << "������Name�ֶΣ�" << ModeName << std::endl;
									AnayliszeResult.TypeName = ModeName;
									//TargetJson.NameValue = ModeName;
								}
							}
							if (childObject.contains("DatasetID"))
							{
								QJsonValue valueJsonName = childObject.value("DatasetID");
								if (valueJsonName.isString())
								{
									std::string ModeName = valueJsonName.toString().toStdString();
									cout << "������DatasetID�ֶΣ�" << ModeName << std::endl;
									//TargetJson.DatasetIDValue = ModeName;
								}
							}
							if (childObject.contains("RealName"))
							{
								QJsonValue valueJsonName = childObject.value("RealName");
								if (valueJsonName.isString())
								{
									std::string ModeName = valueJsonName.toString().toStdString();
									cout << "������RealName�ֶΣ�" << ModeName << std::endl;
									//m_modeInfos.RealNameValue = ModeName;
								}
							}
							if (childObject.contains("Solutions"))
							{
								QJsonValue valueJsonSolutions = childObject.value("Solutions");
								if (valueJsonSolutions.isArray())
								{
									QJsonArray jsonArrayvalueSolutions = valueJsonSolutions.toArray();

									
									for (int j = 0; j < jsonArrayvalueSolutions.count(); j++) //Solutions�ı��� -- ��ǩ��������
									{
										ModelInfos m_modeInfos;
										QJsonValue childValueModel = jsonArrayvalueSolutions[j];
										if (childValueModel.isObject())
										{
											QJsonObject  childObjectName = childValueModel.toObject();
											if (childObjectName.contains("No"))
											{
												QJsonValue valueJsonName = childObjectName.value("No");
												//if (valueJsonName.isEmpty())
												{

													int Solution_ID = valueJsonName.toInt();
													cout << "������Solution_ID��" << Solution_ID << std::endl;
													m_modeInfos.SolutionID = Solution_ID;
												}
											}

											if (childObjectName.contains("Modules"))
											{
												QJsonValue valueJsonFinally = childObjectName.value("Modules");
												//�ж������Ƿ�Ϊarray�����ҽ�array��������
												if (valueJsonFinally.isArray())
												{

													QJsonArray jsonArray = valueJsonFinally.toArray();
													//vector<std::string> m_modeTypeStr; 
													
													for (int ModulesIndex = 0; ModulesIndex < jsonArray.count(); ModulesIndex++) //Modules�ı��� -- ģ������
													{
														QJsonValue childValue = jsonArray[ModulesIndex];
														qDebug() << "";
														qDebug() << childValue << "   end";
														qDebug() << "";
														/*if (j == TargetJson.inSolutionIndex - 1 && ModulesIndex == TargetJson.inModulesIndex - 1)
														{
															TargetJson.TargetModules = childValue;
															std::string trmpShow = childValue.toString().toStdString();
															int sss = 9;
														}*/

														if (childValue.isObject())
														{
															QString child_depid;
															QString child_usernum;
															int child_usern;
															QJsonObject  childObject = childValue.toObject();
															if (childObject.contains("Type"))
															{
																QJsonValue valueJsonLables = childObject.value("Type");
																if (valueJsonLables.isString())
																{
																	std::string tempShow = UTF8ToGBK(valueJsonLables.toString().toStdString());
																	cout << "������JSON�ֶΣ�" << tempShow << std::endl;
																	OneModelInfo m_OneModelInfo;
																	m_OneModelInfo.m_ModeType = tempShow;

																	if (childObject.contains("RealName"))
																	{
																		QJsonValue valueJsonName = childObject.value("RealName");
																		if (valueJsonName.isString())
																		{
																			std::string ModeName22 = valueJsonName.toString().toStdString();
																			ModeName22 = UTF8ToGBK(ModeName22);
																			cout << "������RealName�ֶΣ�" << ModeName22 << std::endl;
																			m_OneModelInfo.RealNameValue = ModeName22;
																		}
																	}
																	if (childObject.contains("Name"))
																	{
																		QJsonValue valueJsonName = childObject.value("Name");
																		if (valueJsonName.isString())
																		{
																			std::string ModeName22 = valueJsonName.toString().toStdString();
																			ModeName22 = UTF8ToGBK(ModeName22);
																			cout << "������RealName�ֶΣ�" << ModeName22 << std::endl;
																			m_OneModelInfo.ModulesName = ModeName22;
																		}
																	}

																	m_modeInfos.ModeType.push_back(m_OneModelInfo);
																	//m_modeTypeStr.push_back(tempShow);
																}
															}
														}
													}
													/*if (ModulesIndex != 0)
													{
														m_modeInfos.ModeType = m_modeTypeStr;
													}*/
													AnayliszeResult.EveryModel.push_back(m_modeInfos);
												}
											}
											//m_modeInfos.ModeType = m_modeTypeStr;
											//AnayliszeResult.EveryModel = m_modeInfos.ModeType;
										}
									}
									if (jsonArrayvalueSolutions.count() != 0)
									{
										//m_ModelNames.push_back(m_LabelNames);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	//�ϲ�Data.JS���Lable

	GetLabelsName(configPath + "/static/data.js", AnayliszeResult);
	/*if (CheckModelNum(AnayliszeResult, AnalysisLables) == false)
	{
		qDebug() << "JSON��������";
		return AnayliszeResult;
	}
	if (GiveModelLables(AnayliszeResult, AnalysisLables) == false)
	{
		qDebug() << "JSON��������";
	}*/
	return AnayliszeResult;
}

void JsonReader::GetLabelsName(QString DataJSPath, ConfigResult &AnayliszeResult)
{
	// ----------------��JS�ļ���ȡJSON�ַ���-----------------
	fstream File_JS;
	File_JS.open(DataJSPath.toLocal8Bit());
	string   strFileContent, strTemp;
	char szTemp[8192] = "";
	File_JS.read(szTemp, 8192);
	std::string DataJSStr = szTemp;
	DataJSStr = UTF8ToGBK(DataJSStr);
	cout << "��ȡǰԭ�ַ���" << DataJSStr << endl;
	int leftIndex = 0, rightIndex = 0;
	for (int i = 0; i < DataJSStr.size(); i++)
	{
		if (DataJSStr[i] == '[')
		{
			leftIndex = i + 1;
			for (int j = DataJSStr.size() - 1; j >= 0; j++)
			{
				if (DataJSStr[j] == ']')
				{
					rightIndex = j;
					break;
				}
			}
			break;
		}
	}
	cout << endl << endl << endl;
	DataJSStr = DataJSStr.substr(leftIndex, rightIndex - leftIndex);
	cout << "��ȡ����ַ���" << DataJSStr << endl;

	//-----------------------JSON����-----------------------
	//bool isiFirst = false; vector<int> m_Vec; int  pushBackNums = 0;
	std::vector<LableInfos> AnalysisStrs; //�������
	QString inStr = QString::fromStdString(DataJSStr);
	QJsonParseError jsonerror;
	std::vector<std::vector<std::string>> m_ModelNames;
	QString temps = QString::fromLocal8Bit(DataJSStr.c_str());
	QJsonDocument json = QJsonDocument::fromJson(temps.toStdString().c_str(), &jsonerror);
	if (jsonerror.error == QJsonParseError::NoError)
	{
		if (json.isObject())
		{
			QJsonObject rootObj = json.object();
			qDebug() << "";
			qDebug() << "rootObj: " << rootObj;
			QString rootpath;
			int rootusernum;
			//�Ƿ���key  Types
			if (rootObj.contains("Modules"))
			{
				QJsonValue valueArray = rootObj.value("Modules");
				qDebug() << "";
				qDebug() << "valueArray: " << valueArray;
				//�ж������Ƿ�Ϊarray�����ҽ�array��������
				if (valueArray.isArray())
				{
					QJsonArray jsonArray = valueArray.toArray();
					for (int i = 0; i < jsonArray.count(); i++) //Modules�ı��� -- ģ������
					{
						QJsonValue childValue = jsonArray[i];

						if (childValue.isObject())
						{
							QString child_depid;
							QString child_usernum;
							int child_usern;
							QJsonObject  childObject = childValue.toObject();
							LableInfos m_LableInfos;

							if (childObject.contains("Solution"))
							{
								
								QJsonValue JsonSolution = childObject.value("Solution");
								QJsonArray m_Solution; int JsonSolutionValue;
								if (JsonSolution.isArray())
								{
									m_Solution = JsonSolution.toArray();
									JsonSolutionValue = m_Solution[0].toInt();

								}
								else
								{
									JsonSolutionValue = JsonSolution.toInt();
								}
								m_LableInfos.SolutionID = JsonSolutionValue;
							}
							if (childObject.contains("Labels"))
							{

								QJsonValue valueJsonLables = childObject.value("Labels");
								if (valueJsonLables.isArray())
								{
									QJsonArray jsonArrayvalueJsonLables = valueJsonLables.toArray();
									std::vector<std::string> m_LabelNames;
									for (int j = 0; j < jsonArrayvalueJsonLables.count(); j++) //Lables�ı��� -- ��ǩ��������
									{
										QJsonValue childValueLables = jsonArrayvalueJsonLables[j];
										if (childValueLables.isObject())
										{
											QJsonObject  childObjectName = childValueLables.toObject();
											if (childObjectName.contains("Name"))
											{
												QJsonValue valueJsonFinally = childObjectName.value("Name");
												child_depid = valueJsonFinally.toString();
												std::string tempShow = UTF8ToGBK(child_depid.toStdString());
												m_LabelNames.push_back(tempShow);
												cout << "������JSON�ֶΣ�" << tempShow << std::endl;

												/*QJsonValue valueJsonFinally = childObjectName.value("Name");
												QString tempsss = valueJsonFinally.toString();
												child_depid = tempsss.toLocal8Bit().data();
												std::string tempShow = UTF8ToGBK(child_depid.toStdString());
												m_LabelNames.push_back(tempShow);
												cout << "������JSON�ֶΣ�" << tempShow << std::endl;*/
											}
										}
									}

									if (childObject.contains("ID"))
									{

										QJsonValue JsonSolution = childObject.value("ID");
										int JsonSolutionValue = JsonSolution.toInt();
										QString NumsChar = QString("%1").arg(JsonSolutionValue);
										FindModuleNumeToInser(NumsChar.toStdString(), AnayliszeResult, m_LabelNames);
									}
								}
							}
							if (childObject.contains("Lables"))
							{

								QJsonValue valueJsonLables = childObject.value("Lables");
								if (valueJsonLables.isArray())
								{
									QJsonArray jsonArrayvalueJsonLables = valueJsonLables.toArray();
									std::vector<std::string> m_LabelNames;
									for (int j = 0; j < jsonArrayvalueJsonLables.count(); j++) //Lables�ı��� -- ��ǩ��������
									{
										QJsonValue childValueLables = jsonArrayvalueJsonLables[j];
										if (childValueLables.isObject())
										{
											QJsonObject  childObjectName = childValueLables.toObject();
											if (childObjectName.contains("Name"))
											{
												QJsonValue valueJsonFinally = childObjectName.value("Name");
												child_depid = valueJsonFinally.toString();
												std::string tempShow = UTF8ToGBK(child_depid.toStdString());
												m_LabelNames.push_back(tempShow);
												cout << "������JSON�ֶΣ�" << tempShow << std::endl;
											}
										}
									}

									if (childObject.contains("ID"))
									{

										QJsonValue JsonSolution = childObject.value("ID");
										int JsonSolutionValue = JsonSolution.toInt();
										QString NumsChar = QString("%1").arg(JsonSolutionValue);
										FindModuleNumeToInser(NumsChar.toStdString(), AnayliszeResult, m_LabelNames);
									}
								}
							}
							AnalysisStrs.push_back(m_LableInfos);
						}
					}
				}
			}
		}
	}
	//return AnalysisStrs;
}

void JsonReader::FindModuleNumeToInser(std::string moduleName, ConfigResult& m_ConfigResult, std::vector<std::string> inLabels)
{
	for (int i = 0; i < m_ConfigResult.EveryModel.size(); i++)
	{
		for (int j = 0; j < m_ConfigResult.EveryModel[i].ModeType.size(); j++)
		{
			if (m_ConfigResult.EveryModel[i].ModeType[j].ModulesName == moduleName)
			{
				m_ConfigResult.EveryModel[i].ModeType[j].LableNames = inLabels;
			}
		}
	}
}

bool JsonReader::CheckModelNum(ConfigResult m_ConfigResult, std::vector<LableInfos> vec_LableInfos)
{
	int ConfigJsonNums = 0;
	for (int i = 0; i < m_ConfigResult.EveryModel.size(); i++)
	{
		//for (int j = 0; j < m_ConfigResult.EveryModel[i].ModeType.size(); j++)
		{
			ConfigJsonNums = ConfigJsonNums + m_ConfigResult.EveryModel[i].ModeType.size();
		}
	}
	if (ConfigJsonNums == vec_LableInfos.size())
		return true;
	else
		return false;
	return true;
}

bool JsonReader::GiveModelLables(ConfigResult& m_ConfigResult, std::vector<LableInfos> vec_LableInfos)
{
	int forIndex = 0;
	for (int i = 0; i < m_ConfigResult.EveryModel.size(); i++)
	{
		for (int j = 0; j < m_ConfigResult.EveryModel[i].ModeType.size(); j++)
		{
			//if (m_ConfigResult.EveryModel[i].SolutionID == vec_LableInfos[forIndex].SolutionID)
			{
				m_ConfigResult.EveryModel[i].ModeType[j].LableNames = vec_LableInfos[forIndex].LableNames;
				forIndex++;
			}	
		}
	}
	if (forIndex == 0)
		return false;
	else
		return true;
}

