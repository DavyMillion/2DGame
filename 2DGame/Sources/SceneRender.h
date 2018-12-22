#include "SDL_headers.h"
#include <iostream>

class CActor;
class CPlayerController;
class CSubTexture;
class CSubBackgroundHandler;

class CGameSceneRender
{
public:
	// Initialisation des variables
	CGameSceneRender(SDL_Window* Window);
	
	// Désallocation de la mémoire
	~CGameSceneRender();

	// Fait le rendu de l'actor
	bool ActorRender(CActor*);

	// Met à jour le rendu de la scène
	void UpdateRendu();

	// Met à jour les coordonnées de la caméra pour qu'elle suive le joueur
	void UpdateCameraTargetPosition();

	// Met à jour le fond
	void UpdateBackground();

	// Charge les textures de tout les actors (à terme)
	bool LoadAllTextures(SDL_Renderer* Renderer);

	// Getters & Setters
	SDL_Renderer* GetRenderer() const;
	CPlayerController* GetPlayerController() const;
	CSubBackgroundHandler* GetBackgroundObject();
	int GetScreenWidth() const;
	int GetScreenHeight() const;
	void SetAttributRenderer(SDL_Renderer*);

private:
	// Les dimensions du niveau
	int A_LEVEL_WIDTH;
	int A_LEVEL_HEIGHT;

	// Les dimensions de la fenêtre
	int A_SCREEN_WIDTH;
	int A_SCREEN_HEIGHT;

	// Le contexte de rendu
	SDL_Renderer* ARenderer;

	// Zone du niveau affichée par le client
	SDL_Rect* ACameraTarget;

	// Notre joueur
	CPlayerController* OurPlayer;

	// Notre instance du Background
	CSubBackgroundHandler* ABackgroundObject;

};