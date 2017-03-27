#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// dimensions
int d;

//board
int board[DIM_MAX][DIM_MAX];

//functions prototype
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
//bool won(void);
//void save(void);

//////////////////////////////////////
//////////////////////////////////////
int main(int argc , string argv[]){
    greet();
    
    d = atoi(argv[1]);
    
     if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }
    
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    
    init();
    
     while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        //save();

        // check for win
        /*
        if (won())
        {
            printf("ftw!\n");
            break;
        }
        */

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}
///////////////////////////////////////
///////////////////////////////////////

//////////////////////////////////////
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}
////////////////////////////////////


///////////////////////////////////////////////////////////
void init(void)
{
    // TODO
        int c = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
        // fill the tiles in descending order
        board[i][j] = d * d - c;
        c++;
        }
    }
    //make the last tile blank
    board[d-1][d-1] = 99;
   
    // if there are an odd number of tiles, switch 1 and 2
    /*
    if ((d * d)%2 == 0)
    {
        board[d-1][d-2] = 2;
        board[d-1][d-3] = 1;
    }
    */
}
////////////////////////////////////////////////////////////


///////////////////////////////////////////////
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++) 
        {
                if (board[i][j] == 99)
            // print the blank tile
                printf(" _");
            else
            // the tiles in descending order
                printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}
///////////////////////////////////////////////

//////////////////////////////////////////////
//checking for the valid move 
bool move(int tile)
{
    // establish algorithm for checking bordering tiles
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                //check if the blank is to the right
                if (j+1 <= d-1 && board[i][j+1] == 99)
                {
                    board[i][j+1] = tile;
                    board[i][j] = 99;
                    return true;
                }
                // check if the blank is to the left
                else if (j-1 >= 0 && board[i][j-1] == 99)
                {
                    board[i][j-1] = tile;
                    board[i][j] = 99;
                    return true;
                }
                // check if the blank is above
                else if (i-1 >= 0 && board[i-1][j] == 99)
                {
                    board[i-1][j] = tile;
                    board[i][j] = 99;
                    return true;
                }
                // check if the blank is below
                else if (i+1 <= d-1 && board[i+1][j] == 99)
                {
                    board[i+1][j] = tile;
                    board[i][j] = 99;
                    return true;
                }
            
            }
        }
    }
    return false;
}
/////////////////////////////////////////////////////////////////