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

	// Initialisation g�n�rale de la SDL et de ses composants
	if (!Client->InitGameEngine()) { return EXIT_ERROR; }
	if (!Client->InitialisationSDL()) { return EXIT_ERROR; }
	if (!Client->InitSceneRendering()) { return EXIT_ERROR; }

	// Raccourcis d�veloppement
	CGameEngine* GameEngine = Client->GetGameEngineProperties();
	CGameSceneRender* SceneRender = Client->GetSceneRenderProperties();

	// Chargement des textures
	if (!SceneRender->LoadAllActorsTexture(SceneRender->GetRenderer())) { return EXIT_ERROR; }
	// on saisira dans cette fonction les containers � partir des dimensions de la texture

	SceneRender->GetPlayerController()->SetSpawnPositionPlayer(LEVEL_WIDTH / 2, LEVEL_HEIGHT / 2); // � modifier

	// Contr�le de la framerate d�l�gu� � l'objet GameEngine
	GameEngine->SetFramerate(GameEngine->CalculRatioFramerate(FRAME_PER_SECOND));
	GameEngine->SetTimeAtThisFrame(clock());

	int bLoop = true;

	// boucle principale du jeu
	while (bLoop)
	{
		SDL_Event Event;

		// boucle de traitement des inputs
		while (SDL_PollEvent(&Event)) // tant qu'il y a des �v�nements dans la liste
		{
			// si l'�v�nement SDL_QUIT a �t� d�clench�
			if (Event.type == SDL_QUIT)
			{
				bLoop = false;
			}
			
			// R�ception et traitement des �v�nements
			SceneRender->GetPlayerController()->EventProcessing(Event, SceneRender);
		}

		// DANS LE FUTUR, ON APPELERA UNE FONCTION QUI METTRA A JOUR TOUTES LES POSITIONS d'un coup
		// On met � jour la position de notre joueur � partir des inputs trait�s
		//....

		// On met � jour la position de la cam�ra
		SceneRender->UpdateCameraTargetPosition();

		// (1)

		// On met � jour le rendu de la sc�ne
		SceneRender->UpdateRendu();
		
		// (2)

		if (Event.type != SDL_QUIT)
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


/* 
A FAIRE

cr�er des m�thodes simples pour qu'� partir d'une position au milieu de (0, 0) (actor)
 calculer la position x, y du container (en inversant ducoup)
 ET DONC ARRIVER A FAIRE SPAWN LE PERSO AU MILIEU EN LUI PASSANT JUSTE LES COORDONNEES (0,0) !!!!

 Mettre en place tout le syst�me pour le scrolling context
 Iteration n�2 des inputs events

 REFACTORISATION DU CODE

 Code r�seau...

 AJOUT DU CODE POUR QUITTER LES SUBSYTEMS SDL
*/