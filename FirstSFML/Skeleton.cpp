#include "Skeleton.h"

Skeleton::Skeleton(sf::Sprite& loadedSprite, sf::Vector2i skeletonSize, sf::RectangleShape& skeletonBoudingRectangle)
	: sprite(loadedSprite), size(skeletonSize), boundingRectangle(skeletonBoudingRectangle)
{
}

void Skeleton::Initialize(float scale, sf::Vector2f& initPos)
{
	// TODO: Sprite Anime
	int spriteOriginX = 8;
	int spriteOriginY = 8;
	int spriteIndeX = 0;
	int spriteIndeY = 0;
	int spriteIndeOffsetX = 32;
	int spriteIndeOffsetY = 32;

	sprite.setTextureRect(sf::IntRect({ spriteOriginX + spriteIndeX * spriteIndeOffsetX, spriteOriginY + spriteIndeY * spriteIndeOffsetY }, { size.x, size.y }));
	sprite.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	sprite.setScale(sf::Vector2f(scale, scale));
	sprite.setPosition(initPos);

	boundingRectangle = sf::RectangleShape(sprite.getGlobalBounds().size);
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);
	sf::Vector2f boundingRectangleSize = boundingRectangle.getSize();
	boundingRectangle.setOrigin(sf::Vector2f(boundingRectangleSize.x / 2, boundingRectangleSize.y / 2));
	boundingRectangle.setPosition(initPos);
}

void Skeleton::Update()
{
	// AI
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);
}