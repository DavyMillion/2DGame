#include "Actor.h"

CActor::CActor()
{
	AAbsolutePosition = new SDL_Point;
	ACenterPositionTextureContainerGrid = new SDL_Point;
	ATextureContainer = new SDL_Rect;
	
	// Initialisation du "joueur"
	ATextureContainer->x = 0;
	ATextureContainer->y = 0;
	ATextureContainer->w = 48;
	ATextureContainer->h = 70;

	// Initialisation de ACenterPositionTextureContainerGrid
	ACenterPositionTextureContainerGrid->x = ATextureContainer->w / 2;
	ACenterPositionTextureContainerGrid->y = ATextureContainer->h / 2;
}

void CActor::CalculateAbsoluteActorCenter(SDL_Point* Point)
{
	// Coordonnées du point A (sommet haut gauche du container)
	int xA = GetActorTextureContainer()->x;
	int yA = GetActorTextureContainer()->y;

	int HalfLengthRectX = GetActorCenterPositionInTextureContainerGrid()->x;
	int HalfLengthRectY = GetActorCenterPositionInTextureContainerGrid()->y;
	
	double phi = 1 / tan((HalfLengthRectY / HalfLengthRectX));
	double theta = GetActorRelativeAngle();
	theta = (theta * M_PI) / 180; // passage en radians

	// Coordonnées du vecteur de A vers T, point d'intersection des diagonales
	int xM = static_cast<int>( -1 * sin(phi) * sin(theta) + cos(phi) * cos(theta) );
	int yM = static_cast<int>( sin(phi) * cos(theta) + cos(phi) * sin(theta) );
	
	// Decomment one of them to test it !

	/* (1)
	Old Physic mouvement model with no vector correction
	Point->x = (int) xA;
	Point->y = (int) yA;
	*/

	/* (2)
	New Physic mouvement model with vector correction */
	int NormeVector = static_cast<int>( sqrt(HalfLengthRectX * HalfLengthRectX + HalfLengthRectY * HalfLengthRectY) );
	Point->x = xA + xM * NormeVector;
	Point->y = yA + yM * NormeVector;/*
	*/
	return;
}

SDL_Point * CActor::GetActorAbsolutePosition()
{
	CalculateAbsoluteActorCenter(AAbsolutePosition);
	return AAbsolutePosition;
}

SDL_Point * CActor::GetActorCenterPositionInTextureContainerGrid()
{
	return ACenterPositionTextureContainerGrid;
}

SDL_Texture * CActor::GetActorTexture()
{
	return ATexture;
}

SDL_Rect* CActor::GetActorTextureContainer()
{
	return ATextureContainer;
}


double CActor::GetActorRelativeAngle()
{
	return ARelativeAngle;
}

void CActor::SetActorPositionX(int CoordX)
{
	this->ATextureContainer->x = CoordX;
}

void CActor::SetActorPositionY(int CoordY)
{
	this->ATextureContainer->y = CoordY;
}

void CActor::SetActorTexture(SDL_Texture* Texture)
{
	this->ATexture = Texture;
}

void CActor::SetActorTextureContainer(SDL_Rect* TextureContainer)
{
	this->ATextureContainer = TextureContainer;
}

void CActor::SetActorRotation(int Incrementation) // système à modifier
{
	this->ARelativeAngle += Incrementation;
}

CActor::~CActor()
{
	/*
	delete APositionCenter;
	delete ATexture;
	delete ATextureContainer;
	*/
}
