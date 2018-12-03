#include "PlayerController.h"

CPlayerController::CPlayerController()
{
	Super::CActor();

	// Initialisation du "joueur"
	ATextureContainer->x = 0;
	ATextureContainer->y = 0;
	ATextureContainer->w = 48;
	ATextureContainer->h = 70;

	// Initialisation de ACenterPositionTextureContainerGrid
	ACenterPositionTextureContainerGrid->x = ATextureContainer->w / 2;
	ACenterPositionTextureContainerGrid->y = ATextureContainer->h / 2;
}

void CPlayerController::SpawnPlayer(SDL_Window * Window)
{
	int LengthX, LengthY;
	SDL_GetWindowSize(Window, &LengthX, &LengthY);
	SetActorPositionX(LengthX / 2);
	SetActorPositionY(LengthY / 2);
}