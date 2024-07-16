/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : 
Student ID#: 
Email      : 
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include<stdio.h>

// User Libraries
#include"w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* tst) {

	int test;

	do
	{
		scanf("%d", &test);
		if (test <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (test <= 0);
	if (tst != NULL)
	{
		*tst = test;
	}
	return test;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* tst) {

	double test;

	do
	{
		scanf("%lf", &test);
		if (test <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (test <= 0);
	if (tst != NULL)
	{
		*tst = test;
	}
	return test;
}



// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int product) {

	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", product);
	printf("NOTE: A 'serving' is %dg\n\n", GRAM);

}

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int cat_food) {

	struct CatFoodInfo cat = { 0 };
	printf("Cat Food Product #%d\n", cat_food);
	printf("--------------------\n");

	printf("SKU           : ");
	getIntPositive(&cat.sku);
	
	printf("PRICE         : $");
	cat.price = getDoublePositive(NULL);
	
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&cat.lbs);
	
	printf("CALORIES/SERV.: ");
	cat.Cal_Per_Ser = getIntPositive(NULL);
	
	printf("\n");
	return cat;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(const int sku, const double* price, const int Cal_Per_Ser, const double* lbs) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *lbs, Cal_Per_Ser);
}
// 7. Logic entry point
void start() {

	openingMessage(MAX);

	struct CatFoodInfo cat[MAX] = { {0 } };

	int i;

	for (i = 0; i < MAX; i++)
	{
		cat[i] = getCatFoodInfo(i + 1);
	}
	displayCatFoodHeader();

	for (i = 0; i < MAX; i++)
	{
		displayCatFoodData(cat[i].sku, &cat[i].price, cat[i].Cal_Per_Ser, &cat[i].lbs);
	}
}