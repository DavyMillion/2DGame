#include "Actor.h"

CActor::CActor()
{
	AAbsolutePosition = new SDL_Point;
	ACenterPositionTextureContainerGrid = new SDL_Point;
	ATextureContainer = new SDL_Rect;
}

void CActor::CalculateAbsoluteActorCenter(SDL_Point* Point)
{
	// Coordonnées du point A (sommet haut gauche du container)
	int xA = GetActorTextureContainer()->x;
	int yA = GetActorTextureContainer()->y;

	int HalfLengthRectX = GetActorCenterPositionInContainerGrid()->x;
	int HalfLengthRectY = GetActorCenterPositionInContainerGrid()->y;

	double theta = GetActorRelativeAngle();
	theta = (theta * M_PI) / 180; // passage en radians
	
	/*
	double phi = 1 / tan((HalfLengthRectY / HalfLengthRectX));
	double theta = GetActorRelativeAngle();
	theta = (theta * M_PI) / 180; // passage en radians

	// Coordonnées du vecteur de A vers T, point d'intersection des diagonales
	double xM = ( sin(phi) * sin(theta) - cos(phi) * cos(theta) );
	double yM = ( sin(phi) * cos(theta) + cos(phi) * sin(theta) );
	
	double NormeVector = sqrt(HalfLengthRectX * HalfLengthRectX + HalfLengthRectY * HalfLengthRectY);

	Point->x = static_cast<int> (xA + xM * NormeVector);
	Point->y = static_cast<int> (yA + yM * NormeVector);
	*/
	/*
	Point->x = static_cast<int> ( xA + (-1 * HalfLengthRectX * cos(theta) + (- 1) * HalfLengthRectY * sin(theta)) );
	Point->y = static_cast<int> ( yA + (HalfLengthRectX * sin(theta) - HalfLengthRectY * cos(theta)) );*/

	Point->x = xA + HalfLengthRectX;
	Point->y = yA + HalfLengthRectY;
	return;
}

SDL_Point * CActor::GetActorAbsolutePosition()
{
	CalculateAbsoluteActorCenter(AAbsolutePosition);
	return AAbsolutePosition;
}

SDL_Point * CActor::GetActorCenterPositionInContainerGrid()
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
	this->ATextureContainer->x = CoordX - GetActorCenterPositionInContainerGrid()->x;
}

void CActor::SetActorPositionY(int CoordY)
{
	this->ATextureContainer->y = CoordY - GetActorCenterPositionInContainerGrid()->y;
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
