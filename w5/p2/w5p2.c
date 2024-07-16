/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3
int main(void)
{
    int year = 0, month = 0, flag = 0, count=1;
    double morning = 0, evening = 0, total_morning = 0, total_evening = 0, avg_morning = 0, avg_evening = 0;
    const int JAN = 1, DEC = 12;
    printf("General Well-being Log");
    printf("\n======================");
    do
    {
        printf("\nSet the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
        
        if ((year <= MAX_YEAR && year >= MIN_YEAR) && (month <= DEC && month >= JAN))
        {
	    printf("\n*** Log date set! ***\n");	
            flag = 1;
            if (month == 1)
            {
                
                for (count = 1; count <= LOG_DAYS; count++)
                {
                    printf("\n%d-JAN-0%d", year,count);
                    
                    do 
                    {
                        printf("\n   Morning rating (0.0-5.0): ");
                        scanf("%lf", &morning);
                        if (morning > 5.0 || morning < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
                        }
                        
                    } while (morning < 0.0 || morning > 5.0);
                   
                    do 
                    {
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%lf", &evening);
                        if (evening > 5.0 || evening < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        }
                            
                    } while (evening < 0.0 || evening > 5.0);  
                    total_morning = total_morning + morning;
                    total_evening = total_evening + evening;
                }
                printf("\nSummary");
                printf("\n=======");
                printf("\nMorning total rating: %6.3lf", total_morning);
                printf("\nEvening total rating: %6.3lf", total_evening);
                printf("\n----------------------------");
                printf("\nOverall total rating: %6.3lf", total_morning + total_evening);
                avg_morning = total_morning / LOG_DAYS;
                printf("\n\nAverage morning rating: %4.1lf", avg_morning);
                avg_evening = total_evening / LOG_DAYS;
                printf("\nAverage evening rating: %4.1lf", avg_evening);
                printf("\n----------------------------");
                printf("\nAverage overall rating: %4.1lf", (total_morning + total_evening)/6);
		printf("\n");
            }
            if (month == 2)
            {
                
                for (count = 1; count <= LOG_DAYS; count++)
                {
                    printf("\n%d-FEB-0%d", year,count);

                    do
                    {
                        printf("\n   Morning rating (0.0-5.0): ");
                        scanf("%lf", &morning);
                        if (morning > 5.0 || morning < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
                        }
                        
                    } while (morning < 0.0 || morning > 5.0);

                    do
                    {
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%lf", &evening);
                        if (evening > 5.0 || evening < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        }
                        
                    } while (evening < 0.0 || evening > 5.0);

                    total_morning = total_morning + morning;
                    total_evening = total_evening + evening;
                }
                printf("\nSummary");
                printf("\n=======");
                printf("\nMorning total rating: %6.3lf", total_morning);
                printf("\nEvening total rating: %6.3lf", total_evening);
                printf("\n----------------------------");
                printf("\nOverall total rating: %6.3lf", total_morning + total_evening);
                avg_morning = total_morning / LOG_DAYS;
                printf("\n\nAverage morning rating: %4.1lf", avg_morning);
                avg_evening = total_evening / LOG_DAYS;
                printf("\nAverage evening rating: %4.1lf", avg_evening);
                printf("\n----------------------------");
                printf("\nAverage overall rating: %4.1lf", (total_morning + total_evening) / 6);
		printf("\n");
            }
     
            if (month == 3)
            {
                
                for (count = 1; count <= LOG_DAYS; count++)
                {
                    printf("\n%d-MAR-0%d", year,count);

                    do
                    {
                        printf("\n   Morning rating (0.0-5.0): ");
                        scanf("%lf", &morning);
                        if (morning > 5.0 || morning < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
                        }
                        
                    } while (morning < 0.0 || morning > 5.0);

                    do
                    {
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%lf", &evening);
                        if (evening > 5.0 || evening < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        }
                        
                    } while (evening < 0.0 || evening > 5.0);
                    total_morning = total_morning + morning;
                    total_evening = total_evening + evening;
                }
                printf("\nSummary");
                printf("\n=======");
                printf("\nMorning total rating: %6.3lf", total_morning);
                printf("\nEvening total rating: %6.3lf", total_evening);
                printf("\n----------------------------");
                printf("\nOverall total rating: %6.3lf", total_morning + total_evening);
                avg_morning = total_morning / LOG_DAYS;
                printf("\n\nAverage morning rating: %4.1lf", avg_morning);
                avg_evening = total_evening / LOG_DAYS;
                printf("\nAverage evening rating: %4.1lf", avg_evening);
                printf("\n----------------------------");
                printf("\nAverage overall rating: %4.1lf", (total_morning + total_evening) / 6);
		printf("\n");
            }
            if (month == 4)
            {
                
                for (count = 1; count <= LOG_DAYS; count++)
                {
                    printf("\n%d-APR-0%d", year,count);

                    do
                    {
                        printf("\n   Morning rating (0.0-5.0): ");
                        scanf("%lf", &morning);
                        if (morning > 5.0 || morning < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
                        }
                       
                    } while (morning < 0.0 || morning > 5.0);

                    do
                    {
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%lf", &evening);
                        if (evening > 5.0 || evening < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        }
                        
                    } while (evening < 0.0 || evening > 5.0);
                    total_morning = total_morning + morning;
                    total_evening = total_evening + evening;
                }
                printf("\nSummary");
                printf("\n=======");
                printf("\nMorning total rating: %6.3lf", total_morning);
                printf("\nEvening total rating: %6.3lf", total_evening);
                printf("\n----------------------------");
                printf("\nOverall total rating: %6.3lf", total_morning + total_evening);
                avg_morning = total_morning / LOG_DAYS;
                printf("\n\nAverage morning rating: %4.1lf", avg_morning);
                avg_evening = total_evening / LOG_DAYS;
                printf("\nAverage evening rating: %4.1lf", avg_evening);
                printf("\n----------------------------");
                printf("\nAverage overall rating: %4.1lf", (total_morning + total_evening) / 6);
		printf("\n");
            }
            if (month == 5)
            {
                
                for (count = 1; count <= LOG_DAYS; count++)
                {
                    printf("\n%d-MAY-0%d", year,count);

                    do
                    {
                        printf("\n   Morning rating (0.0-5.0): ");
                        scanf("%lf", &morning);
                        if (morning > 5.0 || morning < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
                        }
                    } while (morning < 0.0 || morning > 5.0);

                    do
                    {
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%lf", &evening);
                        if (evening > 5.0 || evening < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        }
                        
                    } while (evening < 0.0 || evening > 5.0);
                    total_morning = total_morning + morning;
                    total_evening = total_evening + evening;
                }
                printf("\nSummary");
                printf("\n=======");
                printf("\nMorning total rating: %6.3lf", total_morning);
                printf("\nEvening total rating: %6.3lf", total_evening);
                printf("\n----------------------------");
                printf("\nOverall total rating: %6.3lf", total_morning + total_evening);
                avg_morning = total_morning / LOG_DAYS;
                printf("\n\nAverage morning rating: %4.1lf", avg_morning);
                avg_evening = total_evening / LOG_DAYS;
                printf("\nAverage evening rating: %4.1lf", avg_evening);
                printf("\n----------------------------");
                printf("\nAverage overall rating: %4.1lf", (total_morning + total_evening) / 6);
		printf("\n");
            }
            if (month == 6)
            {
                
                for (count = 1; count <= LOG_DAYS; count++)
                {
                    printf("\n%d-JUN-0%d", year,count);

                    do
                    {
                        printf("\n   Morning rating (0.0-5.0): ");
                        scanf("%lf", &morning);
                        if (morning > 5.0 || morning < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
                        }
                        
                    } while (morning < 0.0 || morning > 5.0);

                    do
                    {
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%lf", &evening);
                        if (evening > 5.0 || evening < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        }
                        
                    } while (evening < 0.0 || evening > 5.0);
                    total_morning = total_morning + morning;
                    total_evening = total_evening + evening;
                }
                printf("\nSummary");
                printf("\n=======");
                printf("\nMorning total rating: %6.3lf", total_morning);
                printf("\nEvening total rating: %6.3lf", total_evening);
                printf("\n----------------------------");
                printf("\nOverall total rating: %6.3lf", total_morning + total_evening);
                avg_morning = total_morning / LOG_DAYS;
                printf("\n\nAverage morning rating: %4.1lf", avg_morning);
                avg_evening = total_evening / LOG_DAYS;
                printf("\nAverage evening rating: %4.1lf", avg_evening);

                printf("\n----------------------------");
                printf("\nAverage overall rating: %4.1lf", (total_morning + total_evening) / 6);
		printf("\n");
            }
            if (month == 7)
            {
                
                for (count = 1; count <= LOG_DAYS; count++)
                {
                    printf("\n%d-JUL-0%d", year,count);

                    do
                    {
                        printf("\n   Morning rating (0.0-5.0): ");
                        scanf("%lf", &morning);
                        if (morning > 5.0 || morning < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
                        }
                        
                    } while (morning < 0.0 || morning > 5.0);

                    do
                    {
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%lf", &evening);
                        if (evening > 5.0 || evening < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        }
                        
                    } while (evening < 0.0 || evening > 5.0);
                    total_morning = total_morning + morning;
                    total_evening = total_evening + evening;
                }
                printf("\nSummary");
                printf("\n=======");
                printf("\nMorning total rating: %6.3lf", total_morning);
                printf("\nEvening total rating: %6.3lf", total_evening);
                printf("\n----------------------------");
                printf("\nOverall total rating: %6.3lf", total_morning + total_evening);
                avg_morning = total_morning / LOG_DAYS;
                printf("\n\nAverage morning rating: %4.1lf", avg_morning);
                avg_evening = total_evening / LOG_DAYS;
                printf("\nAverage evening rating: %4.1lf", avg_evening);
                printf("\n----------------------------");
                printf("\nAverage overall rating: %4.1lf", (total_morning + total_evening) / 6);
		printf("\n");
            }
            if (month == 8)
            {
                
                for (count = 1; count <= LOG_DAYS; count++)
                {
                    printf("\n%d-AUG-0%d", year,count);

                    do
                    {
                        printf("\n   Morning rating (0.0-5.0): ");
                        scanf("%lf", &morning);
                        if (morning > 5.0 || morning < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
                        }
                        
                    } while (morning < 0.0 || morning > 5.0);

                    do
                    {
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%lf", &evening);
                        if (evening > 5.0 || evening < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        }
                        
                    } while (evening < 0.0 || evening > 5.0);
                    total_morning = total_morning + morning;
                    total_evening = total_evening + evening;
                }
                printf("\nSummary");
                printf("\n=======");
                printf("\nMorning total rating: %6.3lf", total_morning);
                printf("\nEvening total rating: %6.3lf", total_evening);
                printf("\n----------------------------");
                printf("\nOverall total rating: %6.3lf", total_morning + total_evening);
                avg_morning = total_morning / LOG_DAYS;
                printf("\n\nAverage morning rating: %4.1lf", avg_morning);
                avg_evening = total_evening / LOG_DAYS;
                printf("\nAverage evening rating: %4.1lf", avg_evening);
                printf("\n----------------------------");
                printf("\nAverage overall rating: %4.1lf", (total_morning + total_evening) / 6);
		printf("\n");
            }
            if (month == 9)
            {
                
                for (count = 1; count <= LOG_DAYS; count++)
                {
                    printf("\n%d-SEP-0%d", year,count);

                    do
                    {
                        printf("\n   Morning rating (0.0-5.0): ");
                        scanf("%lf", &morning);
                        if (morning > 5.0 || morning < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
                        }
                        
                    } while (morning < 0.0 || morning > 5.0);

                    do
                    {
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%lf", &evening);
                        if (evening > 5.0 || evening < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        }
                        
                    } while (evening < 0.0 || evening > 5.0);
                    total_morning = total_morning + morning;
                    total_evening = total_evening + evening;
                }
                printf("\nSummary");
                printf("\n=======");
                printf("\nMorning total rating: %6.3lf", total_morning);
                printf("\nEvening total rating: %6.3lf", total_evening);
                printf("\n----------------------------");
                printf("\nOverall total rating: %6.3lf", total_morning + total_evening);
                avg_morning = total_morning / LOG_DAYS;
                printf("\n\nAverage morning rating: %4.1lf", avg_morning);
                avg_evening = total_evening / LOG_DAYS;
                printf("\nAverage evening rating: %4.1lf", avg_evening);
                printf("\n----------------------------");
                printf("\nAverage overall rating: %4.1lf", (total_morning + total_evening) / 6);
		printf("\n");
            }
            if (month == 10)
            {
                
                for (count = 1; count <= LOG_DAYS; count++)
                {
                    printf("\n%d-OCT-0%d", year,count);

                    do
                    {
                        printf("\n   Morning rating (0.0-5.0): ");
                        scanf("%lf", &morning);
                        if (morning > 5.0 || morning < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
                        }
                        
                    } while (morning < 0.0 || morning > 5.0);

                    do
                    {
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%lf", &evening);
                        if (evening > 5.0 || evening < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        }
                        
                    } while (evening < 0.0 || evening > 5.0);
                    total_morning = total_morning + morning;
                    total_evening = total_evening + evening;
                }
                printf("\nSummary");
                printf("\n=======");
                printf("\nMorning total rating: %6.3lf", total_morning);
                printf("\nEvening total rating: %6.3lf", total_evening);
                printf("\n----------------------------");
                printf("\nOverall total rating: %6.3lf", total_morning + total_evening);
                avg_morning = total_morning / LOG_DAYS;
                printf("\n\nAverage morning rating: %4.1lf", avg_morning);
                avg_evening = total_evening / LOG_DAYS;
                printf("\nAverage evening rating: %4.1lf", avg_evening);
                printf("\n----------------------------");
                printf("\nAverage overall rating: %4.1lf", (total_morning + total_evening) / 6);
		printf("\n");
            }
            if (month == 11)
            {
                
                for (count = 1; count <= LOG_DAYS; count++)
                {
                    printf("\n%d-NOV-0%d", year,count);

                    do
                    {
                        printf("\n   Morning rating (0.0-5.0): ");
                        scanf("%lf", &morning);
                        if (morning > 5.0 || morning < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
                        }
                        
                    } while (morning < 0.0 || morning > 5.0);

                    do
                    {
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%lf", &evening);
                        if (evening > 5.0 || evening < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        }
                        
                    } while (evening < 0.0 || evening > 5.0);
                    total_morning = total_morning + morning;
                    total_evening = total_evening + evening;
                }
                printf("\nSummary");
                printf("\n=======");
                printf("\nMorning total rating: %6.3lf", total_morning);
                printf("\nEvening total rating: %6.3lf", total_evening);
                printf("\n----------------------------");
                printf("\nOverall total rating: %6.3lf", total_morning + total_evening);
                avg_morning = total_morning / LOG_DAYS;
                printf("\n\nAverage morning rating: %4.1lf", avg_morning);
                avg_evening = total_evening / LOG_DAYS;
                printf("\nAverage evening rating: %4.1lf", avg_evening);
                printf("\n----------------------------");
                printf("\nAverage overall rating: %4.1lf", (total_morning + total_evening) / 6);
		printf("\n");
            }
            if (month == 12)
            {
                
                for (count = 1; count <= LOG_DAYS; count++)
                {
                    printf("\n%d-DEC-0%d", year,count);

                    do
                    {
                        printf("\n   Morning rating (0.0-5.0): ");
                        scanf("%lf", &morning);
                        if (morning > 5.0 || morning < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
                        }
                        
                    } while (morning < 0.0 || morning > 5.0);

                    do
                    {
                        printf("   Evening rating (0.0-5.0): ");
                        scanf("%lf", &evening);
                        if (evening > 5.0 || evening < 0.0)
                        {
                            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                        }
                        
                    } while (evening < 0.0 || evening > 5.0);
                    total_morning = total_morning + morning;
                    total_evening = total_evening + evening;

                }
                printf("\nSummary");
                printf("\n=======");
                printf("\nMorning total rating: %6.3lf", total_morning);
                printf("\nEvening total rating: %6.3lf", total_evening);
                printf("\n----------------------------");
                printf("\nOverall total rating: %6.3lf", total_morning + total_evening);
                avg_morning = total_morning / LOG_DAYS;
                printf("\n\nAverage morning rating: %4.1lf", avg_morning);
                avg_evening = total_evening / LOG_DAYS;
                printf("\nAverage evening rating: %4.1lf", avg_evening);
                printf("\n----------------------------");

                printf("\nAverage overall rating: %4.1lf", (total_morning + total_evening) / 6);
		printf("\n");
            }

        }
        else if ((month <= JAN || month >= DEC) && (year >= MIN_YEAR && year <= MAX_YEAR))
        {
            printf("   ERROR: Jan.(1) - Dec.(12)");
        }
        else if ((year <= MIN_YEAR || year >= MAX_YEAR) && (month <= DEC && month >= JAN))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive");
        }
        else
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive");
            printf("\n   ERROR: Jan.(1) - Dec.(12)");
        }

    }while (flag == 0);

    return 0;
}