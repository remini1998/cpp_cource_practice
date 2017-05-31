/********************************************************************************
** Form generated from reading UI file 'db_setting.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DB_SETTING_H
#define UI_DB_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_db_setting
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *txt_host;
    QLineEdit *txt_user;
    QLineEdit *txt_pwd;
    QLineEdit *txt_dbname;
    QLabel *label_6;
    QLineEdit *txt_port;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_save;
    QPushButton *btn_exit;

    void setupUi(QWidget *db_setting)
    {
        if (db_setting->objectName().isEmpty())
            db_setting->setObjectName(QStringLiteral("db_setting"));
        db_setting->resize(489, 320);
        formLayoutWidget = new QWidget(db_setting);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(50, 60, 391, 163));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        txt_host = new QLineEdit(formLayoutWidget);
        txt_host->setObjectName(QStringLiteral("txt_host"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txt_host);

        txt_user = new QLineEdit(formLayoutWidget);
        txt_user->setObjectName(QStringLiteral("txt_user"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txt_user);

        txt_pwd = new QLineEdit(formLayoutWidget);
        txt_pwd->setObjectName(QStringLiteral("txt_pwd"));
        txt_pwd->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, txt_pwd);

        txt_dbname = new QLineEdit(formLayoutWidget);
        txt_dbname->setObjectName(QStringLiteral("txt_dbname"));

        formLayout->setWidget(4, QFormLayout::FieldRole, txt_dbname);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        txt_port = new QLineEdit(formLayoutWidget);
        txt_port->setObjectName(QStringLiteral("txt_port"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txt_port);

        label = new QLabel(db_setting);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 0, 421, 61));
        label->setAcceptDrops(false);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(false);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        horizontalLayoutWidget = new QWidget(db_setting);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(50, 240, 391, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_save = new QPushButton(horizontalLayoutWidget);
        btn_save->setObjectName(QStringLiteral("btn_save"));

        horizontalLayout->addWidget(btn_save);

        btn_exit = new QPushButton(horizontalLayoutWidget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));

        horizontalLayout->addWidget(btn_exit);

        QWidget::setTabOrder(txt_host, txt_user);
        QWidget::setTabOrder(txt_user, txt_dbname);
        QWidget::setTabOrder(txt_dbname, txt_pwd);
        QWidget::setTabOrder(txt_pwd, btn_save);
        QWidget::setTabOrder(btn_save, btn_exit);

        retranslateUi(db_setting);

        QMetaObject::connectSlotsByName(db_setting);
    } // setupUi

    void retranslateUi(QWidget *db_setting)
    {
        db_setting->setWindowTitle(QApplication::translate("db_setting", "\346\225\260\346\215\256\345\272\223\350\256\276\347\275\256", Q_NULLPTR));
        label_2->setText(QApplication::translate("db_setting", "\344\270\273\346\234\272\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("db_setting", "\347\224\250\346\210\267\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("db_setting", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("db_setting", "\345\272\223\345\220\215\357\274\232", Q_NULLPTR));
        txt_host->setText(QApplication::translate("db_setting", "127.0.0.1", Q_NULLPTR));
        txt_user->setText(QApplication::translate("db_setting", "root", Q_NULLPTR));
        txt_dbname->setText(QApplication::translate("db_setting", "library", Q_NULLPTR));
        label_6->setText(QApplication::translate("db_setting", "\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        txt_port->setText(QApplication::translate("db_setting", "3306", Q_NULLPTR));
        label->setText(QApplication::translate("db_setting", "<html><head/><body><p>\346\243\200\346\265\213\345\210\260\346\202\250\346\262\241\346\234\211\346\255\243\347\241\256\345\234\260\350\277\233\350\241\214\346\225\260\346\215\256\345\272\223\350\256\276\347\275\256\357\274\214\350\257\267\345\256\214\346\210\220\350\256\276\347\275\256\357\274\201</p></body></html>", Q_NULLPTR));
        btn_save->setText(QApplication::translate("db_setting", "\344\277\235\345\255\230", Q_NULLPTR));
        btn_exit->setText(QApplication::translate("db_setting", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class db_setting: public Ui_db_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DB_SETTING_H
