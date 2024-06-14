#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>


int main()
{
	std::srand(std::time(nullptr));
	sf::RenderWindow window(sf::VideoMode(800, 600), "ur mom");
	window.setFramerateLimit(60);
	
	//sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));
	//shape.setPosition(sf::Vector2f(10.f, 10.f));
	sf::Vector2f velocity(1.f, 1.f);

	sf::Texture dvdTexture;
	if(!dvdTexture.loadFromFile("assets/dvd.png"))
	{
		std::cout << "Cant load file :(" << std::endl;
	}

	sf::Sprite dvdSprite;
	dvdSprite.setTexture(dvdTexture);
	dvdSprite.setScale(100.f / dvdSprite.getLocalBounds().width, 50.f / dvdSprite.getLocalBounds().height);
	dvdSprite.setPosition(sf::Vector2f(10.f, 10.f));	

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		if(dvdSprite.getPosition().x + dvdSprite.getGlobalBounds().getSize().x >= window.getSize().x || dvdSprite.getPosition().x <= 0)
		{
			velocity.x *= -1;
			dvdSprite.setColor(sf::Color(std::rand() % 255, std::rand() % 255, std::rand() % 255));
		}		
		if(dvdSprite.getPosition().y + dvdSprite.getGlobalBounds().getSize().y >= window.getSize().y || dvdSprite.getPosition().y <= 0)
		{
			velocity.y *= -1;
			dvdSprite.setColor(sf::Color(std::rand() % 255, std::rand() % 255, std::rand() % 255));
		}

		dvdSprite.move(velocity);

		window.clear();
		window.draw(dvdSprite);
		window.display();
	}
}


