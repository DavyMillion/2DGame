#include "PlayerController.h"
#include "SceneRender.h"

CGameSceneRender::CGameSceneRender()
{
	APlayerControlled = new CPlayerController;
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
	ActorRender(APlayerControlled);
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
	return APlayerControlled;
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

void CGameSceneRender::MoveForwardActor(int Increment) // à modifier
{
	int R = Increment;
	int xA = APlayerControlled->GetActorTextureContainer()->x;
	int yA = APlayerControlled->GetActorTextureContainer()->y;

	double theta = APlayerControlled->GetActorRelativeAngle();
	std::cout << "Angle deg : " << theta << std::endl;
	theta = (theta * M_PI) / 180; // passage en radians
	std::cout << "Angle rad : " << theta << std::endl;
	int yB = (int) yA + Increment * (-1) * cos(theta);
	int xB = (int) xA + Increment * sin(theta);

	APlayerControlled->SetActorPositionX(xB);
	APlayerControlled->SetActorPositionY(yB);
}

void CGameSceneRender::SetIncrementAngle(int p_angle)
{
	APlayerControlled->SetActorRotation(p_angle);
}

CGameSceneRender::~CGameSceneRender()
{
	delete ACameraTarget;
}