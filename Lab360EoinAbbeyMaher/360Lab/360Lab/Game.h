/// <summary>
/// @Author: Eoin Abbey-Maher
/// @Date: 9/10/17
/// 
/// Game Header
/// </summary>

#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Xbox360Controller.h"



class Game
{
public:
	//Default Constructor
	Game();
	//Default Deconstructor
	~Game();
	void run();

private:
	
	void processEvents();
	
	void update(sf::Time t_deltaTime);
	
	void render();
	
	void setupSprite();
	
	/// <summary>
	/// Setup The "pressed" Text and all other text
	/// </summary>
	void setupFaceArray();

	
	sf::RenderWindow m_window; // main SFML window
	sf::Texture m_controllerTexture;
	sf::Sprite m_controllerSprite;
	sf::Font m_font;

	/// <summary>
	/// Array of text to say "Pressed"
	/// </summary>
	sf::Text m_pressedFaceArray[BUTTONS];

	/// <summary>
	/// Text of last button pressed
	/// </summary>
	sf::Text m_previousButton;

	/// <summary>
	/// Text of controller index
	/// </summary>
	sf::Text m_controllerNumber;

	/// <summary>
	/// Xbox controller Object
	/// </summary>
	Xbox360Controller m_controller;

	bool m_exitGame;
};

#endif // !GAME

