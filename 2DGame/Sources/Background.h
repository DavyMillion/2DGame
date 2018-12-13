#ifndef BACKGROUND_H
	#define BACKGROUND_H
	
	#include "SDL_headers.h"
	#include <vector>

	// D�claration Avanc�e
	class CSubTexture;
	class CSubAnimatedTexture;
	
	class CSubBackgroundHandler
	{
	public:
		// Constructeur
		CSubBackgroundHandler(int ScreenHeight, int ScreenWidth);

		// Destructeur
		~CSubBackgroundHandler();

		// Initialise tout les �l�ments essentiels � l'affichage du background
		void InitBackground();

		// Fait le rendu des �toiles du background
		void RenderStars(SDL_Renderer* Renderer);

		// Nos Getters
		CSubTexture* GetFilter01();
		CSubTexture* GetFilter02();
		CSubTexture* GetFilter03();
		CSubTexture* GetFilter04();
		CSubTexture* GetFilter05();

	private:

		int AScreenHeight;

		int AScreenWidth;

		// Filtre d'�toiles n�1
		CSubTexture* Filter01;

		// Filtre d'�toiles n�2
		CSubTexture* Filter02;

		// Filtre d'�toiles n�3
		CSubTexture* Filter03;

		// Filtre d'�toiles n�4
		CSubTexture* Filter04;

		// Filtre d'�toiles n�5
		CSubTexture* Filter05;

		std::vector <CSubAnimatedTexture*> FiltersContainer;

	};

	#endif