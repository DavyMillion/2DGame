#include "SDL_headers.h"
#include <iostream>
#include <string>

class CGameSceneRender
{
public:
	CGameSceneRender();
	~CGameSceneRender();

	SDL_Texture* LoadTexture(const std::string);
	void UpdateRendu();

	// Getters & Setters
	SDL_Renderer* GetRenderer() const;
	SDL_Rect* GetCameraTarget() const;

	void SetAttributRenderer(SDL_Renderer*);
	bool SetTexturePlayer(std::string);
	void SetIncrementPosX(int);
	void SetIncrementPosY(int);

	void SetIncrementAngle(int);

private:
	SDL_Renderer* ARenderer;
	SDL_Rect* ACameraTarget;
	SDL_Texture* AssetPlayer;
	SDL_Point PlayerCenter;
	double angle;
};

// Cette classe va gérer la logique du rendu de la scène 2D
// -> par exemple, le rendu de la map en temps réel
// -> le mouvement du joueur