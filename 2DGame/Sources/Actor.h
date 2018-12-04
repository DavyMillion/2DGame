#ifndef ACTOR
#define ACTOR

#include "SDL_headers.h"
#include <iostream>

class CActor
{
public:
	CActor();

	// Re-calcule à chaque appel la position absolue du centre de l'actor
	SDL_Point* GetActorAbsolutePosition();
	void CalculateAbsoluteActorCenter(SDL_Point*);

	// Retourne la texture de l'Actor
	SDL_Texture* GetActorTexture();
	SDL_Point* GetActorCenterPositionInContainerGrid();
	SDL_Rect* GetActorTextureContainer();
	
	// retourne l'angle d'inclinaison relatif de l'actor en degrée
	double GetActorRelativeAngle();
	
	void SetActorPositionX(int);
	void SetActorPositionY(int);
	void SetActorTexture(SDL_Texture*);
	void SetActorTextureContainer(SDL_Rect*);
	void SetActorRotation(int);

	~CActor();
protected:
	SDL_Texture* ATexture = nullptr;
	// Pointeur sur la texture de l'actor
	SDL_Point* AAbsolutePosition = nullptr;
	// Position absolu dans la grille 2D
	// Les champs x et y indiquent la position du centre de gravité de l'actor

	SDL_Point* ACenterPositionInContainerGrid = nullptr;

	SDL_Rect* ATextureContainer = nullptr;
	/* Rectangle englobant la texture de l'acteur dans la grille 2D
	Descriptif des champs de cette structure :
	-> x : coordonnée en x du coin haut gauche du Container (rectangulaire)
	-> y : coordonnée en y du coin haut gauche du Container (rectangulaire)
	-> h : hauteur du rectangle
	-> w : largeur du rectangle
	Le container est fixe par rapport à theta
	*/
	double ARelativeAngle = 0.f;
	// Angle relatif à la normale (y), theta croissant -> sens des aiguilles d'une montre
};

#endif // !ACTOR