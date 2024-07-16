/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
	double monthly_income, sum = 0, avg = 0, priority_sum = 0, priority_avg = 0;
	int flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, priority = 0, priority_year = 0;
	int items = 0, j = 0, b = 0, list = 0, year = 0, months = 0, priority_month = 0;
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
			} while (flag2 == 0);
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
	do
	{
		printf("How do you want to forecast your wish list?");
		printf("\n 1. All items (no filter)");
		printf("\n 2. By priority");
		printf("\n 0. Quit/Exit");
		printf("\nSelection: ");
		scanf("%d", &list);
		if (list == 0)
		{
			flag5 = 1;
			printf("\nBest of luck in all your future endeavours!\n");
		}
		else if (list == 1)
		{
			printf("\n====================================================");
			printf("\nFilter:   All items");
			printf("\nAmount:   $%.2lf", sum);
			avg = sum / monthly_income;
			avg = avg + 0.5;
			year = (int)avg / 12;
			months = (int)(sum / monthly_income + 1) % 12;
			printf("\nForecast: %d years, %d months", year, months);
			for (b = 0; b < items; b++)
			{
				if (yan[b] == 'y')
				{
					printf("\nNOTE: Financing options are available on some items.");
					printf("\n      You can likely reduce the estimated months.");
					b = items;
				}
			}
			printf("\n====================================================\n\n");
		}
		else if (list == 2)
		{
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &priority);
			if (priority == 1)
			{
				for (b = 0; b < items; b++)
				{
					if(imp[b]==1)
					{
						if (yan[b] == 'y'||yan[b]=='n')
						{
							priority_sum = priority_sum + item_price[b];
						}
						else if (yan[b] == 'n' && yan[b] != 'y')
						{
							priority_sum = priority_sum + item_price[b];
						}
					}
				}
				printf("\n====================================================");
				printf("\nFilter:   by priority (%d)", priority);
				printf("\nAmount:   $%.2lf", priority_sum);
				priority_avg = priority_sum / monthly_income;
				priority_avg += 0.5;
				priority_avg = (int)priority_avg;
				priority_year = (int)priority_avg / 12;
				priority_month = (int)(priority_sum / monthly_income + 1) % 12;
				printf("\nForecast: %d years, %d months", priority_year, priority_month);
				priority_sum = 0;
				priority_avg = 0;
				priority_year = 0;
				priority_month = 0;
					for (b = 0; b < items; b++)
					{
						if (priority == imp[b] && yan[b] == 'y')
						{ 
							printf("\nNOTE: Financing options are available on some items.");
							printf("\n      You can likely reduce the estimated months.");
							b = items;
						}
					}
					printf("\n====================================================\n\n");
			}
			else if (priority == 2)
			{
				for (b = 0; b < items; b++)
				{
					if (imp[b] == 2)
					{
						if (yan[b] == 'y' || yan[b] == 'n')
						{
							priority_sum = priority_sum + item_price[b];
						}
						else if (yan[b] == 'n' && yan[b] != 'y')
					{
							priority_sum = priority_sum + item_price[b];
						}
					}
				}
				printf("\n====================================================");
				printf("\nFilter:   by priority (%d)", priority);
				printf("\nAmount:   $%.2lf", priority_sum);
				priority_avg = priority_sum / monthly_income;
				priority_avg += 0.5;
				priority_avg = (int)priority_avg;
				priority_year = (int)priority_avg / 12;
				priority_month = (int)(priority_sum / monthly_income + 1) % 12;
				printf("\nForecast: %d years, %d months", priority_year, priority_month);
				priority_sum = 0;
				priority_avg = 0;
				priority_year = 0;
				priority_month = 0;
				for (b = 0; b < items; b++)
				{
					if (priority == imp[b] && yan[b] == 'y')
					{
						printf("\nNOTE: Financing options are available on some items.");
						printf("\n      You can likely reduce the estimated months.");
					b = items;
					}
				}
				printf("\n====================================================\n\n");
			}
			else if(priority == 3)
			{
				for (b = 0; b < items; b++)
				{
					if (imp[b] == 3)
					{
						if (yan[b] == 'y' || yan[b] == 'n')
						{
							priority_sum = priority_sum + item_price[b];
						}
						else if (yan[b] == 'n' && yan[b] != 'y')
						{
							priority_sum = priority_sum + item_price[b];
						}
					}
				}
				printf("\n====================================================");
				printf("\nFilter:   by priority (%d)", priority);
				printf("\nAmount:   $%.2lf", priority_sum);
				priority_avg = priority_sum / monthly_income;
				priority_avg += 0.5;
				priority_avg = (int)priority_avg;
				priority_year = (int)priority_avg / 12;
				priority_month = (int)(priority_sum / monthly_income + 1) % 12;
				printf("\nForecast: %d years, %d months", priority_year, priority_month);
				priority_sum = 0;
				priority_avg = 0;
				priority_year = 0;
				priority_month = 0;
				for (b = 0; b < items; b++)
				{
					if (priority == imp[b] && yan[b] == 'y')
					{
						printf("\nNOTE: Financing options are available on some items.");
						printf("\n      You can likely reduce the estimated months.");
						b = items;
					}
				}
				printf("\n====================================================\n\n");
			}
		}
		else
		{
			printf("\nERROR: Invalid menu selection.\n\n");
		}
	} while (flag5 == 0);
	
    return 0;
}