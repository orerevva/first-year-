#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

struct ScoreEntry
{
    std::string name;
    int score;
};

std::vector<ScoreEntry> loadHighScores(const std::string& filename);
void saveHighScores(const std::vector<ScoreEntry>& scores, const std::string& filename);
std::string getPlayerName(sf::RenderWindow& window, sf::Font& font);
bool showGameOverMenu(sf::RenderWindow& window, const ScoreEntry& playerScore, const std::vector<ScoreEntry>& highScores);
bool compareScores(const ScoreEntry& a, const ScoreEntry& b);
