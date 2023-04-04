#include "JsonReader.h"
#include <QMessageBox>
//#pragma execution_character_set("utf-8")

// ******************************************** 解析Config.json里的solutionID与各ID的模型数量与类型****************************************************
ConfigResult JsonReader::GetConfigResult(QString configPath)
{
	// -------------------------------- 读取congig.json文件 --------------------------------
	QFile FileConfig(configPath+"/config.json");
	FileConfig.open(QIODevice::ReadOnly | QIODevice::Text);
	if (!FileConfig.isOpen())
	{
		qDebug() << configPath + "文件打开失败";
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

	// --------------------------------------Json解析-----------------------------------------
	ConfigResult AnayliszeResult;
	if (parseJsonErr.error == QJsonParseError::NoError)
	{
		if (document.isObject())
		{
			QJsonObject rootObj = document.object();
			QString rootpath;
			//是否含有key  Types
			if (rootObj.contains("Version"))
			{
				QJsonValue valueJsonVersion = rootObj.value("Version");
				if (valueJsonVersion.isString())
				{
					std::string tempShow = UTF8ToGBK(valueJsonVersion.toString().toStdString());
					cout << "VersionN字段：" << tempShow << std::endl;
					//TargetJson.VersionValue = tempShow;
				}
			}
			if (rootObj.contains("Types"))
			{
				QJsonValue valueArrayTypes = rootObj.value("Types");
				qDebug() << "";
				qDebug() << "valueArray: " << valueArrayTypes;
				//判断类型是否为array，并且将array遍历出来
				if (valueArrayTypes.isArray())
				{
					QJsonArray jsonArray = valueArrayTypes.toArray();
					for (int i = 0; i < jsonArray.count(); i++) //Types的遍历
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
									cout << "解析的Name字段：" << ModeName << std::endl;
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
									cout << "解析的DatasetID字段：" << ModeName << std::endl;
									//TargetJson.DatasetIDValue = ModeName;
								}
							}
							if (childObject.contains("RealName"))
							{
								QJsonValue valueJsonName = childObject.value("RealName");
								if (valueJsonName.isString())
								{
									std::string ModeName = valueJsonName.toString().toStdString();
									cout << "解析的RealName字段：" << ModeName << std::endl;
									//m_modeInfos.RealNameValue = ModeName;
								}
							}
							if (childObject.contains("Solutions"))
							{
								QJsonValue valueJsonSolutions = childObject.value("Solutions");
								if (valueJsonSolutions.isArray())
								{
									QJsonArray jsonArrayvalueSolutions = valueJsonSolutions.toArray();

									
									for (int j = 0; j < jsonArrayvalueSolutions.count(); j++) //Solutions的遍历 -- 标签个数数量
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
													cout << "解析的Solution_ID：" << Solution_ID << std::endl;
													m_modeInfos.SolutionID = Solution_ID;
												}
											}

											if (childObjectName.contains("Modules"))
											{
												QJsonValue valueJsonFinally = childObjectName.value("Modules");
												//判断类型是否为array，并且将array遍历出来
												if (valueJsonFinally.isArray())
												{

													QJsonArray jsonArray = valueJsonFinally.toArray();
													//vector<std::string> m_modeTypeStr; 
													
													for (int ModulesIndex = 0; ModulesIndex < jsonArray.count(); ModulesIndex++) //Modules的遍历 -- 模型数量
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
																	cout << "解析的JSON字段：" << tempShow << std::endl;
																	OneModelInfo m_OneModelInfo;
																	m_OneModelInfo.m_ModeType = tempShow;

																	if (childObject.contains("RealName"))
																	{
																		QJsonValue valueJsonName = childObject.value("RealName");
																		if (valueJsonName.isString())
																		{
																			std::string ModeName22 = valueJsonName.toString().toStdString();
																			ModeName22 = UTF8ToGBK(ModeName22);
																			cout << "解析的RealName字段：" << ModeName22 << std::endl;
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
																			cout << "解析的RealName字段：" << ModeName22 << std::endl;
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

	//合并Data.JS里的Lable

	GetLabelsName(configPath + "/static/data.js", AnayliszeResult);
	/*if (CheckModelNum(AnayliszeResult, AnalysisLables) == false)
	{
		qDebug() << "JSON解析错误";
		return AnayliszeResult;
	}
	if (GiveModelLables(AnayliszeResult, AnalysisLables) == false)
	{
		qDebug() << "JSON解析错误";
	}*/
	return AnayliszeResult;
}

void JsonReader::GetLabelsName(QString DataJSPath, ConfigResult &AnayliszeResult)
{
	// ----------------从JS文件截取JSON字符串-----------------
	fstream File_JS;
	File_JS.open(DataJSPath.toLocal8Bit());
	string   strFileContent, strTemp;
	char szTemp[8192] = "";
	File_JS.read(szTemp, 8192);
	std::string DataJSStr = szTemp;
	DataJSStr = UTF8ToGBK(DataJSStr);
	cout << "截取前原字符：" << DataJSStr << endl;
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
	cout << "截取后的字符：" << DataJSStr << endl;

	//-----------------------JSON解析-----------------------
	//bool isiFirst = false; vector<int> m_Vec; int  pushBackNums = 0;
	std::vector<LableInfos> AnalysisStrs; //解析结果
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
			//是否含有key  Types
			if (rootObj.contains("Modules"))
			{
				QJsonValue valueArray = rootObj.value("Modules");
				qDebug() << "";
				qDebug() << "valueArray: " << valueArray;
				//判断类型是否为array，并且将array遍历出来
				if (valueArray.isArray())
				{
					QJsonArray jsonArray = valueArray.toArray();
					for (int i = 0; i < jsonArray.count(); i++) //Modules的遍历 -- 模型数量
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
									for (int j = 0; j < jsonArrayvalueJsonLables.count(); j++) //Lables的遍历 -- 标签个数数量
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
												cout << "解析的JSON字段：" << tempShow << std::endl;

												/*QJsonValue valueJsonFinally = childObjectName.value("Name");
												QString tempsss = valueJsonFinally.toString();
												child_depid = tempsss.toLocal8Bit().data();
												std::string tempShow = UTF8ToGBK(child_depid.toStdString());
												m_LabelNames.push_back(tempShow);
												cout << "解析的JSON字段：" << tempShow << std::endl;*/
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
									for (int j = 0; j < jsonArrayvalueJsonLables.count(); j++) //Lables的遍历 -- 标签个数数量
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
												cout << "解析的JSON字段：" << tempShow << std::endl;
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

