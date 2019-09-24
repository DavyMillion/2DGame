#include "Background.h"
#include "Texture.h"
#include "PlayerController.h"
#include "Engine.h"
#include "Constantes.h"

CSubBackgroundHandler::CSubBackgroundHandler(int ScreenHeight, int ScreenWidth)
{
	// on instancie tous les filtres
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
	for (int y = -GetFilter01()->GetHeightTexture() * 0.7; y < AScreenHeight; y += GetFilter01()->GetHeightTexture() * 0.7)
	{
		for (int x = -GetFilter01()->GetWidthTexture() * 0.7; x < AScreenWidth; x += GetFilter01()->GetWidthTexture() * 0.7)
		{
			Instances01Container.push_back(CreateNewTextureInstance(Filter01, x, y));
		}
	}

	for (int y = -GetFilter02()->GetHeightTexture() * 0.7; y < AScreenHeight; y += GetFilter02()->GetHeightTexture() * 0.7)
	{
		for (int x = -GetFilter02()->GetWidthTexture() * 0.7; x < AScreenWidth; x += GetFilter02()->GetWidthTexture() * 0.7)
		{
			Instances02Container.push_back(CreateNewTextureInstance(Filter02, x, y));
		}
	}

	for (int y = -GetFilter03()->GetHeightTexture() * 0.7; y < AScreenHeight; y += GetFilter03()->GetHeightTexture() * 0.7)
	{
		for (int x = -GetFilter03()->GetWidthTexture() * 0.7; x < AScreenWidth; x += GetFilter03()->GetWidthTexture() * 0.7)
		{
			Instances03Container.push_back(CreateNewTextureInstance(Filter03, x, y));
		}
	}

	for (int y = -GetFilter04()->GetHeightTexture() * 0.7; y < AScreenHeight; y += GetFilter04()->GetHeightTexture() * 0.7)
	{
		for (int x = -GetFilter04()->GetWidthTexture() * 0.7; x < AScreenWidth; x += GetFilter04()->GetWidthTexture() * 0.7)
		{
			Instances04Container.push_back(CreateNewTextureInstance(Filter04, x, y));
		}
	}

	for (int y = -GetFilter05()->GetHeightTexture() * 0.7; y < AScreenHeight; y += GetFilter05()->GetHeightTexture() * 0.7)
	{
		for (int x = -GetFilter05()->GetWidthTexture() * 0.7; x < AScreenWidth; x += GetFilter05()->GetWidthTexture() * 0.7)
		{
			Instances05Container.push_back(CreateNewTextureInstance(Filter05, x, y));
		}
	}
	
	AStationnaryMode = Up;
}

CSubAnimatedTexture* CSubBackgroundHandler::CreateNewTextureInstance(CSubTexture* Filter, int TexturePositionX, int TexturePositionY)
{
	CSubAnimatedTexture* FilterInstance = new CSubAnimatedTexture;
	FilterInstance->SetTexture(Filter->GetSDLTexture());
	FilterInstance->SetAnimatedTexturePosition(TexturePositionX, TexturePositionY);
	FilterInstance->SetupWidthAndHeightAnimatedTextureContainer();
	return FilterInstance;
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
			x = Object->GetAnimatedTextureContainer()->x + static_cast<int>(round(2 * sin(theta) * (-1)));
			y = Object->GetAnimatedTextureContainer()->y + static_cast<int>(round(2 * cos(theta) ));
			Object->SetAnimatedTexturePosition(x, y);
		}
		
		for (auto Object : Instances02Container)
		{
			x = Object->GetAnimatedTextureContainer()->x + static_cast<int>(round(2 * sin(theta)* (-1)));
			y = Object->GetAnimatedTextureContainer()->y + static_cast<int>(round(2 * cos(theta)));
			Object->SetAnimatedTexturePosition(x, y);
		}

		for (auto Object : Instances03Container)
		{
			x = Object->GetAnimatedTextureContainer()->x + static_cast<int>(round(4 * sin(theta)* (-1)));
			y = Object->GetAnimatedTextureContainer()->y + static_cast<int>(round(4 * cos(theta)));
			Object->SetAnimatedTexturePosition(x, y);
		}

		for (auto Object : Instances04Container)
		{
			x = Object->GetAnimatedTextureContainer()->x + static_cast<int>(round(5 * sin(theta)* (-1)));
			y = Object->GetAnimatedTextureContainer()->y + static_cast<int>(round(5 * cos(theta)));
			Object->SetAnimatedTexturePosition(x, y);
		}

		for (auto Object : Instances05Container)
		{
			x = Object->GetAnimatedTextureContainer()->x + static_cast<int>(round(5 * sin(theta)* (-1)));
			y = Object->GetAnimatedTextureContainer()->y + static_cast<int>(round(5 * cos(theta)));
			Object->SetAnimatedTexturePosition(x, y);
		}
	}
	else // stationnary mode
	{
		if (time > lastupdate + 0.5)
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

	if (BACKGROUND_ENTITY_NUMBER)
		std::cout << Engine::LogTime() << "Total Background Objects instancied : " << Instances01Container.size() + Instances02Container.size() + Instances03Container.size() + Instances04Container.size() + Instances05Container.size() << std::endl;
}

void CSubBackgroundHandler::RenderAllSubObjects(SDL_Renderer* Renderer, std::vector<CSubAnimatedTexture*> &Container)
{
	for (auto Object : Container)
	{
		Object->RenderTexture(
			Renderer,
			Object->GetAnimatedTextureContainer()->x,
			Object->GetAnimatedTextureContainer()->y,
			Object->GetAnimatedTextureContainer()
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

	if (minX > 0) // on sort du cadre par la gauche aka bordel
	{
		for (int y = minY; y < AScreenHeight; y += Filter->GetHeightTexture() * 0.7)
		{
			Container.push_back(CreateNewTextureInstance(Filter, minX - Filter->GetWidthTexture() * 0.7, y));
		}
	}

	if (minY > 0) // on sort du cadre par la gauche aka bordel
	{
		for (int x = minX; x < AScreenWidth; x += Filter->GetWidthTexture() * 0.7)
		{
			Container.push_back(CreateNewTextureInstance(Filter, x, minY - Filter->GetHeightTexture() * 0.7));
		}
	}

	if (maxX + Filter->GetWidthTexture() * 0.7 < AScreenWidth) // on sort du cadre par la droite 
	{
		for (int y = minY; y < AScreenHeight; y += Filter->GetHeightTexture() * 0.7)
		{
			Container.push_back(CreateNewTextureInstance(Filter, maxX + Filter->GetWidthTexture() * 0.7, y));
		}
	}

	if (maxY + Filter->GetHeightTexture() * 0.7 < AScreenHeight) // on sort du cadre par la droite 
	{
		for (int x = minX; x < AScreenWidth; x += Filter->GetWidthTexture() * 0.7)
		{
			Container.push_back(CreateNewTextureInstance(Filter, x, maxY + Filter->GetHeightTexture() * 0.7));
		}
	}

	for (int i = 0; i < Container.size(); )
	{
		CSubAnimatedTexture* Object = Container[i];

		// trop en retrait à gauche
		if (Object->GetAnimatedTextureContainer()->x + Object->GetWidthTexture() * 0.7 < 0)
		{
			Container.erase(Container.begin() + i);
			delete Object;
		}
		else if (Object->GetAnimatedTextureContainer()->x > AScreenWidth)
		{
			Container.erase(Container.begin() + i);
			delete Object;
		}
		else if (Object->GetAnimatedTextureContainer()->y + Object->GetHeightTexture() * 0.7 < 0)
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
