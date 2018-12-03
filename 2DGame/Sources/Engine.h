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
	clock_t GetRatioFramerate() const;
	clock_t GetTimeAtCurrentFrame() const;
	clock_t GetCalculationTime(clock_t TimeAtLastFrame);
	clock_t CalculRatioFramerate(int FramePerSecondWanted);
	void SetDeltaTime(clock_t);
	void SetDelay(clock_t CalculationTime, clock_t FramerateDelay);
	void SetFramerate(clock_t Ratio);
	void SetTimeAtThisFrame(clock_t Time);

private:
	long int AFrameID;
	clock_t ARatioFramerate;
	clock_t ATimeAtCurrentFrame;
	clock_t ADeltaTime;
};