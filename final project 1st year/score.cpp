#include "score.hpp"
#include "const.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

std::vector<ScoreEntry> loadHighScores(const std::string& filename)
{
    std::ifstream file(filename);
    std::vector<ScoreEntry> scores;
    std::string name;
    int score;
    while(file >> name >> score)
    {
        scores.push_back({name, score});
    }
    return scores;
}

void saveHighScores(const std::vector<ScoreEntry>& scores, const std::string& filename)
{
    std::ofstream file(filename);
    for(const ScoreEntry& entry : scores)
    {

        file << entry.name << " " << entry.score << std::endl;
    }
}

std::string getPlayerName(sf::RenderWindow& window, sf::Font& font)
{
    std::string playerName;
    sf::Text prompt("Enter your name:", font, 32);
    prompt.setFillColor(sf::Color::White);
    prompt.setPosition(WIDTH / 2 - 150, HEIGHT / 2 - 20);

    sf::Text nameText("", font, 32);
    nameText.setFillColor(sf::Color::Magenta);
    nameText.setPosition(WIDTH / 2 - 100, HEIGHT / 2 + 20);

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode == '\b')
                {
                    if (!playerName.empty())
                        playerName.pop_back();
                }
                else if (event.text.unicode == '\r' || event.text.unicode == '\n')
                {
                    if(!playerName.empty())
                        return playerName;
                }
                else if (playerName.size() < 12 && std::isalnum(event.text.unicode))
                {
                    playerName += static_cast<char>(event.text.unicode);
                }
            }
        }

        nameText.setString(playerName);
        window.clear();
        window.draw(prompt);
        window.draw(nameText);
        window.display();
    }
    return playerName;
}

bool showGameOverMenu(sf::RenderWindow& window, const ScoreEntry& playerScore, const std::vector<ScoreEntry>& highScores)
{
    sf::Font font;
    if(!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Failed to load font" << std::endl;
        return false;
    }

    sf::Text title("Game Over!", font, 52);
    title.setFillColor(sf::Color::Red);
    title.setPosition(WIDTH / 2 - 150, 60);

    sf::Text scoreText("Your score: " + playerScore.name + "-" + std::to_string(playerScore.score), font, 32);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(WIDTH / 2 - 150, 130);

    std::vector<sf::Text> highScoreTexts;
    for(int i = 0; i < highScores.size(); i++)
    {
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(28);
        text.setFillColor(sf::Color::Yellow);
        text.setString(std::to_string(i + 1) + "." + highScores[i].name + "-" + std::to_string(highScores[i].score));
        text.setPosition(WIDTH / 2 - 120, 180 + i * 35);
        highScoreTexts.push_back(text);
    }

    sf::Text playAgain("Play Again", font, 30);
    playAgain.setPosition(WIDTH / 2 - 80, 400);

    sf::Text exitGame("Exit", font, 30);
    exitGame.setPosition(WIDTH / 2 - 40, 460);

    int selected = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                return false;
            if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Up)
                    selected = (selected + 1) % 2;
                if(event.key.code == sf::Keyboard::Down)
                    selected = (selected + 1) % 2;
                if(event.key.code == sf::Keyboard::Enter)
                    return selected == 0;
            }
        }

        if (selected == 0)
        {
            playAgain.setFillColor(sf::Color::Green);
        }
        else
        {
            playAgain.setFillColor(sf::Color::White);
        }

        if(selected == 1)
        {
            exitGame.setFillColor(sf::Color::Green);
        }
        else
        {
            exitGame.setFillColor(sf::Color::White);
        }

        window.clear(sf::Color::Black);
        window.draw(title);
        window.draw(scoreText);
        for(auto& hs : highScoreTexts)
            window.draw(hs);
        window.draw(playAgain);
        window.draw(exitGame);
        window.display();
    }

    return false;
}

bool compareScores(const ScoreEntry& a, const ScoreEntry& b)
{
    return a.score > b.score;
}