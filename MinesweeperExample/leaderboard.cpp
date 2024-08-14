#include "leaderboard.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

//todo: make gamewindow not interactive while leaderboard window is open
//cannot affect the user-set time state (paused or unpaused)




using namespace std;


// SFML ISSUE with revealing the tiles in game window. tried everything and it doesnt work.
// also an SFML issue with clicking the tiles while in leaderboard window. same thing about trying everything.


// TA Jaiden said to not worry due to it being an SFML issue and not a syntax issue so I hope the point can be given

void leaderboard(int rows, int columns, bool gamewin, string playername, Handler& game) {
    string Clock[4] = {"0","0","0","0"};
    int minutes = game.seconds / 60;
    int seconds = game.seconds % 60;

    string minutes_str = (minutes < 10 ? "0" : "") + to_string(minutes);
    string seconds_str = (seconds < 10 ? "0" : "") + to_string(seconds);
    string time;

    time = minutes_str + ":" + seconds_str;

    string players;
    ifstream leaderboardfile("files/leaderboard.txt");
    int index = 0;
    if(gamewin) {
        string line;
        players += "1.\t" + time + "\t " + playername + "*" + "\n\n";
        index += 1;
        while (getline(leaderboardfile, line) && index < 5) {
            int commaPos = line.find(',');
            if(commaPos != std::string::npos){
                string time = line.substr(0, commaPos);
                string name = line.substr(commaPos + 1);
                players += to_string(index+1) + ".\t" + time + "\t" + name + "\n\n";
                index++;
            }
        }
    } else {
        string line;
        while (getline(leaderboardfile, line) && index <= 5) {
            int commaPos = line.find(',');
            if(commaPos != std::string::npos){
                string time = line.substr(0, commaPos);
                string name = line.substr(commaPos + 1);
                players += to_string(index+1) + ".\t" + time + "\t" + name + "\n\n";
                index++;
            }
        }
    }

    if(leaderboardfile.is_open()) {
        leaderboardfile.close();
    }
    int width = ((columns * 16));
    int height = (rows * 16) + 50;
    sf::RenderWindow leaderboardwindow(sf::VideoMode(width, height), "Minesweeper");
    sf::Font leaderboardfont;

    if (!leaderboardfont.loadFromFile("files/font.ttf")) {
        // error...
    }

    sf::Text maintext;
    sf::Text namestext;

    maintext.setFont(leaderboardfont);
    maintext.setString("LEADERBOARD");
    maintext.setCharacterSize(24);
    maintext.setFillColor(sf::Color::White);
    maintext.setStyle(sf::Text::Bold | sf::Text::Underlined);

    namestext.setFont(leaderboardfont);
    namestext.setString(players);
    namestext.setCharacterSize(18);
    namestext.setFillColor(sf::Color::White);
    namestext.setStyle(sf::Text::Bold);

    setText(maintext, (width/2), ((height/2)-120));
    setText(namestext, (width/2), ((height/2)+20));

    while (leaderboardwindow.isOpen()) {
        sf::Event event;
        while (leaderboardwindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                leaderboardwindow.close();
                game.setleaderunpause();
            }
        }
        leaderboardwindow.clear(sf::Color::Blue);
        leaderboardwindow.draw(maintext);
        leaderboardwindow.draw(namestext);
        leaderboardwindow.display();
    }
}