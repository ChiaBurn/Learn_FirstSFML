#pragma once
#include <SFML/Graphics.hpp>
class Skeleton
{
private:
	sf::Sprite sprite;
	sf::Vector2i size;
	float moveSpeed = 0.1;

public:
	Skeleton(sf::Sprite& loadedSprite, sf::Vector2i sceletonSize);
	void Initialize(float scale, sf::Vector2f& initPos);
	void Update();
	sf::Vector2f GetPosition();
	void Draw(sf::RenderWindow& window);
};
