#include "MyDoubleValidator.h"

MyDoubleValidator::MyDoubleValidator(QObject *parent)
	: QDoubleValidator(parent)
{}

MyDoubleValidator::~MyDoubleValidator()
{}

MyDoubleValidator::MyDoubleValidator(double bottom, double top, int decimals, QObject *parent) :QDoubleValidator(parent)
{
	setRange(bottom, top, decimals);
}

QValidator::State MyDoubleValidator::validate(QString & input, int & pos) const
{
	if (input.isEmpty())
	{
		return QValidator::Intermediate;
	}
	bool OK = false;
	double val = input.toDouble(&OK);

	if (!OK)
	{
		return QValidator::Invalid;
	}

	int dotPos = input.indexOf(".");
	if (dotPos > 0)
	{
		if (input.right(input.length() - dotPos - 1).length() > decimals())
		{
			return QValidator::Invalid;
		}
	}

	if (val <= top() && val >= bottom())
		return QValidator::Acceptable;

	while (1)
	{
		if (val < bottom())
			val = val * 10;
		if (val <= top() && val >= bottom())
			return QValidator::Intermediate;
		if (val > top())
			return QValidator::Invalid;
	}
}
