#include "Actor.h"

CActor::CActor()
{
	APositionCenter = new SDL_Point;
	ATextureContainer = new SDL_Rect;
	// Initialisation du "joueur"
	ATextureContainer->x = 20;
	ATextureContainer->y = 20;
	ATextureContainer->w = 48;
	ATextureContainer->h = 70;

	APositionCenter->x = ATextureContainer->w / 2;
	APositionCenter->y = ATextureContainer->h / 2;
}

SDL_Point * CActor::GetActorPosition()
{
	return APositionCenter;
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
