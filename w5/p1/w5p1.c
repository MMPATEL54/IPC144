/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
int main(void)
{
    int year = 0, month = 0, flag = 0;
    const int JAN = 1, DEC = 12;
    printf("General Well-being Log");
    printf("\n======================");
    do
    {
        printf("\nSet the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
        if ((year <= MAX_YEAR && year >= MIN_YEAR) && (month <= DEC && month >= JAN))
        {
            flag = 1;
            if (month == 1)
            {
                printf("\n*** Log date set! ***");
                printf("\n\nLog starting date: %d-JAN-01", year);
                
            }
            if (month == 2)
            {
                printf("\n*** Log date set! ***");
                printf("\n\nLog starting date: %d-FEB-01", year);
            }
            if (month == 3)
            {
                printf("\n*** Log date set! ***");
                printf("\n\nLog starting date: %d-MAR-01", year);
            }
            if (month == 4)
            {
                printf("\n*** Log date set! ***");
                printf("\n\nLog starting date: %d-APR-01", year);
            }
            if (month == 5)
            {
                printf("\n*** Log date set! ***");
                printf("\n\nLog starting date: %d-MAY-01", year);
            }
            if (month == 6)
            {
                printf("\n*** Log date set! ***");
                printf("\n\nLog starting date: %d-JUN-01", year);
            }
            if (month == 7)
            {
                printf("\n*** Log date set! ***");
                printf("\n\nLog starting date: %d-JUL-01", year);
            }
            if (month == 8)
            {
                printf("\n*** Log date set! ***");
                printf("\n\nLog starting date: %d-AUG-01", year);
            }
            if (month == 9)
            {
                printf("\n*** Log date set! ***");
                printf("\n\nLog starting date: %d-SEPT-01", year);
            }
            if (month == 10)
            {
                printf("\n*** Log date set! ***");
                printf("\n\nLog starting date: %d-OCT-01", year);
            }
            if (month == 11)
            {
                printf("\n*** Log date set! ***");
                printf("\n\nLog starting date: %d-NOV-01", year);
            }
            if (month == 12)
            {
                printf("\n*** Log date set! ***");
                printf("\n\nLog starting date: %d-DEC-01", year);
            }
            
        }
        else if((month <= JAN || month >= DEC)&&(year >= MIN_YEAR && year <= MAX_YEAR))
        {
            printf("   ERROR: Jan.(1) - Dec.(12)");
        }
        else if ((year <= MIN_YEAR || year >= MAX_YEAR)&&(month <= DEC && month >= JAN))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive");
        }
        else
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive");
            printf("\n   ERROR: Jan.(1) - Dec.(12)");
        }

    }while (flag == 0);
    printf("\n");
    return 0;
}