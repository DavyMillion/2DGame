#include "Engine.h"

namespace Engine
{
	clock_t GetTicks()
	{
		return clock();
	}

	clock_t GetCalculationTime(clock_t TimeAtLastFrame)
	{
		clock_t TimeAtThisFrame = clock();
		clock_t CalculationTime = (TimeAtThisFrame - TimeAtLastFrame);
		if (PERFORMANCE_LOG)
			std::cout << "Calculationtime : " << CalculationTime << std::endl;
		return CalculationTime;
	}

	void SetDelay(clock_t CalculationTime, clock_t FramerateDelay)
	{
		if (CalculationTime > FramerateDelay) // si on bouge la fenêtre par exemple
		{
			; // on ne fait rien -> SDL_Delay() ferait de la merde ici
		}
		else
		{
			SDL_Delay((FramerateDelay - CalculationTime)*CLOCKS_PER_SEC / 1000);
		}
		return;
	}

	clock_t TicksRatioCalculation(int framerate)
	{
		clock_t DeltaTime = static_cast<clock_t> ((1000.f / framerate) * (CLOCKS_PER_SEC / 1000));
		return (DeltaTime);
	}

	bool InitSDL()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		{
			std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
			return false;
		}
		return true;
	}

	SDL_Window* CreationFenetre()
	{
		SDL_Window* Window = SDL_CreateWindow("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZE_X_FEN, SIZE_Y_FEN, SDL_WINDOW_SHOWN);

		if (Window == nullptr)
		{
			std::cout << "Failed to create window : " << SDL_GetError() << std::endl;
		}
		return Window;
	}

	SDL_Renderer* CreationRenderer(SDL_Window* Window)
	{
		SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

		if (Renderer == nullptr)
		{
			std::cout << "Failed to create renderer : " << SDL_GetError() << std::endl;
		}
		return Renderer;
	}

	void ConfigurationRenderer(SDL_Renderer* Renderer, SDL_Window* Window)
	{
		// Définis la taille du moteur de rendu comme étant la même que la fenêtre, à adapter avec SDL_GetWindowSize()
		int LengthX, LengthY;
		SDL_GetWindowSize(Window, &LengthX, &LengthY);
		SDL_RenderSetLogicalSize(Renderer, LengthX, LengthY);

		// Définis la couleur du contexte de rendu comme étant bleu foncé
		SDL_SetRenderDrawColor(Renderer, 0, 0, 20, 255);
	}
}