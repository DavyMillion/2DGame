#include "SDL_headers.h"
#include <iostream>
#include <ctime>
#include "Constantes.h"

class CGameEngine; // forward déclaration (C++11) dans le but de limiter les chaines de dépendances

class CGameClient
{
public:
	// Constructeur et Destructeur
	CGameClient();
	~CGameClient();

	bool InitialisationSDL();
	void UpdateRendu();

	// Getters (accesseurs)
	SDL_Renderer* GetRenderer();
	SDL_Rect* GetCameraTarget();
	CGameEngine* GetGameEngineProperties();

	// Setters (mutateurs)
	void SetAttributWindow(SDL_Window*);
	void SetAttributRenderer(SDL_Renderer*);

	// Sera délégué plus-tard à la classe PlayerController
	void SetIncrementPosX(int);
	void SetIncrementPosY(int);

	
private:
	// attributs spécifique à la SDL
	SDL_Window* CWindow;
	SDL_Renderer* CRenderer;
	SDL_Rect CCameraTarget;
	CGameEngine* CEngine;
};