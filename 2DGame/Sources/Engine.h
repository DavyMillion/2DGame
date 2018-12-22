#ifndef ENGINE_H
	#define ENGINE_H

	#include "SDL_headers.h"
	#include <iostream>
	#include <ctime>
	#include "Constantes.h"

	namespace Engine
	{
		// Fonctions spécifique à l'initialisation de la SDL et du moteur de rendu
		bool InitSDL();
		SDL_Window* CreationFenetre();
		SDL_Renderer* CreationRenderer(SDL_Window* Window);
		void ConfigurationRenderer(SDL_Renderer* Renderer, SDL_Window* Window);

		// Fonctions spécifique au contrôle de la Framerate par le moteur de rendu
		clock_t GetTicks();
		clock_t GetCalculationTime(clock_t TimeAtLastFrame);
		clock_t TicksRatioCalculation(int FramePerSecondWanted);

		void SetDelay(clock_t CalculationTime, clock_t FramerateDelay);
	};

#endif