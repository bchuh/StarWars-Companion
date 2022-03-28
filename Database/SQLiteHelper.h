#pragma once
#include <sqlite3.h>
#include <windows.h>
#include <string>
class SQLiteHelper
{
public:
	SQLiteHelper();
	virtual ~SQLiteHelper();
	sqlite3* db;    //数据库本身
	char* nameQuery(int ID);   //查询name函数
	//char* infoQuery(int ID); //查询info函数
	//char* picQuery(int ID);  //查询picture函数
    bool openDB(char* path);   //打开数据库
	void closeDB();            //关闭数据库
};
