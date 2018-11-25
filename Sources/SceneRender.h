#include "SDL_headers.h"
#include <iostream>

class CGameSceneRender
{
public:
	CGameSceneRender();
	~CGameSceneRender();

	void UpdateRendu();

	SDL_Renderer* GetRenderer();
	SDL_Rect* GetCameraTarget();

	void SetAttributRenderer(SDL_Renderer*);

	void SetIncrementPosX(int);
	void SetIncrementPosY(int);

private:
	SDL_Renderer* ARenderer;
	SDL_Rect ACameraTarget;
};

// Cette classe va gérer la logique du rendu de la scène 2D
// -> par exemple, le rendu de la map en temps réel
// -> le mouvement du joueur