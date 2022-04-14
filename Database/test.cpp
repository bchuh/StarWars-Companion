#include<iostream>
#include"sqlite3.h"
#include "SQLiteHelper.h"
#pragma comment(lib,"sqlite3.lib")
using namespace std;

void main()
{
	SQLiteHelper* help = new SQLiteHelper();
	char* name = "star_war.db";   //数据库文件名
	help->openDB(name);
	cout << help->nameQuery(3)<<endl;
	cout << help->infoQuery(3);
	help->closeDB();

}
