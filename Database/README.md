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
	char* infoQuery(int ID); //查询info函数
    bool openDB(char* path);   //打开数据库
	void closeDB();            //关闭数据库
};
```



char* nameQuery(int ID);   //查询name函数

注意：返回的是char*类型(字符串) 

函数的具体使用可以看下test.cpp(main测试)

```c
void main()
{
	SQLiteHelper* help = new SQLiteHelper();
	char* name = "star_war.db";   //数据库文件名
	help->openDB(name);
	cout << help->nameQuery(3)<<endl;
	cout << help->infoQuery(3);
	help->closeDB();

}
```

infoQuery连接前端和之前nameQuery应该可以是一样的