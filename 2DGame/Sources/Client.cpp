#include "Client.h"
#include "SceneRender.h"
#include "Engine.h"

CClient::CClient()
{
	std::cout << "Client initialised successfully !" << std::endl;
}

bool CClient::InitialisationSDL()
{
	if (!AEngine->InitSDL()) 
		return false;

	SDL_Window* TempWindow = AEngine->CreationFenetre();
	if (!TempWindow) 
		return false;

	this->SetAttributWindow(TempWindow);
	return true;
}

bool CClient::InitGameEngine()
{
	AEngine = new CGameEngine;
	if (AEngine == nullptr)
	{
		return false;
	}
	return true;
}

bool CClient::InitSceneRendering()
{
	ASceneRender = new CGameSceneRender(AEngine, AWindow);
	if (ASceneRender == nullptr)
	{
		return false;
	}

	SDL_Renderer* TempRenderer = AEngine->CreationRenderer(AWindow);
	if (!TempRenderer)
		return false;

	this->ASceneRender->SetAttributRenderer(TempRenderer);
	AEngine->ConfigurationRenderer(ASceneRender->GetRenderer(), AWindow);
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