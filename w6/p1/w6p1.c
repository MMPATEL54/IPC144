/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Manan Manojkumar Patel
Student ID#: 141782227
Email      : manan06032004@gmail.com
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define NUM 10
int main(void)
{
	const double MAX = 400000.00;
	const double MIN = 500.00;
	double monthly_income, sum = 0;
	int flag2 = 0,flag3 = 0,flag4 = 0;
	int items = 0, j = 0, b = 0;
	double item_price[NUM];
	int imp[NUM];
	char yan[NUM];
	printf("+--------------------------+");
	printf("\n+   Wish List Forecaster   |");
	printf("\n+--------------------------+");

	do
	{
		printf("\n\nEnter your monthly NET income: $");
		scanf("%lf", &monthly_income);
		if (monthly_income <= MAX && monthly_income >= MIN)
		{
			do
			{
				printf("\nHow many wish list items do you want to forecast?: ");
				scanf("%d", &items);
				if (items <= NUM && items > 0)
				{
					flag2 = 1;
					for (j = 0; j < items; j++)
					{
						printf("\nItem-%d Details:", j + 1);
						do
						{	
							printf("\n   Item cost: $");
							scanf("%lf", &item_price[j]);
							if (item_price[j] >= 100.00)
							{
								sum = sum + item_price[j];
								do
								{
									printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
									scanf("%d", &imp[j]);
									if (imp[j] > 0 && imp[j] < 4)
									{
										flag3 = 1;
										do
										{
											printf("   Does this item have financing options? [y/n]: ");
											scanf("%s", &yan[j]);
											if (yan[j] == 'y' || yan[j] == 'n')
											{
												flag4 = 1;

											}
											else
											{
												printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
											}
										} while (flag4 == 0);
									}
									else
									{
										printf("      ERROR: Value must be between 1 and 3\n");
									}
								} while (flag3 == 0);
							}
							else
							{
								printf("      ERROR: Cost must be at least $100.00");
							}
						} while (item_price[j] <= 100.00);
					}
				}
				else
				{
					printf("ERROR: List is restricted to between 1 and 10 items.\n");
				}
			}while (flag2 == 0);
		}
		else if (monthly_income > MAX && monthly_income >= MIN)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00");
		}
		else
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00");
		}
	} while (monthly_income >= MAX || monthly_income <= MIN);
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	
	
		for (b = 0; b < j; b++)
		{
			printf("%3d  %5d    %5c    %11.2lf\n", b + 1, imp[b], yan[b], item_price[b]);
			
		}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", sum);
	printf("Best of luck in all your future endeavours!\n\n");
    return 0;
}

/*
    HELPER: printf formatting statements....
	=========================================
	
    Step #7:
		printf("Item Priority Financed        Cost\n");
		printf("---- -------- -------- -----------\n");
		
		printf("%3d  %5d    %5c    %11.2lf\n", ...
		

	Step #8:
		printf("---- -------- -------- -----------\n");
		printf("                      $%11.2lf\n\n", ...

*/