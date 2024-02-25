#pragma once

class winTXT
{
private: 
    int dimX, dimY;
    char* win;

public:
    winTXT (int dx, int dy);
    void clear (char c=' ');
    void print (int x, int y, char c);
    void print (int x, int y, char* c);
    void draw (int x=0, int y=0);
//    void pause();
    char getCh();

}; 

void terminalClear (); //clear le terminal