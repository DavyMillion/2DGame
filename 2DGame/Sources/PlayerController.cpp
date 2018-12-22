#include "PlayerController.h"
#include "SceneRender.h"
#include "Input.h"

CPlayerController::CPlayerController()
{ 
	// Appel du constructeur de la classe m�re
	Super::CActor();

	// Cr�ation de l'instance de l'entit� g�rant les Inputs
	AInputHandler = new CSubInputHandler();

	ACalculatedPos = new SDL_Point;
}

CPlayerController::~CPlayerController()
{

}

void CPlayerController::CalculateNextPosition(int Increment) // � modifier
{
	double theta = this->GetActorRelativeAngle();
	theta = (theta * M_PI) / 180; // passage en radians

	ACalculatedPos->x = this->GetActorAbsolutePosition()->x + static_cast<int>(round(Increment * sin(theta)));
	ACalculatedPos->y = this->GetActorAbsolutePosition()->y + static_cast<int>(round(Increment * (-1) * cos(theta)));
}

void CPlayerController::SetSpawnPositionPlayer(int x, int y)
{
	SetActorPosition(x, y);
}

void CPlayerController::EventProcessing(CGameSceneRender* SceneRender)
{
	if (AInputHandler->GetKeyState(SDL_SCANCODE_UP) || AInputHandler->GetKeyState(SDL_SCANCODE_W))
	{
		this->CalculateNextPosition(10);
	}
	
	if (AInputHandler->GetKeyState(SDL_SCANCODE_DOWN) || AInputHandler->GetKeyState(SDL_SCANCODE_S))
	{
		this->CalculateNextPosition(-10);
	}

	if (AInputHandler->GetKeyState(SDL_SCANCODE_LEFT) || AInputHandler->GetKeyState(SDL_SCANCODE_A))
	{
		// En attendant de faire le syst�me de calcul � partir des variations de framerate
		SceneRender->GetPlayerController()->SetActorRotation(-3);
	}

	if (AInputHandler->GetKeyState(SDL_SCANCODE_RIGHT) || AInputHandler->GetKeyState(SDL_SCANCODE_D))
	{
		// En attendant
		SceneRender->GetPlayerController()->SetActorRotation(3);
	}
}

CSubInputHandler* CPlayerController::GetInputHandler() const
{
	return AInputHandler;
}

SDL_Point* CPlayerController::GetActorCalculatedPosition() const
{
	return ACalculatedPos;
}
