#ifndef PLAYER_CONTROLLER
#define PLAYER_CONTROLLER

#include <iostream>
#include "Actor.h"

class CPlayerController : public CActor
{
public:
	CPlayerController();

	void SpawnPlayer(SDL_Window * Window);

private:
	typedef CActor Super;
	// SDL_Window* AWindow = nullptr; // peut être stocké dans le constrcteur
};

// Cette classe centralise le contrôle des entités du jeux (par les humains)

#endif