// Project made by:
// - Ema3nto
// - Giovanni Bellini

/*
TODO LIST

☼ Change table charactewr for windows
☼ Adjust print for windows
☼ Make pointer movement even for windows

THE CODE BETWEEN THE
*****************************************************
COMMENT IS TO CHECK/TRY

THE ADDED CODE HAS THE <- COMMENT ON THE SIDE

*/

#include "inc.h"
#include "structure.c"
#include "winOrLose.c"
#include "menu.c"


/*****************************************************/
/*WHEN EXECUTED WITH GCC IT DON'T GIVE ANY ERROR*//*
#if _WIN64 || _WIN32 // <-

static int set_wide_stream(FILE *stream) // <-
{
    return _setmode(_fileno(stream), _O_U16TEXT); // <-
}

setlocale(LC_ALL, ""); // <-
set_wide_stream(stdout); // <-
*/
// #endif // <-
/*****************************************************/


/**************** VARIABILI GLOBALI ****************/
/*struct pos{
    int X;
    int Y;
};*/

int main(void);
struct pos cursorPos = {5, 11};

char campo[][79] =
{
    "┌───────┬───────┬───────┐",
    "│       │       │       │▒",
    "|       |       |       |▒",
    "│       │       │       │▒",
    "├───────┼───────┼───────┤▒",
    "│       │       │       │▒",
    "|       |       |       |▒",
    "│       │       │       │▒",
    "├───────┼───────┼───────┤▒",
    "│       │       │       │▒",
    "|       |       |       |▒",
    "│       │       │       │▒",
    "└───────┴───────┴───────┘▒",
    " ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒"
};

struct pos pedine[] = 
{
    // 0, 1, 2, 3, 4, 5 this are the name of the pawn
    
    //0       1         2
    {5, 3},  {13, 3},  {21, 3},
    //3       4         5
    {5, 11}, {13, 11}, {21, 11}
};

int selected = 3;
int mosse = 0;
int mosseMacchina = 0;
int isStart = 1;

/**************** GETCH ****************/
#ifdef __linux__ // this functions are only for linux

static struct termios old, current;
void initTermios() 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  current.c_lflag &= ~ECHO; /* set no echo mode */
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character without echo */
char getch(void)
{
  char ch;
  initTermios();
  ch = getchar();
  resetTermios();
  return ch;
}

#endif


/**************** FUNZIONI ****************/

void resetPartita()
{
    // reset the match from the menù and return in start game 2 or more times
    cursorPos.X = 5;
    cursorPos.Y = 11;

    int w = 0;
    for(int i=3; i<=11;i+=8)
    {        
        for(int j=5;j<=21;j+=8)
        {
            pedine[w].X = j;
            pedine[w].Y = i;
            w++;
        }
    }

    selected = 3;
    mosse = 0;
    mosseMacchina = 0;
}

void drawBoard()
{
    int a = 1;
    char check; //check if in the box there is a space
    for(int i = 0; i < sizeof(campo)/sizeof(campo[0]); ++i)
    {
        for(int j = 0; j < strlen(campo[4]); ++j)
        {
            check = 0;
            for(int k = 0; k < sizeof(pedine)/sizeof(pedine[0]); ++k)
            {
                if(pedine[k].X-1 == j && pedine[k].Y-1 == i)
                {
                    //print pawn
                    check |= 1;
                    printf("%d", k);
                    a *= 3;
                    break;                    
                }
            
            }
            if(!check)
            {
                printf("%c", campo[i][j]);
            }
        }
        if(i==1)
            printf("\tUser Moves: %d", mosse);
        if(i==2)
            printf("\tMachine Moves: %d", mosseMacchina);
        puts(""); // go in new line
    }
}

void moveCursor(char ch) 
{
    switch(ch)
    {
        case 'a': // move to sx
            if((cursorPos.X - 8) >= 5)
                cursorPos.X -= 8;
            break;          
        case 's': // move to bottom
            if((cursorPos.Y + 4) <= 11)
                cursorPos.Y += 4;
            break;
        case 'd': // move to dx
            if((cursorPos.X + 8) <= 21)
                cursorPos.X += 8;
            break;
        case 'w': // move to top
            if((cursorPos.Y - 4) >= 3)
                cursorPos.Y -= 4;
                break;
    }
}

