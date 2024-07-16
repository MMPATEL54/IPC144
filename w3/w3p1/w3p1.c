/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Patel Manan Manojkumar 
Student ID#: 141782227
Email      : mananpatel6324@gmail.com
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    // pid stands for product id so pid1 means price of product 1
    int pid1 = 111, pid2 = 222, pid3 = 111;
    // pop stand for price of product so pop1 = price of product 1
    float pop1 = 111.49, pop2 = 222.99, pop3 = 334.49;
    // t stands for taxes if it says 'Y' it means the product is tax able and 'N' means the product is not tax able
    char t1 = 'Y', t2 = 'N', t3 = 'N';
    float avg = 0;//avg stands for average price of all the 3 products

    printf("Product Information");
    printf("\n===================");
    printf("\nProduct-1 (ID:%d)", pid1);
    printf("\n  Taxed: %c", t1);
    printf("\n  Price: $%.4f", pop1);

    printf("\n\nProduct-2 (ID:%d)", pid2);
    printf("\n  Taxed: %c", t2);
    printf("\n  Price: $%.4f", pop2);

    printf("\n\nProduct-3 (ID:%d)", pid3);
    printf("\n  Taxed: %c", t3);
    printf("\n  Price: $%.4f", pop3);

    //calculation
    avg = (pop1 + pop2 + pop3) / (float)3;
    printf("\n\nThe average of all prices is: $%.4f", avg);

    printf("\n\nAbout Relational and Logical Expressions!");
    printf("\n========================================");
    printf("\n1. These expressions evaluate to TRUE or FALSE");
    printf("\n2. FALSE: is always represented by integer value 0");
    printf("\n3. TRUE : is represented by any integer value other than 0");
    printf("\n\nSome Data Analysis...");
    printf("\n=====================");

    printf("\n1. Is product 1 taxable? -> %d", t1 == 'Y');
    printf("\n\n2. Are products 2 and 3 both NOT taxable (N)? -> %d",t2 == 'N' || t3 == 'N');
    printf("\n\n3. Is product 3 less than testValue ($%.2lf)? -> %d", testValue,(pop3 < testValue));
    printf("\n\n4. Is the price of product 3 more than both product 1 and 2 combined? -> %d", pop3 > (pop1 + pop2));
    printf("\n\n5. Is the price of product 1 equal to or more than the price difference");
    printf("\n   of product 3 LESS product 2? ->  %d (price difference: $%.2f)", pop1 >= (pop3 - pop2),(pop3-pop2));
    printf("\n\n6. Is the price of product 2 equal to or more than the average price? -> %d", pop2 >= avg);
    printf("\n\n7. Based on product ID, product 1 is unique -> %d", pid1 != pid2 && pid1 != pid3);
    printf("\n\n8. Based on product ID, product 2 is unique -> %d", pid2 != pid1 && pid2 != pid3);
    printf("\n\n9. Based on product ID, product 3 is unique -> %d",pid3 != pid1 && pid3 != pid2);
    printf("\n");

    return 0;
}