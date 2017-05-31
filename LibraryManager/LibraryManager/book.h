#pragma once
#include <stdio.h>
#include <string.h>

typedef struct {
	char bookName[20], bookNum[20], publish[20];
	double price;
	struct time {
		int year;
		int month;
		int day;
	}publishTime;
	int status;
}BOOK;
