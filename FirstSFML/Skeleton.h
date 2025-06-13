#pragma once
#include <SFML/Graphics.hpp>
class Skeleton
{
private:
	sf::Sprite sprite;
	int hight;
	int width;
	float moveSpeed = 0.1;

public:
	Skeleton(sf::Sprite& loadedSprite, int playerHight, int playerWidth);
	void Initialize(float scale, sf::Vector2f& initPos);
	void Update();
	void GetPosition();
	void Draw(sf::RenderWindow& window);
};
