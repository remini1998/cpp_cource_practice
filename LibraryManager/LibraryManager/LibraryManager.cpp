// LibraryManager.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "book.h"
#include "user.h"
#include <stdlib.h>
#include "LibraryManager.h"
#include <conio.h>

using namespace std;

int main(void)
{
	LOOP:

	int choice;

	ShowWelcomeScreen();
	while (1)
	{
		ShowStartMenu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			Login();
			goto LOOP;
		}
		case 2:
		{
			Regist(0, 1);
			goto LOOP;
		}
		case 3:
		{
			return 0;
		}
		default:
			printf("无效选项，请重新输入");
		}
		system("pause");
		system("cls");
	}
}

void ShowWelcomeScreen()
{
	printf("\t\t***********************************************************************\n");
	printf("\t\t*                                                                     *\n");
	printf("\t\t*                                                                     *\n");
	printf("\t\t*                       Library Management System                     *\n");
	printf("\t\t*                                                                     *\n");
	printf("\t\t*                           Code by：马文瑞                           *\n");
	printf("\t\t*                                                                     *\n");
	printf("\t\t*    Github: https://github.com/remini1998/cpp_cource_practice.git    *\n");
	printf("\t\t*                                                                     *\n");
	printf("\t\t*                                                                     *\n");
	printf("\t\t***********************************************************************\n");
	system("pause");
	system("cls");
}

void ShowStartMenu()
{
	printf("\t\t**************************************\n");
	printf("\t\t*                                    *\n");
	printf("\t\t*        -1- 登陆                    *\n");
	printf("\t\t*        -2- 注册普通用户            *\n");
	printf("\t\t*        -3- 退出                    *\n");
	printf("\t\t*                                    *\n");
	printf("\t\t**************************************\n");
	printf("\t\t  请输入您想进行的操作：");
}

