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
			Instances01Container.push_back(FilterInstance);
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
			Instances02Container.push_back(FilterInstance);
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
			Instances03Container.push_back(FilterInstance);
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
			Instances04Container.push_back(FilterInstance);
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
			Instances05Container.push_back(FilterInstance);
		}
	}
}

void CSubBackgroundHandler::RenderStars(SDL_Renderer* Renderer)
{
	for (auto Object : Instances01Container)
	{
		int x = Object->GetAnimatedTextureContainer()->x + 2;
		int y = Object->GetAnimatedTextureContainer()->y + 2;
		Object->SetAnimatedTexturePosition(x, y);
	}

	// parcours dans le but de déterminer le minimum
	int minX = AScreenWidth;
	int maxX = 0;
	int minY = AScreenHeight;
	int maxY = 0;

	for (auto Object : Instances01Container)
	{
		if (Object->GetAnimatedTextureContainer()->x < minX)
		{
			minX = Object->GetAnimatedTextureContainer()->x;
		}
	}

	for (auto Object : Instances01Container)
	{
		if (Object->GetAnimatedTextureContainer()->y < minY)
		{
			minY = Object->GetAnimatedTextureContainer()->y;
		}
	}

	for (auto Object : Instances01Container)
	{
		if (Object->GetAnimatedTextureContainer()->x > maxX)
		{
			maxX = Object->GetAnimatedTextureContainer()->x;
		}
	}

	for (auto Object : Instances01Container)
	{
		if (Object->GetAnimatedTextureContainer()->y > maxY)
		{
			maxY = Object->GetAnimatedTextureContainer()->y;
		}
	}

	CSubAnimatedTexture* FilterInstance = nullptr;

	if (minX > 0) // on sort du cadre par la gauche aka bordel
	{
		for (int y = minY; y < AScreenHeight; y += GetFilter01()->GetHeightTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter01->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(minX - GetFilter01()->GetWidthTexture(), y);
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			Instances01Container.push_back(FilterInstance);
		}
	}

	if (minY > 0) // on sort du cadre par la gauche aka bordel
	{
		for (int x = minX; x < AScreenWidth; x += GetFilter01()->GetWidthTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter01->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(x, minY - GetFilter01()->GetHeightTexture());
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			Instances01Container.push_back(FilterInstance);
		}
	}

	FilterInstance = new CSubAnimatedTexture();
	FilterInstance->SetTexture(Filter01->GetSDLTexture());
	FilterInstance->SetAnimatedTexturePosition(minX - GetFilter01()->GetWidthTexture(), minY - GetFilter01()->GetHeightTexture());
	FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
	Instances01Container.push_back(FilterInstance);
	// rajouter un pour les deux en même temps

	if (maxX + Filter01->GetWidthTexture() < AScreenWidth) // on sort du cadre par la droite 
	{
		for (int y = minY; y < AScreenHeight; y += GetFilter01()->GetHeightTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter01->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(maxX + Filter01->GetWidthTexture(), y);
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			Instances01Container.push_back(FilterInstance);
		}
	}

	if (maxY + Filter01->GetHeightTexture() < AScreenHeight) // on sort du cadre par la droite 
	{
		for (int x = minX; x < AScreenWidth; x += GetFilter01()->GetWidthTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter01->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(x, maxY + Filter01->GetHeightTexture());
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			Instances01Container.push_back(FilterInstance);
		}
	}

	// rajouter un pour les deux en même temps

	std::cout << "Instances01Container size : " << Instances01Container.size() << std::endl;

	int i = 0;
	for (auto Object : Instances01Container)
	{
		auto Object = Instances01Container[i];

		// trop en retrait à gauche
		if (Object->GetAnimatedTextureContainer()->x + Object->GetWidthTexture() < 0)
		{
			Instances01Container.erase(Instances01Container.begin() + i);
			delete Object;
		}
		else if (Object->GetAnimatedTextureContainer()->x > AScreenWidth)
		{
			Instances01Container.erase(Instances01Container.begin() + i);
			delete Object;
		}
		else if (Object->GetAnimatedTextureContainer()->y + Object->GetHeightTexture() < 0)
		{
			Instances01Container.erase(Instances01Container.begin() + i);
			delete Object;
		}
		else if (Object->GetAnimatedTextureContainer()->y > AScreenHeight)
		{
			Instances01Container.erase(Instances01Container.begin() + i);
			delete Object;
		}
		else
		{
			i++;
		}
	}

	RenderAllSubObjects(Renderer, Instances01Container);
}

void CSubBackgroundHandler::RenderAllSubObjects(SDL_Renderer* Renderer, std::vector<CSubAnimatedTexture*> Container)
{
	for (auto Object : Container)
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
