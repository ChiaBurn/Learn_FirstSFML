#pragma once
#include <SFML/Graphics.hpp>
class Skeleton
{
private:
	sf::Sprite sprite;
	sf::Vector2i size;
	float moveSpeed = 0.1;
	sf::RectangleShape boundingRectangle;

public:
	Skeleton(sf::Sprite& loadedSprite, sf::Vector2i sceletonSize, sf::RectangleShape& playerBoudingRectangle);
	void Initialize(float scale, sf::Vector2f& initPos);
	void Update();
	inline sf::Vector2f GetPosition() { return sprite.getPosition(); };
	void Draw(sf::RenderWindow& window);
	inline const sf::RectangleShape& GetBoundingRectangle() { return boundingRectangle; };
};
