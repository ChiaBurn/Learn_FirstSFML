#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

int main()
{
	const std::filesystem::path playerTextureDir = "resources/Player.png";
	const int playerHight = 32;
	const int playerWidth = 32;
	const float playerScale = 3.f;

#pragma region Initialize
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

	sf::Sprite playerSprite(playerTexture);
	Player player(playerSprite, playerHight, playerWidth);
	player.Initialize(playerScale);

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
		player.Draw(window);
		window.display();
#pragma endregion
	}

	return 0;
}