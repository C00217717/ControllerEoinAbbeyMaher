#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER

#include <SFML\Graphics.hpp>
#include <iostream>

int const BUTTONS{ 12 };

struct GamePadState
{
	bool A;
	bool B;
	bool X;
	bool Y;
	bool LB;
	bool RB;
	bool LeftThumbStickClick;
	bool RightThumbStickClick;
	bool DpadUp;
	bool DpadDown;
	bool DpadLeft;
	bool DpadRight;
};

class Xbox360Controller
{
public:
	Xbox360Controller();
	~Xbox360Controller();


	GamePadState m_currentState;
	GamePadState m_previousState;
	std::string m_previousButton;
	bool isConnected();
	bool connect();

	bool m_textShown[BUTTONS];

	void Xbox360Controller::update();

	void buttonCheck();

private:
	const int dpadTreshold = 50;

};

#endif 

