#include "PlayerController.h"
#include "SceneRender.h"
#include "Input.h"

CPlayerController::CPlayerController()
{ 
	// Appel du constructeur de la classe mère
	Super::CActor();

	// Création de l'instance de l'entité gérant les Inputs
	AInputHandler = new CSubInputHandler();
}

CPlayerController::~CPlayerController()
{

}

void CPlayerController::SetSpawnPositionPlayer(int x, int y)
{
	SetActorPosition(x, y);
}

void CPlayerController::EventProcessing(CGameSceneRender* SceneRender)
{
	if (AInputHandler->GetKeyState(SDL_SCANCODE_UP) || AInputHandler->GetKeyState(SDL_SCANCODE_W))
	{
		SceneRender->MoveActorForward(15);
	}
	
	if (AInputHandler->GetKeyState(SDL_SCANCODE_DOWN) || AInputHandler->GetKeyState(SDL_SCANCODE_S))
	{
		SceneRender->MoveActorForward(-10);
	}

	if (AInputHandler->GetKeyState(SDL_SCANCODE_LEFT) || AInputHandler->GetKeyState(SDL_SCANCODE_A))
	{
		SceneRender->SetIncrementAngle(-10);
	}

	if (AInputHandler->GetKeyState(SDL_SCANCODE_RIGHT) || AInputHandler->GetKeyState(SDL_SCANCODE_D))
	{
		SceneRender->SetIncrementAngle(10);
	}
}

CSubInputHandler* CPlayerController::GetInputHandler() const
{
	return AInputHandler;
}
