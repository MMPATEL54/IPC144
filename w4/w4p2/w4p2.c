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
    //ia: initial apples and similarly io,it,ic and ip stands for different grocery iteams.
    int ia = 0, io = 0, it = 0, ic = 0, ip = 0;
    //fa: nuber of apples required to be picked and similarly fp, ft, fc and fo stands for different grocery iteams.
    int fa = 0, fp = 0, ft = 0, fc = 0, fo = 0;
    //ra: Stands for remaining number of apples and similarly rp,rt,rc and ro for different grocery iteams.
    int ra = 0, rp = 0, rt = 0, rc = 0, ro = 0;
    //fn: stands for yes or no to repeat the grocery shopping 1 is for yes and 0 is for no.
    int yn = 1;
    do
    {
        printf("Grocery Shopping");
        printf("\n================");
        //for taking the input for apple
        do
        {
            printf("\nHow many APPLES do you need? : ");
            scanf("%d", &ia);
            if (ia < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
        } while (ia < 0);
        //for taking the input for oranges
        do
        {
            printf("\nHow many ORANGES do you need? : ");
            scanf("%d", &io);
            if (io < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
        } while (io < 0);
        //for taking the input for pears
        do
        {
            printf("\nHow many PEARS do you need? : ");
            scanf("%d", &ip);
            if (ip < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
        } while (ip < 0);
        //for taking the input for tomatoes
        do
        {
            printf("\nHow many TOMATOES do you need? : ");
            scanf("%d", &it);
            if (it < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
        } while (it < 0);
        //for taking the input for cabbages
        do
        {
            printf("\nHow many CABBAGES do you need? : ");
            scanf("%d", &ic);
            if (ic < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
        } while (ic < 0);

        printf("\n--------------------------");
        printf("\nTime to pick the products!");
        printf("\n--------------------------\n");

        if (ia > 0)
        {
            do
            {
                printf("\nPick some APPLES... how many did you pick? : ");
                scanf("%d", &fa);
                fa = ra + fa;
                if (fa > ia)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.", ia - ra);
                }
                else if (fa <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else if (fa > 0 && fa < ia && fa != ia)
                {
                    printf("Looks like we still need some APPLES...");
                }
                else if (fa == ia)
                {
                    printf("Great, that's the apples done!\n");
                    break;
                }
                if (fa <= ia && fa > 0)
                {
                    ra = fa;
                }
            } while (ia != 0);
        } 

        if (io > 0)
        {
            do
            {
                printf("\nPick some ORANGES... how many did you pick? : ");
                scanf("%d", &fo);
                fo = ro + fo;
                if (fo > io)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.", io - ro);
                }
                else if (fo <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else if (fo > 0 && fo < io && fo != io)
                {
                    printf("Looks like we still need some ORANGES...");
                }
                else if (fo == io)
                {
                    printf("Great, that's the oranges done!\n");
                    break;
                }
                if (fo <= io && fo > 0) {
                    ro = fo;
                }
            } while (io != 0);
        }

        if (ip > 0)
        {
            do
            {
                printf("\nPick some PEARS... how many did you pick? : ");
                scanf("%d", &fp);
                fp = rp + fp;
                if (fp > ip)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.", ip - rp);
                }
                else if (fp <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else if (fp > 0 && fp < ip && fp != ip)
                {
                    printf("Looks like we still need some PEARS...");
                }
                else if (fp == ip)
                {
                    printf("Great, that's the pears done!\n");
                    break;
                }
                if (fp <= ip && fp > 0)
                {
                    rp = fp;
                }
            } while (ip != 0);
        }

        if (it > 0)
        {
            do
            {
                printf("\nPick some TOMATOES... how many did you pick? : ");
                scanf("%d", &ft);
                ft = rt + ft;
                if (ft > it)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.", it - rt);
                }
                else if (ft <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else if (ft > 0 && ft < it && ft != it)
                {
                    printf("Looks like we still need some TOMATOES...");
                }
                else if (ft == it)
                {
                    printf("Great, that's the tomatoes done!\n");
                    break;
                }
                if (ft <= it && ft > 0)
                {
                    rt = ft;
                }
            } while (it != 0);
        }

        if (ic > 0)
        {
            do
            {
                printf("\nPick some CABBAGES... how many did you pick? : ");
                scanf("%d", &fc);
                fc = rc + fc;
                if (fc > ic)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.", ic - rc);
                }
                else if (fc <= 0)
                {
                    printf("ERROR: You must pick at least 1!");
                }
                else if (fc > 0 && fc < ic && fc != ic)
                {
                    printf("Looks like we still need some CABBAGES...");
                }
                else if (fc == ic)
                {
                    printf("Great, that's the cabbages done!\n");
                    break;
                }
                if (fc <= ic && fc > 0)
                {
                    rc = fc;
                }
            } while (ic != 0);
        }

        printf("\nAll the items are picked!");
        printf("\n\nDo another shopping? (0=NO): ");
        scanf("%d", &yn);
	printf("\n");
        if (yn == 0)
        {
            printf("Your tasks are done for today - enjoy your free time!\n");
        }
    } while (yn == 1);
    return 0;
}