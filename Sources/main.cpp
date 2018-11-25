#include "SDL_headers.h"
#include "Constantes.h"
#include "Engine.h"
#include "Client.h"
#include "Server.h"

int main(int argc, char* args[])
{
	// l'instance du client
	CGameClient* Client = new CGameClient;
	CGameEngine* GameEngine = Client->GetGameEngineProperties();

	if (!Client->InitialisationSDL()) { return EXIT_ERROR; }

	int bLoop = true;

	// Variables n�cessaire au contr�le de la framerate
	clock_t RatioFramerate = (clock_t) GameEngine->SetFramerate(FRAME_PER_SECOND); // � d�l�guer
	clock_t TimeAtThisFrame = clock(); // � d�l�guer

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
					Client->SetIncrementPosX(10);
					break;
				case SDLK_LEFT:
					Client->SetIncrementPosX(-10);
					break;
					// Remeber 0,0 in SDL is left-top. So when the user pressus down, the y need to increase
				case SDLK_DOWN:
					Client->SetIncrementPosY(10);
					break;
				case SDLK_UP:
					Client->SetIncrementPosY(-10);
					break;
				default:
					break;
				}
			}
		}

		// (1)

		Client->UpdateRendu();

		// (2)

		if (event.type != SDL_QUIT)
		{
			// on ajuste ici le delay entre le calcul de cette frame et la suivante
			Client->GetGameEngineProperties()->SetDelay(GameEngine->DeltaTime(TimeAtThisFrame), RatioFramerate); // TimeAtThisFrame correspond ici au temps de l'ancienne frame (de l'it�ration pr�c�dente)
			TimeAtThisFrame = clock(); // � d�l�guer
		}
	}
	delete Client;
	return EXIT_SUCCESS;
}


// (1)
// SniffWhatNetworkTellMe()
// r�ception des valeurs r�seau : thread de r�ception charge les donn�es dans une structure temp et
// c'est cette structure temp qui sera �valu� ici.
// On �vite de cette mani�re un �ventuel probl�me d'acc�s aux valeurs des variables en �criture.

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