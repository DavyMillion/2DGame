#ifndef INPUT_H
	#define INPUT_H

	#include "SDL_headers.h"

	class CSubInputHandler
	{
	public:
		// Contructeur
		CSubInputHandler();

		// Destructeur
		~CSubInputHandler();

		// Traitement des events
		void UpdateEvents();

		// Retourne true si l'utilisateur veut quitter le jeu, false sinon
		bool bUserWantToQuit() const;

		// Retourne true si la touche est press�e, false si relach�e
		bool GetKeyState(SDL_Scancode Key) const;

	private:
		// Structure � la base de l'ensemble des �v�nements du jeu
		SDL_Event AEvent;

		// Tableau de bool�en contenant toutes les lettres du clavier
		bool AKey[SDL_NUM_SCANCODES];

		/* tableau de bool�en contenant toutes les touches de la souris :
		7 touches max g�r�s par la SDL commen�ant � l'index 1 */
		bool AMouseButtons[8];

		/* bool�en initialis� par d�faut � false, passe � true si un 
		�v�nement de type SDL_QUIT est recontr� */
		bool AQuit;
	};

#endif