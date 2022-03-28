SQLiteHelper.h 头文件里定义的是类和函数

sqlite3.h是 sqlite3 的 api 头文件   sqlite3.lib可以添加依赖也可以直接用代码包含   #pragma comment(lib,"sqlite3.lib")

```cpp
class SQLiteHelper
{
public:
	SQLiteHelper();
	virtual ~SQLiteHelper();
	sqlite3* db;    //数据库本身
	char* nameQuery(int ID);   //查询name函数
	//char* infoQuery(int ID); //查询info函数
	//char* picQuery(int ID);  //查询picture函数
	void openDB(char* path);   //打开数据库
	void closeDB();            //关闭数据库
};
```



char* nameQuery(int ID);   //查询name函数

注意：返回的是char*类型(字符串) 

函数的具体使用可以看下test.cpp(main测试)