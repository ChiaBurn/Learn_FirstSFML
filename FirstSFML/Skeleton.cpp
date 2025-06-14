#include "Skeleton.h"

Skeleton::Skeleton(sf::Sprite& loadedSprite, sf::Vector2i skeletonSize) : sprite(loadedSprite), size(skeletonSize)
{
}

void Skeleton::Initialize(float scale, sf::Vector2f& initPos)
{
	sprite.setTextureRect(sf::IntRect({ 0,0 }, { size.x, size.y }));
	sprite.setScale(sf::Vector2f(scale, scale));
	sprite.setPosition(initPos);
}

void Skeleton::Update()
{
	// AI
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}