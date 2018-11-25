#include "SDL_headers.h"
#include <iostream>
#include <ctime>
#include "Constantes.h"

class CGameEngine
{
public:
	// Fonctions sp�cifique � l'initialisation de la SDL et du moteur de rendu
	bool InitSDL();
	SDL_Window* CreationFenetre();
	SDL_Renderer* CreationRenderer(SDL_Window* Window);
	void ConfigurationRenderer(SDL_Renderer* Renderer);

	// Fonctions sp�cifique au contr�le de la Framerate par le moteur de rendu
	clock_t DeltaTime(clock_t TimeAtLastFrame);
	void SetDelay(clock_t CalculationTime, clock_t FramerateDelay);
	clock_t SetFramerate(int FramePerSecondWanted);

	// Fonctions sp�cifique au rendu de la map pour le client

private:
	long int FrameID;

};