#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <QtSql>
#include "model.h"

using namespace std;

//为静态变量分配空间
Model* Model::model = NULL;

Model* Model::GetModel()
{
    if (model==NULL)
        model = new Model();
    return model;
}

void Model::ConnectDb()
{
	string host, port, user, pwd, dbname;
	ReadConfig(&host, &port, &user, &pwd, &dbname);
    //    设置登陆信息并尝试连接
        db.setHostName(host.c_str());
        db.setPort(atoi(port.c_str()));
        db.setDatabaseName(user.c_str());
        db.setUserName(pwd.c_str());
        db.setPassword(dbname.c_str());
        if(!db.open()){
    //        qDebug() << "数据库连接失败";
			cout << "数据库连接失败\n" << db.lastError().text().toStdString();
			isConectDb = false;
            throw 10002;
        }
		isConectDb = true;
}

Model::Model()
{
    string host, port, user, pwd, dbname;

//    添加事件驱动
    db = QSqlDatabase::addDatabase("QMYSQL");

    ConnectDb();

}

void Model::ReadConfig(string *host, string *port, string *user, string *pwd, string *dbname)
{
    //    读取配置文件
        ifstream fin("config.ini");
        if (!fin) {
            throw 10001;
        }

		char chost[50], cport[50], cuser[50], cpwd[50], cdbname[50];
		
		try {
			fin >> chost >> cport >> cuser >> cpwd >> cdbname;
			*host = chost;
			*port = cport;
			*user = cuser;
			*pwd = cpwd;
			*dbname = cdbname;
		}
		catch (...) {
			fin.close();
			throw 10001;
		}
		fin.close();
}

void Model::WriteConfig(string host, string port, string user, string pwd, string dbname)
{
	ofstream file;
	file.open("config.ini");
	file << host << endl << port << endl << user << endl << pwd << endl << dbname;
	file.close();
}