#include "Engine.h"

clock_t Engine::GetTicks()
{
	return clock();
}

clock_t Engine::GetCalculationTime(clock_t TimeAtLastFrame)
{
	clock_t TimeAtThisFrame = clock();
	clock_t CalculationTime = (TimeAtThisFrame - TimeAtLastFrame);
	if (PERFORMANCE_LOG)
		std::cout << LogTime() << "Calculationtime : " << CalculationTime << std::endl;
	return CalculationTime;
}

void Engine::SetDelay(clock_t CalculationTime, clock_t FramerateDelay)
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

clock_t Engine::TicksRatioCalculation(int framerate)
{
	clock_t DeltaTime = static_cast<clock_t> ((1000.f / framerate) * (CLOCKS_PER_SEC / 1000));
	return (DeltaTime);
}

bool Engine::InitSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << LogTime() << "Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

SDL_Window* Engine::CreateWindow()
{
	SDL_Window* Window = SDL_CreateWindow("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZE_X_FEN, SIZE_Y_FEN, SDL_WINDOW_SHOWN);

	if (Window == nullptr)
	{
		std::cout << LogTime() << "Failed to create window : " << SDL_GetError() << std::endl;
	}
	return Window;
}

SDL_Renderer* Engine::CreateRenderer(SDL_Window* Window)
{
	SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

	if (Renderer == nullptr)
	{
		std::cout << LogTime() << "Failed to create renderer : " << SDL_GetError() << std::endl;
	}
	return Renderer;
}

void Engine::ConfigurationRenderer(SDL_Renderer* Renderer, SDL_Window* Window)
{
	// Définis la taille du moteur de rendu comme étant la même que la fenêtre, à adapter avec SDL_GetWindowSize()
	int LengthX, LengthY;
	SDL_GetWindowSize(Window, &LengthX, &LengthY);

	/* Expérimental */
	/*
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.

	SDL_RenderSetLogicalSize(Renderer, LengthX * 2, LengthY * 2); //tell the renderer to work internally with this size, it will be scaled back when displayed on your screen
	*/

	SDL_RenderSetLogicalSize(Renderer, LengthX, LengthY);

	// Définis la couleur du contexte de rendu comme étant bleu foncé
	SDL_SetRenderDrawColor(Renderer, 0, 0, 20, 255);
}

std::string Engine::LogTime()
{
	// now correspond à l'heure courante
	std::time_t now = std::time(NULL);

	// on la convertis ici en heure locale
	std::tm tm_now;
	localtime_s(&tm_now, &now);

	std::stringstream ss;
	ss << std::put_time(&tm_now, "<%H:%M:%S> "); // %d/%m/%Y pour jour, minute, année

	// on tire la string du container
	return ss.str();
}

bool Engine::InitSDL_Net()
{
	if (SDLNet_Init() == -1)
	{
		std::cout << LogTime() << "Failed to initialize SDLNet : " << SDLNet_GetError() << std::endl;
		return false;
	}
	return true;
}