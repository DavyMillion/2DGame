#include "PlayerController.h"
#include "SceneRender.h"
#include "Texture.h"
#include "Background.h"
#include "Constantes.h"

CGameSceneRender::CGameSceneRender(SDL_Window* Window, SDL_Renderer* Renderer)
{
	// A pour effet de bord de modifier les variables A_SCREEN_WIDTH et A_SCREEN_HEIGHT
	SDL_GetWindowSize(Window, &A_SCREEN_WIDTH, &A_SCREEN_HEIGHT);

	// Allocation mémoire des objets
	OurPlayer = new CPlayerController();

	Player3 = new CPlayerController();

	ACameraTarget = new SDL_Rect;
	ABackgroundObject = new CSubBackgroundHandler(A_SCREEN_HEIGHT, A_SCREEN_WIDTH);
	
	A_LEVEL_WIDTH = LEVEL_WIDTH;
	A_LEVEL_HEIGHT = LEVEL_HEIGHT;

	// Initialisation du SDL_Rect de la caméra
	*ACameraTarget = { 0, 0, A_SCREEN_WIDTH, A_SCREEN_HEIGHT };

	this->ARenderer = Renderer;
}

bool CGameSceneRender::ActorRender(CActor* Actor)
{
	// on s'assure que le rendu de l'actor ne se fera que dans une zone bien précise
	SDL_Rect* RenderQuad = new SDL_Rect;
	RenderQuad->x = Actor->GetActorTextureContainer()->x - ACameraTarget->x;
	RenderQuad->y = Actor->GetActorTextureContainer()->y - ACameraTarget->y;
	RenderQuad->w = Actor->GetActorTextureContainer()->w;
	RenderQuad->h = Actor->GetActorTextureContainer()->h;

	if (SEE_ACTOR_TEXTURE_CONTAINER)
	{
		SDL_SetRenderDrawColor(ARenderer, 0, 255, 0, 0);
		SDL_RenderFillRect(ARenderer, RenderQuad);
	}

	SDL_RenderCopyEx(
		ARenderer,
		Actor->GetActorTextureObject()->GetSDLTexture(),
		NULL,
		RenderQuad,
		Actor->GetActorRelativeAngle(),
		Actor->GetActorCenterPositionInContainerGrid(),
		SDL_FLIP_NONE
	);	

	delete RenderQuad;
	return true;
}

void CGameSceneRender::UpdateRendu()
{
	SDL_SetRenderDrawColor(ARenderer, 0, 0, 20, 255);
	SDL_RenderClear(ARenderer);

	ABackgroundObject->RenderStars(ARenderer);
	//Background->RenderTexture(ARenderer, 0, 0, ACameraTarget);

	// à terme, un container (vector ou map) contiendra toutes les entités "visibles" du joueurs
	// et on affichera toutes ces entités avec un for


	ActorRender(Player3);
	ActorRender(OurPlayer);

	std::cout << "pos player 1 x : " << OurPlayer->GetActorAbsolutePosition()->x << "\n"
		<< "pos player 3 x : " << Player3->GetActorAbsolutePosition()->x << "\n";

	/*
	std::cout << "pos player 1 absolu x : " << OurPlayer->GetActorAbsolutePosition()->x << "\n"
		<< "pos player 1 x : " << OurPlayer->GetActorTextureContainer()->x - ACameraTarget->x << "\n"
		<< "pos player 3 absolu x : " << Player3->GetActorAbsolutePosition()->x << "\n" <<
		"pos player 3 x : " << Player3->GetActorTextureContainer()->x - ACameraTarget->x << "\n";
		*/


	// Dessine tous les changements opérés sur la scène
	SDL_RenderPresent(ARenderer);

	return;
}

