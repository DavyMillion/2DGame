#include "PlayerController.h"
#include "SceneRender.h"
#include "Texture.h"

CGameSceneRender::CGameSceneRender(CGameEngine* Engine, SDL_Window* Window)
{
	OurPlayer = new CPlayerController();
	AWindow = Window;
	AEngine = Engine;
}

bool CGameSceneRender::ActorRender(CActor* Actor)
{
	SDL_RenderCopyEx(
		ARenderer,
		Actor->GetActorTextureObject()->GetSDLTexture(),
		NULL,
		Actor->GetActorTextureContainer(),
		Actor->GetActorRelativeAngle(),
		Actor->GetActorCenterPositionInContainerGrid(),
		SDL_FLIP_NONE
	);
	return true;
}

void CGameSceneRender::UpdateRendu()
{
	// Clear the window and make it all bleu foncé
	SDL_SetRenderDrawColor(ARenderer, 0, 0, 20, 255);
	SDL_RenderClear(ARenderer);

	// Change color of the "drawing tool" to white
	SDL_SetRenderDrawColor(ARenderer, 255, 0, 0, 0);

	// ICI : updateBackgroundTexturePosition

	// à terme, un container (vector ou map) contiendra toute les entités "visibles" du joueurs
	// et on affichera toutes ces entités avec un for
	SDL_RenderFillRect(ARenderer, GetPlayerController()->GetActorTextureContainer()); // Affichage du container
	ActorRender(OurPlayer);
	
	
	// Render the changes above
	SDL_RenderPresent(ARenderer);

	return;
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

bool CGameSceneRender::LoadAllActorTextures(SDL_Renderer* Renderer)
{
	// bientot container d'actor toussa toussa ... en attendant :
	OurPlayer->SetActorTexture(Renderer, "./assets/textures/player.png");
	if (!OurPlayer->GetActorTextureObject()->GetSDLTexture())
		return false;
	return true;
}

void CGameSceneRender::MoveActorForward(int Increment) // à modifier
{
	double theta = OurPlayer->GetActorRelativeAngle();
	theta = (theta * M_PI) / 180; // passage en radians

	int xB = static_cast<int>( OurPlayer->GetActorAbsolutePosition()->x + Increment * sin(theta) );
	int yB = static_cast<int>( OurPlayer->GetActorAbsolutePosition()->y + Increment * (-1) * cos(theta) );
	
	OurPlayer->SetActorPosition(xB, yB);
}

void CGameSceneRender::SetIncrementAngle(int p_angle)
{
	OurPlayer->SetActorRotation(p_angle);
}

CGameSceneRender::~CGameSceneRender()
{

}