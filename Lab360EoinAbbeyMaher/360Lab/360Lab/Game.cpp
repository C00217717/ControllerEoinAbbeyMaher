// author Peter Lowe

#include "Game.h"

#include <iostream>

/// <summary>
/// Default Game Constructor
/// setup game objects at the start of the game
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
		if (!m_font.loadFromFile("ASSETS\\FONTS\\Althea.ttf"))
	{
		std::cout << "Font not loaded" << std::endl;
	}

	setupSprite();
	setupFaceArray();
}

/// <summary>
/// Default deconstructor
/// </summary>
Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); //set frame to run at 60 fps
	while (m_window.isOpen())
	{
		processEvents(); 
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame); //update at 60 fps
		}
		render(); // functoin to Draw objects on screen
	}
}

/// <summary>
/// Process Events whilst game Window is open
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			
		}
	}
}

/// <summary>
/// Game Update 
/// </summary>
/// <param name="t_deltaTime"> Running at 60 fps</param>
void Game::update(sf::Time t_deltaTime)
{
	//Controller Update
	m_controller.update();

	if (m_exitGame)
	{
		m_window.close();
	}

	/// <summary>
	/// Update text displayed on the screen
	/// </summary>
	m_previousButton.setString("Previous Button Pressed: " + m_controller.m_previousButton);
	m_pressedFaceArray[12].setString(std::to_string(m_controller.m_currentState.LTrigger));
	m_pressedFaceArray[13].setString(std::to_string(m_controller.m_currentState.RTrigger * -1));
	m_pressedFaceArray[14].setString(std::to_string(m_controller.m_currentState.RightThumbStick.x) + " , " + std::to_string(m_controller.m_currentState.RightThumbStick.y));
	m_pressedFaceArray[15].setString(std::to_string(m_controller.m_currentState.LeftThumbStick.x) + " , " + std::to_string(m_controller.m_currentState.LeftThumbStick.y));

	/// <summary>
	/// if the player presses the back button quit out 
	/// of the game
	/// </summary>
	if (m_controller.m_currentState.Back)
	{
		m_window.close();
	}
}

/// <summary>
/// Funtion to draw all game objects on the screen
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_controllerSprite);
	m_window.draw(m_previousButton);
	m_window.draw(m_controllerNumber);
	
	/// <summary>
	/// If the text shown bool is true then draw the corresponding 
	/// button "Pressed"
	/// </summary>
	for (int i = 0; i < BUTTONS; i++)
	{
		if (m_controller.m_textShown[i] == true)
		{
			m_window.draw(m_pressedFaceArray[i]);
		}
	}
	m_window.display();
}

/// <summary>
/// Set up the controller sprite in the window
/// </summary>
void Game::setupSprite()
{
	if (!m_controllerTexture.loadFromFile("ASSETS\\IMAGES\\Controller.jpg"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_controllerSprite.setTexture(m_controllerTexture);
	m_controllerSprite.setOrigin(450, 300);
	m_controllerSprite.setPosition(m_window.getSize().x * .5, m_window.getSize().y * .5);
	m_controllerSprite.setScale(.85, .85);
}

/// <summary>
/// Setup Text and fonts
/// </summary>
void Game::setupFaceArray()
{
	m_previousButton.setFont(m_font);
	m_previousButton.setFillColor(sf::Color::Black);
	m_previousButton.setPosition(50, 560);
	m_previousButton.setCharacterSize(22);

	m_controllerNumber.setFont(m_font);
	m_controllerNumber.setString("Controller Number " + std::to_string(m_controller.sf_Joystick_Index));
	m_controllerNumber.setPosition(300, 100);
	m_controllerNumber.setFillColor(sf::Color::Black);
	m_controllerNumber.setCharacterSize(22);

	for (int i = 0; i < BUTTONS; i++)
	{
		m_pressedFaceArray[i].setFont(m_font);
		m_pressedFaceArray[i].setString("Pressed");
		m_pressedFaceArray[i].setFillColor(sf::Color::Black);
		m_pressedFaceArray[i].setCharacterSize(22);
	}

	m_pressedFaceArray[0].setPosition(660, 405); // A
	m_pressedFaceArray[1].setPosition(660, 355); // B
	m_pressedFaceArray[2].setPosition(660, 305); // X
	m_pressedFaceArray[3].setPosition(660, 255); // Y
	m_pressedFaceArray[4].setPosition(620, 160); // RB
	m_pressedFaceArray[5].setPosition(60, 160);  // LB
	m_pressedFaceArray[6].setPosition(20, 280);  // Left stick click
	m_pressedFaceArray[7].setPosition(460, 520); // Right Stick Click
	m_pressedFaceArray[8].setPosition(330, 490); //Dpad Right
	m_pressedFaceArray[9].setPosition(210, 490); //Dpad Left
	m_pressedFaceArray[10].setPosition(280, 450); //Dpad UP
	m_pressedFaceArray[11].setPosition(280, 530); //Dpad Down
	m_pressedFaceArray[12].setPosition(200, 80); //Left Trigger;
	m_pressedFaceArray[13].setPosition(500, 80); //Right Trigger ;
	m_pressedFaceArray[14].setPosition(460, 500); //Right Stick Coords
	m_pressedFaceArray[15].setPosition(10, 220); //Left Stick Coords
	m_pressedFaceArray[16].setPosition(660, 470); //Start

	
}
