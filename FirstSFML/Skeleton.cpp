#include "Skeleton.h"

Skeleton::Skeleton(sf::Sprite& loadedSprite, int SkeletonHight, int SkeletonWidth) : sprite(loadedSprite), hight(SkeletonHight), width(SkeletonWidth)
{
}

void Skeleton::Initialize(float scale, sf::Vector2f& initPos)
{
	sprite.setTextureRect(sf::IntRect({ 0,0 }, { hight, width }));
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