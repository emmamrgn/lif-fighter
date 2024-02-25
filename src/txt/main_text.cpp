#include "winTXT.h"
#include "txtSF.h"

#include "../core/Game.h"

int main(int argc, char** argv)
{
    terminalClear();
    Game game;
    boucleTXT(game);
    terminalClear();

    return 0;
}