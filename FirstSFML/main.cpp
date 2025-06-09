#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow w(sf::VideoMode({ 800,600 }), "Test");

	while (w.isOpen())
	{
#pragma region Update

		while (auto e = w.pollEvent())
		{
			if (e->is<sf::Event::Closed>())
				w.close();
		}
#pragma endregion

#pragma region Draw
		w.clear(sf::Color::Magenta);
		w.display();
#pragma endregion
	}

	return 0;
}