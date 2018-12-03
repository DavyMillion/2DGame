#include "SDL_headers.h"
#include <iostream>
#include <cmath>
#include <string>

class CActor;
class CPlayerController;
class CGameEngine;

class CGameSceneRender
{
public:
	CGameSceneRender(CGameEngine* Engine, SDL_Window* Window);
	~CGameSceneRender();

	bool ActorRender(CActor*);
	SDL_Texture* LoadTexture(const std::string);
	void UpdateRendu();

	// Getters & Setters
	SDL_Renderer* GetRenderer() const;
	CPlayerController* GetPlayerController() const;

	void SetAttributRenderer(SDL_Renderer*);
	bool SetTextureToActor(CActor* Actor, std::string);

	void MoveActorForward(int);

	void SetIncrementAngle(int);

private:
	SDL_Renderer* ARenderer;
	CPlayerController* OurPlayer;
	CGameEngine* AEngine;
	SDL_Window* AWindow;
};

// Cette classe va gérer la logique du rendu de la scène 2D
// -> par exemple, le rendu de la map en temps réel
// -> le mouvement du joueur