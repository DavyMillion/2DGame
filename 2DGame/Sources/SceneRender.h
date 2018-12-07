#include "SDL_headers.h"
#include <iostream>
#include <cmath>

class CActor;
class CPlayerController;
class CGameEngine;
class CSubTexture;

class CGameSceneRender
{
public:
	void TESTBACKGROUND();

	// Initialisation des variables
	CGameSceneRender(CGameEngine* Engine, SDL_Window* Window);
	
	// Désallocation de la mémoire
	~CGameSceneRender();

	// Fait le rendu de l'actor
	bool ActorRender(CActor*);

	// Met à jour le rendu de la scène
	void UpdateRendu();

	// Met à jour les coordonnées de la caméra pour qu'elle suive le joueur
	void UpdateCameraTarget();

	// Charge les textures de tout les actors (à terme)
	bool LoadAllActorsTexture(SDL_Renderer* Renderer);

	// Déplace l'actor vers l'avant (la direction dépend de son orientation)
	void MoveActorForward(int);

	// Getters & Setters
	SDL_Renderer* GetRenderer() const;
	CPlayerController* GetPlayerController() const;
	void SetAttributRenderer(SDL_Renderer*);
	void SetIncrementAngle(int);

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

	// L'objet Engine
	CGameEngine* AEngine;

	// Notre fenêtre courante
	SDL_Window* AWindow;

	// TEST
	CSubTexture* Background;
};