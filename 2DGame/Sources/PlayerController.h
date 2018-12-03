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
	// SDL_Window* AWindow = nullptr; // peut �tre stock� dans le constrcteur
};

// Cette classe centralise le contr�le des entit�s du jeux (par les humains)

#endif