#include "inc.h"

void stampaMenu()
{
    //don't call this function out of this file
     char arr[][172]=
    {
        "┌───────────────────────────────────────────────────────┐",
        "│    _   _                 ______                       │",
        "│   | | | |                | ___ \\                      │",
        "│   | |_| | _____  ____ _  | |_/ /_ ___      ___ __     │",
        "│   |  _  |/ _ \\ \\/ / _` | |  __/ _` \\ \\ /\\ / / '_ \\    │",
        "│   | | | |  __/>  < (_| | | | | (_| |\\ V  V /| | | |   │",
        "│   \\_| |_/\\___/_/\\_\\__,_| \\_|  \\__,_| \\_/\\_/ |_| |_|   │",
        "│                                                       │",
        "│                                                       │",
        "│       1) Start Game                                   │",
        "│         2) Rules                                      │",
        "│        3) Acknowledgment                              │",
        "│          4) Reset Game                                │",
        "│        5) Exit                                        │",
        "│───────────────────────────────────────────────────────│",
        "└───────────────────────────────────────────────────────┘"
    };
    
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < strlen(arr[i]); j++)
        {
            printf("%c", arr[i][j]);
        }
        puts("");
    }
}

void printHLP()
{
    CLEAR;
    char arr[][256] = {
        "╭───────────────────────────────────────────────────────────────────────────────────╮",
        "│  RULES                                                                            │",
        "│                                                                                   │",
        "│  In the 3*3 field are 6 pawns, 0,1,2 are from the PC,                             │",
        "│  and 3,4,5 are yours.                                                             │",
        "│                                                                                   │",
        "│  HOW TO PLAY                                                                      │",
        "│    ☼ To move the cursor use: [a] (left), [s] (down), [w] (up), [d] (right).       │",
        "│                                                                                   │",
        "│    ☼ To (select) a pawn press [space],                                            │",
        "│    and to (place) a selected pawn press [enter].                                  │",
        "│                                                                                   │",
        "│    ☼ You can move the selected pawn forward by one position,                      │",
        "│    if there isn't any pawn.                                                       │",
        "│                                                                                   │",
        "│    ☼ It's possible to eat an opponent's pawn only by moving sideways.             │",
        "│                                                                                   │",
        "│    ☼ The pawns cannot move horizontally and backwards.                            │",
        "│                                                                                   │",
        "│  HOW TO WIN                                                                       │",
        "│    ☼ The 1st way to win is eat all opponent's pawns.                              │",
        "│                                                                                   │",
        "│    ☼ In 2nd is to reach the opponet's border with one of your pawn.               │",
        "│                                                                                   │",
        "│    ☼ All the opponent's pawns have to be blocked in his turn.                     │",
        "│                                                                                   │",
        "╰───────────────────────────────────────────────────────────────────────────────────╯"
    };

    for(int i = 0; i < 27; i++)
    {
        for(int j = 0; j < strlen(arr[i]); j++)
        {
            printf("%c", arr[i][j]);
        }
        puts("");
    }
    PAUSE;
}



void printAck()
{
    CLEAR;
    char arr[][147] = {
        "ACKNOWLEDGMENT",
        "   ☼ Ema3nto",
        "   ☼ Bellini Giovanni",
        "    __      ___                 _   _                           __  ___    _   _               ",
        "    \\ \\    / (_)               | | | |                         /_ |/ _ \\  | \\ | |              ",
        "     \\ \\  / / _ ___ _   _  __ _| | | |     __ _ ___  ___ _ __   | | | | | |  \\| | _____      __",
        "      \\ \\/ / | / __| | | |/ _` | | | |    / _` / __|/ _ \\ '__|  | | | | | | . ` |/ _ \\ \\ /\\ / /",
        "       \\  /  | \\__ \\ |_| | (_| | | | |___| (_| \\__ \\  __/ |     | | |_| | | |\\  |  __/\\ V  V / ",
        "        \\/   |_|___/\\__,_|\\__,_|_| |______\\__,_|___/\\___|_|     |_|\\___/  |_| \\_|\\___| \\_/\\_/\n\n",
        "   Source - https://github.com/VisualLaser10New/HexaPawn"
    };

    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < strlen(arr[i]); j++)
        {
            printf("%c", arr[i][j]);
        }
        puts("");
    }
    PAUSE;
}

void menu()
{
    char t,c;
    do{
        CLEAR;
        stampaMenu();
       // printf(">> ");
        char scelta;
        //do{
            printf(">> ");
            FFLUSHSTDIN;
            FFLUSHSTDOUT;
            scanf("%c",&scelta);
            
        //}while(strchr("12345",scelta) == NULL);

        switch(scelta)
        {
            case '1': // start game
                return;
            case '2': // help
                printHLP();
                break;
            case '3': // Acknowledgment
                printAck();
                break;
            case '4': // remove the saved data
                remove("data.db");
                break;
            case '5':
                CLEAR;
                exit(0);
        }
    }while(1);
}