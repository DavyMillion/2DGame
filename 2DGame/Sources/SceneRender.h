#include "SDL_headers.h"
#include <iostream>
#include <cmath>

class CActor;
class CPlayerController;
class CGameEngine;

class CGameSceneRender
{
public:
	// Initialisation des variables
	CGameSceneRender(CGameEngine* Engine, SDL_Window* Window);
	
	// Désallocation de la mémoire
	~CGameSceneRender();

	// Fait le rendu de l'actor
	bool ActorRender(CActor*);

	// Met à jour le rendu de la scène
	void UpdateRendu();

	// Charge les textures de tout les actors (à terme)
	bool LoadAllActorTextures(SDL_Renderer* Renderer);

	// Déplace l'actor vers l'avant (la direction dépend de son orientation)
	void MoveActorForward(int);

	// Getters & Setters
	SDL_Renderer* GetRenderer() const;
	CPlayerController* GetPlayerController() const;
	void SetAttributRenderer(SDL_Renderer*);
	void SetIncrementAngle(int);

private:
	// Le contexte de rendu
	SDL_Renderer* ARenderer;

	// Zone du niveau affichée par le client
	SDL_Rect* Camera;

	// Notre joueur
	CPlayerController* OurPlayer;

	// L'objet Engine
	CGameEngine* AEngine;

	// Notre fenêtre courante
	SDL_Window* AWindow;
};