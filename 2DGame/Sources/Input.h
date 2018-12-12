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

		// Retourne true si la touche est pressée, false si relachée
		bool GetKeyState(SDL_Scancode Key) const;

	private:
		// Structure à la base de l'ensemble des évènements du jeu
		SDL_Event AEvent;

		// Tableau de booléen contenant toutes les lettres du clavier
		bool AKey[SDL_NUM_SCANCODES];

		/* tableau de booléen contenant toutes les touches de la souris :
		7 touches max gérés par la SDL commençant à l'index 1 */
		bool AMouseButtons[8];

		/* booléen initialisé par défaut à false, passe à true si un 
		évènement de type SDL_QUIT est recontré */
		bool AQuit;
	};

#endif