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

	// On utilisera ces variables pour plus de clart�
	CGameSceneRender* SceneObject = Client->GetSceneRenderProperties();
	CPlayerController* OurPlayer = SceneObject->GetPlayerController();
	CSubInputHandler* InputHandler = OurPlayer->GetInputHandler();

	// Chargement des textures
	if (!SceneObject->LoadAllTextures()) { return EXIT_ERROR; }
	
	// � terme, le serveur d�cidera du point de spawn
	OurPlayer->SetSpawnPositionPlayer(LEVEL_WIDTH / 2, LEVEL_HEIGHT / 2);

	// Initialisation des entit�s composant le fond
	SceneObject->GetBackgroundObject()->InitBackground();
	
	// Contr�le de la framerate d�l�gu� � l'objet GameEngine
	clock_t Framerate = Engine::TicksRatioCalculation(FRAME_PER_SECOND);
	clock_t CurrentFrameTime = Engine::GetTicks();

	bool bLoop = true;

	// Boucle principale du jeu
	while (bLoop)
	{
		// R�ception et enregistrement des �v�nements
		InputHandler->UpdateEvents();

		// Traitement des Inputs et Calcul de la prochaine position du joueur
		OurPlayer->EventProcessing(SceneObject);
		
		// D�placement du joueur � partir des coordonn�es calcul�es
		OurPlayer->MoveActor(
			SceneObject->GetScreenWidth(), 
			SceneObject->GetScreenHeight(),
			OurPlayer->GetActorCalculatedPosition()
		);

		// On met � jour la position de la cam�ra
		SceneObject->UpdateCameraTargetPosition();

		// On met � jour le fond
		SceneObject->UpdateBackground();

		// (1)

		// On calcule le rendu de la sc�ne et on affiche la frame
		SceneObject->UpdateRendu();

		// Si l'utilisateur veut quitter le jeu
		if (InputHandler->bUserWantToQuit())
		{
			bLoop = false;
		}

		if (bLoop == true)
		{
			/* On ajuste ici le delay entre le calcul de cette frame et la suivante
			dans le but de ne pas surcharger le CPU (et de contr�ler notre framerate) */

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
// r�ception des valeurs r�seau : thread de r�ception charge les donn�es dans une structure temp et
// c'est cette structure temp qui sera �valu� ici.
// On �vite de cette mani�re un �ventuel probl�me d'acc�s aux valeurs des variables en �criture
// par un autre thread concurrent.


/*
A FAIRE

 ajouter de l'al�atoire pour le flip des textures anim�es constituant le fond
 ajouter de l'al�atoire pour le mouvement des �toiles en stationnary mode


 REFACTORISATION DU CODE

 Commencer le code r�seau...

 AJOUT DU CODE POUR QUITTER LES SUBSYTEMS SDL
*/