void Login()
{
	USER U;
	char username[MAX_USERNAME_LENGTH];
	char password[MAX_PWD_LENGTH];
	int t = 1;
	int a = 0;
	bool adminAvaliable = true;
	int choice;

LOOP:
	printf("\t\t  请输入用户名:");
	scanf("%s", username);
	printf("\t\t  请输入密码:");
	input_pwd(password);

		FILE * fp = fopen(USER_FILE, "a+");
		while (fscanf(fp, "\t\t  %s\t%s\t%d\t%d\n", U.username, U.password, &U.status, &U.role) != -1)
		{
			//如果存在新注册的管理员，则废弃默认管理员
			if (adminAvaliable && U.role == 2 && U.status == 1) adminAvaliable = !adminAvaliable;

			if (strcmp(username, U.username) == 0 && strcmp(password, U.password) == 0)
			{
				if (U.status == 0)
				{
					printf("\t\t  登录失败，账号审核中\n");
					goto LOOP;
				}
				else if (U.status == 2)
				{
					printf("\t\t  登录失败，账号未通过审核\n");
					goto LOOP;
				}
				else
				{
					printf("\t\t  登陆成功\n");
					system("pause");
					system("cls");
					if (U.role == 1)
					{
						a++;
						ShowNormalUserMenu();
						return;
					}
					if (U.role == 2)
					{
						a++;
						ShowAdminUserMenu();
						return;
					}
					return;
				}
			}
		}
		if (adminAvaliable && strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
		{
			printf("\t\t  登陆成功\n");
			system("cls");
			ShowAdminUserMenu();
			return;
		}
		printf("\t\t  登录失败，密码或用户名错误%d次\n", t++);
		if (t == 4)
		{
			Lock();
		}
		goto LOOP;
}

void Lock() {
	for (int i = 0; i < 180; i++) {
		printf("\t\t\t\t…………程序锁定.…………\n");
		Sleep(1000);
	}
}

void Regist(int status, int role)
{
	USER u;
	char repass[MAX_PWD_LENGTH];
LOOP:
	printf("\t\t  输入用户名:");
	scanf("%s", u.username);
	printf("\t\t  输入密码:");
	input_pwd(u.password);
	printf("\t\t  重复密码：");
	input_pwd(repass);
	if (strcmp(repass, u.password) == 0)
	{
		printf("\t\t  注册成功\n");
		u.role = role;
		u.status = status;
		SaveToFile(u);
	}
	else
	{
		printf("\t\t  两次密码不一致，请您重新输入！\n");
		system("pause");
		goto LOOP;
	}
}

void SaveToFile(USER user)
{
	FILE *fp;
	fp = fopen(USER_FILE, "a+");
	fprintf(fp, "\t\t  %s\t%s\t%d\t%d\n", user.username, user.password, user.status, user.role);
	fclose(fp);
}

void ShowNormalUserMenu()
{
	int chioce;
LOOP:
	puts("\t\t\t\t  -1- 查看所有图书");
	puts("\t\t\t\t  -2- 借阅");
	puts("\t\t\t\t  -3- 还书");
	puts("\t\t\t\t  -4- 返回");
	puts("\t\t\t\t  请输入选择：");
	scanf("%d", &chioce);
	system("cls");
	switch (chioce) {
	case 1:
		ShowBookData();
		system("pause");
		system("cls");
		goto LOOP;
	case 2:
		BorrowBook();
		goto LOOP;
	case 3:
		ReturnBook();
		goto LOOP;
	case 4:
		return;
	default:
		puts("\t\t  无效选项，请重新输入");
		goto LOOP;
	}
}

void ShowAdminUserMenu()
{
	int chioce;
LOOP:
	puts("\t\t\t\t  -1- 录入新图书");
	puts("\t\t\t\t  -2- 查看所有图书");
	puts("\t\t\t\t  -3- 修改图书信息");
	puts("\t\t\t\t  -4- 注册新管理员用户");
	puts("\t\t\t\t  -5- 用户注册审批");
	puts("\t\t\t\t  -6- 返回上一页");
	puts("\t\t\t\t  请输入选项前序号：");
	scanf("%d", &chioce);
	system("cls");
	switch (chioce) {
	case 1:
		InputNewBook();
		goto LOOP;
	case 2:
		ShowBookData();
		system("pause");
		system("cls");
		goto LOOP;
	case 3:
		UpdateBookData();
		goto LOOP;
	case 4:
		Regist(0, 2);
		system("pause");
		system("cls");
		goto LOOP;
	case 5:
		AcceptUser();
		goto LOOP;
	case 6:
		return;
	default:
		puts("\t\t\t\t  无效选项，请重新输入");
		goto LOOP;
	}
}

void InputNewBook(void)
{
	int time;
	BOOK temp;
	FILE * fp = fopen(BOOK_FILE, "a+");
	puts("\t\t  录入将要录入图书的数量:");
	scanf("%d", &time);
	for (int i = 1; i <= time; i++) {
		printf("\t\t  请输入第%d本书的名称：", i);
		scanf("%s", temp.bookName);
		printf("\t\t  请输入第%d本书的编号：", i);
		scanf("%s", temp.bookNum);
		printf("\t\t  请输入第%d本书的出版社名称：", i);
		scanf("%s", temp.publish);
		printf("\t\t  请输入第%d本书的租金：", i);
		scanf("%lf", &temp.price);
		printf("\t\t  请输入第%d本书的出版日期（xxxx/xx/xx）：", i);
		scanf("%d/%d/%d", &temp.publishTime.year, &temp.publishTime.month, &temp.publishTime.day);
		fprintf(fp, "\t\t  %s\t%s\t%s\t%lf\t%d/%d/%d\t0\n", temp.bookName, temp.bookNum, temp.publish, temp.price,
			temp.publishTime.year, temp.publishTime.month, temp.publishTime.day);
	}
	fclose(fp);
	puts("\t\t  录入成功");
	system("pause");
	system("cls");
	return;
}

void ShowBookData(void)
{
	FILE * fp = fopen(BOOK_FILE, "a+");
	BOOK temp;
	int time = 0;
	while (fscanf(fp, "\t\t  %s\t%s\t%s\t%lf\t%d/%d/%d\t%d\n", temp.bookName, temp.bookNum, temp.publish, &temp.price, &temp.publishTime.year, &temp.publishTime.month, &temp.publishTime.day, &temp.status) != -1)
	{
		time++;
		printf("%d--", time);
		printf("\t\t  %s\t\t%s\t%s\t%lf\t%d/%d/%d\t", temp.bookName, temp.bookNum, temp.publish, temp.price,
			temp.publishTime.year, temp.publishTime.month, temp.publishTime.day);
		if (temp.status == 0) printf("\t\t  未被借阅\n");
		if (temp.status == 1) printf("\t\t  已被借阅\n");
	}
	fclose(fp);
	return;
}

int CountLineInFile(char filename[]) {
	FILE * fp = fopen(filename, "a+");
	int line = 0;
	while (!feof(fp)) {
		char a = fgetc(fp);
		if (a == '\n') line++;
	}
	fclose(fp);
	return line;
}

void UpdateBookData(void) {
	BOOK *temp = new BOOK[CountLineInFile(BOOK_FILE) + 1];
	int i, j = 0;
	FILE * fp = fopen(BOOK_FILE, "a+");
	while (fscanf(fp, "\t\t  %s\t%s\t%s\t%lf\t%d/%d/%d\t%d\n", temp[i].bookName, temp[i].bookNum, temp[i].publish, &temp[i].price,
		&temp[i].publishTime.year, &temp[i].publishTime.month, &temp[i].publishTime.day, &temp[i].status) != -1)
		i++;
	fclose(fp);
	char num[20];
LOOP:
	ShowBookData();
	puts("\t\t  请输入需要修改的图书编号：");
	scanf("%s", num);
	system("cls");
	for (; j < i; j++) {
		if (strcmp(num, temp[j].bookNum) == 0) break;
	}
	if (j == i)
	{
		puts("\t\t  无效输入，请重新选择");
		goto LOOP;
	}
	printf("\t\t  请输入书的名称：");
	scanf("%s", temp[j].bookName);
	printf("\t\t  请输入书的编号：");
	scanf("%s", temp[j].bookNum);
	printf("\t\t  请输入书的出版社名称：");
	scanf("%s", temp[j].publish);
	printf("\t\t  请输入书的租金：");
	scanf("%lf", &temp[j].price);
	printf("\t\t  请输入书的出版日期（xxxx/xx/xx）：");
	scanf("%d/%d/%d", &temp[j].publishTime.year, &temp[j].publishTime.month, &temp[j].publishTime.day);
	system("cls");
	fp = fopen(BOOK_FILE, "r+");
	for (j = 0; j < i; j++) {
		fprintf(fp, "\t\t  %s\t%s\t%s\t%lf\t%d/%d/%d\t%d\n", temp[j].bookName, temp[j].bookNum, temp[j].publish, temp[j].price,
			temp[j].publishTime.year, temp[j].publishTime.month, temp[j].publishTime.day, temp[j].status);
	}
	fclose(fp);
	puts("\t\t  修改成功");
	return;
}

void AcceptUser(void)
{
	USER *temp = new USER[CountLineInFile(USER_FILE) + 1];
	int i = 0;
	int j = 0;
	int a = 0;
	int num = 0;

	//读取文件并打印
	FILE * fp = fopen(USER_FILE, "a+");
	while (fscanf(fp, "\t\t  %s\t%s\t%d\t%d\n", temp[i].username, temp[i].password, &temp[i].status, &temp[i].role) != -1)
	{
		
		if (temp[i].status == 0)
		{
			printf("\t\t  %d--%s\t%s\t%d\t%d\n", i + 1, temp[i].username, temp[i].password, temp[i].status, temp[i].role);
			a++;
		}
		i++;
	}
	fclose(fp);
	LOOP:
		if (a != 0)
		{
			puts("\t\t  请输入需要审核的用户前面的序号：");
			scanf("%d", &num);
			if (num <= 0 || num > i || temp[num - 1].status != 0)
			{
				puts("\t\t  无效输入，请重新选择");
				goto LOOP;
			}
			temp[num - 1].status = 1;
			fp = fopen(USER_FILE, "r+");
			for (j = 0; j < i; j++)
			{
				fprintf(fp, "\t\t  %s\t%s\t%d\t%d\n", temp[j].username, temp[j].password, temp[j].status, temp[j].role);
			}
			puts("\t\t  审核成功");
		}
		else
			printf("当前没有任何待审核的注册用户\n");
		fclose(fp);
	system("pause");
	system("cls");
}

void BorrowBook()
{
	BOOK *temp = new BOOK[CountLineInFile(BOOK_FILE) + 1];
	int i=0, j = 0;
	FILE * fp = fopen(BOOK_FILE, "a+");
	while (fscanf(fp, "\t\t  %s\t%s\t%s\t%lf\t%d/%d/%d\t%d\n", temp[i].bookName, temp[i].bookNum, temp[i].publish, &temp[i].price, &temp[i].publishTime.year, &temp[i].publishTime.month, &temp[i].publishTime.day, &temp[i].status) != -1)
		i++;
	fclose(fp);
	char num[20];
LOOP:
	ShowBookData();
	puts("\t\t  请输入需要借阅图书的编号：");
	scanf("%s", num);
	system("cls");
	for (; j < i; j++)
	{
		if (strcmp(num, temp[j].bookNum) == 0)
			break;
	}
	if (j == i) {
		puts("\t\t  无效输入，请重新选择");
		goto LOOP;
	}
	temp[j].status = 1;
	fp = fopen(BOOK_FILE, "r+");
	for (j = 0; j < i; j++) {
		fprintf(fp, "\t\t  %s\t%s\t%s\t%lf\t%d/%d/%d\t%d\n", temp[j].bookName, temp[j].bookNum, temp[j].publish, temp[j].price,
			temp[j].publishTime.year, temp[j].publishTime.month, temp[j].publishTime.day, temp[j].status);
	}
	fclose(fp);
	puts("\t\t  借阅成功");
	return;
}


void ReturnBook(void)
{
	BOOK *temp = new BOOK[CountLineInFile(BOOK_FILE) + 1];
	int i = 0, j = 0;

	FILE * fp = fopen(BOOK_FILE, "a+");
	while (fscanf(fp, "\t\t  %s\t%s\t%s\t%lf\t%d/%d/%d\t%d\n", temp[i].bookName, temp[i].bookNum, temp[i].publish, &temp[i].price, &temp[i].publishTime.year, &temp[i].publishTime.month, &temp[i].publishTime.day, &temp[i].status) != -1)
		i++;

	fclose(fp);
	char num[20];
LOOP:
	ShowBookData();
	puts("\t\t  请输入需要还图书的编号：");
	scanf("%s", num);
	system("cls");
	for (; j < i; j++) {
		if (strcmp(num, temp[j].bookNum) == 0) break;
	}
	if (j == i) {
		puts("\t\t  无效输入，请重新选择");
		goto LOOP;
	}
	temp[j].status = 0;
	fp = fopen(BOOK_FILE, "r+");
	for (j = 0; j < i; j++) {
		fprintf(fp, "\t\t  %s\t%s\t%s\t%lf\t%d/%d/%d\t%d\n", temp[j].bookName, temp[j].bookNum, temp[j].publish, temp[j].price,
			temp[j].publishTime.year, temp[j].publishTime.month, temp[j].publishTime.day, temp[j].status);
	}
	fclose(fp);
	puts("\t\t  还书成功");
	return;
}

void input_pwd(char* output) {
	int n = 0;
	while (1) {
		output[n] = (char)getch();
		if (output[n] == '\r' || output[n] == '\n') {
			output[n] = '\0';
			printf("\n");
			break;//遇到回车则退出输入
		}
		n++;
		printf("*");
	}
}