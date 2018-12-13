#include "PlayerController.h"
#include "SceneRender.h"
#include "Texture.h"
#include "Background.h"
#include "Constantes.h"

void CGameSceneRender::TESTBACKGROUND()
{
	Background = new CSubTexture;
	Background->LoadTextureFromFile(ARenderer, "./assets/textures/testBG.png");
	// ça va virer donc on s'en fout des sécurités
}

CGameSceneRender::CGameSceneRender(CGameEngine* Engine, SDL_Window* Window)
{
	// A pour effet de bord de modifier les variables A_SCREEN_WIDTH et A_SCREEN_HEIGHT
	SDL_GetWindowSize(Window, &A_SCREEN_WIDTH, &A_SCREEN_HEIGHT);

	// Allocation mémoire des objets
	OurPlayer = new CPlayerController();
	ACameraTarget = new SDL_Rect;
	ABackgroundObject = new CSubBackgroundHandler(A_SCREEN_HEIGHT, A_SCREEN_WIDTH);

	// Initialisation des variables
	AEngine = Engine;
	
	A_LEVEL_WIDTH = LEVEL_WIDTH;
	A_LEVEL_HEIGHT = LEVEL_HEIGHT;

	// Initialisation du SDL_Rect de la caméra
	*ACameraTarget = { 0, 0, A_SCREEN_WIDTH, A_SCREEN_HEIGHT };
}

bool CGameSceneRender::ActorRender(CActor* Actor)
{
	// on s'assure que le rendu de l'actor ne se fera que dans une zone bien précise
	SDL_Rect* RenderQuad = new SDL_Rect;
	RenderQuad->x = OurPlayer->GetActorTextureContainer()->x - ACameraTarget->x;
	RenderQuad->y = OurPlayer->GetActorTextureContainer()->y - ACameraTarget->y;
	RenderQuad->w = OurPlayer->GetActorTextureContainer()->w;
	RenderQuad->h = OurPlayer->GetActorTextureContainer()->h;

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

	//Background->RenderTexture(ARenderer, 0, 0, ACameraTarget);
	ABackgroundObject->RenderStars(ARenderer);

	// ICI : updateBackgroundTexturePosition

	// à terme, un container (vector ou map) contiendra toute les entités "visibles" du joueurs
	// et on affichera toutes ces entités avec un for

	ActorRender(OurPlayer);

	// Dessine tous les changements opérés sur la scène
	SDL_RenderPresent(ARenderer);

	return;
}

void CGameSceneRender::UpdateCameraTargetPosition()
{
	// Placement en x et y dans le cas général
	ACameraTarget->x = OurPlayer->GetActorAbsolutePosition()->x - A_SCREEN_WIDTH / 2;
	ACameraTarget->y = OurPlayer->GetActorAbsolutePosition()->y - A_SCREEN_HEIGHT / 2;

	// Placement de la caméra dans les cas non généraux : coin de l'écran, limite gauche, droite, haut, bas...

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

SDL_Renderer * CGameSceneRender::GetRenderer() const { return ARenderer; }

CPlayerController * CGameSceneRender::GetPlayerController() const
{
	return OurPlayer;
}

CSubBackgroundHandler * CGameSceneRender::GetBackgroundObject()
{
	return ABackgroundObject;
}

void CGameSceneRender::SetAttributRenderer(SDL_Renderer * Renderer)
{
	this->ARenderer = Renderer;
	return;
}

bool CGameSceneRender::LoadAllTextures(SDL_Renderer* Renderer)
{
	// bientot container d'actor toussa toussa ... en attendant :
	OurPlayer->SetActorTexture(Renderer, "./assets/textures/player.png");
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

	// Chargement des filtres pour l'affichage du fond
	if 
	(
		!ABackgroundObject->GetFilter01()->LoadTextureFromFile(Renderer, "./assets/textures/BG01.png") ||
		!ABackgroundObject->GetFilter02()->LoadTextureFromFile(Renderer, "./assets/textures/BG02.png") ||
		!ABackgroundObject->GetFilter03()->LoadTextureFromFile(Renderer, "./assets/textures/BG03.png") ||
		!ABackgroundObject->GetFilter04()->LoadTextureFromFile(Renderer, "./assets/textures/BG04.png") ||
		!ABackgroundObject->GetFilter05()->LoadTextureFromFile(Renderer, "./assets/textures/BG05.png")
	)
		return false;

	// test, va disparaitre
	//TESTBACKGROUND();


	return true;
}

void CGameSceneRender::MoveActorForward(int Increment) // à modifier
{
	double theta = OurPlayer->GetActorRelativeAngle();
	theta = (theta * M_PI) / 180; // passage en radians

	int xB = static_cast<int>( OurPlayer->GetActorAbsolutePosition()->x + Increment * sin(theta) );
	int yB = static_cast<int>( OurPlayer->GetActorAbsolutePosition()->y + Increment * (-1) * cos(theta) );
	
	if (xB < 0 || xB > A_LEVEL_WIDTH)
	{
		xB = OurPlayer->GetActorAbsolutePosition()->x;
	}

	if (yB < 0 || yB > A_LEVEL_HEIGHT)
	{
		yB = OurPlayer->GetActorAbsolutePosition()->y;
	}
		
	OurPlayer->SetActorPosition(xB, yB);
}

void CGameSceneRender::SetIncrementAngle(int p_angle)
{
	OurPlayer->SetActorRotation(p_angle);
}

CGameSceneRender::~CGameSceneRender()
{
	// delete...
}