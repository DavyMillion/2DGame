#ifndef BACKGROUND_H
	#define BACKGROUND_H
	
	#include "SDL_headers.h"
	#include <vector>

	// Déclaration Avancée
	class CSubTexture;
	class CSubAnimatedTexture;
	
	class CSubBackgroundHandler
	{
	public:
		// Constructeur
		CSubBackgroundHandler(int ScreenHeight, int ScreenWidth);

		// Destructeur
		~CSubBackgroundHandler();

		// Initialise tout les élèments essentiels à l'affichage du background
		void InitBackground();

		// Fait le rendu des étoiles du background
		void RenderStars(SDL_Renderer* Renderer);
		void RenderAllSubObjects(SDL_Renderer* Renderer, std::vector<CSubAnimatedTexture*> &Container);
		void HandleAllSubObjects(CSubTexture* Filter, std::vector<CSubAnimatedTexture*> &Container);

		// Nos Getters
		CSubTexture* GetFilter01();
		CSubTexture* GetFilter02();
		CSubTexture* GetFilter03();
		CSubTexture* GetFilter04();
		CSubTexture* GetFilter05();

	private:

		int AScreenHeight;

		int AScreenWidth;

		// Filtre d'étoiles n°1
		CSubTexture* Filter01;

		// Filtre d'étoiles n°2
		CSubTexture* Filter02;

		// Filtre d'étoiles n°3
		CSubTexture* Filter03;

		// Filtre d'étoiles n°4
		CSubTexture* Filter04;

		// Filtre d'étoiles n°5
		CSubTexture* Filter05;

		std::vector <CSubAnimatedTexture*> FiltersContainer;

		std::vector <CSubAnimatedTexture*> Instances01Container;
		std::vector <CSubAnimatedTexture*> Instances02Container;
		std::vector <CSubAnimatedTexture*> Instances03Container;
		std::vector <CSubAnimatedTexture*> Instances04Container;
		std::vector <CSubAnimatedTexture*> Instances05Container;
	};

	#endif