int selection(struct pos input, int is3to6) // check if the input is on one of the pawns of the opponent
{
    int i = (is3to6)? 3 : 0;
    int a = (is3to6)? 6 : 3;
    for(; i < a; i++)
    {
        if(input.X == pedine[i].X && input.Y == pedine[i].Y)
        {
            return i;
        }
    }
    return -1;
}

int iselement(struct pos position) // check if in the input position there is an opponent pawn, if there is return the position of the pawn
{
    for(int i=0 ; i < 6; ++i)
    {
        if(position.X == pedine[i].X && position.Y == pedine[i].Y)
        {
            return i;
        }
    }
    return -1;
}

int rules(struct pos input, int upOrDown)
{
    if(input.X == pedine[selected].X && input.Y == pedine[selected].Y + upOrDown && iselement(input) == -1)
    {
        // if he moves by 1 position and there aren't pawns
        return 1;
    }
    else if(input.X == pedine[selected].X + 8 && input.Y == pedine[selected].Y + upOrDown && iselement(input) != -1)
    {
        // if he moves in oblique dx by 1 and there is an opponent pawn
        return 1;
    }
    else if(input.X == pedine[selected].X - 8 && input.Y == pedine[selected].Y + upOrDown && iselement(input) != -1)
    {
        // if he moves in oblique sx by 1 and there is an opponent pawn
        return 1;
    }

    return 0;
}

int piazza()
{
    if(selected != -1 && selection(cursorPos, 1) == -1 && rules(cursorPos, -4)) // check if the selected pawn is of the player, check if thecursor is on one of the player pawns, check if the rules are respected
    
    {
        int index = iselement(cursorPos); // index of opponent's pawn (if it is present)
        
        pedine[selected].X = cursorPos.X; // update the X & Y of the selected pawns
        pedine[selected].Y = cursorPos.Y;
        
        if(index != -1) // if the index is valid
        {
            //printf("\npiazza: %d\n", index);
            // delete the opponent's pawn
            pedine[index].X = -1;
            pedine[index].Y = -1;
        }

        selected = -1; // reset the selection

        mosse++;
        CLEAR;
        drawBoard();        
        return 1;
    }
    return 0;
}

int option(char ch)
{   
    // user turn
    switch(ch)
    {
        case 'a': // move to sx           
        case 's': // move to bottom           
        case 'd': // move to dx          
        case 'w': // move to top
            moveCursor(ch);
            break;
        case 32: // to select the pawn [space]
            selected = selection(cursorPos, 1);
            break;
        case 10: // to place the pawn [enter]
            return piazza();
        case 27:
            CLEAR;
            main();
            break;
    }
    return 0;
}

int isColorelement(int pIndex, struct pos arr[], int from, int to)
{
    for(int i = from; i < to; ++i)
    {
        if(pedine[pIndex].X == arr[i].X && pedine[pIndex].Y == arr[i].Y)
        {
            return 0;
        }
    }
    return 1;
}

struct pToRemove machine()
{
    ++mosseMacchina;
    struct pToRemove out;
    // computer turn
    for(int i = 0; i < sizeof(boxArr)/sizeof(boxArr[0]); ++i)
    {
        int j;
        for(j = 0; j < 6; ++j)
        {
            if(isColorelement(j, boxArr[i].board,(j < 3) ? 0 : 3, (j < 3) ? 3 : 6))
            {
                break;
            }
        }

        if(j == 6)
        {
            // if the i configuration is the actual
            int n_mossa;
            do{
                n_mossa = rand() % boxArr[i].howmany;
            }while(boxArr[i].active[n_mossa]==0);        
            // repeat the selection in the case of the extracted move is disabled

            int pedina_attuale;
            int pedinaDAmov = iselement(boxArr[i].moves[n_mossa][0]);
            pedina_attuale = iselement(boxArr[i].moves[n_mossa][1]);

            if(pedina_attuale != -1)
            {
                //if in the position to moves, is already there a pawn, the latter will be eaten
                pedine[pedina_attuale].X = -1;
                pedine[pedina_attuale].Y = -1;
            }
            
            //moves the pawn to the agreed position
            pedine[pedinaDAmov].X = boxArr[i].moves[n_mossa][1].X;
            pedine[pedinaDAmov].Y = boxArr[i].moves[n_mossa][1].Y;            

            CLEAR;
            drawBoard();
            out.n_box = i;
            out.pallino = n_mossa;
            return out;
        }
    }
}


