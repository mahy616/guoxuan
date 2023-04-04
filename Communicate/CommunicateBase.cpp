#include "CommunicateBase.h"

bool CommunicateBase::Write(QString message)
{
	return true;
}

bool CommunicateBase::Write(QString address, QString message)
{
	return true;
}
bool CommunicateBase::Write(QString address, int inNum)
{
	return true;
}
bool CommunicateBase::Write(QString address, double infloat)
{
	return true;
}
bool CommunicateBase::Read(QString address, QString &input)
{
	return true;
}
bool CommunicateBase::Read(QString address, int &input)
{
	return true;
}
bool CommunicateBase::Read(QString address, double &input)
{
	return true;
}

bool CommunicateBase::isConnectting()
{
	return isConnect;
}