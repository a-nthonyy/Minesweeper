#include "game.h"
#include "leaderboard.h"
#include <SFML/Graphics.hpp>

void gameloop(int rows, int columns, Handler& game) {
    int width = ((columns * 32));
    int height = (rows * 32) + 100;
    sf::RenderWindow gamewindow(sf::VideoMode(width, height), "Minesweeper");

    while (gamewindow.isOpen()) {
        sf::Event event;
        while (gamewindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gamewindow.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (!game.leaderpausestatus()) {
                    if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.y / 32 < rows && !game.pausestatus()) {
                        game.tileclicked(event.mouseButton.x / 32, event.mouseButton.y / 32);
                        game.mineclicked(event.mouseButton.x / 32, event.mouseButton.y / 32);
                    }
                    if (event.mouseButton.button == sf::Mouse::Right && event.mouseButton.y / 32 < rows && !game.pausestatus()) {
                        game.tileflagged(event.mouseButton.x / 32, event.mouseButton.y / 32);
                    }
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (game.buttons.happyfaceclicked(event.mouseButton.x, event.mouseButton.y)
                            || game.buttons.losefaceclicked(event.mouseButton.x, event.mouseButton.y)
                            || game.buttons.winfaceclicked(event.mouseButton.x, event.mouseButton.y)) {
                            game.reset();
                        }
                    }
                    if (event.mouseButton.button == sf::Mouse::Left && !game.pausestatus()) {
                        if (game.buttons.debugclicked(event.mouseButton.x, event.mouseButton.y)) {
                            game.setdebug();
                        }
                    }
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (game.buttons.playclicked(event.mouseButton.x, event.mouseButton.y)
                            || game.buttons.pauseclicked(event.mouseButton.x, event.mouseButton.y)) {
                            game.setpause();
                        }
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (game.buttons.leaderboardclicked(event.mouseButton.x, event.mouseButton.y)) {
                        game.setleaderpause();
                        leaderboard(rows, columns, game.gamewinstatus(), game.getplayername(), game);
                    }
                }
            }
        }

        gamewindow.clear(sf::Color::White);
        game.DisplayBoard(gamewindow);
        game.DisplayButtons(gamewindow);
        gamewindow.display();
    }
}
