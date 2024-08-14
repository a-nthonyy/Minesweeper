#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <chrono>

using namespace std;


class Tile {
    // revealed and flagged inherently false
    bool revealed = false;
    bool flagged = false;
    bool bomb = false;

    int x = 0;
    int y = 0;
    sf::Sprite tile_hidden;
    sf::Sprite tile_revealed;
    sf::Sprite tile_mine;
    sf::Sprite flag;
    sf::Sprite number_1;
    sf::Sprite number_2;
    sf::Sprite number_3;
    sf::Sprite number_4;
    sf::Sprite number_5;
    sf::Sprite number_6;
    sf::Sprite number_7;
    sf::Sprite number_8;

public:
    vector<Tile *> adjacent_tiles;
    int nearbybombs = 0;

    Tile() {
    }

    Tile(bool revealed, bool flagged, bool bomb) {
        this->revealed = revealed;
        this->flagged = flagged;
        this->bomb = bomb;
    }

    Tile(int x, int y, sf::Texture &tile_hidden, sf::Texture &tile_revealed, sf::Texture &mine_texture,
         sf::Texture &flag, sf::Texture &number_1, sf::Texture &number_2, sf::Texture &number_3, sf::Texture &number_4,
         sf::Texture &number_5, sf::Texture &number_6, sf::Texture &number_7, sf::Texture &number_8) {
        this->x = x;
        this->y = y;

        this->tile_hidden.setTexture(tile_hidden);
        this->tile_hidden.setPosition(x * 32, y * 32);

        this->tile_revealed.setTexture(tile_revealed);
        this->tile_revealed.setPosition(x * 32, y * 32);

        this->tile_mine.setTexture(mine_texture);
        this->tile_mine.setPosition(x * 32, y * 32);

        this->flag.setTexture(flag);
        this->flag.setPosition(x * 32, y * 32);

        this->number_1.setTexture(number_1);
        this->number_1.setPosition(x * 32, y * 32);

        this->number_2.setTexture(number_2);
        this->number_2.setPosition(x * 32, y * 32);

        this->number_3.setTexture(number_3);
        this->number_3.setPosition(x * 32, y * 32);

        this->number_4.setTexture(number_4);
        this->number_4.setPosition(x * 32, y * 32);

        this->number_5.setTexture(number_5);
        this->number_5.setPosition(x * 32, y * 32);

        this->number_6.setTexture(number_6);
        this->number_6.setPosition(x * 32, y * 32);

        this->number_7.setTexture(number_7);
        this->number_7.setPosition(x * 32, y * 32);

        this->number_8.setTexture(number_8);
        this->number_8.setPosition(x * 32, y * 32);

    }

    void DrawBoardSprites(sf::RenderWindow &window, bool gameover, bool gamewin, bool debugger, bool paused, bool leaderpaused) {
        if(paused && !gamewin && !gameover || leaderpaused){
            window.draw(tile_revealed);
        } else {
            if (!revealed) {
                window.draw(tile_hidden);
            } else {
                window.draw(tile_revealed);
            }



            if (revealed && nearbybombs == 1 && !bomb) {
                window.draw(number_1);
            }
            if (revealed && nearbybombs == 2 && !bomb) {
                window.draw(number_2);
            }
            if (revealed && nearbybombs == 3 && !bomb) {
                window.draw(number_3);
            }
            if (revealed && nearbybombs == 4 && !bomb) {
                window.draw(number_4);
            }
            if (revealed && nearbybombs == 5 && !bomb) {
                window.draw(number_5);
            }
            if (revealed && nearbybombs == 6 && !bomb) {
                window.draw(number_6);
            }
            if (revealed && nearbybombs == 7 && !bomb) {
                window.draw(number_7);
            }
            if (revealed && nearbybombs == 8 && !bomb) {
                window.draw(number_8);
            }

            if (gamewin && bomb) {
                window.draw(flag);
            }

            if (!gameover && !gamewin) {
                if (!flagged && !revealed) {
                    window.draw(tile_hidden);
                } else if (flagged && !revealed) {
                    window.draw(flag);
                }
            }
            if (bomb && revealed || gameover && bomb || debugger && bomb && !gameover && !gamewin) {
                window.draw(tile_mine);
            }
        }

    }

    bool &revealstatus() {
        return revealed;
    }

    bool &bombstatus() {
        return bomb;
    }

