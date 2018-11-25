#include "SDL_headers.h"
#include <iostream>
#include <ctime>
#include "Constantes.h"

class CGameEngine; // forward déclaration (C++11) dans le but de limiter les chaines de dépendances
class CGameSceneRender;

class CGameClient
{
public:
	// Constructeur et Destructeur
	CGameClient();
	~CGameClient();

	bool InitialisationSDL();

	// Getters (accesseurs)
	CGameEngine* GetGameEngineProperties();
	CGameSceneRender* GetSceneRenderProperties();

	// Setters (mutateurs)
	void SetAttributWindow(SDL_Window*);
	
private:

	SDL_Window* AWindow;
	CGameEngine* AEngine;
	CGameSceneRender* ASceneRender;
};