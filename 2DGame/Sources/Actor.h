#ifndef ACTOR
#define ACTOR

#include "SDL_headers.h"
#include <iostream>

class CActor
{
public:
	CActor();

	void CalculateAbsoluteActorCenter(SDL_Point*);

	SDL_Point* GetActorAbsolutePosition();
	// Re-calcule à chaque appel la position absolue du centre de l'acteur
	SDL_Point* GetActorCenterPositionInContainerGrid(); // retourne la position du centre dans la grille du texture container
	SDL_Texture* GetActorTexture();
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
	SDL_Point* ACenterPositionTextureContainerGrid = nullptr;
	// Position dans la grille ATextureContainer du centre de gravité de l'actor
	SDL_Rect* ATextureContainer = nullptr;
	/* Rectangle englobant la texture de l'acteur dans la grille 2D
	Descriptif des champs de cette structure :
	-> x : coordonnée en x du coin haut gauche du Container (rectangulaire)
	-> y : coordonnée en y du coin haut gauche du Container (rectangulaire)
	-> h : hauteur du rectangle
	-> w : largeur du rectangle
	*/
	double ARelativeAngle; 
	// Angle relatif à la normale (y), theta croissant -> sens des aiguilles d'une montre
};

#endif // !ACTOR