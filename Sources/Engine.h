#include "SDL_headers.h"
#include <iostream>
#include <ctime>
#include "Constantes.h"

class CGameEngine
{
public:
	// Fonctions spécifique à l'initialisation de la SDL et du moteur de rendu
	bool InitSDL();
	SDL_Window* CreationFenetre();
	SDL_Renderer* CreationRenderer(SDL_Window* Window);
	void ConfigurationRenderer(SDL_Renderer* Renderer);

	// Fonctions spécifique au contrôle de la Framerate par le moteur de rendu
	clock_t DeltaTime(clock_t TimeAtLastFrame);
	void SetDelay(clock_t CalculationTime, clock_t FramerateDelay);
	clock_t CalculRatioFramerate(int FramePerSecondWanted);
	
	// Getters & Setters
	void SetFramerate(clock_t Ratio);
	void SetTimeAtThisFrame(clock_t Time);
	clock_t GetRatioFramerate();
	clock_t GetTimeAtCurrentFrame();
	// Fonctions spécifique au rendu de la map pour le client

private:
	long int AFrameID;
	clock_t ARatioFramerate;
	clock_t ATimeAtCurrentFrame;
};