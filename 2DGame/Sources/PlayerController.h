#ifndef PLAYER_CONTROLLER
#define PLAYER_CONTROLLER

#include <iostream>
#include <map>
#include "Actor.h"

// Déclaration avancée
class CGameSceneRender;
struct CSubInputHandler;

class CPlayerController : public CActor
{
public:
	CPlayerController();

	void SetSpawnPositionPlayer(int, int); // peut-être à mettre dans Actor

	void EventProcessing(SDL_Event& event, CGameSceneRender* SceneRender);

private:
	typedef CActor Super;

	CSubInputHandler* Input;
};

// Cette classe centralise le contrôle des entités du jeux (par les humains)
// l'idée est de receptionner les events dans cette classe
// on les traite en fonction d'une certaine vitesse saisi dans cette classe.

#endif

/*
	Modification à faire :
	Finir la classe input
	Equiper CPlayercController de PosX, PosY : variable qui prendront la valeur de la nouvelle position calculé
	Conséquence : on bouge MoveActorForward qu'on rebaptisera pour l'occasion CalculatePlayer...
	On retrouvera un équilibre de cette manière dans la classe du rendu
	On finira par créer une méthode Move pour actor qui se contentera d'aller chercher les nouvelles positions calculées.
*/