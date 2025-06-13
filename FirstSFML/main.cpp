#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Skeleton.h"

int main()
{
#pragma region Initialize
	const std::filesystem::path playerTextureDir = "resources/Player.png";
	const int playerHight = 32;
	const int playerWidth = 32;
	const float playerScale = 3.f;
	sf::Vector2f playerInitPos = sf::Vector2f(0, 0);

	const std::filesystem::path skeletonTextureDir = "resources/Skeleton.png";
	const int skeletonHight = 32;
	const int skeletonWidth = 32;
	const float skeletonScale = 3.f;
	sf::Vector2f skeletonInitPos = sf::Vector2f(480, 270);

	sf::RenderWindow window(sf::VideoMode({ 960,540 }), "First Game!");

#pragma endregion

#pragma region Load
	sf::Texture playerTexture;

	if (!playerTexture.loadFromFile(playerTextureDir))
	{
		std::cout << "Falid to load Player's texture: " << playerTextureDir << std::endl;
		system("pause");
		return 0;
	}
	sf::Texture skeletonTexture;

	if (!skeletonTexture.loadFromFile(skeletonTextureDir))
	{
		std::cout << "Falid to load skeleton's texture: " << skeletonTextureDir << std::endl;
		system("pause");
		return 0;
	}

	sf::Sprite playerSprite(playerTexture);
	Player player(playerSprite, playerHight, playerWidth);
	player.Initialize(playerScale, playerInitPos);

	sf::Sprite skeletonSprite(skeletonTexture);
	Skeleton skeleton(skeletonSprite, skeletonHight, skeletonWidth);
	skeleton.Initialize(skeletonScale, skeletonInitPos);

#pragma endregion

	while (window.isOpen())
	{
#pragma region Update

		while (auto e = window.pollEvent())
		{
			if (e->is<sf::Event::Closed>())
				window.close();
		}
		player.Update();
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