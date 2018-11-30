#include "PlayerController.h"
#include "SceneRender.h"

CGameSceneRender::CGameSceneRender(CGameEngine* Engine)
{
	OurPlayer = new CPlayerController;
	ACameraTarget = new SDL_Rect;
	AEngine = Engine;
}

bool CGameSceneRender::ActorRender(CActor* Actor)
{
	SDL_RenderCopyEx(
		ARenderer,
		Actor->GetActorTexture(),
		NULL,
		Actor->GetActorTextureContainer(),
		Actor->GetActorRelativeAngle(),
		Actor->GetActorCenterPositionInTextureContainerGrid(),
		SDL_FLIP_NONE
	);
	return true;
}

SDL_Texture* CGameSceneRender::LoadTexture(const std::string path)
{
	SDL_Texture* Texture = IMG_LoadTexture(ARenderer, path.c_str());
	if (Texture == nullptr)
	{
		std::cout << "Failed to load the following texture : " << path << "\n" << SDL_GetError() << std::endl;
		return nullptr;
	}
	return Texture;
}

void CGameSceneRender::UpdateRendu()
{
	// Clear the window and make it all bleu foncé
	SDL_RenderClear(ARenderer);

	// Change color of the "drawing tool" to white
	SDL_SetRenderDrawColor(ARenderer, 0, 0, 20, 255);

	// à terme, un container contiendra toute les entités "visibles" du joueurs
	// et on affichera toutes ces entités avec un for
	ActorRender(OurPlayer);
	/*
	// Render our "player"
	SDL_RenderFillRect(ARenderer, ACameraTarget);
	// -> CCameraTarget corresponds à la cible du rendu
	// |-> c'est cette cible qu'on fera varier en temps réel pour le scrolling
	// |-> elle se devra d'être centré sur le joueur
	*/

	// Render the changes above
	SDL_RenderPresent(ARenderer);

	return;
}

SDL_Renderer * CGameSceneRender::GetRenderer() const { return ARenderer; }

SDL_Rect * CGameSceneRender::GetCameraTarget() const { return ACameraTarget; }

CPlayerController * CGameSceneRender::GetPlayerController() const
{
	return OurPlayer;
}

void CGameSceneRender::SetAttributRenderer(SDL_Renderer * Renderer)
{
	this->ARenderer = Renderer;
	return;
}

bool CGameSceneRender::SetTextureToActor(CActor * Actor, std::string path)
{
	Actor->SetActorTexture(LoadTexture(path));
	if (!Actor->GetActorTexture())
		return false;
	return true;
}

void CGameSceneRender::MoveActorForward(int Increment) // à modifier
{
	double theta = OurPlayer->GetActorRelativeAngle();
	theta = (theta * M_PI) / 180; // passage en radians

	int xB = static_cast<int>( OurPlayer->GetActorAbsolutePosition()->x + Increment * sin(theta) );
	int yB = static_cast<int>( OurPlayer->GetActorAbsolutePosition()->y + Increment * (-1) * cos(theta) );
	
	OurPlayer->SetActorPositionX(xB);
	OurPlayer->SetActorPositionY(yB);
}

void CGameSceneRender::SetIncrementAngle(int p_angle)
{
	OurPlayer->SetActorRotation(p_angle);
}

CGameSceneRender::~CGameSceneRender()
{
	delete ACameraTarget;
}