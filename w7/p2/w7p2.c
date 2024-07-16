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
struct GameArrays {
    char moves[70];
    char num_array[70];
    char bar_array[70];
};

int main()
{
    struct Player ply;
    struct Game gm;
    struct GameArrays ga;
    int i, j;
    double lim;
    int mod_count = 0, num_count = 0, player_moves = 0;
    int flag1 = 1, flag2 = 1, flag3 = 0, flag4 = 0;

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
            printf("    Value must be between %d and %.lf\n", ply.no_lives, lim);
        }
    } while (gm.max_moves > lim || gm.max_moves < ply.no_lives);

    printf("\nBOMB Placement");
    printf("\n--------------");
    printf("\nEnter the bomb positions in sets of 5 where a value");
    printf("\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.");
    printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gm.path_length);

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
    printf("\n====================================\n");

    for (i = 0; i < gm.path_length; i++)
    { 
        ga.moves[i] = '-';
    }
    for (i = 1; i < gm.path_length + 1; i++) 
    {
        if (i % 10 == 0) 
        {
            ga.bar_array[i - 1] = mod_count + '1';
            mod_count++;
        }
        else 
        {
            ga.bar_array[i - 1] = '|';
        }
    }
    for (i = 0; i < gm.path_length; i++) 
    {
        num_count++;
        if (num_count == 10) 
        {
            ga.num_array[i] = 0;
            num_count = 0;
        }
        else 
        {
            ga.num_array[i] = num_count;
        }
    }

    ply.num_treasure = 0;
    
    do 
    {

        if (flag4 == 0) 
        {
            flag4 = 1;
        }
        else 
        {
            printf("  ");
            while (flag1 == 1) 
            {
                for (i = 1; i <= player_moves; i++) 
                {
                    if (player_moves == i) 
                    {
                        printf("%c", ply.player_name);
                    }
                    else 
                    {
                        printf(" ");
                    }
                }
                flag1 = 0;
            }
        }
        printf("\n");
        printf("  ");
        for (i = 0; i < gm.path_length; i++) 
        {
            printf("%c", ga.moves[i]);
        }
        printf("\n");
        printf("  ");
        for (i = 0; i < gm.path_length; i++) 
        {
            printf("%c", ga.bar_array[i]);
        }
        printf("\n");
        printf("  ");
        for (i = 0; i < gm.path_length; i++) 
        {
            printf("%d", ga.num_array[i]);
        }
        printf("\n");

        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", ply.no_lives, ply.num_treasure, gm.max_moves);
        printf("+---------------------------------------------------+\n");

        if (gm.max_moves != 0 && ply.no_lives != 0) 
        {
            do
            {
                printf("Next Move [1-%d]: ", gm.path_length);
                scanf("%d", &player_moves);
                flag1 = 1;
                if (player_moves > gm.path_length || player_moves < 1)
                {
                    printf("  Out of Range!!!\n");
                }
                else
                {
                    flag2 = 0;
                }
            } while (flag2 == 1);

            if (ga.moves[player_moves - 1] != '-')
            {
                printf("\n===============> Dope! You've been here before!\n\n");
            }
            else if (gm.bomb[player_moves - 1] == 1 && gm.treasure[player_moves - 1] == 1)
            {
                printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                ga.moves[player_moves - 1] = '&';
                gm.max_moves--;
                ply.no_lives--;
                ply.num_treasure++;
            }
            else if (gm.bomb[player_moves - 1] == 1)
            {
                printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
                ga.moves[player_moves - 1] = '!';
                ply.no_lives--;
                gm.max_moves--;
            }
            else if (gm.treasure[player_moves - 1] == 1) 
            {
                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                ga.moves[player_moves - 1] = '$';
                ply.num_treasure++;
                gm.max_moves--;
            }
            else
            {
                printf("\n===============> [.] ...Nothing found here... [.]\n\n");
                ga.moves[player_moves - 1] = '.';
                gm.max_moves--;
            }
            if (ply.no_lives== 0) 
            {
                printf("No more LIVES remaining!\n\n");
            }
            else if (gm.max_moves == 0) 
            {
                printf("No more MOVES remaining!\n\n");
            }
        }
        else
        {
            printf("\n##################\n");
            printf("#   Game over!   #\n");
            printf("##################\n\n");
            flag3 = 1;
        }
    } while (flag3 == 0);

    printf("You should play again and try to beat your score!");
    
    printf("\n");

    return 0;
}