    bool &flaggedstatus() {
        return flagged;
    }

};


class Mine {
    int x = 0;
    int y = 0;
    bool clicked = false;
    sf::Sprite mine;

public:
    int nearbytiles = 1;

    Mine() {
    }

    Mine(int x, int y, sf::Texture &mine) {
        this->x = x;
        this->y = y;

        this->mine.setTexture(mine);
        this->mine.setPosition(x * 32, y * 32);
    }
};


class Buttons {
    // for all the bottom buttons
    sf::Sprite face_happy;
    sf::Sprite face_lose;
    sf::Sprite face_win;
    sf::Sprite debug;
    sf::Sprite play;
    sf::Sprite pause;
    sf::Sprite leaderboard;
    sf::Sprite hundreds;
    sf::Sprite tens;
    sf::Sprite ones;
    sf::Sprite negativesign;
    sf::Sprite seconds;
    sf::Sprite tens_seconds;
    sf::Sprite minutes;
    sf::Sprite tens_minutes;


public:
    void setfacebuttons(sf::Texture &face_happy, sf::Texture &face_lose, sf::Texture &face_win, int columns, int rows) {
        int x = ((columns / 2) * 32) - 32;
        int y = (32 * (rows + 0.5));
        this->face_happy.setTexture(face_happy);
        this->face_lose.setTexture(face_lose);
        this->face_win.setTexture(face_win);

        this->face_happy.setPosition(x, y);
        this->face_lose.setPosition(x, y);
        this->face_win.setPosition(x, y);
    }

    void setdebugbutton(sf::Texture &debug, int columns, int rows) {
        int x = ((columns * 32) - 304);
        int y = (32 * (rows + 0.5));
        this->debug.setTexture(debug);
        this->debug.setPosition(x, y);
    }

    void setplaypausebuttons(sf::Texture &play, sf::Texture &pause, int columns, int rows) {
        int x = ((columns * 32) - 240);
        int y = (32 * (rows + 0.5));

        this->play.setTexture(play);
        this->pause.setTexture(pause);

        this->play.setPosition(x, y);
        this->pause.setPosition(x, y);
    }

    void setleaderboardbutton(sf::Texture &leaderboard, int columns, int rows) {
        int x = ((columns * 32) - 176);
        int y = (32 * (rows + 0.5));
        this->leaderboard.setTexture(leaderboard);
        this->leaderboard.setPosition(x, y);
    }

