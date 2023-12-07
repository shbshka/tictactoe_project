#include <stdio.h>

void grid(char *all_rows[]);
int x_filling_form(void);
int y_filling_form(void);
int win_situation(char *all_rows[]);

void main()
{
    char first_row[] = {' ', ' ', ' '};
    char second_row[] = {' ', ' ', ' '};
    char third_row[] = {' ', ' ', ' '};
    char *rows[] = {first_row, second_row, third_row};

    grid(rows);

    int count;
    int player;

    for(count = 0, player = 0; count < 9; count++, player++)    
    {

        if (win_situation(rows) == 1)
        {
            printf("You won!");
            break;
        }

        char symbol;

        if (player % 2 == 0)
        {
            printf("Player A\n");
            symbol = 'X';
        }
        else
        {
            printf("Player B\n");
            symbol = 'O';
        }

        int x = 0;
        int y = 0;

        x = x_filling_form();
        y = y_filling_form();
        
        if(rows[y - 1][x - 1] == 'X' || rows[y - 1][x - 1] == 'O')
        {
            printf("\nThe cell is already occupied :(\n\n");
        }
        else
        {
            rows[y - 1][x - 1] = symbol;       
            grid(rows);
        }        
    }

    if (win_situation(rows) == 0)  
    {
        printf("You both are loosers :(");
    }
}


void grid(char *all_rows[])

/* Draws the tictactoe field */

{
    int upper, side;

    printf(" |");
    for(upper = 1; upper <= 3; upper++)
    {
        printf(" %d ", upper);
        putchar('|');
    }

    putchar('\n');
    printf("-------------\n");

    for(side = 0; side <= 2; side++)
    {
        printf("%d| %c | %c | %c |\n", side + 1, all_rows[side][0], all_rows[side][1], all_rows[side][2]); 
        printf("-------------\n");
    }
}


int x_filling_form()

/* Retrieves an upper coordinate from input from input*/

{
    int x = 0;

    while(x > 3 || x < 1)
    {
        printf("Enter the upper coordinate you want to put a character in (1/2/3): ");
        scanf("%d", &x);
    }

    return(x);
}


int y_filling_form()

/* Retrieves a side coordinate from input*/

{
    int y = 0;

    while(y > 3 || y < 1)
    {
        printf("Enter the side coordinate you want to put a character in (1/2/3): ");
        scanf("%d", &y);
    }

    return(y);
}

int win_situation(char *all_rows[])
{
    int x = 0;
    int y = 0;

    /* диагонали */
    if(all_rows[y][x] == all_rows[y + 1][x + 1] && all_rows[y + 1][x + 1] == all_rows[y + 2][x + 2] && all_rows[x][y] != ' ' \
        && all_rows[x + 1][y + 1] != ' ' && all_rows[x + 2][y + 2] != ' ')
        {
            return 1;
        }

    x = 0;
    
    /* горизонтали */
    for(y = 0; y < 3; y++)
    {
        if(all_rows[y][x] == all_rows[y][x + 1] && all_rows[y][x + 1] == all_rows[y][x + 2] && all_rows[x][y] != ' ' \
        && all_rows[y][x + 1] != ' ' && all_rows[y][x + 2] != ' ')
            {
            return 1;
            }
    }

    y = 0;

    /* вертикали */

    for(x = 0; x < 3; x++)
    if(all_rows[y][x] == all_rows[y + 1][x] && all_rows[y + 1][x] == all_rows[y + 2][x] && all_rows[y][x] != ' ' \
    && all_rows[y + 1][x] != ' ' && all_rows[y + 2][x] != ' ')
        return 1;
     
    return 0;
}  