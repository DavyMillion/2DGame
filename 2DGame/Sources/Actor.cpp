#include "Actor.h"

CActor::CActor()
{
	AAbsolutePosition = new SDL_Point;
	ATextureContainer = new SDL_Rect;
	ACenterPositionInContainerGrid = new SDL_Point;
}

void CActor::CalculateAbsoluteActorCenter(SDL_Point* Point)
{
	// Coordonnées du point A (sommet haut gauche du container)
	int xA = GetActorTextureContainer()->x;
	int yA = GetActorTextureContainer()->y;
	
	int HalfLengthRectX = ATextureContainer->w / 2;
	int HalfLengthRectY = ATextureContainer->h / 2;

	Point->x = xA + HalfLengthRectX;
	Point->y = yA + HalfLengthRectY;
	return;
}

SDL_Point * CActor::GetActorAbsolutePosition()
{
	CalculateAbsoluteActorCenter(AAbsolutePosition);
	return AAbsolutePosition;
}

SDL_Texture * CActor::GetActorTexture()
{
	return ATexture;
}

SDL_Point * CActor::GetActorCenterPositionInContainerGrid()
{
	return ACenterPositionInContainerGrid;
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
	this->ATextureContainer->x = CoordX - ATextureContainer->w / 2;
}

void CActor::SetActorPositionY(int CoordY)
{
	this->ATextureContainer->y = CoordY - ATextureContainer->h / 2;
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
