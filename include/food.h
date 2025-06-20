#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Food {
public:
	Food();

	void renderFood(sf::RenderTarget& target) const;
	sf::Vector2f getFoodPos() const;
	void moveFood(sf::Vector2i newPosition); 

private:
	sf::RectangleShape food;

	// Kept static b/c they belong to the class and not each instance
	// Kept private for better encapsulation
	static constexpr sf::Vector2i foodStartPos = { 300, 200 };
	static constexpr sf::Vector2i foodSize = { 20, 20 };

};