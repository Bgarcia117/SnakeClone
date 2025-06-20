/**
 * @file snake.cpp
 * @brief Implementation of the Snake class
 * 
 * This file contains all the function definitions for the Snake class.
 * The Snake class manages the player controlled snake, including:
 * - Segment creation and rendering
 * - Movement and direction changes
 * - Growth when food is consumed
 * - Collision detection
*/

#include "snake.h"

/**
 * @brief Default constructor
 * 
 * Initializes the snake with:
 * - Starting position at (200, 200)
 * - Initial length of 3 segments
 * - Default movement direction (Right)
 * - Head, body, and tail segments configured
 */
Snake::Snake() : length(1), moveDirection(Direction::Right), 
                            nextDirection(Direction::Right) {

	body.push_back(createSegment(true, true));

	grow();
	grow();
}

/**
 * @brief Get the position of the snake's head
 * 
 * Returns the top left corner position of the head segment.
 * Used for collision detection and boundary checks.
 * @return sf::Vector2i The head position as integer coordinates
 */
sf::Vector2i Snake::getHeadPos() const {
	sf::Vector2f pos = body.front().part.getPosition();
	return { static_cast<int>(pos.x), static_cast<int>(pos.y) };
}

/**
 * @brief Get the position of the snake's tail
 * 
 * Returns the position of the last segment in the snake's body.
 * Useful for growth mechanics and tail specific operations.
 * 
 * @returns sf::Vector2i The tail position as integer coordinates
 */
sf::Vector2i Snake::getTailPos() const {
	sf::Vector2f pos = body.back().part.getPosition();
	return { static_cast<int>(pos.x), static_cast<int>(pos.y) };
}

/**
 * @brief Get positions of all snake segments
 *
 * Returns a vector containing the positions of all segments from head to tail.
 * Used for collision detection (self-colllison, food overlap checks).
 * 
 * @returns std::vector<sf::Vector2f> Vector of all segment positions
 */
std::vector<sf::Vector2f> Snake::getSegmentPos() const {
	std::vector<sf::Vector2f> positions;

	for (const auto& segment : body) {
		positions.push_back(segment.part.getPosition());
	}

	return positions;
}

/**
 * @brief Check if the snake has reached maximum length
 * 
 * Determines if the snake has filled the entire window.
 * This is the win condition for the game.
 * 
 * @return true if snake is at max length, false otherwise
 */
bool Snake::isMaxLength() const {
	return length == 30;
}

/**
 * @brief Add a new segment to the snake (grows longer)
 * 
 * Called when the snake consumes food. Add new segment at tail
 * position, making the snake segment longer.
 */
void Snake::grow() {
	if (!body.empty()) {
		body.back().isTail = false;
	}

	body.push_back(createSegment(false, true));
	length++;
}

/**
 * @brief Update the snake's position and state
 * 
 * Called once per game cycle to:
 * - Apply any queued direction changes
 * - Move all segments to their new positions
 * - Update segment directions for smooth snake-like behavior
 */
void Snake::updateSnake() {
	// Each segment copies the position and direction of the one in ahead of it
	for (int i = body.size() - 1; i > 0; --i) {
		body[i].part.setPosition(body[i - 1].part.getPosition());// Copy Position
		body[i].segDirection = body[i - 1].segDirection;         // Copy Direction

	}

	// After the for loop to ensure change starts at the new frame
	moveDirection = nextDirection;
	moveSegments(body[0], moveDirection);
	body[0].segDirection = moveDirection;
}

 /**
  * @brief Changes the snake's movement direction with validation.
  *
  * Changes the snake's direction while preventing invalid moves:
  * - Cannot reverse directly into the opposite direction.
  * - Queues the direction change for the next movement update
  *
  * @param newDirection The requested new direction
  */
void Snake::changeDirection(Direction newDirection) {
	if ((moveDirection == Direction::Up && newDirection == Direction::Down)    ||
		(moveDirection == Direction::Down && newDirection == Direction::Up)    ||
		(moveDirection == Direction::Right && newDirection == Direction::Left) ||
		(moveDirection == Direction::Left && newDirection == Direction::Right)) {
		return;
	}

	nextDirection = newDirection;
}

/**
 * @brief Render the snake to the specified render target
 * 
 * Draws all snake segments to the provided render target.
 * Segmens are drawn in order from tail to head so that the 
 * head appears on top in case of overlaps
 * 
 * @param target The SFML render target to draw to (the window in this case)
 */
void Snake::renderSnake(sf::RenderTarget& target) const {
	for (const auto& segment : body) {
		target.draw(segment.part);
	}
}

/**
 * @brief Create a new snake segment with specified properties
 * 
 * Creates configured snake segments with size, color, and positioning.
 * 
 * @param isHead True if the segment should be marked as the head.
 * @param isTail True if the segment should be marked as the tail.
 * @return SnakeSegment A fully configured segment
 */
SnakeSegment Snake::createSegment(bool isHead, bool isTail) const {
	SnakeSegment segment;
	segment.part.setSize({ static_cast<float>(segmentSize), 
		                   static_cast<float>(segmentSize) });
	segment.part.setFillColor(isHead ? sf::Color::Yellow : sf::Color::Green);
	segment.part.setOutlineColor(sf::Color::Black);
	segment.part.setOutlineThickness(1);

	if (body.empty()) {
		segment.part.setPosition({static_cast<float>(startPos.x), 
			                      static_cast<float>(startPos.x)});

	}
	else {
		segment.part.setPosition({ static_cast<float>(getTailPos().x - segmentSize), 
			                       static_cast<float>(getTailPos().y) });
	}

	segment.segDirection = Direction::Right;
	segment.isHead = isHead;
	segment.isTail = isTail;
	return segment;
}

/**
 * @brief Move a single snake segment in the specified direction
 * 
 * Updates the position of a given snake segment by shifting it by
 * one grid unit (20 pixels) in the given direction.
 * 
 * @param segment Reference to the SnakeSegment to move
 * @param direction Direction in which to move the segment
 */
void Snake::moveSegments(SnakeSegment& segment, Direction direction) {

	switch (direction) {
	// Move upwards by decreasing the y-coordinate
	case Direction::Up:
		segment.part.move({ 0, static_cast<float>(-segmentSize)});
		break;

	case Direction::Down:
		// Move downward by increasing tdhe y-coordinate
		segment.part.move({ 0, static_cast<float>(segmentSize) });
		break;

	case Direction::Left:
		// Move left by decreasing the x-coordinate
		segment.part.move({ static_cast<float>(-segmentSize), 0 });
		break;

	case Direction::Right:
		// Move right by decreasing the x-coordinate
		segment.part.move({ static_cast<float>(segmentSize), 0 });
		break;
	}
}