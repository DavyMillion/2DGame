#include "SDL_headers.h"
#include "Engine.h"
#include "Client.h"
#include "Server.h"
#include "SceneRender.h"
#include "PlayerController.h"
#include "Constantes.h"

int main(int argc, char** argv)
{
	// L'instance du client
	CClient* Client = new CClient;

	// Initialisation générale de la SDL et de ses composants
	if (!Client->InitGameEngine()) { return EXIT_ERROR; }
	if (!Client->InitialisationSDL()) { return EXIT_ERROR; }
	if (!Client->InitSceneRendering()) { return EXIT_ERROR; }

	CGameEngine* GameEngine = Client->GetGameEngineProperties();
	CGameSceneRender* SceneRender = Client->GetSceneRenderProperties();

	// Chargement des textures, cette condition sera délégué dans une fonction qui retournera un bouléen
	if (!SceneRender->LoadAllActorsTexture(SceneRender->GetRenderer())) { return EXIT_ERROR; }
	// on saisira dans cette fonction les containers à partir des dimensions de la texture

	SceneRender->GetPlayerController()->SetSpawnPositionPlayer(LEVEL_WIDTH / 2, LEVEL_HEIGHT / 2); // à modifier

	// Contrôle de la framerate délégué à l'objet GameEngine
	GameEngine->SetFramerate(GameEngine->CalculRatioFramerate(FRAME_PER_SECOND));
	GameEngine->SetTimeAtThisFrame(clock());

	int bLoop = true;

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
// réception des valeurs réseau : thread de réception charge les données dans une structure temp et
// c'est cette structure temp qui sera évalué ici.
// On évite de cette manière un éventuel problème d'accès aux valeurs des variables en écriture
// par un autre thread concurrent.

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


/* 
A FAIRE

créer des méthodes simples pour qu'à partir d'une position au milieu de (0, 0) (actor)
 calculer la position x, y du container (en inversant ducoup)
 ET DONC ARRIVER A FAIRE SPAWN LE PERSO AU MILIEU EN LUI PASSANT JUSTE LES COORDONNEES (0,0) !!!!

 Mettre en place tout le système pour le scrolling context
 Iteration n°2 des inputs events

 REFACTORISATION DU CODE

 Code réseau...

 AJOUT DU CODE POUR QUITTER LES SUBSYTEMS SDL
*/