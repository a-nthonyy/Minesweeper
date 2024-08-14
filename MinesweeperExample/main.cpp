#include "game.h"
#include "welcome.h"
#include "leaderboard.h"

Handler game;

bool gamey = false;

int main()
{
    string playername;
    game.readconfig();
    game.init();

    int rows = game.getrows();
    int columns = game.getcolumns();

    //game.display_terminal();

    welcomewindow(rows, columns, gamey, playername);
    if(gamey == true) {
        game.playernameintaker(playername);
        gameloop(rows, columns, game);
    }

    return 0;
}