#include "Input.h"

CSubInputHandler::CSubInputHandler()
{
	AQuit = false;

	// Initialisation de AKey
	for (int i = 0; i < SDL_NUM_SCANCODES; i++)
	{
		AKey[i] = false;
	}

	// Initialisation de AMouseButton
	for (int i = 0; i < 8; i++)
	{
		AMouseButtons[i] = false;
	}
}

CSubInputHandler::~CSubInputHandler()
{

}

void CSubInputHandler::UpdateEvents()
{
	/* Boucle de traitement des inputs : SDL_PollEvent() retourne 1
	   si il y a encore des évènements dans la file à traiter */

	while (SDL_PollEvent(&AEvent))
	{
		switch (AEvent.type)
		{
		// Cas d'une touche enfoncée
		case SDL_KEYDOWN:
			AKey[AEvent.key.keysym.scancode] = true;
			break;

		// Cas d'une touche relâchée
		case SDL_KEYUP:
			AKey[AEvent.key.keysym.scancode] = false;
			break;

		// Cas de pression sur un bouton de la souris
		case SDL_MOUSEBUTTONDOWN:
			AMouseButtons[AEvent.button.button] = true;
			break;

		// Cas du relâchement d'un bouton de la souris
		case SDL_MOUSEBUTTONUP:
			AMouseButtons[AEvent.button.button] = false;
			break;

		// Cas de la fermeture de la fenêtre
		case SDL_WINDOWEVENT:
			if (AEvent.window.event == SDL_WINDOWEVENT_CLOSE)
				AQuit = true;
			break;

		default:
			break;
		}
	}
}

bool CSubInputHandler::bUserWantToQuit() const
{
	return AQuit;
}

bool CSubInputHandler::GetKeyState(SDL_Scancode Key) const
{
	return AKey[Key];
}
