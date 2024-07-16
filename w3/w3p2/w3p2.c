/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : Patel Manan Manojkumar
Student ID#: 141782228
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    //tc stands for type of coffee
    char tc1, tc2, tc3, tc4, tc5;
    // bw stands for bag weight
    int bw1 = 0, bw2 = 0, bw3 = 0,bw4=0,bw5=0;
    // sc stands for served with cream here y or Y stands for yes and n or N represents No
    char yn1, yn2,yn3,yn4,yn5;
    printf("Take a Break - Coffee Shop");
    printf("\n==========================");
    printf("\n\nEnter the coffee product information being sold today...");
    printf("\n\nCOFFEE-1...");
    printf("\nType ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &tc1);
    printf("Bag weight (g): ");
    scanf("%d", &bw1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &yn1);
    printf("\nCOFFEE-2...");
    printf("\nType ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &tc2);
    printf("Bag weight (g): ");
    scanf("%d", &bw2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &yn2);
    printf("\nCOFFEE-3...");
    printf("\nType ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &tc3);
    printf("Bag weight (g): ");
    scanf("%d", &bw3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &yn3);
    printf("\n---+------------------------+---------------+-------+");
    printf("\n   |    Coffee              |   Packaged    | Best  |");
    printf("\n   |     Type               |  Bag Weight   | Served|");
    printf("\n   +------------------------+---------------+ With  |");
    printf("\nID | Light | Medium | Rich  |  (G) | Lbs    | Cream |");
    printf("\n---+------------------------+---------------+-------|");
    printf("\n 1 | %3d   | %3d    | %3d   | %4d |%7.3f |   %d   |", (tc1 == 'l' ||tc1 == 'L'),(tc2 == 'l'||tc2=='L'), (tc3 == 'l' || tc3 == 'L'),bw1,bw1/ GRAMS_IN_LBS,yn1 == 'y'||yn1 == 'Y');
    printf("\n 2 | %3d   | %3d    | %3d   | %4d |%7.3f | %3d   |", (tc1 == 'm' || tc1 == 'M'), (tc2 == 'm' || tc2 == 'M'), (tc3 == 'm' || tc3 == 'M'), bw2, (bw2 / GRAMS_IN_LBS), (yn2 == 'y' ||yn2== 'Y'));
    printf("\n 3 | %3d   | %3d    | %3d   | %4d |%7.3f | %3d   |", (tc1 == 'r' || tc1 == 'R'), (tc2 == 'r' || tc2 == 'R'), (tc3 == 'r' || tc3 == 'R'), bw3,( bw3 / GRAMS_IN_LBS), (yn3 == 'y'||yn3== 'Y'));
    printf("\n\nEnter how you like your coffee...");
    printf("\n\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &tc4);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &yn4);
    printf("Typical number of daily servings: ");
    scanf("%d", &bw4);
    printf("\nThe below table shows how your preferences align to the available products:");
    printf("\n\n--------------------+-------------+-------+");
    printf("\n  |     Coffee      |  Packaged   | With  |");
    printf("\nID|      Type       | Bag Weight  | Cream |");
    printf("\n--+-----------------+-------------+-------+");
    printf("\n 1|       %d         |      %d      |   %d   |",(tc4 == 'l' || tc4 == 'L'), (bw4 == 250) || (bw4 >= 1 && bw4 <= 4), (yn4 == 'y' || yn4 == 'Y'));
    printf("\n 2|       %d         |      %d      |   %d   |", (tc4 == 'r' || tc4 == 'R'), (bw4 == 500) || (bw4 >= 5 && bw4 <= 9), (yn4 == 'n' || yn4 == 'N'));
    printf("\n 3|       %d         |      %d      |   %d   |", (tc4 == 'm' || tc4 == 'M'), (bw4 == 1000) || (bw4 >= 10 && bw5 <= 1000), (yn4 == 'n' || yn4 == 'N'));
    printf("\n\nEnter how you like your coffee...");
    printf("\n\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &tc5);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &yn5);
    printf("Typical number of daily servings: ");
    scanf("%d", &bw5);
    printf("\nThe below table shows how your preferences align to the available products:");
    printf("\n\n--------------------+-------------+-------+");
    printf("\n  |     Coffee      |  Packaged   | With  |");
    printf("\nID|      Type       | Bag Weight  | Cream |");
    printf("\n--+-----------------+-------------+-------+");
    printf("\n 1|       %d         |      %d      |   %d   |", (tc5 == 'l'||tc5 == 'L'), (bw5 == 250) || (bw5 >= 1 && bw5 <= 4), (yn5 == 'y' || yn5 == 'Y') && (yn5 == yn1));
    printf("\n 2|       %d         |      %d      |   %d   |", (tc5 == 'r'||tc5 == 'R'), (bw5 == 500) || (bw5 >= 5 && bw5 <= 9), (yn5 == 'n' || yn5 == 'N'));
    printf("\n 3|       %d         |      %d      |   %d   |", (tc5 == 'm'||tc5 == 'M'), (bw5 == 1000) || (bw5 >= 10 && bw5 <= 1000), (yn5 == 'n' || yn5 == 'N'));
    printf("\n\nHope you found a product that suits your likes!");
    printf("\n");

    return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/ 