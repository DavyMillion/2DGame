#include "PlayerController.h"
#include "SceneRender.h"
#include "Texture.h"
#include "Constantes.h"

void CGameSceneRender::TESTBACKGROUND()
{
	Background = new CSubTexture;
	Background->LoadTextureFromFile(ARenderer, "./assets/textures/testBG.png");
	if (!Background) std::cout << "ifou " << std::endl;
}

CGameSceneRender::CGameSceneRender(CGameEngine* Engine, SDL_Window* Window)
{
	// Allocation mémoire des objets
	OurPlayer = new CPlayerController();
	ACameraTarget = new SDL_Rect;
	
	// Initialisation des variables
	AWindow = Window;
	AEngine = Engine;
	
	A_LEVEL_WIDTH = LEVEL_WIDTH;
	A_LEVEL_HEIGHT = LEVEL_HEIGHT;

	// A pour effet de bord de modifier les variables A_SCREEN_WIDTH et A_SCREEN_HEIGHT
	SDL_GetWindowSize(Window, &A_SCREEN_WIDTH, &A_SCREEN_HEIGHT);

	// Initialisation du SDL_Rect de la caméra
	*ACameraTarget = { 0, 0, A_SCREEN_WIDTH, A_SCREEN_HEIGHT };
}

bool CGameSceneRender::ActorRender(CActor* Actor)
{
	SDL_Rect RenderQuad = { OurPlayer->GetActorTextureContainer()->x - ACameraTarget->x,
		OurPlayer->GetActorTextureContainer()->y - ACameraTarget->y,
		OurPlayer->GetActorTextureContainer()->w,
		OurPlayer->GetActorTextureContainer()->h };

	SDL_RenderCopyEx(
		ARenderer,
		Actor->GetActorTextureObject()->GetSDLTexture(),
		NULL,
		&RenderQuad,
		Actor->GetActorRelativeAngle(),
		Actor->GetActorCenterPositionInContainerGrid(),
		SDL_FLIP_NONE
	);	

	/*
	SDL_RenderCopyEx(
		ARenderer,
		Actor->GetActorTextureObject()->GetSDLTexture(),
		NULL,
		Actor->GetActorTextureContainer(),
		Actor->GetActorRelativeAngle(),
		Actor->GetActorCenterPositionInContainerGrid(),
		SDL_FLIP_NONE
	);*/
	return true;
}

void CGameSceneRender::UpdateRendu()
{
	// Clear the window and make it all bleu foncé
	SDL_SetRenderDrawColor(ARenderer, 0, 0, 20, 255);
	SDL_RenderClear(ARenderer);

	SDL_SetRenderDrawColor(ARenderer, 255, 255, 255, 255);
	UpdateCameraTarget();

	Background->RenderTexture(ARenderer, 0, 0, ACameraTarget);

	// ICI : updateBackgroundTexturePosition

	// à terme, un container (vector ou map) contiendra toute les entités "visibles" du joueurs
	// et on affichera toutes ces entités avec un for

	ActorRender(OurPlayer);
	
	// Render the changes above
	SDL_RenderPresent(ARenderer);

	return;
}

void CGameSceneRender::UpdateCameraTarget()
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

void CGameSceneRender::SetAttributRenderer(SDL_Renderer * Renderer)
{
	this->ARenderer = Renderer;
	return;
}

bool CGameSceneRender::LoadAllActorsTexture(SDL_Renderer* Renderer)
{
	// bientot container d'actor toussa toussa ... en attendant :
	OurPlayer->SetActorTexture(Renderer, "./assets/textures/player.png");
	if (!OurPlayer->GetActorTextureObject()->GetSDLTexture())
		return false;
	TESTBACKGROUND();
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

}