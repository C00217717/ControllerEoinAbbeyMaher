#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER

#include <SFML\Graphics.hpp>
#include <iostream>

struct GamePadState
{
	bool A;
	bool B;
	bool X;
	bool Y;
};

class Xbox360Controller
{
public:
	Xbox360Controller();
	~Xbox360Controller();


	GamePadState m_currentState;
	GamePadState m_previousState;
	std::string m_currentButton;
	std::string m_previousButton;
	bool isConnected();
	bool connect();

	bool m_textShown[4] = { false, false, false, false };

	void Xbox360Controller::update();

private:
	const int dpadTreshold = 50;

};

#endif 

