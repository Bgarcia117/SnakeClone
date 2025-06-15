#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Food {
public:
	Food();
	~Food();

	void renderFood(sf::RenderTarget& target) const;
	sf::Vector2f getFoodPos() const;
	void moveFood(sf::Vector2i newPosition); 

private:
	sf::RectangleShape food;

	const sf::Vector2i foodStartPos = { 300, 200 };
	const sf::Vector2i foodSize = { 20, 20 };

};