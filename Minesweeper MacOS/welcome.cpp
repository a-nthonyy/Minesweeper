#include "welcome.h"
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.h"

using namespace std;

void setText(sf::Text &text, float x, float y){
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

void welcomewindow(int rows, int columns, bool& game, string& playername) {
    int width = ((columns*32));
    int height = (rows*32) + 100;

    sf::RenderWindow welcomewindow(sf::VideoMode(width, height), "Minesweeper");
    sf::Font welcomefont;

    if (!welcomefont.loadFromFile("files/font.ttf"))
    {
        // error...
    }

    sf::Text maintext;
    sf::Text nametext;
    sf::Text metext;


    sf::Text playertext;
    string playernameinput;




    maintext.setFont(welcomefont);
    maintext.setString("WELCOME TO MINESWEEPER!");
    maintext.setCharacterSize(24);
    maintext.setFillColor(sf::Color::White);
    maintext.setStyle(sf::Text::Bold | sf::Text::Underlined);

    nametext.setFont(welcomefont);
    nametext.setString("Enter your name:");
    nametext.setCharacterSize(20);
    nametext.setFillColor(sf::Color::White);
    nametext.setStyle(sf::Text::Bold);

    metext.setFont(welcomefont);
    metext.setString("Created by: Anthony Perez\n\n\t   UF COP3503C");
    metext.setCharacterSize(20);
    metext.setFillColor(sf::Color::White);
    metext.setStyle(sf::Text::Bold);

    playertext.setFont(welcomefont);
    playertext.setCharacterSize(18);
    playertext.setFillColor(sf::Color::Yellow);
    playertext.setStyle(sf::Text::Bold);


    setText(maintext, (width/2), ((height/2)-150));
    setText(nametext, (width/2), ((height/2)-75));
    setText(metext, (width/2), ((height/2)+250));


    playertext.setString("|");
    while(welcomewindow.isOpen()) {
        sf::Event event;

        while (welcomewindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                welcomewindow.close();

            if (event.type == sf::Event::TextEntered) {
                char c = static_cast<char>(event.text.unicode);
                if(playernameinput.size() == 0) {
                    c = toupper(c);
                } else {
                    c = tolower(c);
                }

                if(event.text.unicode == 8 && playernameinput.size() != 0) {
                    playernameinput.pop_back();
                }

                if(playernameinput.size() < 10 && isalpha(c)) {
                    playernameinput.push_back(c);
                }

                // unicode is 13 for enter on windows
                // unicode is 10 for enter on macOS
                if(event.text.unicode == 10 && playernameinput.size() >= 1) {
                    welcomewindow.close();
                    game = true;
                }

                playername = playernameinput;
                playertext.setString(playernameinput + "|");

            }
        }


        welcomewindow.clear(sf::Color::Blue);
        welcomewindow.draw(maintext);
        welcomewindow.draw(nametext);
        welcomewindow.draw(metext);
        setText(playertext, (width/2), ((height/2)-45));
        welcomewindow.draw(playertext);
        welcomewindow.display();
    }
}