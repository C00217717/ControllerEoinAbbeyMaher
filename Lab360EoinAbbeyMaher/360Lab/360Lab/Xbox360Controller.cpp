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
	

	for (int i = 0; i < BUTTONS; i++)
	{
		m_textShown[i] = false;
	}
	m_previousState = m_currentState;
	buttonCheck();
}

void Xbox360Controller::buttonCheck()
{

	if (sf::Joystick::isButtonPressed(0, 1)) //B
	{
		//m_previousState = m_currentState;
		m_currentState.B = true;
		m_textShown[1] = true;
		if (m_previousState.B)
		{
			m_previousButton = "B";
		}
	}
	else
	{
		m_currentState.B = false;
	}

	if (sf::Joystick::isButtonPressed(0, 0)) //A
	{
	//	m_previousState = m_currentState;
		m_currentState.A = true;
		m_textShown[0] = true;
		if (m_previousState.A)
		{
			m_previousButton = "A";
		}
	}
	else
	{
		m_currentState.A = false;
	}

	if (sf::Joystick::isButtonPressed(0, 2)) //X
	{
		//m_previousState = m_currentState;
		m_currentState.X = true;
		m_textShown[2] = true;
		if (m_previousState.X)
		{
			m_previousButton = "X";
		}
	}
	else
	{
		m_currentState.X = false;
	}

	if (sf::Joystick::isButtonPressed(0, 3)) //Y
	{
		//m_previousState = m_currentState;
		m_currentState.Y = true;
		m_textShown[3] = true;
		if (m_previousState.Y)
		{
			m_previousButton = "Y";
		}
	}
	else
	{
		m_currentState.Y = false;
	}

	if (sf::Joystick::isButtonPressed(0, 5)) //RB
	{
		//m_previousState = m_currentState;
		m_currentState.RB = true;
		m_textShown[4] = true;
		if (m_previousState.RB)
		{
			m_previousButton = "RB";
		}
	}
	else
	{
		m_currentState.RB = false;
	}

	if (sf::Joystick::isButtonPressed(0, 4)) //LB
	{
		//m_previousState = m_currentState;
		m_currentState.LB = true;
		m_textShown[5] = true;
		if (m_previousState.LB)
		{
			m_previousButton = "LB";
		}
	}
	else
	{
		m_currentState.LB = false;
	}

	if (sf::Joystick::isButtonPressed(0, 8))
	{
		//m_previousState = m_currentState;
		m_currentState.LeftThumbStickClick = true;
		m_textShown[6] = true;
		if (m_previousState.LeftThumbStickClick)
		{
			m_previousButton = "Left Thumb Stick";
		}
	}
	else
	{
		m_currentState.LeftThumbStickClick = false;
	}

	if (sf::Joystick::isButtonPressed(0, 9))
	{
		m_currentState.RightThumbStickClick = true;
		m_textShown[7] = true;
		if (m_previousState.RightThumbStickClick)
		{
			m_previousButton = "Right Mouse Click";
		}
	}
	else
	{
		m_currentState.RightThumbStickClick = false;
	}

	if()
}

