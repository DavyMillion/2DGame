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

void CActor::MoveActor(int ScreenWidth, int ScreenHeight, SDL_Point* NextPosition)
{
	if (NextPosition->x < 0 || NextPosition->x > ScreenWidth || NextPosition->y < 0 || NextPosition->y > ScreenHeight)
	{
		NextPosition->x = this->GetActorAbsolutePosition()->x;
		NextPosition->y = this->GetActorAbsolutePosition()->y;
	}

	this->SetActorPosition(NextPosition->x, NextPosition->y);
}

void CActor::CalculateAbsoluteActorCenter(SDL_Point* Point)
{
	// Coordonn�es du point A (sommet haut gauche du container)
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

	ACenterPositionInContainerGrid->x = ATextureContainer->w / 2;
	ACenterPositionInContainerGrid->y = ATextureContainer->h / 2;
}

void CActor::SetActorTextureContainer(int x, int y, int w, int h)
{
	this->ATextureContainer->x = x;
	this->ATextureContainer->y = y;
	this->ATextureContainer->w = w;
	this->ATextureContainer->h = h;

	ACenterPositionInContainerGrid->x = ATextureContainer->w / 2;
	ACenterPositionInContainerGrid->y = ATextureContainer->h / 2;
}

void CActor::SetActorRotation(int Incrementation) // syst�me � modifier
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
