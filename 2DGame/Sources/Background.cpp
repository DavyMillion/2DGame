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

	for (int y = -GetFilter01()->GetHeightTexture(); y < AScreenHeight; y += GetFilter01()->GetHeightTexture())
	{
		for (int x = -GetFilter01()->GetWidthTexture(); x < AScreenWidth; x += GetFilter01()->GetWidthTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter01->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(x, y);
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			Instances01Container.push_back(FilterInstance);
		}
	}

	for (int y = -GetFilter02()->GetHeightTexture(); y < AScreenHeight; y += GetFilter02()->GetHeightTexture())
	{
		for (int x = -GetFilter02()->GetWidthTexture(); x < AScreenWidth; x += GetFilter02()->GetWidthTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter02->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(x, y);
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			Instances02Container.push_back(FilterInstance);
		}
	}

	for (int y = -GetFilter03()->GetHeightTexture(); y < AScreenHeight; y += GetFilter03()->GetHeightTexture())
	{
		for (int x = -GetFilter03()->GetWidthTexture(); x < AScreenWidth; x += GetFilter03()->GetWidthTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter03->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(x, y);
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			Instances03Container.push_back(FilterInstance);
		}
	}

	for (int y = -GetFilter04()->GetHeightTexture(); y < AScreenHeight; y += GetFilter04()->GetHeightTexture())
	{
		for (int x = -GetFilter04()->GetWidthTexture(); x < AScreenWidth; x += GetFilter04()->GetWidthTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter04->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(x, y);
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			Instances04Container.push_back(FilterInstance);
		}
	}

	for (int y = -GetFilter05()->GetHeightTexture(); y < AScreenHeight; y += GetFilter05()->GetHeightTexture())
	{
		for (int x = -GetFilter05()->GetWidthTexture(); x < AScreenWidth; x += GetFilter05()->GetWidthTexture())
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
		int x = Object->GetAnimatedTextureContainer()->x - 1;
		int y = Object->GetAnimatedTextureContainer()->y - 1;
		Object->SetAnimatedTexturePosition(x, y);
	}

	for (auto Object : Instances02Container)
	{
		int x = Object->GetAnimatedTextureContainer()->x - 3;
		int y = Object->GetAnimatedTextureContainer()->y - 3;
		Object->SetAnimatedTexturePosition(x, y);
	}

	for (auto Object : Instances03Container)
	{
		int x = Object->GetAnimatedTextureContainer()->x + 5;
		int y = Object->GetAnimatedTextureContainer()->y + 5;
		Object->SetAnimatedTexturePosition(x, y);
	}

	for (auto Object : Instances04Container)
	{
		int x = Object->GetAnimatedTextureContainer()->x + 7;
		int y = Object->GetAnimatedTextureContainer()->y + 7;
		Object->SetAnimatedTexturePosition(x, y);
	}

	for (auto Object : Instances05Container)
	{
		int x = Object->GetAnimatedTextureContainer()->x + 9;
		int y = Object->GetAnimatedTextureContainer()->y + 9;
		Object->SetAnimatedTexturePosition(x, y);
	}

	HandleAllSubObjects(Filter01, Instances01Container);
	HandleAllSubObjects(Filter02, Instances02Container);
	HandleAllSubObjects(Filter03, Instances03Container);
	HandleAllSubObjects(Filter04, Instances04Container);
	HandleAllSubObjects(Filter05, Instances05Container);

	RenderAllSubObjects(Renderer, Instances01Container);
	RenderAllSubObjects(Renderer, Instances02Container);
	RenderAllSubObjects(Renderer, Instances03Container);
	RenderAllSubObjects(Renderer, Instances04Container);
	RenderAllSubObjects(Renderer, Instances05Container);

	std::cout << "Total Background Objects instancied : " << Instances01Container.size() + Instances02Container.size() + Instances03Container.size() + Instances04Container.size() + Instances05Container.size() << std::endl;
}

void CSubBackgroundHandler::RenderAllSubObjects(SDL_Renderer* Renderer, std::vector<CSubAnimatedTexture*> &Container)
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

void CSubBackgroundHandler::HandleAllSubObjects(CSubTexture * Filter, std::vector<CSubAnimatedTexture*> &Container)
{
	// parcours dans le but de déterminer le minimum
	int minX = AScreenWidth;
	int maxX = 0;
	int minY = AScreenHeight;
	int maxY = 0;

	for (auto Object : Container)
	{
		if (Object->GetAnimatedTextureContainer()->x < minX)
		{
			minX = Object->GetAnimatedTextureContainer()->x;
		}
	}

	for (auto Object : Container)
	{
		if (Object->GetAnimatedTextureContainer()->y < minY)
		{
			minY = Object->GetAnimatedTextureContainer()->y;
		}
	}

	for (auto Object : Container)
	{
		if (Object->GetAnimatedTextureContainer()->x > maxX)
		{
			maxX = Object->GetAnimatedTextureContainer()->x;
		}
	}

	for (auto Object : Container)
	{
		if (Object->GetAnimatedTextureContainer()->y > maxY)
		{
			maxY = Object->GetAnimatedTextureContainer()->y;
		}
	}

	CSubAnimatedTexture* FilterInstance = nullptr;

	if (minX > 0) // on sort du cadre par la gauche aka bordel
	{
		for (int y = minY; y < AScreenHeight; y += Filter->GetHeightTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(minX - Filter->GetWidthTexture(), y);
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			Container.push_back(FilterInstance);
		}
	}

	if (minY > 0) // on sort du cadre par la gauche aka bordel
	{
		for (int x = minX; x < AScreenWidth; x += Filter->GetWidthTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(x, minY - Filter->GetHeightTexture());
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			Container.push_back(FilterInstance);
		}
	}

	if (maxX + Filter->GetWidthTexture() < AScreenWidth) // on sort du cadre par la droite 
	{
		for (int y = minY; y < AScreenHeight; y += Filter->GetHeightTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(maxX + Filter->GetWidthTexture(), y);
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			Container.push_back(FilterInstance);
		}
	}

	if (maxY + Filter->GetHeightTexture() < AScreenHeight) // on sort du cadre par la droite 
	{
		for (int x = minX; x < AScreenWidth; x += Filter->GetWidthTexture())
		{
			FilterInstance = new CSubAnimatedTexture();
			FilterInstance->SetTexture(Filter->GetSDLTexture());
			FilterInstance->SetAnimatedTexturePosition(x, maxY + Filter->GetHeightTexture());
			FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
			Container.push_back(FilterInstance);
		}
	}

	for (int i = 0; i < Container.size(); )
	{
		CSubAnimatedTexture* Object = Container[i];

		// trop en retrait à gauche
		if (Object->GetAnimatedTextureContainer()->x + Object->GetWidthTexture() < 0)
		{
			Container.erase(Container.begin() + i);
			delete Object;
		}
		else if (Object->GetAnimatedTextureContainer()->x > AScreenWidth)
		{
			Container.erase(Container.begin() + i);
			delete Object;
		}
		else if (Object->GetAnimatedTextureContainer()->y + Object->GetHeightTexture() < 0)
		{
			Container.erase(Container.begin() + i);
			delete Object;
		}
		else if (Object->GetAnimatedTextureContainer()->y > AScreenHeight)
		{
			Container.erase(Container.begin() + i);
			delete Object;
		}
		else
		{
			i++;
		}
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
