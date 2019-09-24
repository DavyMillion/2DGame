#include "SDL_headers.h"
#include <iostream>
#include <ctime>
#include "Constantes.h"

class CGameSceneRender; // forward déclaration (C++11) dans le but de limiter les chaines de dépendances

class CClient
{
public:
	// Constructeur et Destructeur
	CClient();
	~CClient();

	// Initialisation générale de tout les composants du client
	bool InitClient();

	// Getters (accesseurs)
	CGameSceneRender* GetSceneRenderProperties() const;
	SDL_Window* GetWindow() const;
	
private:
	SDL_Window* AWindow;
	CGameSceneRender* ASceneRender;
};