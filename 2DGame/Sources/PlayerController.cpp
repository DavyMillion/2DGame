#include "PlayerController.h"
#include "SceneRender.h"

CPlayerController::CPlayerController()
{ 
	Super::CActor();

}

void CPlayerController::SetSpawnPositionPlayer(int x, int y)
{
	SetActorPosition(x, y);
}

void CPlayerController::EventProcessing(SDL_Event& Event, CGameSceneRender* SceneRender)
{
	/*
	// Si une touche est pressée
	if (Event.type == SDL_KEYDOWN && Event.key.repeat == 0)
	{
		// On ajuste la vitesse
		switch (Event.key.keysym.sym)
		{
		case SDLK_UP: 
			mVelY -= DOT_VEL; 
			break;
		case SDLK_DOWN: 
			mVelY += DOT_VEL; 
			break;
		case SDLK_LEFT: 
			mVelX -= DOT_VEL; 
			break;
		case SDLK_RIGHT: 
			mVelX += DOT_VEL; 
			break;
		}
	}

	// Si une touche est relachée
	else if (Event.type == SDL_KEYUP && Event.key.repeat == 0)
	{
		//Adjust the velocity
		switch (Event.key.keysym.sym)
		{
		case SDLK_UP: 
			mVelY += DOT_VEL; 
			break;
		case SDLK_DOWN: 
			mVelY -= DOT_VEL; 
			break;
		case SDLK_LEFT: 
			mVelX += DOT_VEL; 
			break;
		case SDLK_RIGHT: 
			mVelX -= DOT_VEL; 
			break;
		}
	}
	*/
	
	switch (Event.key.keysym.sym)
	{
	case SDLK_RIGHT:
		SceneRender->SetIncrementAngle(10);
		break;
	case SDLK_LEFT:
		SceneRender->SetIncrementAngle(-10);
		break;
	case SDLK_DOWN:
		SceneRender->MoveActorForward(-10);
		break;
	case SDLK_UP:
		SceneRender->MoveActorForward(15);
		break;
	default:
		break;
	}
	/*
	if (Event.type == SDL_KEYDOWN && Event.key.repeat == 0)
	{
		// On ajuste la vitesse
		switch (Event.key.keysym.sym)
		{
		case SDLK_UP:
			SceneRender->MoveActorForward(15);
			break;
		case SDLK_DOWN:
			SceneRender->MoveActorForward(-10);
			break;
		case SDLK_LEFT:
			SceneRender->SetIncrementAngle(-10);
			break;
		case SDLK_RIGHT:
			SceneRender->SetIncrementAngle(10);
			break;
		}
	}

	// Si une touche est relachée
	else if (Event.type == SDL_KEYUP && Event.key.repeat == 0)
	{
		//Adjust the velocity
		switch (Event.key.keysym.sym)
		{
		case SDLK_UP:
			SceneRender->MoveActorForward(15);
			break;
		case SDLK_DOWN:
			SceneRender->MoveActorForward(-10);
			break;
		case SDLK_LEFT:
			SceneRender->SetIncrementAngle(-10);
			break;
		case SDLK_RIGHT:
			SceneRender->SetIncrementAngle(10);
			break;
		}
	}*/
}
