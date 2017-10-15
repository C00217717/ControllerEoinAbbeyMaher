// author Peter Lowe

#include "Game.h"

#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	if (m_controller.isConnected())
	{
		std::cout << "controller Is Connected" << std::endl;
	}
	if (!m_font.loadFromFile("ASSETS\\FONTS\\Gameplay.ttf"))
	{
		std::cout << "Font not loaded" << std::endl;
	}

	setupSprite();
	setupFaceArray();
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
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
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	m_controller.update();
	if (m_exitGame)
	{
		m_window.close();
	}
	m_currentButton.setString("Current Button Pressed: " + m_controller.m_currentButton);
	m_PreviousButton.setString("Previous Button Pressed: " + m_controller.m_previousButton);
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_controllerSprite);
	m_window.draw(m_currentButton);
	m_window.draw(m_PreviousButton);
	for (int i = 0; i < 4; i++)
	{
		if (m_controller.m_textShown[i] == true)
		{
			m_window.draw(m_pressedFaceArray[i]);
		}
	}
	m_window.display();
}


/// <summary>
/// load the texture and setup the sprite for the logo
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

void Game::setupFaceArray()
{

	m_currentButton.setFont(m_font);
	m_currentButton.setFillColor(sf::Color::Black);
	m_currentButton.setPosition(50, 540);
	m_currentButton.setCharacterSize(15);
	m_currentButton.setString("Current Button Pressed: ");

	m_PreviousButton.setFont(m_font);
	m_PreviousButton.setFillColor(sf::Color::Black);
	m_PreviousButton.setPosition(350, 540);
	m_PreviousButton.setCharacterSize(15);
	m_currentButton.setString("Previous Button Pressed");

	for (int i = 0; i < 4; i++)
	{
		m_pressedFaceArray[i].setFont(m_font);
		m_pressedFaceArray[i].setString("Pressed");
		m_pressedFaceArray[i].setFillColor(sf::Color::Blue);
		m_pressedFaceArray[i].setCharacterSize(15);
	}

	m_pressedFaceArray[0].setPosition(660, 255);
	m_pressedFaceArray[1].setPosition(660, 305);
	m_pressedFaceArray[2].setPosition(660, 355);
	m_pressedFaceArray[3].setPosition(660, 405);
}
