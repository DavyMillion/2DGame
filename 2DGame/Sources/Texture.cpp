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
	SDL_QueryTexture(ATexture, NULL, NULL, &ATextureWidth, &ATextureHeight);

	return ATexture;
}

void CSubTexture::FreeTexture()
{

}

void CSubTexture::RenderTexture(SDL_Renderer* Renderer, int x, int y, SDL_Rect* Container, double Angle, SDL_Point* CenterPosition, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, GetWidthTexture(), GetHeightTexture() };
	if (Container != nullptr)
	{
		renderQuad.w = Container->w;
		renderQuad.h = Container->h;
	};
	
	SDL_RenderCopyEx(Renderer, ATexture, Container, &renderQuad, Angle, CenterPosition, SDL_FLIP_NONE);
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
