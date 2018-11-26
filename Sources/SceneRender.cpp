#include "SceneRender.h"

CGameSceneRender::CGameSceneRender()
{
	ACameraTarget = new SDL_Rect;
	// Initialisation du "joueur"
	ACameraTarget->x = 20;
	ACameraTarget->y = 20;
	ACameraTarget->w = 48;
	ACameraTarget->h = 70;

	PlayerCenter.x = ACameraTarget->w / 2;
	PlayerCenter.y = ACameraTarget->h / 2;
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

	// Render our "player"
	SDL_RenderFillRect(ARenderer, ACameraTarget);
	// -> CCameraTarget corresponds à la cible du rendu
	// |-> c'est cette cible qu'on fera varier en temps réel pour le scrolling
	// |-> elle se devra d'être centré sur le joueur

	// Change color of the "drawing tool" to blue foncé
	SDL_SetRenderDrawColor(ARenderer, 0, 0, 20, 255);

	SDL_RenderCopyEx(
		ARenderer,
		AssetPlayer,
		NULL,
		ACameraTarget,
		angle,
		&PlayerCenter,
		SDL_FLIP_NONE
	);

	// Render the changes above
	SDL_RenderPresent(ARenderer);

	return;
}

SDL_Renderer * CGameSceneRender::GetRenderer() const { return ARenderer; }

SDL_Rect * CGameSceneRender::GetCameraTarget() const { return ACameraTarget; }

void CGameSceneRender::SetAttributRenderer(SDL_Renderer * Renderer)
{
	this->ARenderer = Renderer;
	return;
}

bool CGameSceneRender::SetTexturePlayer(std::string path)
{
	AssetPlayer = LoadTexture(path);
	if (!AssetPlayer)
		return false;
	return true;
}

void CGameSceneRender::SetIncrementPosX(int Increment)
{
	ACameraTarget->x += Increment;
}

void CGameSceneRender::SetIncrementPosY(int Increment)
{
	ACameraTarget->y += Increment;
}

void CGameSceneRender::SetIncrementAngle(int p_angle)
{
	angle += p_angle;
}

CGameSceneRender::~CGameSceneRender()
{
	delete ACameraTarget;
}