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
	
	// D�sallocation de la m�moire
	~CGameSceneRender();

	// Fait le rendu de l'actor
	bool ActorRender(CActor*);

	// Met � jour le rendu de la sc�ne
	void UpdateRendu();

	// Met � jour les coordonn�es de la cam�ra pour qu'elle suive le joueur
	void UpdateCameraTarget();

	// Charge les textures de tout les actors (� terme)
	bool LoadAllActorsTexture(SDL_Renderer* Renderer);

	// D�place l'actor vers l'avant (la direction d�pend de son orientation)
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

	// Les dimensions de la fen�tre
	int A_SCREEN_WIDTH;
	int A_SCREEN_HEIGHT;

	// Le contexte de rendu
	SDL_Renderer* ARenderer;

	// Zone du niveau affich�e par le client
	SDL_Rect* ACameraTarget;

	// Notre joueur
	CPlayerController* OurPlayer;

	// L'objet Engine
	CGameEngine* AEngine;

	// Notre fen�tre courante
	SDL_Window* AWindow;

	// TEST
	CSubTexture* Background;
};