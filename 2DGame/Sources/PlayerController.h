#ifndef PLAYER_CONTROLLER
	#define PLAYER_CONTROLLER

	#include <iostream>
	#include <cmath>
	#include "Actor.h"

	// D�claration avanc�e
	class CGameSceneRender;
	class CSubInputHandler;

	class CPlayerController : public CActor
	{
	public:
		// Constructeur
		CPlayerController();

		// Destructeur
		~CPlayerController();

		// Changement du point de spawn du joueur
		void SetSpawnPositionPlayer(int x, int y); // peut-�tre � mettre dans Actor

		// Traitement des inputs
		void EventProcessing(CGameSceneRender* SceneRender);
		
		// Notre Getter sur l'objet Input
		CSubInputHandler* GetInputHandler() const;

		// Notre Getter sur la position calcul�e � partir des inputs
		SDL_Point* GetActorCalculatedPosition() const;

	private:
		// Retourne un SDL_Point sur la prochaine position du joueur
		void CalculateNextPosition(int Increment);

		typedef CActor Super;

		CSubInputHandler* AInputHandler;

		SDL_Point* ACalculatedPos;
	};

	// Cette classe centralise le contr�le des entit�s du jeux (par les humains)
	// l'id�e est de receptionner les events dans cette classe
	// on les traite en fonction d'une certaine vitesse saisi dans cette classe.

#endif

/*
	Modification � faire :
	Finir la classe input
	Equiper CPlayercController de PosX, PosY : variable qui prendront la valeur de la nouvelle position calcul�
	Cons�quence : on bouge MoveActorForward qu'on rebaptisera pour l'occasion CalculatePlayer...
	On retrouvera un �quilibre de cette mani�re dans la classe du rendu
	On finira par cr�er une m�thode Move pour actor qui se contentera d'aller chercher les nouvelles positions calcul�es.
*/