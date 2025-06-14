#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Skeleton.h"

int main()
{
#pragma region Initialize
	const std::filesystem::path playerTexturePath = "Assets/SpriteSheet/Player.png";
	sf::Vector2i playerSize = sf::Vector2i(32, 32);
	const float playerScale = 3.f;
	sf::Vector2f playerInitPos = sf::Vector2f(0, 0);
	const float playerSpeed = 0.0005f;

	const std::filesystem::path skeletonTexturePath = "Assets/SpriteSheet/Skeleton.png";
	sf::Vector2i skeletonSize = sf::Vector2i(32, 32);
	const float skeletonScale = 3.f;
	sf::Vector2f skeletonInitPos = sf::Vector2f(480, 270);

	sf::RenderWindow window(sf::VideoMode({ 960,540 }), "First Game!");

#pragma endregion

#pragma region Load
	sf::Texture playerTexture;
	sf::Texture skeletonTexture;

	bool isPlayerTextureLoaded = playerTexture.loadFromFile(playerTexturePath);
	bool isSkeletonTextureLoaded = skeletonTexture.loadFromFile(skeletonTexturePath);

	if (!isPlayerTextureLoaded)
		std::cout << "Falid to load Player's texture: " << playerTexturePath << std::endl;
	if (!isSkeletonTextureLoaded)
		std::cout << "Falid to load skeleton's texture: " << skeletonTexturePath << std::endl;

	if (!(isPlayerTextureLoaded && isSkeletonTextureLoaded))
	{
		system("pause");
		return 0;
	}

	sf::Sprite playerSprite(playerTexture);
	Player player(playerSprite, playerSize, playerSpeed);
	player.Initialize(playerScale, playerInitPos);

	sf::Sprite skeletonSprite(skeletonTexture);
	Skeleton skeleton(skeletonSprite, skeletonSize);
	skeleton.Initialize(skeletonScale, skeletonInitPos);

#pragma endregion
	sf::Clock clock;
	while (window.isOpen())
	{
		float deltaTime = clock.restart().asMicroseconds();

#pragma region Update

		while (auto e = window.pollEvent())
		{
			if (e->is<sf::Event::Closed>())
				window.close();
		}
		player.Update(deltaTime);
#pragma endregion

#pragma region Draw
		window.clear(sf::Color::Black);
		skeleton.Draw(window);
		player.Draw(window);
		window.display();
#pragma endregion
	}

	return 0;
}