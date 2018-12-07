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
	
	// D�sallocation de la m�moire
	~CGameSceneRender();

	// Fait le rendu de l'actor
	bool ActorRender(CActor*);

	// Met � jour le rendu de la sc�ne
	void UpdateRendu();

	// Charge les textures de tout les actors (� terme)
	bool LoadAllActorTextures(SDL_Renderer* Renderer);

	// D�place l'actor vers l'avant (la direction d�pend de son orientation)
	void MoveActorForward(int);

	// Getters & Setters
	SDL_Renderer* GetRenderer() const;
	CPlayerController* GetPlayerController() const;
	void SetAttributRenderer(SDL_Renderer*);
	void SetIncrementAngle(int);

private:
	// Le contexte de rendu
	SDL_Renderer* ARenderer;

	// Zone du niveau affich�e par le client
	SDL_Rect* Camera;

	// Notre joueur
	CPlayerController* OurPlayer;

	// L'objet Engine
	CGameEngine* AEngine;

	// Notre fen�tre courante
	SDL_Window* AWindow;
};