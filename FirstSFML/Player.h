#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Sprite sprite;
	int hight;
	int width;
	float moveSpeed = 0.1;

public:
	Player(sf::Sprite& loadedSprite, int playerHight, int playerWidth);
	void Initialize(float scale);
	void Update();
	void GetPosition();
	void Draw(sf::RenderWindow& window);
};
