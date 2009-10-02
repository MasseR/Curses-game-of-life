#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <locale.h>
#include <time.h>
#include "macros.h"


static int *cells = NULL;
static int *buffer = NULL;
static int lifecols = 0;
static int lifelines = 0;
static int ticksize = 1;

static WINDOW *info = NULL;
static WINDOW *life = NULL;

static struct timespec sleeptime = {0};

void print();
void status();
void init();
void initcurses();
void finish();
void tick();
void activate(int y, int x);
WINDOW *createwin(int height, int width, int begy, int begx);
bool kbd(int ch);
int neighbours(int y, int x);

int main()
{
    int ch;
    init();

    do
    { /* Keyboard loop */
        ch = getch();
    }
    while(kbd(ch));

    finish();

    return 0;
}

bool kbd(int ch)
{
    int x,y;
    getyx(life, y, x);
    switch(ch)
    {
        case 'q':
            return false;
            break;
        case 'l':
            x=(x+1)%CMAX;
            break;
        case 'h':
            x=(x-1)%CMAX;
            break;
        case 'j':
            y=(y+1)%LMAX;
            break;
        case 'k':
            y=(y-1)%LMAX;
            break;
        case ' ':
            activate(y, x);
            break;
        case 10: /* Enter */
            tick();
            break;
        case KEY_UP:
            ticksize++;
            status();
            break;
        case KEY_DOWN:
            ticksize--;
            status();
            break;
    }
    wmove(life, y, x);
    wrefresh(life);
    return true;
}

void tick()
{
    struct timespec *remaining;
    int t, x, y, n;
    COPYC;
    for(t = 0; t < ticksize; t++)
    {
        for(x = 0; x < lifecols; x++)
        {
            for(y = 0; y < lifelines; y++)
            {
                n = neighbours(y, x);
                if(n < 2 || n > 3)
                {
                    ABCPR(y,x);
                    mvwaddch(life, y, x, ' ');
                }
                if(n == 3)
                {
                    BCPR(y, x);
                    mvwaddch(life, y, x, 'X');
                }
            }
        }
        COPYB;
        nanosleep(&sleeptime, remaining);
        wrefresh(life);
    }
}

int neighbours(int y, int x)
{
    int n = 0;
    if(y < LMAX)
    {
        n += ALIVE(y+1,x);
    }
    if(y > 0)
    {
        n += ALIVE(y-1,x);
    }
    if(x < CMAX)
    {
        n += ALIVE(y, x+1);
        if(y > 0)
        {
            n += ALIVE(y-1, x+1);
        }
        if(y < LMAX)
        {
            n += ALIVE(y+1, x+1);
        }
    }
    if(x > 0)
    {
        n += ALIVE(y, x-1);
        if(y > 0)
        {
            n += ALIVE(y-1, x-1);
        }
        if(y < LMAX)
        {
            n += ALIVE(y+1, x-1);
        }
    }

    return n;
}

void finish()
{
    free(cells);
    free(buffer);
    delwin(info);
    delwin(life);
    endwin();
}

WINDOW *createwin(int height, int width, int begy, int begx)
{
    WINDOW *local_win = NULL;

    local_win = newwin(height, width, begy, begx);
    if(local_win == NULL)
        exit(EXIT_FAILURE);

    wmove(local_win, 1, 1); /* Looks better if the cursor is not on
                               top of lines */

    wrefresh(local_win);

    return local_win;
}

void initcurses()
{
    /* Initialize curses */
    initscr();
    noecho();
    raw();
    keypad(stdscr, true);
    refresh();

    lifecols = COLS-ICOLS-1; /* Leave one column empty */
    lifelines = LINES; /* Full height */

    life = createwin(lifelines, lifecols, 0, 0);
    info = createwin(ILINES, ICOLS, 0, lifecols+1);
    box(info, 0, 0);
    mvwprintw(info, 1,1, "INFO");
    wmove(life, 1,1);
    wrefresh(info);
    wrefresh(life);
}

void init()
{
    sleeptime.tv_nsec = SLEEP;
    initcurses();
    /* Locale */
    setlocale(LC_ALL, "");
    /* Initialize arrays */
    cells = malloc(SIZE);
    if(cells == NULL)
        exit(1);
    memset(cells, 0, SIZE);

    buffer = malloc(SIZE);
    if(buffer == NULL)
        exit(1);
    memset(buffer, 0, SIZE);

    status();
}

void print()
{
    int x, y;
    printf("\n");
    for(x = 0; x < COLS+2; x++)
        printf("-");
    printf("\n");
    for(y = 0; y < LINES; y++)
    {
        printf("|");
        for(x = 0; x < COLS; x++)
            printf("%d", CELL(y, x));
        printf("|\n");
    }
    for(x = 0; x < COLS+2; x++)
        printf("-");
    printf("\n");
}

void status()
{
    int y,x;
    mvwprintw(info, 2, 1, "Total sizes");
    mvwprintw(info, 3, 1, " Columns: %d", COLS);
    mvwprintw(info, 4, 1, " Lines: %d", LINES);
    mvwprintw(info, 5, 1, "Life sizes");
    mvwprintw(info, 6, 1, " Columns: %d", lifecols);
    mvwprintw(info, 7, 1, " Lines: %d", lifelines);
    mvwprintw(info, 8, 1, "Array size: %d", ASIZE);
    mvwprintw(info, 9, 1, "Tick size: %d", ticksize);
    getyx(life, y, x);
    wmove(life, y, x);
    wrefresh(info);
    wrefresh(life);
}

void activate(int y, int x)
{
    CPR(y,x);
    mvwaddch(life, y, x, 'X');
}
