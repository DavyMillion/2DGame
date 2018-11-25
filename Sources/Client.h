#include "SDL_headers.h"
#include <iostream>
#include <ctime>
#include "Constantes.h"

class CGameEngine; // forward d�claration (C++11) dans le but de limiter les chaines de d�pendances

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

	// Sera d�l�gu� plus-tard � la classe PlayerController
	void SetIncrementPosX(int);
	void SetIncrementPosY(int);

	
private:
	// attributs sp�cifique � la SDL
	SDL_Window* CWindow;
	SDL_Renderer* CRenderer;
	SDL_Rect CCameraTarget;
	CGameEngine* CEngine;
};