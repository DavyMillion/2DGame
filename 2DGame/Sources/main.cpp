#include "SDL_headers.h"
#include "Client.h"
#include "Engine.h"
#include "Input.h"
#include "Server.h"
#include "SceneRender.h"
#include "Background.h"
#include "PlayerController.h"
#include "Constantes.h"


int main(int argc, char** argv)
{
	// L'instance du client
	CClient* Client = new CClient;

	// Initialisation du Client et de la SDL
	if (!Client->InitClient()) { return EXIT_ERROR; }

	// On utilisera ces variables pour plus de clarté
	CGameSceneRender* SceneObject = Client->GetSceneRenderProperties();
	CPlayerController* OurPlayer = SceneObject->GetPlayerController();
	CSubInputHandler* InputHandler = OurPlayer->GetInputHandler();

	// Chargement des textures
	if (!SceneObject->LoadAllTextures()) { return EXIT_ERROR; }
	
	// à terme, le serveur décidera du point de spawn
	OurPlayer->SetSpawnPositionPlayer(LEVEL_WIDTH / 2, LEVEL_HEIGHT / 2);

	// Initialisation des entités composant le fond
	SceneObject->GetBackgroundObject()->InitBackground();
	
	// Contrôle de la framerate délégué à l'objet GameEngine
	clock_t Framerate = Engine::TicksRatioCalculation(FRAME_PER_SECOND);
	clock_t CurrentFrameTime = Engine::GetTicks();

	bool bLoop = true;

	// Boucle principale du jeu
	while (bLoop)
	{
		// Réception et enregistrement des évènements
		InputHandler->UpdateEvents();

		// Traitement des Inputs et Calcul de la prochaine position du joueur
		OurPlayer->EventProcessing(SceneObject);
		
		// Déplacement du joueur à partir des coordonnées calculées
		OurPlayer->MoveActor(
			SceneObject->GetScreenWidth(), 
			SceneObject->GetScreenHeight(),
			OurPlayer->GetActorCalculatedPosition()
		);

		// On met à jour la position de la caméra
		SceneObject->UpdateCameraTargetPosition();

		// On met à jour le fond
		SceneObject->UpdateBackground();

		// (1)

		// On calcule le rendu de la scène et on affiche la frame
		SceneObject->UpdateRendu();

		// Si l'utilisateur veut quitter le jeu
		if (InputHandler->bUserWantToQuit())
		{
			bLoop = false;
		}

		if (bLoop == true)
		{
			/* On ajuste ici le delay entre le calcul de cette frame et la suivante
			dans le but de ne pas surcharger le CPU (et de contrôler notre framerate) */

			Engine::SetDelay(
				Engine::GetCalculationTime(CurrentFrameTime), 
				Framerate
			);
			
			CurrentFrameTime = Engine::GetTicks();
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


/*
A FAIRE

 ajouter de l'aléatoire pour le flip des textures animées constituant le fond
 ajouter de l'aléatoire pour le mouvement des étoiles en stationnary mode


 REFACTORISATION DU CODE

 Commencer le code réseau...

 AJOUT DU CODE POUR QUITTER LES SUBSYTEMS SDL
*/