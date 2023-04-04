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
	MIN_BUTTON = 0,         // 最小化和关闭按钮;
	MIN_MAX_BUTTON,        // 最小化、最大化和关闭按钮;
	ONLY_CLOSE_BUTTON       // 只有关闭按钮;
};
enum TittleType
{
	MinBUTTON = 0,         // 最小化
	MaxBUTTON,             // 最大化
	RestoreBUTTON,         // 还原按钮
	CloseBUTTON,           // 关闭按钮
	SoftInfo,             // 最大化
	LogoImage,			   // 公司logo图片
	SoftName,              // 软件标题文字
};

class MyTitleBar : public QToolBar
{
	Q_OBJECT

public:
	MyTitleBar(QWidget *parent);
	//这里parent没有给默认值NULL，保证在创建MyTitleBar对象时父指针必须得赋值;且赋值不为NULL;
	~MyTitleBar();
	// 初始化控件，容器的值需按照循序;
	void initControl(std::vector<TittleType> tittleTypes);
	// 加载样式文件;
	void loadStyleSheet(const QString &sheetName);
	// 设置标题栏背景色及是否设置标题栏背景色透明;
	void setBackgroundColor(int r, int g, int b, bool isTransparent = false);
	// 设置标题栏图标;
	void setTitleIcon(QString filePath, QSize IconSize = QSize(25, 25));
	// 设置标题内容;
	void setTitleContent(QString titleContent, int titleFontSize = 9);
	// 设置标题栏长度;
	void setTitleWidth(int width);
	// 设置logo是否可见
	void SetLogoVisuable(bool isSee);
	// 获取当前logo是否可见
	bool GetLogoVisuable();
	// 获取标题内容
	QString GetSoftName();
	// 设置标题栏中的标题是否会滚动;具体可以看效果;
	//void setTitleRoll();
	// 设置窗口边框宽度;
	void setWindowBorderWidth(int borderWidth);
	// 保存/获取 最大化前窗口的位置及大小;
	void saveRestoreInfo(const QPoint point, const QSize size);
	void getRestoreInfo(QPoint& point, QSize& size);

private:
	void paintEvent(QPaintEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
// 按钮触发的信号;
signals:
	void signalButtonMinClicked();
signals:
	void signalButtonRestoreClicked();
signals:
	void signalButtonMaxClicked();
signals:
	void signalButtonCloseClicked();

public slots:
	// 按钮触发的槽;
	void onButtonMinClicked();
	void onButtonRestoreClicked();
	void onButtonMaxClicked();
	void onButtonCloseClicked();
	void onButtonSoftInfo();
public:
	QLabel* m_pIcon;                    // 标题栏图标;
	QLabel* m_pTitleContent;            // 标题栏内容;
	QToolButton * m_pButtonSoftInfo;          // 最小化按钮;
	QToolButton * m_pButtonMin;          // 最小化按钮;
	QToolButton * m_pButtonRestore;      // 最大化还原按钮;
	QToolButton * m_pButtonMax;          // 最大化按钮;
	QToolButton * m_pButtonClose;        // 关闭按钮;
	QAction* QAction_MaxBtn;
	QAction* QAction_RestoreBtn;
	QAction* QAction_Logo;

	// 标题栏背景色;
	int m_colorR;
	int m_colorG;
	int m_colorB;

	// 最大化，最小化变量;
	QPoint m_restorePos;
	QSize m_restoreSize;
	// 移动窗口的变量;
	bool m_isPressed;
	QPoint m_startMovePos;
	// 标题栏内容;
	QString m_titleContent;
	// 窗口边框宽度;
	int m_windowBorderWidth;
	// 标题栏是否透明;
	bool m_isTransparent;
	bool isMax;
	bool isLogoVisuable;
};

