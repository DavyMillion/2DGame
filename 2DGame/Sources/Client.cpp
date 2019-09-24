#include "Client.h"
#include "Engine.h"
#include "SceneRender.h"

CClient::CClient()
{
	std::cout
		<< "================================================================================" << std::endl
		<< "    2DSpaceGame : another 2D Game project..." << std::endl
		<< "    It's a simple multiplayer space shooter game, dev with SDL" << std::endl
		<< "================================================================================" << std::endl
		<< std::endl;
}

bool CClient::InitClient()
{
	if (!Engine::InitSDL())
		return false;

	if (!Engine::InitSDL_Net())
		return false;

	SDL_Window* TempWindow = Engine::CreateWindow();
	if (!TempWindow) 
		return false;

	this->AWindow = TempWindow;

	SDL_Renderer* TempRenderer = Engine::CreateRenderer(AWindow);
	if (!TempRenderer)
		return false;
	
	ASceneRender = new CGameSceneRender(AWindow, TempRenderer);
	if (!ASceneRender)
		return false;

	// TODO : Demander à l'objet de le faire
	Engine::ConfigurationRenderer(ASceneRender->GetRenderer(), AWindow);

	std::cout << Engine::LogTime() << "CClient::InitClient --> Success !" << std::endl;
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


CClient::~CClient()
{
	delete ASceneRender;
}