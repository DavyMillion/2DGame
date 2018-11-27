#ifndef ACTOR
#define ACTOR

#include "SDL_headers.h"
#include <iostream>

class CActor
{
public:
	CActor();
	~CActor();

	// Getters & Setters

	SDL_Point* GetActorPosition();
	SDL_Texture* GetActorTexture();
	SDL_Rect* GetActorTextureContainer();
	double GetActorRelativeAngle();

	void SetActorPositionX(int);
	void SetActorPositionY(int);
	void SetActorTexture(SDL_Texture*);
	void SetActorTextureContainer(SDL_Rect*);
	void SetActorRotation(int);

private:
	SDL_Texture* ATexture = nullptr;
	SDL_Point* APosition; // position dans la grille 2D du centre de gravité de l'actor
	SDL_Rect* ATextureContainer;
	double ARelativeAngle; // angle relatif à la normale (y), theta croissant -> sens des aiguilles d'une montre
};

#endif // !ACTOR