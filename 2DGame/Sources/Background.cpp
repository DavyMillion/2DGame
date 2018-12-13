#include "Background.h"
#include "Texture.h"

CSubBackgroundHandler::CSubBackgroundHandler(int ScreenHeight, int ScreenWidth)
{
	// on instancie toutes les filtres
	Filter01 = new CSubTexture();
	Filter02 = new CSubTexture();
	Filter03 = new CSubTexture();
	Filter04 = new CSubTexture();
	Filter05 = new CSubTexture();

	AScreenHeight = ScreenHeight;
	AScreenWidth = ScreenWidth;
}

CSubBackgroundHandler::~CSubBackgroundHandler()
{

}

void CSubBackgroundHandler::InitBackground()
{
	CSubAnimatedTexture* FilterInstance = nullptr;

	for (int y = 0; y < AScreenHeight; y += GetFilter01()->GetHeightTexture())
	{
		for (int x = 0; x < AScreenWidth; x += GetFilter01()->GetWidthTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter01->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(x, y);
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			FiltersContainer.push_back(FilterInstance);
		}
	}

	for (int y = 0; y < AScreenHeight; y += GetFilter02()->GetHeightTexture())
	{
		for (int x = 0; x < AScreenWidth; x += GetFilter02()->GetWidthTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter02->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(x, y);
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			FiltersContainer.push_back(FilterInstance);
		}
	}

	for (int y = 0; y < AScreenHeight; y += GetFilter03()->GetHeightTexture())
	{
		for (int x = 0; x < AScreenWidth; x += GetFilter03()->GetWidthTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter03->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(x, y);
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			FiltersContainer.push_back(FilterInstance);
		}
	}

	for (int y = 0; y < AScreenHeight; y += GetFilter04()->GetHeightTexture())
	{
		for (int x = 0; x < AScreenWidth; x += GetFilter04()->GetWidthTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter04->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(x, y);
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			FiltersContainer.push_back(FilterInstance);
		}
	}

	for (int y = 0; y < AScreenHeight; y += GetFilter05()->GetHeightTexture())
	{
		for (int x = 0; x < AScreenWidth; x += GetFilter05()->GetWidthTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter05->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(x, y);
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			FiltersContainer.push_back(FilterInstance);
		}
	}
}

void CSubBackgroundHandler::RenderStars(SDL_Renderer* Renderer)
{
	for (auto Object : FiltersContainer)
	{
		Object->RenderTexture(
			Renderer,
			Object->GetAnimatedTextureContainer()->x,
			Object->GetAnimatedTextureContainer()->y
		);
	}
}

CSubTexture * CSubBackgroundHandler::GetFilter01()
{
	return Filter01;
}

CSubTexture * CSubBackgroundHandler::GetFilter02()
{
	return Filter02;
}

CSubTexture * CSubBackgroundHandler::GetFilter03()
{
	return Filter03;
}

CSubTexture * CSubBackgroundHandler::GetFilter04()
{
	return Filter04;
}

CSubTexture * CSubBackgroundHandler::GetFilter05()
{
	return Filter05;
}
