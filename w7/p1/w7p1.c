/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Manan Manojkumar Patel
Student ID#: 141782227
Email      : manana06032004@gmail.com
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 10
#define MIN 1
struct Player
{
    char player_name;
    int no_lives;
    int num_treasure;
    int history_array[70];
    
};
struct Game
{
    int max_moves;
    int path_length;
    int bomb[70];
    int treasure[70]; 
};

int main()
{
    struct Player ply;
    struct Game gm;
    int i, j;
    double lim;
    printf("================================"); 
    printf("\n         Treasure Hunt!");
    printf("\n================================");
    printf("\n\nPLAYER Configuration");
    printf("\n--------------------");
    printf("\nEnter a single character to represent the player: ");
    scanf("%c%*c", &ply.player_name);
    do
    {
        printf("Set the number of lives: ");
        scanf("%d%*c", &ply.no_lives);
        if (ply.no_lives > MAX || ply.no_lives < MIN)
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while (ply.no_lives > MAX || ply.no_lives < MIN);
    printf("Player configuration set-up is complete");
    printf("\n\nGAME Configuration");
    printf("\n------------------");
    
    do
    {
        printf("\nSet the path length (a multiple of 5 between 10-70): ");
        scanf("%d%*c", &gm.path_length);
        if (gm.path_length > 70 || gm.path_length < 10 || gm.path_length % 5 != 0)
        {
            printf("     Must be a multiple of 5 and between 10-70!!!");
        }
    } while (gm.path_length < 10 || gm.path_length > 70 || gm.path_length % 5 != 0);
    lim = gm.path_length * 0.75;
    lim += 0.5;
    lim = (int)lim;
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d%*c", &gm.max_moves);
        if (gm.max_moves > lim || gm.max_moves < ply.no_lives)
        {
            printf("    Value must be between %d and %.lf\n",ply.no_lives, lim);
        }
    } while (gm.max_moves > lim || gm.max_moves < ply.no_lives);
    
    printf("\nBOMB Placement");
    printf("\n--------------");
    printf("\nEnter the bomb positions in sets of 5 where a value");
    printf("\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.");
    printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",gm.path_length);

    for (j = 0; j < gm.path_length; j = j + 5)
    {
        printf("   Positions [%2d-%2d]: ", j + 1, j + 5);
        scanf("%d%*c %d%*c %d%*c %d%*c %d%*c", &gm.bomb[j], &gm.bomb[j + 1], &gm.bomb[j + 2], &gm.bomb[j + 3], &gm.bomb[j + 4]);
    }

    printf("BOMB placement set");
    printf("\n\nTREASURE Placement");
    printf("\n------------------");
    printf("\nEnter the treasure placements in sets of 5 where a value");
    printf("\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.");
    printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gm.path_length);


    for (i = 0; i < gm.path_length; i = i + 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d%*c %d%*c %d%*c %d%*c %d%*c", &gm.treasure[i], &gm.treasure[i + 1], &gm.treasure[i + 2], &gm.treasure[i + 3], &gm.treasure[i + 4]);
    }
    
    printf("TREASURE placement set");
    printf("\n\nGAME configuration set-up is complete...");
    
    printf("\n\n------------------------------------");
    printf("\nTREASURE HUNT Configuration Settings");
    printf("\n------------------------------------");
    printf("\nPlayer:");
    printf("\n   Symbol     : %c", ply.player_name);
    printf("\n   Lives      : %d", ply.no_lives);
    printf("\n   Treasure   : [ready for gameplay]");
    printf("\n   History    : [ready for gameplay]");

    printf("\n\nGame:");
    printf("\n   Path Length: %d", gm.path_length);
    printf("\n   Bombs      : ");
    for (j = 0; j < gm.path_length; j++)
    {
        printf("%d", gm.bomb[j]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < gm.path_length; i++)
    {
        printf("%d", gm.treasure[i]);
    }

    printf("\n\n====================================");
    printf("\n~ Get ready to play TREASURE HUNT! ~");
    printf("\n====================================");

    printf("\n");
    
    return 0;
}
