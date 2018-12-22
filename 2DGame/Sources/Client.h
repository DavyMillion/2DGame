#include "SDL_headers.h"
#include <iostream>
#include <ctime>
#include "Constantes.h"

class CGameSceneRender; // forward d�claration (C++11) dans le but de limiter les chaines de d�pendances

class CClient
{
public:
	// Constructeur et Destructeur
	CClient();
	~CClient();

	bool InitClient();

	// Getters (accesseurs)
	CGameSceneRender* GetSceneRenderProperties() const;
	SDL_Window* GetWindow() const;

	// Setters (mutateurs)
	void SetAttributWindow(SDL_Window*);
	
private:
	SDL_Window* AWindow;
	CGameSceneRender* ASceneRender;
};