    void setcounter(sf::Texture* digits[], int hundreds, int tens, int ones, int rows) {
        int negative_x = 12;
        int hundreds_x = 33;
        int tens_x = 54;
        int ones_x = 75;

        int y = (32 * (rows + 0.5) + 16);

        this->negativesign.setTexture(*digits[10]);
        this->negativesign.setPosition(negative_x, y);

        if (hundreds == 0) {
            this->hundreds.setTexture(*digits[0]);
            this->hundreds.setPosition(hundreds_x, y);
        } else if (hundreds == 1) {
            this->hundreds.setTexture(*digits[1]);
            this->hundreds.setPosition(hundreds_x, y);
        } else if (hundreds == 2) {
            this->hundreds.setTexture(*digits[2]);
            this->hundreds.setPosition(hundreds_x, y);
        } else if (hundreds == 3) {
            this->hundreds.setTexture(*digits[3]);
            this->hundreds.setPosition(hundreds_x, y);
        } else if (hundreds == 4) {
            this->hundreds.setTexture(*digits[4]);
            this->hundreds.setPosition(hundreds_x, y);
        } else if (hundreds == 5) {
            this->hundreds.setTexture(*digits[5]);
            this->hundreds.setPosition(hundreds_x, y);
        } else if (hundreds == 6) {
            this->hundreds.setTexture(*digits[6]);
            this->hundreds.setPosition(hundreds_x, y);
        } else if (hundreds == 7) {
            this->hundreds.setTexture(*digits[7]);
            this->hundreds.setPosition(hundreds_x, y);
        } else if (hundreds == 8) {
            this->hundreds.setTexture(*digits[8]);
            this->hundreds.setPosition(hundreds_x, y);
        } else if (hundreds == 9) {
            this->hundreds.setTexture(*digits[9]);
            this->hundreds.setPosition(hundreds_x, y);
        }

        if (tens == 0) {
            this->tens.setTexture(*digits[0]);
            this->tens.setPosition(tens_x, y);
        } else if (tens == 1) {
            this->tens.setTexture(*digits[1]);
            this->tens.setPosition(tens_x, y);
        } else if (tens == 2) {
            this->tens.setTexture(*digits[2]);
            this->tens.setPosition(tens_x, y);
        } else if (tens == 3) {
            this->tens.setTexture(*digits[3]);
            this->tens.setPosition(tens_x, y);
        } else if (tens == 4) {
            this->tens.setTexture(*digits[4]);
            this->tens.setPosition(tens_x, y);
        } else if (tens == 5) {
            this->tens.setTexture(*digits[5]);
            this->tens.setPosition(tens_x, y);
        } else if (tens == 6) {
            this->tens.setTexture(*digits[6]);
            this->tens.setPosition(tens_x, y);
        } else if (tens == 7) {
            this->tens.setTexture(*digits[7]);
            this->tens.setPosition(tens_x, y);
        } else if (tens == 8) {
            this->tens.setTexture(*digits[8]);
            this->tens.setPosition(tens_x, y);
        } else if (tens == 9) {
            this->tens.setTexture(*digits[9]);
            this->tens.setPosition(tens_x, y);
        }

        if (ones == 0) {
            this->ones.setTexture(*digits[0]);
            this->ones.setPosition(ones_x, y);
        } else if (ones == 1) {
            this->ones.setTexture(*digits[1]);
            this->ones.setPosition(ones_x, y);
        } else if (ones == 2) {
            this->ones.setTexture(*digits[2]);
            this->ones.setPosition(ones_x, y);
        } else if (ones == 3) {
            this->ones.setTexture(*digits[3]);
            this->ones.setPosition(ones_x, y);
        } else if (ones == 4) {
            this->ones.setTexture(*digits[4]);
            this->ones.setPosition(ones_x, y);
        } else if (ones == 5) {
            this->ones.setTexture(*digits[5]);
            this->ones.setPosition(ones_x, y);
        } else if (ones == 6) {
            this->ones.setTexture(*digits[6]);
            this->ones.setPosition(ones_x, y);
        } else if (ones == 7) {
            this->ones.setTexture(*digits[7]);
            this->ones.setPosition(ones_x, y);
        } else if (ones == 8) {
            this->ones.setTexture(*digits[8]);
            this->ones.setPosition(ones_x, y);
        } else if (ones == 9) {
            this->ones.setTexture(*digits[9]);
            this->ones.setPosition(ones_x, y);
        }


    }

    void settimer(sf::Texture* digits[], int elapsed_seconds, int rows, int columns){
        int minutes = elapsed_seconds / 60;
        int seconds = elapsed_seconds % 60;

        string minutes_str = (minutes < 10 ? "0" : "") + to_string(minutes);
        string seconds_str = (seconds < 10 ? "0" : "") + to_string(seconds);

        int tens_min_x = ((columns * 32) - 97);
        int min_x = ((columns * 32) - 76);
        int tens_sec_x = ((columns * 32) - 54);
        int sec_x = ((columns * 32) - 33);
        int y = (32 * (rows + 0.5) + 16);

        this->tens_minutes.setTexture(*digits[minutes_str[0] - '0']);
        this->tens_minutes.setPosition(tens_min_x, y);

        this->minutes.setTexture(*digits[minutes_str[1] - '0']);
        this->minutes.setPosition(min_x, y);

        this->tens_seconds.setTexture(*digits[seconds_str[0] - '0']);
        this->tens_seconds.setPosition(tens_sec_x, y);

        this->seconds.setTexture(*digits[seconds_str[1] - '0']);
        this->seconds.setPosition(sec_x, y);
    }

    void DisplayTimer(sf::RenderWindow &window){
        window.draw(seconds);
        window.draw(tens_seconds);
        window.draw(minutes);
        window.draw(tens_minutes);
    }

    void DisplayCounter(sf::RenderWindow &window, bool negative){
        window.draw(hundreds);
        window.draw(tens);
        window.draw(ones);
        if(negative){
            window.draw(negativesign);
        }
    }

    void DisplayFaceButtons(sf::RenderWindow &window, bool gameover, bool gamewin) {
        if (!gameover && !gamewin) {
            window.draw(face_happy);
        } else if (gameover) {
            window.draw(face_lose);
        } else if (gamewin) {
            window.draw(face_win);
        }
    }

