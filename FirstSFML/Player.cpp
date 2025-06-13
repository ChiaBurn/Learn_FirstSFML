#include "Player.h"

Player::Player(sf::Sprite& loadedSprite, int playerHight, int playerWidth) : sprite(loadedSprite), hight(playerHight), width(playerWidth)
{
}

void Player::Initialize(float scale, sf::Vector2f& initPos)
{
	sprite.setTextureRect(sf::IntRect({ 0,0 }, { hight, width }));
	sprite.setScale(sf::Vector2f(scale, scale));
	sprite.setPosition(initPos);
}

void Player::Update()
{
	float xDelta = 0;
	float yDelta = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		--yDelta;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		--xDelta;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		++yDelta;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		++xDelta;

	sf::Vector2f position = sprite.getPosition();
	sprite.setPosition(position + sf::Vector2f(xDelta, yDelta) * moveSpeed);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}