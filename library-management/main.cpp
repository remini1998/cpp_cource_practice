#include <QApplication>
#include "mainwindow.h"
#include "db_setting.h"
#include "model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	//������ݿ������Ƿ���ȷ
	try {
		Model* m = Model::GetModel();
	}catch(int errCode){
		if (errCode == 10001 || errCode == 10002) {
			db_setting db;
			db.show();
			return a.exec();
		}
		throw errCode;
	}
    MainWindow w;
	w.show();
    return a.exec();
}
