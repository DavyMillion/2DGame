#include "Client.h"
#include "SceneRender.h"
#include "Engine.h"

CClient::CClient()
{
	std::cout << "Création de l'instance du Client" << std::endl;

	AEngine = new CGameEngine;
	ASceneRender = new CGameSceneRender(AEngine, AWindow);
}

bool CClient::InitialisationSDL()
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

SDL_Window* CClient::GetWindow() const
{
	return AWindow;
}

CGameEngine* CClient::GetGameEngineProperties() const
{
	return AEngine;
}

CGameSceneRender* CClient::GetSceneRenderProperties() const
{
	return ASceneRender;
}

void CClient::SetAttributWindow(SDL_Window * Window)
{
	this->AWindow = Window;
	return;
}


CClient::~CClient()
{
	delete AEngine;
	delete ASceneRender;
}