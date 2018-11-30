#include "SDL_headers.h"
#include "Engine.h"
#include "Client.h"
#include "Server.h"
#include "SceneRender.h"
#include "PlayerController.h"
#include "Constantes.h"

int main(int argc, char* args[])
{
	// l'instance du client
	CClient* Client = new CClient;
	CGameEngine* GameEngine = Client->GetGameEngineProperties();
	CGameSceneRender* SceneRender = Client->GetSceneRenderProperties();


	if (!Client->InitialisationSDL()) { return EXIT_ERROR; }

	// Chargement des textures
	if (!SceneRender->SetTextureToActor(SceneRender->GetPlayerController(), "./assets/textures/player.png")) { return EXIT_ERROR; }

	// Contr�le de la framerate d�l�gu� � l'objet GameEngine
	GameEngine->SetFramerate(GameEngine->CalculRatioFramerate(FRAME_PER_SECOND));
	GameEngine->SetTimeAtThisFrame(clock());

	int bLoop = true;

	// boucle principale du jeu
	while (bLoop)
	{
		SDL_Event event;

		// boucle de traitement des inputs
		while (SDL_PollEvent(&event)) // tant qu'il y a des �v�nements dans la liste
		{
			if (event.type == SDL_QUIT)
				bLoop = false;
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_RIGHT:
					SceneRender->SetIncrementAngle(10);
					break;
				case SDLK_LEFT:
					SceneRender->SetIncrementAngle(-10);
					break;
				case SDLK_DOWN:
					SceneRender->MoveActorForward(-10);
					break;
				case SDLK_UP:
					SceneRender->MoveActorForward(10);
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
				GameEngine->GetCalculationTime(GameEngine->GetTimeAtCurrentFrame()), 
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
// r�ception des valeurs r�seau : thread de r�ception charge les donn�es dans une structure temp et
// c'est cette structure temp qui sera �valu� ici.
// On �vite de cette mani�re un �ventuel probl�me d'acc�s aux valeurs des variables en �criture
// par un autre thread concurrent.

// (2)
// �tablir un tracking syst�me de la position --> GameEngine (?)
/*
	std::cout << "Position X : " << CameraCalibration.x << std::endl;
	std::cout << "Position Y : " << CameraCalibration.y << std::endl;
	std::cout << "Position W : " << CameraCalibration.w << std::endl;
	std::cout << "Position H : " << CameraCalibration.h << std::endl;
*/

// ARCHITECTURE
// Classe Client (contient une instance de PlayerController et une instance de Engine)

// Classe GameEngine (contient toute les fonctions de traitement de l'image... ainsi que des fonctions de log)
// encapsulera tout le code du contr�le de la framerate
// Log full system avec Frame ID et tout