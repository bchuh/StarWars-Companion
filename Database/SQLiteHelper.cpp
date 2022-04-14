#include "SQLiteHelper.h"
#include <iostream>
using namespace std;


SQLiteHelper::SQLiteHelper() {

}

SQLiteHelper::~SQLiteHelper() {
    closeDB();
}

char* SQLiteHelper::nameQuery(int ID) {

	int r;      //返回表的行数
	int c;      //返回表的列
	int rc;     //函数调用是否成功

	string condition = " id = ";
	string sid = to_string(ID);    //int id 转换为字符串类型
	condition = "select name from information where" + condition + sid + ";";
	char* sql = (char*)condition.data();
	//char* sql = "select name from information where id = 2;";
	char** result;   //result存的是字符串的一维数组  字符串又是一个数组
	rc = sqlite3_get_table(this->db, sql, &result, &r, &c, 0);
	if (rc == SQLITE_OK)
		return result[1];
	else 
        return nullptr;
}

char* SQLiteHelper::infoQuery(int ID) {
	int r;      
	int c;      
	int rc;     
	
	string condition = " id = ";
	string sid = to_string(ID);   
	condition = "select info from information where" + condition + sid + ";";
	char* sql = (char*)condition.data();
	//char* sql = "select info from information where id = 2;";
	char** result;  
	rc = sqlite3_get_table(this->db, sql, &result, &r, &c, 0);
	if (rc == SQLITE_OK) {
		return result[1];
	}
}

/*
char* picQuery(int ID) {
}
*/

bool SQLiteHelper::openDB(char* path)
{

    db=nullptr;
    int last = sqlite3_open(path, &db);

	if (SQLITE_OK != last)
	{
		cout << "Fail to open db" << endl;
        //PostQuitMessage(0);
        return false;
    }else

        return true;

}

void SQLiteHelper::closeDB()
{
    //sqlite3_close(db);

}
