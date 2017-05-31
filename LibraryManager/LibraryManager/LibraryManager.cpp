// LibraryManager.cpp : �������̨Ӧ�ó������ڵ㡣
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
			printf("��Чѡ�����������");
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
	printf("\t\t*                           Code by��������                           *\n");
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
	printf("\t\t*        -1- ��½                    *\n");
	printf("\t\t*        -2- ע����ͨ�û�            *\n");
	printf("\t\t*        -3- �˳�                    *\n");
	printf("\t\t*                                    *\n");
	printf("\t\t**************************************\n");
	printf("\t\t  ������������еĲ�����");
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
	printf("\t\t  �������û���:");
	scanf("%s", username);
	printf("\t\t  ����������:");
	input_pwd(password);

		FILE * fp = fopen(USER_FILE, "a+");
		while (fscanf(fp, "\t\t  %s\t%s\t%d\t%d\n", U.username, U.password, &U.status, &U.role) != -1)
		{
			//���������ע��Ĺ���Ա�������Ĭ�Ϲ���Ա
			if (adminAvaliable && U.role == 2 && U.status == 1) adminAvaliable = !adminAvaliable;

			if (strcmp(username, U.username) == 0 && strcmp(password, U.password) == 0)
			{
				if (U.status == 0)
				{
					printf("\t\t  ��¼ʧ�ܣ��˺������\n");
					goto LOOP;
				}
				else if (U.status == 2)
				{
					printf("\t\t  ��¼ʧ�ܣ��˺�δͨ�����\n");
					goto LOOP;
				}
				else
				{
					printf("\t\t  ��½�ɹ�\n");
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
			printf("\t\t  ��½�ɹ�\n");
			system("cls");
			ShowAdminUserMenu();
			return;
		}
		printf("\t\t  ��¼ʧ�ܣ�������û�������%d��\n", t++);
		if (t == 4)
		{
			Lock();
		}
		goto LOOP;
}

void Lock() {
	for (int i = 0; i < 180; i++) {
		printf("\t\t\t\t����������������.��������\n");
		Sleep(1000);
	}
}

void Regist(int status, int role)
{
	USER u;
	char repass[MAX_PWD_LENGTH];
LOOP:
	printf("\t\t  �����û���:");
	scanf("%s", u.username);
	printf("\t\t  ��������:");
	input_pwd(u.password);
	printf("\t\t  �ظ����룺");
	input_pwd(repass);
	if (strcmp(repass, u.password) == 0)
	{
		printf("\t\t  ע��ɹ�\n");
		u.role = role;
		u.status = status;
		SaveToFile(u);
	}
	else
	{
		printf("\t\t  �������벻һ�£������������룡\n");
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
	puts("\t\t\t\t  -1- �鿴����ͼ��");
	puts("\t\t\t\t  -2- ����");
	puts("\t\t\t\t  -3- ����");
	puts("\t\t\t\t  -4- ����");
	puts("\t\t\t\t  ������ѡ��");
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
		puts("\t\t  ��Чѡ�����������");
		goto LOOP;
	}
}

void ShowAdminUserMenu()
{
	int chioce;
LOOP:
	puts("\t\t\t\t  -1- ¼����ͼ��");
	puts("\t\t\t\t  -2- �鿴����ͼ��");
	puts("\t\t\t\t  -3- �޸�ͼ����Ϣ");
	puts("\t\t\t\t  -4- ע���¹���Ա�û�");
	puts("\t\t\t\t  -5- �û�ע������");
	puts("\t\t\t\t  -6- ������һҳ");
	puts("\t\t\t\t  ������ѡ��ǰ��ţ�");
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
		puts("\t\t\t\t  ��Чѡ�����������");
		goto LOOP;
	}
}

