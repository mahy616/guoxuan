#pragma once

#include <QWidget>
#include "ui_DialogMCBinSetting.h"

class CommunicateMC_Bin;
class DialogMCBinSetting : public QWidget
{
	Q_OBJECT

public:
	DialogMCBinSetting(CommunicateMC_Bin *in_MCBin, QWidget *parent = nullptr);
	~DialogMCBinSetting();
private:
	void InitVariables();
	void InitConnections();
	void updateCtrls(bool isConnected);
private:
	Ui::DialogMCBinSettingClass ui;
	CommunicateMC_Bin *m_MCBin;
};
