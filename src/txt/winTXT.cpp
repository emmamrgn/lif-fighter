#include "winTXT.h"
#include <cassert>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <stdio.h>

#if _WIN32
#include <windef.h>
#include <winbase.h>
#include <wincon.h>
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <unistd.h>
#endif

void terminalInit()
{
    {
#ifdef _WIN32
        HANDLE console = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(console, &mode);
        SetConsoleMode(console, mode & ~ENABLE_LINE_INPUT & ~ENABLE_ECHO_INPUT);
#else
        struct termios ttystate;
        bool state = true;

        // get the terminal state
        tcgetattr(STDIN_FILENO, &ttystate);

        if (state)
        {
            // turn off canonical mode
            ttystate.c_lflag &= ~ICANON;
            // minimum of number input read.
            ttystate.c_cc[VMIN] = 1;
        }
        else
        {
            // turn on canonical mode
            ttystate.c_lflag |= ICANON;
        }
        // set the terminal attributes.
        tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);

        struct termios t;
        tcgetattr(STDIN_FILENO, &t);
        t.c_lflag |= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &t);
#endif
    }
}

void terminalMove(int x, int y) // deplace le curseur du terminal
{
#ifdef _WIN32
    // Deplace le curseur en haut a gauche du terminal
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD origine = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(console, origine);
#else
    char t[16];
    sprintf(t, "\033[%d;%dH", y, x);
    printf("%s", t);
#endif
}

void terminalClear() // efface le terminal
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

winTXT::winTXT(int dx, int dy)
{
    dimX = dx;
    dimY = dy;
    win = new char[dimX * dimY];
    clear();
    terminalInit();
}

void winTXT::clear(char c) 
{
    for (int i = 0; i<dimX; ++i)
    {
        for (int j=0; j<dimY; ++j)
        {
            print(i,j,c);
        }
    }
}

void winTXT::print(int x, int y, char c) 
{
    if (x<0) return;
    if (y<0) return;
    if (x>=dimX) return;
    if (y>=dimY) return;
    win[y*dimX+x] = c;
}

void winTXT::print (int x, int y, char* c) 
{
    int i=0;
    while (c[i]!='\0') {print(x+i,y,c[i]);++i;}
}

void winTXT::draw (int x, int y) 
{
    terminalMove(0,0);
    for(int j=0;j<dimY;++j) {
        for(int i=0;i<dimX;++i)
            printf("%c",win[j*dimX+i]);
        printf("\n");
    }
    terminalMove(0,dimY);
}


#if not defined _WIN32
int kbhit() {
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}
#endif

char winTXT::getCh() { // lire un caractere si une touche a ete pressee
    char touche=0;
#ifdef _WIN32
    if (kbhit())
    {
        DWORD mode;
        DWORD n;
        HANDLE consoleI = GetStdHandle(STD_INPUT_HANDLE);
        GetConsoleMode(consoleI, &mode);
        SetConsoleMode(consoleI, mode & ~ENABLE_LINE_INPUT & ~ENABLE_ECHO_INPUT);
        ReadConsole(consoleI, &touche, 1, &n, NULL);
    }
#else
    if (kbhit())
        touche = fgetc(stdin);
#endif
    return touche;
}
