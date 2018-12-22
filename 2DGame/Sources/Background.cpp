#include "Background.h"
#include "Texture.h"
#include "PlayerController.h"

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
	
	AStationnaryMode = Up;
}

void CSubBackgroundHandler::UpdateBackgroundArrangement(CPlayerController* Player)
{
	double time = clock() / CLOCKS_PER_SEC;

	if (AFormerPlayerPos.x != Player->GetActorAbsolutePosition()->x || AFormerPlayerPos.y != Player->GetActorAbsolutePosition()->y) // si mouvement
	{
		double theta = Player->GetActorRelativeAngle();
		theta = (theta * M_PI) / 180; // passage en radians 
		int x, y;
		
		for (auto Object : Instances01Container)
		{
			x = Object->GetAnimatedTextureContainer()->x + static_cast<int>(round(2 * sin(theta)));
			y = Object->GetAnimatedTextureContainer()->y + static_cast<int>(round(2 * cos(theta) * (-1)));
			
			Object->SetAnimatedTexturePosition(x, y);
		}
		
		for (auto Object : Instances02Container)
		{
			x = Object->GetAnimatedTextureContainer()->x + static_cast<int>(round(4 * sin(theta)* (-1)));
			y = Object->GetAnimatedTextureContainer()->y + static_cast<int>(round(4 * cos(theta)));
			Object->SetAnimatedTexturePosition(x, y);
		}

		for (auto Object : Instances03Container)
		{
			x = Object->GetAnimatedTextureContainer()->x + static_cast<int>(round(6 * sin(theta)* (-1)));
			y = Object->GetAnimatedTextureContainer()->y + static_cast<int>(round(6 * cos(theta)));
			Object->SetAnimatedTexturePosition(x, y);
		}

		for (auto Object : Instances04Container)
		{
			x = Object->GetAnimatedTextureContainer()->x + static_cast<int>(round(8 * sin(theta)* (-1)));
			y = Object->GetAnimatedTextureContainer()->y + static_cast<int>(round(8 * cos(theta)));
			Object->SetAnimatedTexturePosition(x, y);
		}

		for (auto Object : Instances05Container)
		{
			x = Object->GetAnimatedTextureContainer()->x + static_cast<int>(round(10 * sin(theta)* (-1)));
			y = Object->GetAnimatedTextureContainer()->y + static_cast<int>(round(10 * cos(theta)));
			Object->SetAnimatedTexturePosition(x, y);
		}
	}
	else // stationnary mode
	{
		if (time > lastupdate + 1)
		{
			int IncrementX, IncrementY;

			if (AStationnaryMode == Up)
			{
				IncrementX = 0;
				IncrementY = -1;
				AStationnaryMode = Right;
			}
			else if (AStationnaryMode == Right)
			{
				IncrementX = 1;
				IncrementY = 0;
				AStationnaryMode = Down;
			}
			else if (AStationnaryMode == Down)
			{
				IncrementX = 0;
				IncrementY = 1;
				AStationnaryMode = Left;
			}
			else
			{
				IncrementX = -1;
				IncrementY = 0;
				AStationnaryMode = Up;
			}

			std::cout << "IncrementX :" << IncrementX << std::endl;
			std::cout << "IncrementY :" << IncrementY << std::endl;

			int x, y;
			for (auto Object : Instances03Container)
			{
				x = Object->GetAnimatedTextureContainer()->x + IncrementX;
				y = Object->GetAnimatedTextureContainer()->y + IncrementY;
				Object->SetAnimatedTexturePosition(x, y);
			}

			for (auto Object : Instances04Container)
			{
				x = Object->GetAnimatedTextureContainer()->x + IncrementX;
				y = Object->GetAnimatedTextureContainer()->y + IncrementY;
				Object->SetAnimatedTexturePosition(x, y);
			}

			for (auto Object : Instances05Container)
			{
				x = Object->GetAnimatedTextureContainer()->x + IncrementX;
				y = Object->GetAnimatedTextureContainer()->y + IncrementY;
				Object->SetAnimatedTexturePosition(x, y);
			}
			lastupdate = clock() / CLOCKS_PER_SEC;
		}
	}

	// Affectation pour la prochaine frame
	AFormerPlayerPos = *(Player->GetActorAbsolutePosition());
}

void CSubBackgroundHandler::RenderStars(SDL_Renderer* Renderer)
{

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

	//std::cout << "Total Background Objects instancied : " << Instances01Container.size() + Instances02Container.size() + Instances03Container.size() + Instances04Container.size() + Instances05Container.size() << std::endl;
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

void CSubBackgroundHandler::SetPlayerPos(int x, int y)
{
	AFormerPlayerPos.x = x;
	AFormerPlayerPos.y = y;
}
