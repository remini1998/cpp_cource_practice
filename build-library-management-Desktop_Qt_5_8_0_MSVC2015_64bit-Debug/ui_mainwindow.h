/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionlogin;
    QAction *actionregister;
    QAction *actionlogout;
    QAction *actionexit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *txt_user;
    QLabel *label_5;
    QLineEdit *txt_pwd;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_login;
    QPushButton *btn_register;
    QMenuBar *menuBar;
    QMenu *menufsdfs;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(180, 180));
        actionlogin = new QAction(MainWindow);
        actionlogin->setObjectName(QStringLiteral("actionlogin"));
        actionregister = new QAction(MainWindow);
        actionregister->setObjectName(QStringLiteral("actionregister"));
        actionlogout = new QAction(MainWindow);
        actionlogout->setObjectName(QStringLiteral("actionlogout"));
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetFixedSize);
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setVerticalSpacing(24);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMargin(3);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        txt_user = new QLineEdit(centralWidget);
        txt_user->setObjectName(QStringLiteral("txt_user"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txt_user);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMargin(3);
        label_5->setIndent(-1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        txt_pwd = new QLineEdit(centralWidget);
        txt_pwd->setObjectName(QStringLiteral("txt_pwd"));
        txt_pwd->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, txt_pwd);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_login = new QPushButton(centralWidget);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setMinimumSize(QSize(0, 20));

        horizontalLayout->addWidget(btn_login);

        btn_register = new QPushButton(centralWidget);
        btn_register->setObjectName(QStringLiteral("btn_register"));
        btn_register->setMinimumSize(QSize(0, 20));

        horizontalLayout->addWidget(btn_register);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 30));
        menufsdfs = new QMenu(menuBar);
        menufsdfs->setObjectName(QStringLiteral("menufsdfs"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menufsdfs->menuAction());
        menufsdfs->addAction(actionlogin);
        menufsdfs->addAction(actionregister);
        menufsdfs->addSeparator();
        menufsdfs->addAction(actionlogout);
        menufsdfs->addSeparator();
        menufsdfs->addAction(actionexit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\233\276\344\271\246\347\256\241\347\220\206\345\221\230\347\263\273\347\273\237", Q_NULLPTR));
        actionlogin->setText(QApplication::translate("MainWindow", "\347\231\273\351\231\206", Q_NULLPTR));
        actionregister->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
        actionlogout->setText(QApplication::translate("MainWindow", "\347\231\273\345\207\272", Q_NULLPTR));
        actionexit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\357\274\232", Q_NULLPTR));
        txt_user->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        btn_login->setText(QApplication::translate("MainWindow", "\347\231\273\351\231\206", Q_NULLPTR));
        btn_register->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
        menufsdfs->setTitle(QApplication::translate("MainWindow", "\347\224\250\346\210\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
