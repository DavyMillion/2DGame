#include "SceneRender.h"

CGameSceneRender::CGameSceneRender()
{
	// Initialisation du joueur
	ACameraTarget.x = 20;
	ACameraTarget.y = 20;
	ACameraTarget.w = 202;
	ACameraTarget.h = 206;
}

CGameSceneRender::~CGameSceneRender()
{

}

void CGameSceneRender::UpdateRendu()
{
	// Clear the window and make it all bleu foncé
	SDL_RenderClear(ARenderer);

	// Change color of the "drawing tool" to white
	SDL_SetRenderDrawColor(ARenderer, 255, 255, 255, 255);

	// Render our "player"
	SDL_RenderFillRect(ARenderer, &ACameraTarget);
	// -> CCameraTarget corresponds à la cible du rendu
	// |-> c'est cette cible qu'on fera varier en temps réel pour le scrolling
	// |-> elle se devra d'être centré sur le joueur

	// Change color of the "drawing tool" to blue foncé
	SDL_SetRenderDrawColor(ARenderer, 0, 0, 20, 255);

	// Render the changes above
	SDL_RenderPresent(ARenderer);

	return;
}

SDL_Renderer * CGameSceneRender::GetRenderer()
{
	return ARenderer;
}

SDL_Rect * CGameSceneRender::GetCameraTarget()
{
	return &ACameraTarget;
}

void CGameSceneRender::SetAttributRenderer(SDL_Renderer * Renderer)
{
	this->ARenderer = Renderer;
	return;
}

void CGameSceneRender::SetIncrementPosX(int Increment)
{
	ACameraTarget.x += Increment;
}

void CGameSceneRender::SetIncrementPosY(int Increment)
{
	ACameraTarget.y += Increment;
}