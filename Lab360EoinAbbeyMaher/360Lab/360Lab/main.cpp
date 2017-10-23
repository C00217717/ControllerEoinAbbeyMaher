/// <summary>
/// @Author: Eoin Abbey-Maher
/// @Date: 9/10/17
/// 
/// @Brief : Program to take in and output controller inputs
/// Known Bugs: No Known Bugs
/// 
/// Time Taken: 9 hours
/// Main Entry Point
/// </summary>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "Game.h"

/// <summary>
/// Main entry point
/// </summary>
int main()
{
	Game game;
	game.run();

	return 1;
}