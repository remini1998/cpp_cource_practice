#ifndef DB_SETTING_H
#define DB_SETTING_H

#include <QWidget>

namespace Ui {
class db_setting;
}

class db_setting : public QWidget
{
    Q_OBJECT

public:
    explicit db_setting(QWidget *parent = 0);
    ~db_setting();

private slots:
    void on_btn_save_clicked();

    void on_btn_exit_clicked();

private:
    Ui::db_setting *ui;
};

#endif // DB_SETTING_H
