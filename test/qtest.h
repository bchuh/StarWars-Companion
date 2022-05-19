#pragma once
#include <QString>
#include <QtTest>
#include <QCoreApplication>

//ע�ⶨ�����֮��ĳ�ͻ
//#define CAMERAS
//#define DLLMODEL
//#define FRONTER
//#define SUBWIDGET

#include "camera_module.h"

/*�ļ�˵������Ҫ����Qt����Я���ĵ�Ԫ���Կ�ܣ�QTest���в��ԣ���Ϊ��Ҫ����Qt���̣���˲���ѡ��˿��*/

class qtest : public QObject
{
	Q_OBJECT

public:
	qtest();

	private Q_SLOTS:
	void initTestCase();
	void cleanupTestCase();

	//�������
	void testCase1();
	void testCase2();

    //�������
	void testCase3();
	void testCase4();

private:

#ifdef CAMERAS
	/*�Ե��е���ʽ��ȡ����*/
	Camera* cam;
#endif // CAMERA

#ifdef DLLMODEL
	/*�Ե��е���ʽ��ȡ����*/
	Camera* cams;
	DLmodule *model��
#endif // DLLMODEL

#ifdef FRONTER
	/*�Ե��е���ʽ��ȡ����*/
	MainWindow* fronter;
#endif // DLLMODEL

#ifdef SUBWIDGET
	/*��ʼ���ؼ����󣬲�����Ҫʵ�����У���Ϊ��lib*/
	subwidget *m_subwidget;
#endif // DEBUG

};