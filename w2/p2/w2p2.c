/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    float small_size = 0, medium_size = 0, large_size = 0, x = 0, y = 0, z = 0;
    int number_small = 0, number_medium = 0, number_large = 0, a = 0, b = 0,c = 0,d=0,e=0,f=0;
    float st_patty = 0, st_sally = 0, st_tommy = 0;
    float tax_patty = 0, tax_sally = 0, tax_tommy = 0,amount_withtax = 0;
    float final_subtotal = 0, final_taxes = 0, final_total = 0;
    float amount_withouttax = 0,avg_nontax = 0,total_number = 0,avg_tax = 0;
    int g = 0, h = 0, i = 0, j = 0, k = 0, l = 0;

    printf("Set Shirt Prices");
    printf("\n================");

    //asking for the price of the shirt
    printf("\nEnter the price for a SMALL shirt: $");
    scanf("%f", &small_size);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &medium_size);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &large_size);

    //prints the prices of the shirt
    printf("\nShirt Store Price List");
    printf("\n======================");
    printf("\nSMALL  : $%.2f", small_size);
    printf("\nMEDIUM : $%.2f", medium_size);
    printf("\nLARGE  : $%.2f", large_size);

    //asking for the number of shirts
    printf("\n\nPatty's shirt size is '%c'",patSize);
    printf("\nNumber of shirts Patty is buying: ");
    scanf("%d", &number_small);
    printf("\nTommy's shirt size is '%c'", tomSize);
    printf("\nNumber of shirts Tommy is buying: ");
    scanf("%d", &number_large);
    printf("\nSally's shirt size is '%c'", salSize);
    printf("\nNumber of shirts Sally is buying: ");
    scanf("%d", &number_medium);

    //calculation for patty
    x = small_size * 100;
    st_patty = x * number_small;
    st_patty = st_patty + 0.5;
    st_patty = (int)st_patty / (float)100;
    tax_patty = st_patty * TAX;
    tax_patty = tax_patty * 100;
    tax_patty = tax_patty + 0.5;
    tax_patty = (int)tax_patty / (float)100;

    //calculation for Tommy
    y = large_size * 100;
    st_tommy = y * number_large;
    st_tommy = st_tommy + 0.5;
    st_tommy = (int)st_tommy / (float)100;
    tax_tommy = st_tommy * TAX;
    tax_tommy = tax_tommy * 100;
    tax_tommy = tax_tommy + 0.5;
    tax_tommy = (int)tax_tommy / (float)100;

    //calculation for Sally
    z = medium_size * 100;
    st_sally = z * number_medium;
    st_sally = st_sally + 0.5;
    st_sally = (int)st_sally / (float)100;
    tax_sally = st_sally * TAX;
    tax_sally = tax_sally * 100;
    tax_sally = tax_sally + 0.5;
    tax_sally = (int)tax_sally / (float)100;

    //calculation for final sum of sub total, tax and total
    final_subtotal = st_patty + st_sally + st_tommy;
    final_taxes = tax_patty + tax_sally + tax_tommy;
    final_total = final_subtotal + final_taxes;

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total");
    printf("\n-------- ---- ----- --- --------- --------- ---------");
    printf("\nPatty    S %8.2f %3d %9.4f %9.4f %9.4f", small_size, number_small, st_patty, tax_patty, st_patty + tax_patty);
    printf("\nSally    M %8.2f %3d %9.4f %9.4f %9.4f", medium_size, number_medium, st_sally, tax_sally, st_sally + tax_sally);
    printf("\nTommy    L %8.2f %3d %9.4f %9.4f %9.4f", large_size, number_large, st_tommy, tax_tommy, st_tommy + tax_tommy);
    printf("\n-------- ---- ----- --- --------- --------- ---------");
    printf("\n%33.4f %9.4f %9.4f", final_subtotal,final_taxes, final_total);
    printf("\n\nDaily retail sales represented by coins");
    printf("\n=======================================");
    printf("\n\nSales EXCLUDING tax");
    printf("\nCoin     Qty   Balance");
    printf("\n-------- --- ---------");

    //calculation and printing excluding tax
    amount_withouttax = final_subtotal*100;
    printf("\n%22.4f", amount_withouttax/100);
    a = (amount_withouttax/(float)100) / (float)2;
    amount_withouttax = (amount_withouttax / (float)100) - (a*2);
    printf("\nToonies %4d %9.4f", a, amount_withouttax);    
    b = amount_withouttax / (float)1;
    amount_withouttax = amount_withouttax - (b*1);
    printf("\nLoonies %4d %9.4f", b, amount_withouttax);
    c = amount_withouttax / (float)0.25;
    amount_withouttax = amount_withouttax - (float)(c * 0.25);
    printf("\nQuarters %3d %9.4f", c, amount_withouttax);
    d = amount_withouttax / (float)0.10;
    amount_withouttax = amount_withouttax - (float)(d * 0.10);
    printf("\nDimes %6d %9.4f", d, amount_withouttax);
    e = amount_withouttax / (float)0.05;
    amount_withouttax = amount_withouttax - (float)(e * 0.05);
    printf("\nNickels %4d %9.4f", e, amount_withouttax);
    f = amount_withouttax / (float)0.01;
    amount_withouttax = amount_withouttax - (float)(f * 0.01);
    printf("\nPennies %4d %9.4f", f, amount_withouttax);

    //calculation for average for non-tax
    total_number = (float)(number_small + number_medium + number_large);
    avg_nontax = final_subtotal / total_number;
    printf("\n\nAverage cost/shirt: $%.4f", avg_nontax);

    printf("\n\nSales INCLUDING tax");
    printf("\nCoin     Qty   Balance");
    printf("\n-------- --- ---------");
    //calculation and printing includeing tax
    amount_withtax = final_total * 100;
    printf("\n%22.4f", amount_withtax / 100);
    g = (amount_withtax / (float)100) / (float)2;
    amount_withtax = (amount_withtax / (float)100) - (g * 2);
    printf("\nToonies %4d %9.4f", g, amount_withtax);
    h = amount_withtax / (float)1;
    amount_withtax = amount_withtax - (h * 1);
    printf("\nLoonies %4d %9.4f", h, amount_withtax);
    i = amount_withtax / (float)0.25;
    amount_withtax = amount_withtax - (float)(i * 0.25);
    printf("\nQuarters %3d %9.4f", i, amount_withtax);
    j = amount_withtax / (float)0.10;
    amount_withtax = amount_withtax - (float)(j * 0.10);
    printf("\nDimes %6d %9.4f", j, amount_withtax);
    k = amount_withtax / (float)0.05;
    amount_withtax = amount_withtax - (float)(k * 0.05);
    printf("\nNickels %4d %9.4f", k, amount_withtax);
    l = amount_withtax / (float)0.01;
    amount_withtax = amount_withtax - (float)(l * 0.01);
    printf("\nPennies %4d %9.4f", l, amount_withtax);

    //calculation for average for tax
    avg_tax = final_total / total_number;
    printf("\n\nAverage cost/shirt: $%.4f", avg_tax);
    printf("\n");
    
    return 0;
}