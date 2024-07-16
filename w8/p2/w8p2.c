/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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


// System Libraries
#include<stdio.h>

// User-Defined Libraries
#include"w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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

	printf("Cat Food Cost Analysis");
	printf("\n======================");
	printf("\n\nEnter the details for %d dry food bags of product data for analysis.", product);
	printf("\nNOTE: A 'serving' is %dg\n", GRAM);

}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int cat_food) {

	struct CatFoodInfo cat = { 0 };
	printf("\nCat Food Product #%d", cat_food);
	printf("\n--------------------");

	printf("\nSKU           : ");
	getIntPositive(&cat.sku);

	printf("PRICE         : $");
	cat.price = getDoublePositive(NULL);

	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&cat.lbs);

	printf("CALORIES/SERV.: ");
	cat.Cal_Per_Ser = getIntPositive(NULL);

	return cat;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv");
	printf("\n------- ---------- ---------- --------");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int Cal_Per_Ser, const double* lbs)
{
	printf("\n%07d %10.2lf %10.1lf %8d", sku, *price, *lbs, Cal_Per_Ser);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* kg)
{
	double i;
	i = *lbs / CONVERT;

	if (kg != NULL)
	{
		*kg = i;
	}
	
	return(i);
}


// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* g) {

	int i;
	i = convertLbsKg(lbs, 0) * 1000;
	if (g != NULL)
	{
		*g = i;

	} 
	return(i);
}

// 10. convert lbs: kg and g
void convertLbs(const double* newlbs, double* kg, int* g)
{
	convertLbsKg(newlbs, kg);
	convertLbsG(newlbs, g);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int gPerServ, const int totalGrams, double* result)
{
	double i;
	i = (double)totalGrams / (double)gPerServ;
	
	if (result != NULL)
	{
		*result = i;
	}
	return(i);
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* total, double* result)
{
	double costPerServing = 0;
	costPerServing = *price / *total;

	if (result != NULL)
	{
		*result = costPerServing;
	}
	return (costPerServing);
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* Cal_Per_Ser, double* costpcal)
{
	double costpercal = 0;
	
	if (*Cal_Per_Ser != 0) 
	{
		costpercal = *price / *Cal_Per_Ser;
	}
	
	if (costpcal != NULL)
	{
		*costpcal = costpercal;
	}
	
	return costpercal;
}


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo productInfo) 
{
	struct ReportData rep;

	// assign values for report
	rep.sku = productInfo.sku;
	rep.price = productInfo.price;
	rep.Cal_Per_Ser = productInfo.Cal_Per_Ser;
	rep.lbs = productInfo.lbs;
	rep.kg = convertLbsKg(&productInfo.lbs, &rep.kg);
	rep.g = convertLbsG(&productInfo.lbs, &rep.g);
	rep.total = calculateServings(GRAM, rep.g, &rep.total);
	rep.cp_serv = calculateCostPerServing(&rep.price, &rep.total, &rep.cp_serv);

	if (rep.Cal_Per_Ser != 0 && rep.total != 0)
	{
		rep.cp_cal = rep.price / (rep.Cal_Per_Ser * rep.total);
	}
	return(rep);
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\n\nAnalysis Report (Note: Serving = %dg)", GRAM);
	printf("\n---------------");
	printf("\nSKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal");
	printf("\n------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rep, const int cheapestOption) 
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rep.sku, rep.price, rep.lbs, rep.kg, rep.g, rep.Cal_Per_Ser, rep.total, rep.cp_serv, rep.cp_cal);
}
int cheapestProduct = 0;

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProduct)
{
	printf("\nFinal Analysis");
	printf("\n--------------");
	printf("\nBased on the comparison data, the PURRR-fect economical option is:");
	printf("\nSKU:%07d Price: $%.2lf", cheapestProduct.sku, cheapestProduct.price);
	printf("\n\nHappy shopping!\n");

}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	openingMessage(MAX);

	struct CatFoodInfo cats[MAX] = { {0 } };

	int i;

	for (i = 0; i < MAX; i++)
	{
		cats[i] = getCatFoodInfo(i + 1);
	}
	displayCatFoodHeader();

	for (i = 0; i < MAX; i++)
	{
		displayCatFoodData(cats[i].sku, &cats[i].price, cats[i].Cal_Per_Ser, &cats[i].lbs);
	}

	struct ReportData rep[MAX];

	displayReportHeader();
	
	for (i = 0; i < MAX; i++) 
	{
		rep[i] = calculateReportData(cats[i]);
		if (rep[i].cp_serv < rep[cheapestProduct].cp_serv)
		{
			cheapestProduct = i;
		}
	}
	int j;
	for (j = 0; j < MAX; j++)
	{
		struct ReportData c = { 0 };
		c = rep[j];
		displayReportData(c, cheapestProduct);
		if (cheapestProduct == j)
		{
			printf(" ***");
		} printf("\n");
	}
	displayFinalAnalysis(cats[cheapestProduct]);
}
