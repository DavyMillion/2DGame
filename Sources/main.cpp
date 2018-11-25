#include "SDL_headers.h"
#include "Engine.h"
#include "Client.h"
#include "Server.h"
#include "SceneRender.h"
#include "Constantes.h"

int main(int argc, char* args[])
{
	// l'instance du client
	CGameClient* Client = new CGameClient;
	CGameEngine* GameEngine = Client->GetGameEngineProperties();
	CGameSceneRender* SceneRender = Client->GetSceneRenderProperties();

	if (!Client->InitialisationSDL()) { return EXIT_ERROR; }

	int bLoop = true;

	// Contrôle de la framerate délégué à l'objet GameEngine
	GameEngine->SetFramerate(GameEngine->CalculRatioFramerate(FRAME_PER_SECOND));
	GameEngine->SetTimeAtThisFrame(clock());

	// boucle principale du jeu
	while (bLoop)
	{
		SDL_Event event;

		// boucle de traitement des inputs
		while (SDL_PollEvent(&event)) // tant qu'il y a des évènements dans la liste
		{
			if (event.type == SDL_QUIT)
				bLoop = false;
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_RIGHT:
					SceneRender->SetIncrementPosX(10);
					break;
				case SDLK_LEFT:
					SceneRender->SetIncrementPosX(-10);
					break;
					// Remeber 0,0 in SDL is left-top. So when the user pressus down, the y need to increase
				case SDLK_DOWN:
					SceneRender->SetIncrementPosY(10);
					break;
				case SDLK_UP:
					SceneRender->SetIncrementPosY(-10);
					break;
				default:
					break;
				}
			}
		}

		// (1)

		SceneRender->UpdateRendu();

		// (2)

		if (event.type != SDL_QUIT)
		{
			// on ajuste ici le delay entre le calcul de cette frame et la suivante
			Client->GetGameEngineProperties()->SetDelay(
				GameEngine->DeltaTime(GameEngine->GetTimeAtCurrentFrame()), 
				GameEngine->GetRatioFramerate()
			);
			
			GameEngine->SetTimeAtThisFrame(clock());
		}
	}
	delete Client;
	return EXIT_SUCCESS;
}


// (1)
// SniffWhatNetworkTellMe()
// réception des valeurs réseau : thread de réception charge les données dans une structure temp et
// c'est cette structure temp qui sera évalué ici.
// On évite de cette manière un éventuel problème d'accès aux valeurs des variables en écriture.

// (2)
// établir un tracking système de la position --> GameEngine (?)
/*
	std::cout << "Position X : " << CameraCalibration.x << std::endl;
	std::cout << "Position Y : " << CameraCalibration.y << std::endl;
	std::cout << "Position W : " << CameraCalibration.w << std::endl;
	std::cout << "Position H : " << CameraCalibration.h << std::endl;
*/

// ARCHITECTURE
// Classe Client (contient une instance de PlayerController et une instance de Engine)

// Classe GameEngine (contient toute les fonctions de traitement de l'image... ainsi que des fonctions de log)
// encapsulera tout le code du contrôle de la framerate
// Log full system avec Frame ID et tout