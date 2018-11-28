#include "SDL_headers.h"
#include <iostream>
#include <math.h>
#include <string>

class CActor;
class CPlayerController;

class CGameSceneRender
{
public:
	CGameSceneRender();
	~CGameSceneRender();

	bool ActorRender(CActor*);
	SDL_Texture* LoadTexture(const std::string);
	void UpdateRendu();

	// Getters & Setters
	SDL_Renderer* GetRenderer() const;
	SDL_Rect* GetCameraTarget() const;
	CPlayerController* GetPlayerController() const;

	void SetAttributRenderer(SDL_Renderer*);
	bool SetTextureToActor(CActor* Actor, std::string);

	void MoveForwardActor(int);

	void SetIncrementAngle(int);

private:
	SDL_Renderer* ARenderer;
	SDL_Rect* ACameraTarget;
	CPlayerController* APlayerControlled;
};

// Cette classe va gérer la logique du rendu de la scène 2D
// -> par exemple, le rendu de la map en temps réel
// -> le mouvement du joueur