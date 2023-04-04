#pragma once

#include <QObject>
#include <QDoubleValidator>

class MyDoubleValidator  : public QDoubleValidator
{
	Q_OBJECT

public:
	MyDoubleValidator(QObject *parent);
	~MyDoubleValidator();
	MyDoubleValidator(double bottom, double top, int decimals, QObject *parent = nullptr);
	virtual QValidator::State validate(QString &input, int &pos) const;
};