int win(char isUser)
{
    int i = (isUser) ? 0 : 3;
    int j = (isUser) ? 3 : 0;
    int cicli = (isUser) ? 3 : 6;
    int cicli2 = (isUser) ? 6 : 3;
    int endBoard = (isUser) ? 3 : 11;


    // if all the pawns of the user/pc are eaten
    for(; i < cicli; ++i)
    {
        if(pedine[i].X != -1)
        {
            break;
        }
    }
    
    if(i == ((isUser) ? 3 : 6))
    {
        //if someone has lost all the pawns
        return 1;
    }

    // if at leas one of the pawns have reached the end of the board
    for(; j < cicli2; ++j) 
    {        
        if(pedine[j].Y == endBoard)
        {
            return 1;
        }
    }
    
    //check if a move is possible for the opponent
    i = (isUser) ? 0 : 3;
    int upOrDown = (isUser) ? 4 : -4;

    for(; i < cicli; ++i)
    { // foreach opponent's pawn in the field
        selected = i;
        struct pos tmp = pedine[selected];
        if(tmp.X == -1) // if the pawn isn't in the field move on to the next one
            continue;

        tmp.Y += upOrDown;
        
        if(tmp.Y > 0)
        {
            for(int otto = -8; otto <= 8; otto += 8)
            {
                
                if(((tmp.X == 5 && otto < 0) || (tmp.X == 21 && otto > 0)))
                {
                    
                    continue;
                }
                tmp.X += otto;
                
                //printf("sel %d %d --", pedine[selected].X, pedine[selected].Y);
                //printf("%d %d\n", tmp.X, tmp.Y);
                if(selection(tmp, !isUser) == -1 && rules(tmp, upOrDown))
                {
                    // if only 1 pawn can moves return 0
                    /*i = cicli + 1;                    
                    break;*/
                    selected= -1;
                   
                    return 0;
                }
            }
        }
    }

    selected = -1;
    if(i == cicli)
    {
        // the opponent's pawn cannot moves
        return 1;
    }
    return 0;
}

/**************** MAIN LOOP ****************/
int main(void)
{
    int c=0;

    resetPartita();// reset previous game's info

    /*
    * since the main is called after the end of the match
    * we need to reset the match, and doesn't show the splash screen for ever, moreover it has to show the menù
    */

    if(isStart)     // if is the start
        printTitle();  // print title
    isStart = 0;

    menu();        // print the menu
    readFile();    // read file to get the winning moves
    FFLUSHSTDOUT;
    
    srand(time(NULL));
    CLEAR;
    drawBoard();   // draw field
    FFLUSHSTDOUT;

    struct pToRemove p;

    while(1)
    {
        do{
            printf("\033[%d;%dH", cursorPos.Y, cursorPos.X);
            c = option(getch()); // user turn
        }while(c==0);
        if(win(1))
        {
            if(boxArr[p.n_box].howmany != 1)
            {
                boxArr[p.n_box].active[p.pallino] = 0;
            }
            remove("./data.db");
            for(int i = 0; i < sizeof(boxArr)/sizeof(boxArr[0]); ++i)
            {
                writeFile(boxArr[i].active, sizeof(boxArr[i].active)/sizeof(boxArr[i].active[0]));
            }

            //user win
            printWin();
            main();
        }
        
        SLEEP(300);
        p = machine();
        if(win(0))
        {
            //pc win
            printLose();
            main();
        }
        
    }
    return 0;
}