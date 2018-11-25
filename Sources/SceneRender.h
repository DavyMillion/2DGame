#include "SDL_headers.h"
#include <iostream>

class CGameSceneRender
{
public:
	CGameSceneRender();
	~CGameSceneRender();

	void UpdateRendu();


	// Getters & Setters
	SDL_Renderer* GetRenderer() const;
	SDL_Rect* GetCameraTarget() const;

	void SetAttributRenderer(SDL_Renderer*);
	void SetIncrementPosX(int);
	void SetIncrementPosY(int);

private:
	SDL_Renderer* ARenderer;
	SDL_Rect* ACameraTarget;
};

// Cette classe va g�rer la logique du rendu de la sc�ne 2D
// -> par exemple, le rendu de la map en temps r�el
// -> le mouvement du joueur