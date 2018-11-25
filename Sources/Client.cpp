#include "Client.h"
#include "Engine.h"

CGameClient::CGameClient()
{
	std::cout << "Création de l'instance du Client" << std::endl;
	// Initialisation du joueur
	CCameraTarget.x = 20;
	CCameraTarget.y = 20;
	CCameraTarget.w = 202;
	CCameraTarget.h = 206;

	CEngine = new CGameEngine;
}

bool CGameClient::InitialisationSDL()
{
	if (!CEngine->InitSDL()) 
		return false;

	SDL_Window* TempWindow = CEngine->CreationFenetre();
	if (!TempWindow) 
		return false;

	SDL_Renderer* TempRenderer = CEngine->CreationRenderer(TempWindow);
	if (!TempRenderer)
		return false;

	this->SetAttributWindow(TempWindow);
	this->SetAttributRenderer(TempRenderer);
	CEngine->ConfigurationRenderer(CRenderer);
	return true;
}

void CGameClient::UpdateRendu()
{
	// Clear the window and make it all bleu foncé
	SDL_RenderClear(CRenderer);

	// Change color of the "drawing tool" to white
	SDL_SetRenderDrawColor(CRenderer, 255, 255, 255, 255);

	// Render our "player"
	SDL_RenderFillRect(CRenderer, &CCameraTarget);
	// -> CCameraTarget corresponds à la cible du rendu
	// |-> c'est cette cible qu'on fera varier en temps réel pour le scrolling
	// |-> elle se devra d'être centré sur le joueur

	// Change color of the "drawing tool" to blue foncé
	SDL_SetRenderDrawColor(CRenderer, 0, 0, 20, 255);

	// Render the changes above
	SDL_RenderPresent(CRenderer);
}

SDL_Renderer* CGameClient::GetRenderer()
{
	return CRenderer;
}

SDL_Rect* CGameClient::GetCameraTarget()
{
	return &CCameraTarget;
}

CGameEngine* CGameClient::GetGameEngineProperties()
{
	return CEngine;
}

void CGameClient::SetAttributWindow(SDL_Window * Window)
{
	this->CWindow = Window;
	return;
}

void CGameClient::SetAttributRenderer(SDL_Renderer * Renderer)
{
	this->CRenderer = Renderer;
	return;
}

// à bouger
void CGameClient::SetIncrementPosX(int Increment)
{
	CCameraTarget.x += Increment;
}

void CGameClient::SetIncrementPosY(int Increment)
{
	CCameraTarget.y += Increment;
}

CGameClient::~CGameClient()
{
	delete CEngine;
}