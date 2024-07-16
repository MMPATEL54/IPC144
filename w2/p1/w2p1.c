/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Manan Manojkumar Patel
Student ID#: 141782227
Email      : mananpatel6324@gmail.com
Section    : NDD

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    float small_size = 0, medium_size = 0, large_size = 0;
    float taxes = 0, sub_total = 0, x = 0;
    int number_of_shirt = 0;
    printf("Set Shirt Prices");
    printf("\n================");

    //Entering the values of the shirt.
    printf("\nEnter the price for a SMALL shirt: $");
    scanf("%f", &small_size);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &medium_size);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &large_size);

    printf("\nShirt Store Price List");
    printf("\n======================");


    printf("\nSMALL  : $%.2f", small_size);
    printf("\nMEDIUM : $%.2f", medium_size);
    printf("\nLARGE  : $%.2f", large_size);

    printf("\n\nPatty's shirt size is '%c'", patSize);
    printf("\nNumber of shirts Patty is buying: ");
    scanf("%d", &number_of_shirt);

    printf("\nPatty's shopping cart...");
    printf("\nContains : %d shirts", number_of_shirt);

    //Calculation
    x = small_size * 100;
    sub_total = x * number_of_shirt;
    taxes = sub_total * TAX;
    taxes = taxes + 0.5;
    taxes = (int)taxes / (float)100;
    //Final Display along with Calculation.
    printf("\nSub-total: $%.4f", sub_total / 100);
    printf("\nTaxes    : $%8.4f", taxes);
    printf("\nTotal    : $%.4f", taxes + (sub_total / 100));
    printf("\n");
    return 0;
}