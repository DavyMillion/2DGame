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
	
	// D�sallocation de la m�moire
	~CGameSceneRender();

	// Fait le rendu de l'actor
	bool ActorRender(CActor*);

	// Met � jour le rendu de la sc�ne
	void UpdateRendu();

	// Met � jour les coordonn�es de la cam�ra pour qu'elle suive le joueur
	void UpdateCameraTargetPosition();

	// Met � jour le fond
	void UpdateBackground();

	// Charge les textures de tout les actors (� terme)
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

	// Les dimensions de la fen�tre
	int A_SCREEN_WIDTH;
	int A_SCREEN_HEIGHT;

	// Le contexte de rendu
	SDL_Renderer* ARenderer;

	// Zone du niveau affich�e par le client
	SDL_Rect* ACameraTarget;

	// Notre joueur
	CPlayerController* OurPlayer;

	// Notre instance du Background
	CSubBackgroundHandler* ABackgroundObject;

};