    void DisplayDebugButton(sf::RenderWindow &window) {
        window.draw(debug);
    }

    void DisplayPlayPauseButtons(sf::RenderWindow &window, bool paused) {
        if (!paused) {
            window.draw(play);
        } else if (paused) {
            window.draw(pause);
        }
    }

    void DisplayLeaderboardButton(sf::RenderWindow &window) {
        window.draw(leaderboard);
    }

    bool happyfaceclicked(int x, int y) {
        sf::FloatRect bounds;
        bounds = face_happy.getGlobalBounds();
        return bounds.contains(x, y);
    }

    bool losefaceclicked(int x, int y) {
        sf::FloatRect bounds;
        bounds = face_lose.getGlobalBounds();
        return bounds.contains(x, y);
    }

    bool winfaceclicked(int x, int y) {
        sf::FloatRect bounds;
        bounds = face_win.getGlobalBounds();
        return bounds.contains(x, y);
    }

    bool debugclicked(int x, int y) {
        sf::FloatRect bounds;
        bounds = debug.getGlobalBounds();
        return bounds.contains(x, y);
    }

    bool playclicked(int x, int y) {
        sf::FloatRect bounds;
        bounds = play.getGlobalBounds();
        return bounds.contains(x, y);
    }

    bool pauseclicked(int x, int y) {
        sf::FloatRect bounds;
        bounds = pause.getGlobalBounds();
        return bounds.contains(x, y);
    }

    bool leaderboardclicked(int x, int y) {
        sf::FloatRect bounds;
        bounds = leaderboard.getGlobalBounds();
        return bounds.contains(x, y);
    }
};


class Handler {
    string playernameinput;
    vector<vector<Mine> > mines_vector;
    vector<vector<Tile> > tiles_vector;
    int rows = 0;
    int columns = 0;
    int bomb_amt = 0;
    int flagsPlaced = 0;

    bool gameover = false;
    bool gamewin = false;
    bool debugger = false;
    bool paused = false;
    bool leaderpaused = false;
    bool negative = false;
    bool leaderboardOpen = false;


    sf::Texture tile_hidden;
    sf::Texture tile_revealed;
    sf::Texture mine;
    sf::Texture face_happy;
    sf::Texture face_lose;
    sf::Texture face_win;
    sf::Texture debug;
    sf::Texture play;
    sf::Texture pause;
    sf::Texture leaderboard;
    sf::Texture flag;
    sf::Texture number_1;
    sf::Texture number_2;
    sf::Texture number_3;
    sf::Texture number_4;
    sf::Texture number_5;
    sf::Texture number_6;
    sf::Texture number_7;
    sf::Texture number_8;
    sf::Texture digits_0;
    sf::Texture digits_1;
    sf::Texture digits_2;
    sf::Texture digits_3;
    sf::Texture digits_4;
    sf::Texture digits_5;
    sf::Texture digits_6;
    sf::Texture digits_7;
    sf::Texture digits_8;
    sf::Texture digits_9;
    sf::Texture digits_negative;
public:
    Tile *north = nullptr;
    Tile *south = nullptr;
    Tile *west = nullptr;
    Tile *east = nullptr;
    Tile *northwest = nullptr;
    Tile *northeast = nullptr;
    Tile *southwest = nullptr;
    Tile *southeast = nullptr;
    Buttons buttons;
    sf::Texture* Digits[11];
    sf::Clock Clock;
    int save_time = 0;
    int seconds = 0;

    Handler() {
        tile_hidden.loadFromFile("files/images/tile_hidden.png");
        tile_revealed.loadFromFile("files/images/tile_revealed.png");
        mine.loadFromFile("files/images/mine.png");
        face_happy.loadFromFile("files/images/face_happy.png");
        face_lose.loadFromFile("files/images/face_lose.png");
        face_win.loadFromFile("files/images/face_win.png");
        debug.loadFromFile("files/images/debug.png");
        play.loadFromFile("files/images/play.png");
        pause.loadFromFile("files/images/pause.png");
        leaderboard.loadFromFile("files/images/leaderboard.png");
        flag.loadFromFile("files/images/flag.png");
        number_1.loadFromFile("files/images/number_1.png");
        number_2.loadFromFile("files/images/number_2.png");
        number_3.loadFromFile("files/images/number_3.png");
        number_4.loadFromFile("files/images/number_4.png");
        number_5.loadFromFile("files/images/number_5.png");
        number_6.loadFromFile("files/images/number_6.png");
        number_7.loadFromFile("files/images/number_7.png");
        number_8.loadFromFile("files/images/number_8.png");
        for(int i = 0; i < 11; i++)
        {
            sf::Texture* temp = new sf::Texture;
            temp->loadFromFile("files/images/digits.png", sf::IntRect(21*i,0,21,32));
            Digits[i] = temp;
        }
    }

