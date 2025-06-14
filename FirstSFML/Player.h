#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Sprite sprite;
	sf::Vector2i size;
	float moveSpeed = 0.001f;

public:
	Player(sf::Sprite& loadedSprite, sf::Vector2i playerSize, float playerSpeed);
	void Initialize(float scale, sf::Vector2f& initPos);
	void Update(float deltaTime);
	sf::Vector2f GetPosition();
	void Draw(sf::RenderWindow& window);
};
