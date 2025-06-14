#include "Player.h"

Player::Player(sf::Sprite& loadedSprite, sf::Vector2i playerSize, float playerSpeed) : sprite(loadedSprite), size(playerSize), moveSpeed(playerSpeed)
{
}

void Player::Initialize(float scale, sf::Vector2f& initPos)
{
	sprite.setTextureRect(sf::IntRect({ 0,0 }, { size.x, size.y }));
	sprite.setScale(sf::Vector2f(scale, scale));
	sprite.setPosition(initPos);
}

void Player::Update(float deltaTime)
{
	float deltaX = 0;
	float deltaY = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		--deltaY;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		++deltaY;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		--deltaX;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		++deltaX;

	sf::Vector2f position = sprite.getPosition();
	sprite.setPosition(position + sf::Vector2f(deltaX, deltaY) * moveSpeed * deltaTime);
}

sf::Vector2f Player::GetPosition()
{
	return sprite.getPosition();
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}