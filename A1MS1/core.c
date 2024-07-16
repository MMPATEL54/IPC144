#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include "core.h"

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
			if (input[0] == validCharInput[i])
			{
				flag = 1;
			}
		}
		if(flag == 0)
		{
			printf("ERROR: Character must be one of [%s]: ", validCharInput);
			clearInputBuffer();
		}
	} while (flag == 0);
	clearInputBuffer();
	return input[0];
}

void inputCString(char* inputString, int min, int max) 
{
	int len, i = 0;
	char input[100];
	do 
	{
		scanf("%99[^\n]", input);  // Limit input to 99 characters
		clearInputBuffer();
		for (len = 0; input[len] != '\0'; len++);
		if (min == max && (len != max)) 
		{
			printf("ERROR: String length must be exactly %d chars: ", max);
		}
		else if (len > max)
		{
			printf("ERROR: String length must be no more than %d chars: ", max);
		}
		else if (len < min)
		{
			printf("ERROR: String length must be between %d and %d chars: ", min, max);
		}
	} while (len < min || len > max);
	for (i = 0; i < len; i++)
	{
		inputString[i] = input[i];
	}
	
}

void displayFormattedPhone(const char* phone)
{
	int i, isNumber = 1, count = 0;
	count = 0;

	if (phone == NULL) 
	{
		printf("(___)___-____");
		return;
	}
	for (i = 0; phone[i] != '\0'; i++) 
	{
		count++;
		if (phone[i] < 48 || phone[i] > 57) 
		{
			isNumber = 0;
		}
	}
	if (count == 10 && isNumber)
	{
		printf("(");
		for (i = 0; i < 3; i++)
		{
			printf("%c", phone[i]);
		}
		printf(")");
		for (i = 3; i < 6; i++)
		{
			printf("%c", phone[i]);
		}
		printf("-");
		for (i = 6; i < 10; i++) 
		{
			printf("%c", phone[i]);
		}
	}
	else
	{
		printf("(___)___-____");
	}
}


