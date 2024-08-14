#pragma once
#include "game.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <string>

void leaderboard(int rows, int columns, bool gamewin, string playername, Handler& game);
void setText(sf::Text &text, float x, float y);
