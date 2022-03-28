#include<iostream>
#include"sqlite3.h"
#include "SQLiteHelper.h"
#pragma comment(lib,"sqlite3.lib")
using namespace std;

void main()
{
	SQLiteHelper* help = new SQLiteHelper();
	char* name = "star_war.db";
	help->openDB(name);
	cout << help->nameQuery(3);
	help->closeDB();

}
