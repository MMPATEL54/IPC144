/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Manan Manojkumar Patel
Student ID#: 141782227
Email      : mmpatel54@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include "core.h"

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//
void clearInputBuffer(void)
{
	// Discard all remaining char's from the standard input buffer:
	while (getchar() != '\n')
	{
		; // do nothing!
	}
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
	printf("<ENTER> to continue...");
	clearInputBuffer();
	putchar('\n');
}

int inputInt(void) {
	int num;
	char newLine;

	do
	{
		scanf("%d%c", &num, &newLine);

		if (newLine != '\n')
		{
			printf("Error! Input a whole number: ");
			clearInputBuffer();
		}

	} while (newLine != '\n');

	return num;
}

int inputIntPositive(void) {
	int number;
	do
	{
		number = inputInt();
		if (number <= 0)
		{
			printf("ERROR! Value must be > 0: ");
		}
	} while (number <= 0);
	return number;
}

int inputIntRange(int lowerBound, int upperBound) {
	int number;

	do
	{
		number = inputInt();
		if (number < lowerBound || number > upperBound)
		{
			printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
		}
	} while (number < lowerBound || number > upperBound);
	return number;
}

char inputCharOption(const char validCharInput[])
{
	char input[MAX] = { 0 };
	int flag = 0, i = 0;
	do
	{
		scanf(" %s", input);
		for (i = 0; validCharInput[i] != '\0'; i++)
		{
			if (input[0] == validCharInput[i] && strlen(input) == 1)
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			printf("ERROR: Character must be one of [%s]: ", validCharInput);
			clearInputBuffer();
		}
	} while (flag == 0);
	clearInputBuffer();
	return input[0];
}

void inputCString(char* inputString, int minLen, int maxLen)
{
	do
	{
		scanf("%[^\n]s", inputString);
		if (strlen(inputString) < minLen || strlen(inputString) > maxLen) {
			if (minLen == maxLen) {
				clearInputBuffer();
				printf("Invalid %d-digit number! Number: ", maxLen);
			}
			else if (strlen(inputString) > maxLen)
			{
				clearInputBuffer();
				printf("ERROR: String length must be no more than %d chars: ", maxLen);
			}
			else {
				clearInputBuffer();
				printf("ERROR: String length must be between %d and %d chars: ", minLen, maxLen);
			}
		}
	} while (strlen(inputString) < minLen || strlen(inputString) > maxLen);
}

void displayFormattedPhone(const char* phone_number)
{
	int i, count = 0, len = strlen(phone_number);

	if (phone_number == NULL) {
		printf("(___)___-____");
		return;
	}
	for (i = 0; i < len; i++) {
		if (phone_number[i] >= '0' && phone_number[i] <= '9') {
			count++;
		}
	}
	if (len != 10 || len != count) {
		printf("(___)___-____");
	}
	else
		printf("(%c%c%c)%c%c%c-%c%c%c%c",
			phone_number[0],
			phone_number[1],
			phone_number[2],
			phone_number[3],
			phone_number[4],
			phone_number[5],
			phone_number[6],
			phone_number[7],
			phone_number[8],
			phone_number[9]);

}