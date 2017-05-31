#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include "book.h"
#include "user.h"
#include <stdlib.h>

#define USER_FILE "user_data.ini"
#define BOOK_FILE "book_data.ini"
#define MAX_USERNAME_LENGTH 20
#define MAX_PWD_LENGTH 20

void ShowWelcomeScreen();
void ShowStartMenu();
void Login();
void Regist(int status, int role);
void SaveToFile(USER user);
void ShowNormalUserMenu();
void ShowAdminUserMenu();
void InputNewBook();
void ShowBookData();
void UpdateBookData();
void Lock();
int CountLineInFile(char filename[]);
void AcceptUser();
void BorrowBook();
void ReturnBook();
void input_pwd(char* output);