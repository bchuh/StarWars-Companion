#pragma once
#include <QString>
#include <QtTest>
#include <QCoreApplication>

//注意定义对象之间的冲突
//#define CAMERAS
//#define DLLMODEL
//#define FRONTER
//#define SUBWIDGET

#include "camera_module.h"

/*文件说明，主要采用Qt自身携带的单元测试框架，QTest进行测试，因为主要都是Qt工程，因此采用选择此框架*/

class qtest : public QObject
{
	Q_OBJECT

public:
	qtest();

	private Q_SLOTS:
	void initTestCase();
	void cleanupTestCase();

	//正向测试
	void testCase1();
	void testCase2();

    //反向测试
	void testCase3();
	void testCase4();

private:

#ifdef CAMERAS
	/*以单列的形式获取对象*/
	Camera* cam;
#endif // CAMERA

#ifdef DLLMODEL
	/*以单列的形式获取对象*/
	Camera* cams;
	DLmodule *model；
#endif // DLLMODEL

#ifdef FRONTER
	/*以单列的形式获取对象*/
	MainWindow* fronter;
#endif // DLLMODEL

#ifdef SUBWIDGET
	/*初始化控件对象，并不需要实际运行，因为是lib*/
	subwidget *m_subwidget;
#endif // DEBUG

};