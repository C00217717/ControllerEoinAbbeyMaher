/// <summary>
/// @Author : Eoin Abbey-Maher
/// @Brief : Program to read controller inputs
/// 
/// Known Bugs: Current and Previous state buttons not working 100%
/// </summary>

#include "Xbox360Controller.h"

Xbox360Controller::Xbox360Controller()
{
	
}

Xbox360Controller::~Xbox360Controller()
{
}

bool Xbox360Controller::isConnected()
{
	if (sf::Joystick::isConnected(0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Xbox360Controller::connect()
{
	return false;
}

void Xbox360Controller::update()
{
	for (int i = 0; i < 4; i++)
	{
		m_textShown[i] = false;
	}

	m_currentButton = "";

	if (sf::Joystick::isButtonPressed(0,1))
	{
		m_previousState = m_currentState;
		m_currentState.A = true;
		m_textShown[3] = true;
		m_currentButton = "A";
		if (m_previousState.A)
		{
			m_previousButton = "A";
		}
	}
	
	if (sf::Joystick::isButtonPressed(0, 0))
	{
		m_previousState = m_currentState;
		m_currentState.X = true;
		m_textShown[1] = true;
		m_currentButton = "X";
		if (m_previousState.X)
		{
			m_previousButton = "X";
		}
	}

	if (sf::Joystick::isButtonPressed(0, 2))
	{
		m_previousState = m_currentState;
		m_currentState.B = true;
		m_textShown[2] = true;
		m_currentButton = "B";
		if (m_previousState.B)
		{
			m_previousButton = "B";
		}
	}

	if (sf::Joystick::isButtonPressed(0, 3))
	{
		m_previousState = m_currentState;
		m_currentState.Y = true;
		m_textShown[0] = true;
		m_currentButton = "Y";
		if (m_previousState.Y)
		{
			m_previousButton = "Y";
		}
	}

}

