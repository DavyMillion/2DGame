#include "PlayerController.h"
#include "SceneRender.h"


CGameSceneRender::CGameSceneRender()
{
	AMainPlayer = new CPlayerController;
	ACameraTarget = new SDL_Rect;
}

bool CGameSceneRender::ActorRender(CActor* Actor)
{
	SDL_RenderCopyEx(
		ARenderer,
		Actor->GetActorTexture(),
		NULL,
		Actor->GetActorTextureContainer(),
		Actor->GetActorRelativeAngle(),
		Actor->GetActorPosition(),
		SDL_FLIP_NONE
	);
	return true;
}

SDL_Texture* CGameSceneRender::LoadTexture(const std::string path)
{
	// Load image as SDL_Surface

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

	ActorRender(AMainPlayer);
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
	return AMainPlayer;
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

void CGameSceneRender::SetIncrementPosY(int Increment)
{
	AMainPlayer->SetActorPositionX(AMainPlayer->GetActorPosition()->x + Increment);
	AMainPlayer->SetActorPositionY(AMainPlayer->GetActorPosition()->y + Increment);
}

void CGameSceneRender::SetIncrementAngle(int p_angle)
{
	AMainPlayer->SetActorRotation(p_angle);
}

CGameSceneRender::~CGameSceneRender()
{
	delete ACameraTarget;
}