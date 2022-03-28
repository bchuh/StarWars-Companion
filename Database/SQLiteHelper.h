#pragma once
#include <sqlite3.h>
#include <windows.h>
#include <string>
class SQLiteHelper
{
public:
	SQLiteHelper();
	virtual ~SQLiteHelper();
	sqlite3* db;    //���ݿⱾ��
	char* nameQuery(int ID);   //��ѯname����
	//char* infoQuery(int ID); //��ѯinfo����
	//char* picQuery(int ID);  //��ѯpicture����
    bool openDB(char* path);   //�����ݿ�
	void closeDB();            //�ر����ݿ�
};
