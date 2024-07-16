#pragma once
#define _CRT_SECRURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>

void clearInputBuffer(void);

void suspend(void);

int inputInt(void);

int inputIntPositive(void);

int inputIntRange(int, int);

char inputCharOption(const char*);

void inputCString(char*, int, int);

void displayFormattedPhone(const char* phone);