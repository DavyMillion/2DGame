#include "Actor.h"
#include "Texture.h"

CActor::CActor()
{
	AAbsolutePosition = new SDL_Point;
	ATextureContainer = new SDL_Rect;
	ACenterPositionInContainerGrid = new SDL_Point;
	ATextureObject = new CSubTexture();
	ARelativeAngle = 0.f;
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

CSubTexture * CActor::GetActorTextureObject()
{
	return ATextureObject;
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

void CActor::SetActorPosition(int CoordX, int CoordY)
{
	this->ATextureContainer->x = CoordX - ATextureContainer->w / 2;
	this->ATextureContainer->y = CoordY - ATextureContainer->h / 2;
}

void CActor::SetActorTexture(SDL_Renderer* Renderer, std::string path)
{
	this->ATextureObject->LoadTextureFromFile(Renderer, path);
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
