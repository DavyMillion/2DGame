#include "Client.h"
#include "SceneRender.h"
#include "Engine.h"

CGameClient::CGameClient()
{
	std::cout << "Création de l'instance du Client" << std::endl;

	AEngine = new CGameEngine;
	ASceneRender = new CGameSceneRender;
}

bool CGameClient::InitialisationSDL()
{
	if (!AEngine->InitSDL()) 
		return false;

	SDL_Window* TempWindow = AEngine->CreationFenetre();
	if (!TempWindow) 
		return false;

	SDL_Renderer* TempRenderer = AEngine->CreationRenderer(TempWindow);
	if (!TempRenderer)
		return false;

	this->SetAttributWindow(TempWindow);
	this->ASceneRender->SetAttributRenderer(TempRenderer);
	AEngine->ConfigurationRenderer(ASceneRender->GetRenderer());
	return true;
}

CGameEngine* CGameClient::GetGameEngineProperties()
{
	return AEngine;
}

CGameSceneRender* CGameClient::GetSceneRenderProperties()
{
	return ASceneRender;
}

void CGameClient::SetAttributWindow(SDL_Window * Window)
{
	this->AWindow = Window;
	return;
}


CGameClient::~CGameClient()
{
	delete AEngine;
	delete ASceneRender;
}