    void init() {
        north = nullptr;
        south = nullptr;
        west = nullptr;
        east = nullptr;
        northwest = nullptr;
        northeast = nullptr;
        southwest = nullptr;
        southeast = nullptr;
        seconds = 0;
        save_time = 0;
        Clock.restart();
        leaderboardOpen = false;
        leaderpaused = false;
        paused = false;
        gameover = false;
        gamewin = false;
        debugger = false;
        flagsPlaced = 0;

        for (int i = 0; i < rows; i++) {
            vector<Tile> row;
            for (int j = 0; j < columns; j++) {
                Tile tile(j, i, tile_hidden, tile_revealed, mine, flag, number_1, number_2, number_3, number_4, number_5, number_6, number_7, number_8);
                row.push_back(tile);
            }
            tiles_vector.push_back(row);
        }
        int minesPlaced = 0;
        while (minesPlaced < bomb_amt) {
            int miney = 0;
            int minex = 0;
            minex = (rand() % (columns));
            miney = (rand() % (rows));

            if (!tiles_vector[miney][minex].bombstatus()) {
                tiles_vector[miney][minex].bombstatus() = true;
                minesPlaced++;
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                int row_before = i - 1;
                int row_after = i + 1;
                int column_before = j - 1;
                int column_after = j + 1;

                if (row_before >= 0) {
                    // tile points up
                    north = &tiles_vector[row_before][j];
                    tiles_vector[i][j].adjacent_tiles.push_back(north);
                }
                if (row_after < rows) {
                    // tile points down
                    south = &tiles_vector[row_after][j];
                    tiles_vector[i][j].adjacent_tiles.push_back(south);
                }
                if (column_before >= 0) {
                    // tile points left
                    west = &tiles_vector[i][column_before];
                    tiles_vector[i][j].adjacent_tiles.push_back(west);
                }
                if (column_after < columns) {
                    // tile points right
                    east = &tiles_vector[i][column_after];
                    tiles_vector[i][j].adjacent_tiles.push_back(east);
                }
                if (row_before >= 0 && column_before >= 0) {
                    // tile points northwest
                    northwest = &tiles_vector[row_before][column_before];
                    tiles_vector[i][j].adjacent_tiles.push_back(northwest);
                }
                if (column_before >= 0 && row_after < rows) {
                    // tile points southwest
                    southwest = &tiles_vector[row_after][column_before];
                    tiles_vector[i][j].adjacent_tiles.push_back(southwest);
                }
                if (column_after < columns && row_after < rows) {
                    // tile points southeast
                    southeast = &tiles_vector[row_after][column_after];
                    tiles_vector[i][j].adjacent_tiles.push_back(southeast);
                }
                if (column_after < columns && row_before >= 0) {
                    // tile points northeast
                    northeast = &tiles_vector[row_before][column_after];
                    tiles_vector[i][j].adjacent_tiles.push_back(northeast);
                }
                for(int k = 0; k < tiles_vector[i][j].adjacent_tiles.size(); k++) {
                    if(tiles_vector[i][j].adjacent_tiles[k] != nullptr && tiles_vector[i][j].adjacent_tiles[k]->bombstatus() == true) {
                        tiles_vector[i][j].nearbybombs++;
                    }
                }
            }
        }

    }
    void DisplayBoard(sf::RenderWindow &window) {
        int amount_revealed = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if(tiles_vector[i][j].revealstatus() == true){
                    amount_revealed++;
                }
            }
        }
        if(amount_revealed == (rows*columns) - bomb_amt){
            gameover = false;
            gamewin = true;
            paused = true;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                tiles_vector[i][j].DrawBoardSprites(window, gameover, gamewin, debugger, paused, leaderpaused);
            }
        }
        if(flagsPlaced > bomb_amt){
            negative = true;
        } else {
            negative = false;
        }

        buttons.setfacebuttons(face_happy, face_lose, face_win, columns, rows);
        buttons.setdebugbutton(debug, columns, rows);
        buttons.setplaypausebuttons(play, pause, columns, rows);
        buttons.setleaderboardbutton(leaderboard, columns, rows);
        buttons.setcounter(Digits, abs(bomb_amt - flagsPlaced) / 100,(abs(bomb_amt - flagsPlaced) / 10)
                                                                     % 10, (abs(bomb_amt - flagsPlaced)) % 10, rows);
        if(!paused){
            seconds = (Clock.getElapsedTime().asSeconds() + save_time);
        }
        buttons.settimer(Digits, seconds, rows, columns);
        //cout << int(seconds) << endl;
    }

    void DisplayButtons(sf::RenderWindow &window) {
        buttons.DisplayTimer(window);
        buttons.DisplayFaceButtons(window, gameover, gamewin);
        buttons.DisplayDebugButton(window);
        buttons.DisplayPlayPauseButtons(window, paused);
        buttons.DisplayLeaderboardButton(window);
        buttons.DisplayCounter(window, negative);
    }

    void reset() {
        tiles_vector.clear();
        mines_vector.clear();
        init();
    }

    void readconfig() {
        int index = 0;
        string line;
        ifstream config("files/config.cfg");
        while (getline(config, line)) {
            if (index == 0) {
                columns = stoi(line);
            } else if (index == 1) {
                rows = stoi(line);
            } else if (index == 2) {
                bomb_amt = stoi(line);
            }
            index++;
        }
    }

    void recursiveflood(Tile *tile) {
        if (tile == nullptr || tile->bombstatus() || tile->flaggedstatus() || tile->revealstatus()) {
            return;
        }

        if(tile->nearbybombs > 0) {
            tile->revealstatus() = true;
            return;
        }
        tile->revealstatus() = true;
        for (Tile* adjacent : tile->adjacent_tiles) {
            recursiveflood(adjacent);
        }
    }

    void tileclicked(int x, int y) {
        if (!gameover && !gamewin && tiles_vector[y][x].flaggedstatus() == false) {
            tiles_vector[y][x].revealstatus() = true;
            if (tiles_vector[y][x].nearbybombs == 0 && tiles_vector[y][x].bombstatus() == false) {
                for(int i = 0; i < tiles_vector[y][x].adjacent_tiles.size(); i++) {
                    recursiveflood(tiles_vector[y][x].adjacent_tiles[i]);
                }
            }
        }
    }

    bool mineclicked(int x, int y) {
        if (tiles_vector[y][x].bombstatus() == true && tiles_vector[y][x].flaggedstatus() == false) {
            setgameover();
        }
    }


    void tileflagged(int x, int y) {
        if (tiles_vector[y][x].flaggedstatus() == true) {
            tiles_vector[y][x].flaggedstatus() = false;
            flagsPlaced --;
        } else if (tiles_vector[y][x].flaggedstatus() == false) {
            tiles_vector[y][x].flaggedstatus() = true;
            flagsPlaced ++;
        }
    }

    int getrows() {
        return rows;
    }

    int getcolumns() {
        return columns;
    }

    int getbomb_amt() {
        return bomb_amt;
    }

    void setgameover() {
        gameover = true;
        paused = true;
    }

    bool gameoverstatus() {
        return gameover;
    }

    bool gamewinstatus() {
        return gamewin;
    }

    void setdebug() {
        if (!debugger) {
            debugger = true;
        } else if (debugger == true) {
            debugger = false;
        }
    }

    void setpause() {
        if (!gameover && !gamewin) {
            if (!paused) {
                paused = true;
                save_time = seconds;
            } else if (paused == true) {
                paused = false;
                Clock.restart();
                seconds = save_time;
            }
        }
    }

    void setleaderpause() {
        if (!gameover && !gamewin) {
            if (!leaderpaused) {
                leaderpaused = true;
            }
        }
    }

    void setleaderunpause(){
        if (!gameover && !gamewin) {
            if (leaderpaused) {
                leaderpaused = false;
            }
        }
    }

    bool pausestatus(){
        return paused;
    }

    bool leaderpausestatus(){
        return leaderpaused;
    }


    void playernameintaker(string playernameinput) {
        this->playernameinput = playernameinput;
    }

    string getplayername() {
        return playernameinput;
    }
};

void gameloop(int rows, int columns, Handler &game);