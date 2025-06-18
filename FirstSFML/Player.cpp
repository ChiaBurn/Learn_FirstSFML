#include "Player.h"

Player::Player(sf::Sprite& loadedSprite, sf::Vector2i playerSize, float playerSpeed)
	: sprite(loadedSprite), size(playerSize), moveSpeed(playerSpeed)
{
}

void Player::Initialize(float scale, sf::Vector2f& initPos)
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
	boundingRectangle.setOutlineColor(sf::Color::Blue);
	boundingRectangle.setOutlineThickness(1);
	sf::Vector2f boundingRectangleSize = boundingRectangle.getSize();
	boundingRectangle.setOrigin(sf::Vector2f(boundingRectangleSize.x / 2, boundingRectangleSize.y / 2));
	boundingRectangle.setPosition(initPos);
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

	sf::Vector2f updateedPosition = sprite.getPosition() + sf::Vector2f(deltaX, deltaY) * moveSpeed * deltaTime;

	sprite.setPosition(updateedPosition);
	boundingRectangle.setPosition(updateedPosition);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);
}