void InputNewBook(void)
{
	int time;
	BOOK temp;
	FILE * fp = fopen(BOOK_FILE, "a+");
	puts("\t\t  ¼�뽫Ҫ¼��ͼ�������:");
	scanf("%d", &time);
	for (int i = 1; i <= time; i++) {
		printf("\t\t  �������%d��������ƣ�", i);
		scanf("%s", temp.bookName);
		printf("\t\t  �������%d����ı�ţ�", i);
		scanf("%s", temp.bookNum);
		printf("\t\t  �������%d����ĳ��������ƣ�", i);
		scanf("%s", temp.publish);
		printf("\t\t  �������%d��������", i);
		scanf("%lf", &temp.price);
		printf("\t\t  �������%d����ĳ������ڣ�xxxx/xx/xx����", i);
		scanf("%d/%d/%d", &temp.publishTime.year, &temp.publishTime.month, &temp.publishTime.day);
		fprintf(fp, "\t\t  %s\t%s\t%s\t%lf\t%d/%d/%d\t0\n", temp.bookName, temp.bookNum, temp.publish, temp.price,
			temp.publishTime.year, temp.publishTime.month, temp.publishTime.day);
	}
	fclose(fp);
	puts("\t\t  ¼��ɹ�");
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
		if (temp.status == 0) printf("\t\t  δ������\n");
		if (temp.status == 1) printf("\t\t  �ѱ�����\n");
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
	puts("\t\t  ��������Ҫ�޸ĵ�ͼ���ţ�");
	scanf("%s", num);
	system("cls");
	for (; j < i; j++) {
		if (strcmp(num, temp[j].bookNum) == 0) break;
	}
	if (j == i)
	{
		puts("\t\t  ��Ч���룬������ѡ��");
		goto LOOP;
	}
	printf("\t\t  ������������ƣ�");
	scanf("%s", temp[j].bookName);
	printf("\t\t  ��������ı�ţ�");
	scanf("%s", temp[j].bookNum);
	printf("\t\t  ��������ĳ��������ƣ�");
	scanf("%s", temp[j].publish);
	printf("\t\t  ������������");
	scanf("%lf", &temp[j].price);
	printf("\t\t  ��������ĳ������ڣ�xxxx/xx/xx����");
	scanf("%d/%d/%d", &temp[j].publishTime.year, &temp[j].publishTime.month, &temp[j].publishTime.day);
	system("cls");
	fp = fopen(BOOK_FILE, "r+");
	for (j = 0; j < i; j++) {
		fprintf(fp, "\t\t  %s\t%s\t%s\t%lf\t%d/%d/%d\t%d\n", temp[j].bookName, temp[j].bookNum, temp[j].publish, temp[j].price,
			temp[j].publishTime.year, temp[j].publishTime.month, temp[j].publishTime.day, temp[j].status);
	}
	fclose(fp);
	puts("\t\t  �޸ĳɹ�");
	return;
}

void AcceptUser(void)
{
	USER *temp = new USER[CountLineInFile(USER_FILE) + 1];
	int i = 0;
	int j = 0;
	int a = 0;
	int num = 0;

	//��ȡ�ļ�����ӡ
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
			puts("\t\t  ��������Ҫ��˵��û�ǰ�����ţ�");
			scanf("%d", &num);
			if (num <= 0 || num > i || temp[num - 1].status != 0)
			{
				puts("\t\t  ��Ч���룬������ѡ��");
				goto LOOP;
			}
			temp[num - 1].status = 1;
			fp = fopen(USER_FILE, "r+");
			for (j = 0; j < i; j++)
			{
				fprintf(fp, "\t\t  %s\t%s\t%d\t%d\n", temp[j].username, temp[j].password, temp[j].status, temp[j].role);
			}
			puts("\t\t  ��˳ɹ�");
		}
		else
			printf("��ǰû���κδ���˵�ע���û�\n");
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
	puts("\t\t  ��������Ҫ����ͼ��ı�ţ�");
	scanf("%s", num);
	system("cls");
	for (; j < i; j++)
	{
		if (strcmp(num, temp[j].bookNum) == 0)
			break;
	}
	if (j == i) {
		puts("\t\t  ��Ч���룬������ѡ��");
		goto LOOP;
	}
	temp[j].status = 1;
	fp = fopen(BOOK_FILE, "r+");
	for (j = 0; j < i; j++) {
		fprintf(fp, "\t\t  %s\t%s\t%s\t%lf\t%d/%d/%d\t%d\n", temp[j].bookName, temp[j].bookNum, temp[j].publish, temp[j].price,
			temp[j].publishTime.year, temp[j].publishTime.month, temp[j].publishTime.day, temp[j].status);
	}
	fclose(fp);
	puts("\t\t  ���ĳɹ�");
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
	puts("\t\t  ��������Ҫ��ͼ��ı�ţ�");
	scanf("%s", num);
	system("cls");
	for (; j < i; j++) {
		if (strcmp(num, temp[j].bookNum) == 0) break;
	}
	if (j == i) {
		puts("\t\t  ��Ч���룬������ѡ��");
		goto LOOP;
	}
	temp[j].status = 0;
	fp = fopen(BOOK_FILE, "r+");
	for (j = 0; j < i; j++) {
		fprintf(fp, "\t\t  %s\t%s\t%s\t%lf\t%d/%d/%d\t%d\n", temp[j].bookName, temp[j].bookNum, temp[j].publish, temp[j].price,
			temp[j].publishTime.year, temp[j].publishTime.month, temp[j].publishTime.day, temp[j].status);
	}
	fclose(fp);
	puts("\t\t  ����ɹ�");
	return;
}

void input_pwd(char* output) {
	int n = 0;
	while (1) {
		output[n] = (char)getch();
		if (output[n] == '\r' || output[n] == '\n') {
			output[n] = '\0';
			printf("\n");
			break;//�����س����˳�����
		}
		n++;
		printf("*");
	}
}