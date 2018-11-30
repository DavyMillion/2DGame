#include "Engine.h"

clock_t CGameEngine::GetCalculationTime(clock_t TimeAtLastFrame)
{
	clock_t TimeAtThisFrame = clock();
	clock_t CalculationTime = (TimeAtThisFrame - TimeAtLastFrame);
	if (PERFORMANCE_LOG)
	printf("Calculation time : %ld ms\n", CalculationTime);
	return CalculationTime;
}

void CGameEngine::SetDelay(clock_t CalculationTime, clock_t FramerateDelay)
{
	if (CalculationTime > FramerateDelay) // si on bouge la fenêtre par exemple
	{
		; // on ne fait rien -> SDL_Delay() ferait de la merde ici
	}
	else
	{
		SDL_Delay(FramerateDelay - CalculationTime);
	}
	return;
}

clock_t CGameEngine::CalculRatioFramerate(int framerate)
{
	clock_t DeltaTime = 1000 / framerate;
	SetDeltaTime(DeltaTime);
	return (DeltaTime);
}

void CGameEngine::SetDeltaTime(clock_t DeltaTime)
{
	ADeltaTime = DeltaTime;
	return;
}

void CGameEngine::SetFramerate(clock_t Ratio)
{
	ARatioFramerate = Ratio;
	return;
}

void CGameEngine::SetTimeAtThisFrame(clock_t Time)
{
	ATimeAtCurrentFrame = Time;
	return;
}

clock_t CGameEngine::GetRatioFramerate() const { return ARatioFramerate; }

clock_t CGameEngine::GetTimeAtCurrentFrame() const { return ATimeAtCurrentFrame; }


bool CGameEngine::InitSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

SDL_Window* CGameEngine::CreationFenetre()
{
	SDL_Window* Window = SDL_CreateWindow("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZE_X_FEN, SIZE_Y_FEN, 0);

	if (Window == nullptr)
	{
		std::cout << "Failed to create window : " << SDL_GetError() << std::endl;
	}
	return Window;
}

SDL_Renderer* CGameEngine::CreationRenderer(SDL_Window* Window)
{
	SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, 0);

	if (Renderer == nullptr)
	{
		std::cout << "Failed to create renderer : " << SDL_GetError() << std::endl;
	}
	return Renderer;
}

void CGameEngine::ConfigurationRenderer(SDL_Renderer* Renderer)
{
	// Définis la taille du moteur de rendu comme étant la même que la fenêtre
	SDL_RenderSetLogicalSize(Renderer, SIZE_X_FEN, SIZE_Y_FEN);

	// Set color of renderer to bleu foncé
	SDL_SetRenderDrawColor(Renderer, 0, 0, 20, 255);
}

