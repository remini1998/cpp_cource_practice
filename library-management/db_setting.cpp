#include "db_setting.h"
#include "ui_db_setting.h"
#include "model.h"

db_setting::db_setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::db_setting)
{
    ui->setupUi(this);
}

db_setting::~db_setting()
{
    delete ui;
}

void db_setting::on_btn_save_clicked()
{
	ui->txt_host->text();
	Model::WriteConfig(ui->txt_host->text().toStdString(), ui->txt_port->text().toStdString(), ui->txt_user->text().toStdString(), ui->txt_pwd->text().toStdString(), ui->txt_dbname->text().toStdString());

	//Model::WriteConfig(ui->txt_host->text.string, ui->txt_port->text.toStdString(), ui->txt_user->text.toStdString(), ui->txt_pwd->text.toStdString(), ui->txt_dbname->text.toStdString());
	QCoreApplication::quit();
}

void db_setting::on_btn_exit_clicked()
{
    QCoreApplication::quit();
}
