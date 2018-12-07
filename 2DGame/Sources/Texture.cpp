#include "Texture.h"

CSubTexture::CSubTexture()
{
	ATexture = nullptr;
	ATextureWidth = 0;
	ATextureHeight = 0;
}

CSubTexture::~CSubTexture()
{
	//...
}

SDL_Texture* CSubTexture::LoadTextureFromFile(SDL_Renderer* Renderer, std::string path)
{
	ATexture = IMG_LoadTexture(Renderer, path.c_str());
	if (ATexture == nullptr)
	{
		std::cout << "Failed to load the following texture : " << path << "\n" << SDL_GetError() << std::endl;
		return nullptr;
	}
	return ATexture;
}

void CSubTexture::FreeTexture()
{

}

void CSubTexture::RenderTexture(SDL_Renderer* Renderer, int x, int y, SDL_Rect* truc, double Angle, SDL_Point* CenterPosition, SDL_RendererFlip flip)
{

}

int CSubTexture::GetWidthTexture()
{
	return ATextureWidth;
}

int CSubTexture::GetHeightTexture()
{
	return ATextureHeight;
}

SDL_Texture * CSubTexture::GetSDLTexture()
{
	return ATexture;
}
