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
	//1.��������1���жϵ����Ƿ��ȡ�ɹ�
	if (cam != NULL)
	{
		qDebug() << "���г�ʼ���ɹ�" << endl;
	}
	else
	{
		qDebug() << "���г�ʼ��ʧ��" << endl;
	}
#endif // CAMERAS

#ifdef DLLMODEL
	//1.��������1���жϵ����Ƿ��ȡ�ɹ�
	m_subwidget = new subwidget();
	if (m_subwidget == NULL)
	{
		qDebug() << "��������1��ʵ��ʧ��" << endl;
	}
#endif // CAMERAS

#ifdef FRONTER
	//1.��������1���жϵ����Ƿ��ȡ�ɹ�
	MainWindow = new MainWindow();
	if (MainWindow == NULL)
	{
		qDebug() << "��������1��ʵ��ʧ��" << endl;
	}
#endif // CAMERAS

#ifdef SUBWIDGET
	//1.��������1���жϵ����Ƿ��ȡ�ɹ�
	m_subwidget = new subwidget();
	if (m_subwidget == NULL)
	{
		qDebug() << "��������1��ʵ��ʧ��" << endl;
	}
#endif // CAMERAS
	
}

void qtest::cleanupTestCase()
{

}
/*
@ �����Ƿ�����������
*/
void qtest::testCase1()
{
#ifdef CAMERAS
	if (cam->getCamNum() <= 0)
		qDebug << "No camera detected!" << endl;
#endif // CAMERAS

#ifdef FRONTER
	//�߳��Ƿ�����ⲿ��������
	MainWindow->run();
#endif // CAMERAS

#ifdef SUBWIDGET
	//�߳��Ƿ�����ⲿ��������
	QTest::keyClicks(&Back, "���ذ�ť���Ե��");
	QTest::keyClicks(&Previous, "ǰһҳ���Ե��");
	QTest::keyClicks(&Next, "��һҳ���Ե��");
#endif // CAMER
	
}

/*
@ �����Ƿ��ܶ���ʾ���
*/
void qtest::testCase2()
{ 
#ifdef CAMERAS
	while (true)
	{
		auto frame = cam->nextFrame();
		cv::imshow("��ȡ��Ƶ", frame);
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
		cv::imshow("��ȡ��Ƶ", frame);
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
	//�������һ�����棬��Ϊû�з���ֵ
	qDebug() << "��������1��û�з���ֵ���޷������Ƿ�����" << endl;
#endif // CAMERAS
}
/*
@ ��������������1�������ѡ����
*/
void  qtest::testCase3()
{
#ifdef CAMERAS
	if (cam->getCamNum() >= 1)
		qDebug << "camera����moduleδ���������1������������������������" << endl;
#endif // CAMERAS
}
/*
@ ���nextFrame ��������ֵ�ᵼ�³��������
*/
void  qtest::testCase4()
{
#ifdef CAMERAS
	while (true)
	{
		auto frame = cam->nextFrame(200,200);
		cv::imshow("��ȡ��Ƶ", frame);
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

