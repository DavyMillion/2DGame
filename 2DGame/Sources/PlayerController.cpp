#include "PlayerController.h"

CPlayerController::CPlayerController()
{ 
	Super::CActor();

	// Initialisation du "joueur"
	ATextureContainer->x = 0;
	ATextureContainer->y = 0;
	ATextureContainer->w = 48;
	ATextureContainer->h = 70;

	ACenterPositionInContainerGrid->x = ATextureContainer->w / 2;
	ACenterPositionInContainerGrid->y = ATextureContainer->h / 2;
}

void CPlayerController::SetSpawnPositionPlayer(int x, int y)
{
	SetActorPosition(x, y);
}