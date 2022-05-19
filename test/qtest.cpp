#include "qtest.h"
#include "qdebug.h"

qtest::qtest()
{
#ifdef CAMERAS
		cam = Camera::getInstance();
	#endif // CAMERAS
#ifdef DLLMODEL
		cams = Camera::getInstance();
		model = DLmodule::getInstance();
#endif // CAMERAS
}

void qtest::initTestCase()
{
#ifdef CAMERAS
	//1.测试用例1，判断单列是否获取成功
	if (cam != NULL)
	{
		qDebug() << "单列初始化成功" << endl;
	}
	else
	{
		qDebug() << "单列初始化失败" << endl;
	}
#endif // CAMERAS

#ifdef DLLMODEL
	//1.测试用例1，判断单列是否获取成功
	m_subwidget = new subwidget();
	if (m_subwidget == NULL)
	{
		qDebug() << "测试用例1，实例失败" << endl;
	}
#endif // CAMERAS

#ifdef FRONTER
	//1.测试用例1，判断单列是否获取成功
	MainWindow = new MainWindow();
	if (MainWindow == NULL)
	{
		qDebug() << "测试用例1，实例失败" << endl;
	}
#endif // CAMERAS

#ifdef SUBWIDGET
	//1.测试用例1，判断单列是否获取成功
	m_subwidget = new subwidget();
	if (m_subwidget == NULL)
	{
		qDebug() << "测试用例1，实例失败" << endl;
	}
#endif // CAMERAS
	
}

void qtest::cleanupTestCase()
{

}
/*
@ 测试是否存在相机数量
*/
void qtest::testCase1()
{
#ifdef CAMERAS
	if (cam->getCamNum() <= 0)
		qDebug << "No camera detected!" << endl;
#endif // CAMERAS

#ifdef FRONTER
	//线程是否可以外部启动测试
	MainWindow->run();
#endif // CAMERAS

#ifdef SUBWIDGET
	//线程是否可以外部启动测试
	QTest::keyClicks(&Back, "返回按钮可以点击");
	QTest::keyClicks(&Previous, "前一页可以点击");
	QTest::keyClicks(&Next, "下一页可以点击");
#endif // CAMER
	
}

/*
@ 测试是否能都显示相机
*/
void qtest::testCase2()
{ 
#ifdef CAMERAS
	while (true)
	{
		auto frame = cam->nextFrame();
		cv::imshow("读取视频", frame);
		if (cv::waitKey(1) != -1)
		{
			Camera::Destory();
			std::cout << "finished by user\n";
			break;
		}
	}
#endif // CAMERAS

#ifdef DLLMODEL
	int result;
	while (true)
	{
		auto frame = cam->nextFrame();
		cv::imshow("读取视频", frame);
		result = model->classify(frame);
		std::cout << result << endl;
		if (cv::waitKey(1) != -1)
		{
			Camera::Destory();
			DLmodule::Destory();
			std::cout << "finished by user\n";
			break;
		}
	}
#endif // CAMERAS

#ifdef SUBWIDGET
	m_subwidget->setID(0xFFFFFFFF);
	//这里给出一个警告，因为没有返回值
	qDebug() << "测试用例1，没有返回值，无法测试是否正常" << endl;
#endif // CAMERAS
}
/*
@ 如果相机数量大于1，是随机选择吗？
*/
void  qtest::testCase3()
{
#ifdef CAMERAS
	if (cam->getCamNum() >= 1)
		qDebug << "camera——module未对相机大于1的做出处理或者相机数量大于" << endl;
#endif // CAMERAS
}
/*
@ 如果nextFrame 传入任意值会导致程序崩溃吗
*/
void  qtest::testCase4()
{
#ifdef CAMERAS
	while (true)
	{
		auto frame = cam->nextFrame(200,200);
		cv::imshow("读取视频", frame);
		if (cv::waitKey(1) != -1)
		{
			Camera::Destory();
			std::cout << "finished by user\n";
			break;
		}
#endif // CAMERAS

#ifdef SUBWIDGET
		on_Next_clicked();
		on_Back_clicked();
#endif // CAMERAS

}
QTEST_MAIN(qtest)