void CGameSceneRender::UpdateCameraTargetPosition()
{
	// Placement en x et y dans le cas général
	ACameraTarget->x = OurPlayer->GetActorAbsolutePosition()->x - A_SCREEN_WIDTH / 2;
	ACameraTarget->y = OurPlayer->GetActorAbsolutePosition()->y - A_SCREEN_HEIGHT / 2;

	/* Placement de la caméra dans les cas non généraux : 
	   coin de l'écran, limite gauche, droite, haut et bas */

	if (ACameraTarget->x < 0)
	{
		ACameraTarget->x = 0;
	}

	if (ACameraTarget->y < 0)
	{
		ACameraTarget->y = 0;
	}

	if (ACameraTarget->x + ACameraTarget->w > A_LEVEL_WIDTH)
	{
		ACameraTarget->x = A_LEVEL_WIDTH - ACameraTarget->w;
	}

	if (ACameraTarget->y + ACameraTarget->h > A_LEVEL_HEIGHT)
	{
		ACameraTarget->y = A_LEVEL_HEIGHT - ACameraTarget->h;
	}
}

void CGameSceneRender::UpdateBackground()
{
	ABackgroundObject->UpdateBackgroundArrangement(OurPlayer);
}

SDL_Renderer * CGameSceneRender::GetRenderer() const { return ARenderer; }

CPlayerController * CGameSceneRender::GetPlayerController() const
{
	return OurPlayer;
}

CSubBackgroundHandler * CGameSceneRender::GetBackgroundObject()
{
	return ABackgroundObject;
}

int CGameSceneRender::GetScreenWidth() const
{
	return A_LEVEL_WIDTH;
}

int CGameSceneRender::GetScreenHeight() const
{
	return A_LEVEL_HEIGHT;
}

void CGameSceneRender::SetAttributRenderer(SDL_Renderer * Renderer)
{
	this->ARenderer = Renderer;
	return;
}

bool CGameSceneRender::LoadAllTextures()
{
	// bientot container d'actor toussa toussa ... en attendant :
	OurPlayer->SetActorTexture(ARenderer, "./assets/textures/player.png");
	if (!OurPlayer->GetActorTextureObject()->GetSDLTexture())
		return false;
	
	int Ratio = 2;

	// Création du Container au dimensions de la texture
	OurPlayer->SetActorTextureContainer(
		0, 
		0, 
		OurPlayer->GetActorTextureObject()->GetWidthTexture() * Ratio, 
		OurPlayer->GetActorTextureObject()->GetHeightTexture() * Ratio
	);

	/* MODIFS */
	Player3->SetActorTexture(ARenderer, "./assets/textures/player.png");
	if (!OurPlayer->GetActorTextureObject()->GetSDLTexture())
		return false;

	// TODO : SetActorTextureContainer -> effet de bord : modification de la position si elle a été précédemment inséré
	// problème avec Player3
	/* MODIFS */
	Player3->SetActorTextureContainer(
		0,
		0,
		OurPlayer->GetActorTextureObject()->GetWidthTexture() * Ratio,
		OurPlayer->GetActorTextureObject()->GetHeightTexture() * Ratio
	);

	// Chargement des filtres pour l'affichage du fond
	if 
	(
		!ABackgroundObject->GetFilter01()->LoadTextureFromFile(ARenderer, "./assets/textures/BG01.png") ||
		!ABackgroundObject->GetFilter02()->LoadTextureFromFile(ARenderer, "./assets/textures/BG02.png") ||
		!ABackgroundObject->GetFilter03()->LoadTextureFromFile(ARenderer, "./assets/textures/BG03.png") ||
		!ABackgroundObject->GetFilter04()->LoadTextureFromFile(ARenderer, "./assets/textures/BG04.png") ||
		!ABackgroundObject->GetFilter05()->LoadTextureFromFile(ARenderer, "./assets/textures/BG05.png")
	)
		return false;

	Player3->SetActorPosition(LEVEL_WIDTH / 2, LEVEL_HEIGHT / 2);

	return true;
}

CGameSceneRender::~CGameSceneRender()
{
	// delete...
}