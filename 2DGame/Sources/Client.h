#include "SDL_headers.h"
#include <iostream>
#include <ctime>
#include "Constantes.h"

class CGameEngine; // forward déclaration (C++11) dans le but de limiter les chaines de dépendances
class CGameSceneRender;

class CClient
{
public:
	// Constructeur et Destructeur
	CClient();
	~CClient();

	bool InitialisationSDL();

	// Getters (accesseurs)
	CGameEngine* GetGameEngineProperties() const;
	CGameSceneRender* GetSceneRenderProperties() const;
	SDL_Window* GetWindow() const;

	// Setters (mutateurs)
	void SetAttributWindow(SDL_Window*);
	
private:
	SDL_Window* AWindow;
	CGameEngine* AEngine;
	CGameSceneRender* ASceneRender;
};