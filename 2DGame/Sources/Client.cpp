#include "Client.h"
#include "Engine.h"
#include "SceneRender.h"

CClient::CClient()
{
	std::cout << "Client initialised successfully !" << std::endl;
}

bool CClient::InitClient()
{
	if (!Engine::InitSDL())
		return false;

	SDL_Window* TempWindow = Engine::CreationFenetre();
	if (!TempWindow) 
		return false;

	this->SetAttributWindow(TempWindow);
	
	ASceneRender = new CGameSceneRender(AWindow);
	if (ASceneRender == nullptr)
	{
		return false;
	}

	SDL_Renderer* TempRenderer = Engine::CreationRenderer(AWindow);
	if (!TempRenderer)
		return false;

	this->ASceneRender->SetAttributRenderer(TempRenderer);
	Engine::ConfigurationRenderer(ASceneRender->GetRenderer(), AWindow);

	return true;
}

SDL_Window* CClient::GetWindow() const
{
	return AWindow;
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
	delete ASceneRender;
}