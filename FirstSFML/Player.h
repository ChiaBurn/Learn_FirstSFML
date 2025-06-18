#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Sprite sprite;
	sf::Vector2i size;
	float moveSpeed = 0.001f;
	sf::RectangleShape boundingRectangle;

public:
	Player(sf::Sprite& loadedSprite, sf::Vector2i playerSize, float playerSpeed);
	void Initialize(float scale, sf::Vector2f& initPos);
	void Update(float deltaTime);
	inline sf::Vector2f GetPosition() { return sprite.getPosition(); };
	void Draw(sf::RenderWindow& window);
	inline const sf::RectangleShape& GetBoundingRectangle() { return boundingRectangle; };
};
