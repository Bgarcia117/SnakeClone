#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Food {
public:
	Food();
	~Food();

	void renderFood(sf::RenderTarget& target) const;

private:
	sf::RectangleShape food;

	const sf::Vector2i foodStartPos = { 300, 200 };
	const sf::Vector2i foodSize = { 20, 20 };

	sf::Vector2i position;

	void setPosition();
	void spawnFood(const Snake& snake);
};