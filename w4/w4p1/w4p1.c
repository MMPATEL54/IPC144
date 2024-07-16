/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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
    int NL=0,x=0;//NL stands for number of times the loop has to be repeated
    char TL=0;// TL stands for the type of loop
    printf("+----------------------+");
    printf("\nLoop application STARTED");
    printf("\n+----------------------+");
    do
    {
        printf("\n\nD = do/while | W = while | F = for | Q = quit");
        printf("\nEnter loop type and the number of times to iterate (Quit=Q0): ");
        scanf("%c%d%*c", &TL, &NL);
        if (TL == 'D')
        {
            if (NL >= 3 && NL <= 20)
            {
                x = 0;
                printf("DO-WHILE: ");
                do 
                {
                    printf("%c", TL);
                    x++;
                } while (x < NL);
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!");
            }
        }
        else if (TL == 'W')
        {
            if (NL >= 3 && NL <= 20)
            {
                x = 0;
                printf("WHILE   : ");
                while (x < NL)
                {
                    printf("%c", TL);
                    x++;
                }
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!");
            }
        }
        else if (TL == 'F')
        {
            if (NL >= 3 && NL <= 20)
            {
		printf("FOR     : ");
                for (x = 0; x < NL; x++)
                {
                    printf("%c", TL);
                }
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!");
            }
        }
        else if (TL == 'Q')
        {
            if (NL == 0)
            {
                printf("\n+--------------------+");
                printf("\nLoop application ENDED");
                printf("\n+--------------------+");
                printf("\n");
                break;
            }
            else
            {
                printf("ERROR: To quit, the number of iterations should be 0!");
            }
        }
        else
        {
            printf("ERROR: Invalid entered value(s)!");
        }
    } while (TL >='A'&&TL<='z');
        return 0;
}