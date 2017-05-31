#ifndef MODEL_H
#define MODEL_H

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <QtSql>

using namespace std;

//处理所有与数据持久化相关的交互
class Model
{
public:
    static Model* GetModel();
    bool isConectDb = false;
	//读取配置文件并连接数据库
    void ConnectDb();
    //读取配置文件，请于外部创建字符串
	static void ReadConfig(string* host, string* port, string* user, string* pwd, string* dbname);
	//写入配置文件，请于外部创建字符串
	static void WriteConfig(string host, string port, string user, string pwd, string dbname);

private:
    static Model* model;
    Model();
    QSqlDatabase db;
};

#endif // MODEL_H
