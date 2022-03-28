#include "SQLiteHelper.h"
#include <iostream>
using namespace std;


SQLiteHelper::SQLiteHelper() {

}

SQLiteHelper::~SQLiteHelper() {

}

char* SQLiteHelper::nameQuery(int ID) {
	int r;      //���ر�������
	int c;      //���ر�����
	int rc;     //���������Ƿ�ɹ�
	string condition = " id = ";
	string sid = to_string(ID);    //int id ת��Ϊ�ַ�������
	condition = "select name from information where" + condition + sid + ";";
	char* sql = (char*)condition.data();
	//char* sql = "select name from information where id = 2;";
	char** result;   //result������ַ�����һά����  �ַ�������һ������
	rc = sqlite3_get_table(this->db, sql, &result, &r, &c, 0);
	if (rc == SQLITE_OK)
		return result[1];
	else 
		return "sqlite_wrong";
}

/*char* infoQuery(int ID) {

}
char* picQuery(int ID) {

}
*/

void SQLiteHelper::openDB(char* path)
{
	int last = sqlite3_open(path, &db);
	if (SQLITE_OK != last)
	{
		cout << "Fail to open db" << endl;
		return;
		PostQuitMessage(0);
	}
}

void SQLiteHelper::closeDB()
{
	sqlite3_close(db);

}
