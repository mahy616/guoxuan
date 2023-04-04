#pragma once
#include <QtWidgets/QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QToolBar>
#include <QToolButton>
#include <QSpacerItem>

enum ButtonType
{
	MIN_BUTTON = 0,         // ��С���͹رհ�ť;
	MIN_MAX_BUTTON,        // ��С������󻯺͹رհ�ť;
	ONLY_CLOSE_BUTTON       // ֻ�йرհ�ť;
};
enum TittleType
{
	MinBUTTON = 0,         // ��С��
	MaxBUTTON,             // ���
	RestoreBUTTON,         // ��ԭ��ť
	CloseBUTTON,           // �رհ�ť
	SoftInfo,             // ���
	LogoImage,			   // ��˾logoͼƬ
	SoftName,              // �����������
};

class MyTitleBar : public QToolBar
{
	Q_OBJECT

public:
	MyTitleBar(QWidget *parent);
	//����parentû�и�Ĭ��ֵNULL����֤�ڴ���MyTitleBar����ʱ��ָ�����ø�ֵ;�Ҹ�ֵ��ΪNULL;
	~MyTitleBar();
	// ��ʼ���ؼ���������ֵ�谴��ѭ��;
	void initControl(std::vector<TittleType> tittleTypes);
	// ������ʽ�ļ�;
	void loadStyleSheet(const QString &sheetName);
	// ���ñ���������ɫ���Ƿ����ñ���������ɫ͸��;
	void setBackgroundColor(int r, int g, int b, bool isTransparent = false);
	// ���ñ�����ͼ��;
	void setTitleIcon(QString filePath, QSize IconSize = QSize(25, 25));
	// ���ñ�������;
	void setTitleContent(QString titleContent, int titleFontSize = 9);
	// ���ñ���������;
	void setTitleWidth(int width);
	// ����logo�Ƿ�ɼ�
	void SetLogoVisuable(bool isSee);
	// ��ȡ��ǰlogo�Ƿ�ɼ�
	bool GetLogoVisuable();
	// ��ȡ��������
	QString GetSoftName();
	// ���ñ������еı����Ƿ�����;������Կ�Ч��;
	//void setTitleRoll();
	// ���ô��ڱ߿���;
	void setWindowBorderWidth(int borderWidth);
	// ����/��ȡ ���ǰ���ڵ�λ�ü���С;
	void saveRestoreInfo(const QPoint point, const QSize size);
	void getRestoreInfo(QPoint& point, QSize& size);

private:
	void paintEvent(QPaintEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
// ��ť�������ź�;
signals:
	void signalButtonMinClicked();
signals:
	void signalButtonRestoreClicked();
signals:
	void signalButtonMaxClicked();
signals:
	void signalButtonCloseClicked();

public slots:
	// ��ť�����Ĳ�;
	void onButtonMinClicked();
	void onButtonRestoreClicked();
	void onButtonMaxClicked();
	void onButtonCloseClicked();
	void onButtonSoftInfo();
public:
	QLabel* m_pIcon;                    // ������ͼ��;
	QLabel* m_pTitleContent;            // ����������;
	QToolButton * m_pButtonSoftInfo;          // ��С����ť;
	QToolButton * m_pButtonMin;          // ��С����ť;
	QToolButton * m_pButtonRestore;      // ��󻯻�ԭ��ť;
	QToolButton * m_pButtonMax;          // ��󻯰�ť;
	QToolButton * m_pButtonClose;        // �رհ�ť;
	QAction* QAction_MaxBtn;
	QAction* QAction_RestoreBtn;
	QAction* QAction_Logo;

	// ����������ɫ;
	int m_colorR;
	int m_colorG;
	int m_colorB;

	// ��󻯣���С������;
	QPoint m_restorePos;
	QSize m_restoreSize;
	// �ƶ����ڵı���;
	bool m_isPressed;
	QPoint m_startMovePos;
	// ����������;
	QString m_titleContent;
	// ���ڱ߿���;
	int m_windowBorderWidth;
	// �������Ƿ�͸��;
	bool m_isTransparent;
	bool isMax;
	bool isLogoVisuable;
};

