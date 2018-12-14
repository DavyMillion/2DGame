#ifndef TEXTURE
	#define TEXTURE
	
	#include "SDL_headers.h"
	#include <iostream>
	#include <string>
	
	class CSubTexture
	{
	public:
		// Initialisation des variables
		CSubTexture();

		// Désallocation de la mémoire
		~CSubTexture();

		// Chargement d'une texture via un fichier
		SDL_Texture* LoadTextureFromFile(SDL_Renderer* Renderer, std::string path);

		// Libération de la mémoire de ladite texture
		void FreeTexture();

		// Fait le rendu de la texture à une certaine position donnée
		void RenderTexture(SDL_Renderer* Renderer, int x, int y, SDL_Rect* Container = NULL, double Angle = 0.f, SDL_Point* CenterPosition = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

		// Nos Getters
		SDL_Texture* GetSDLTexture();
		int GetWidthTexture();
		int GetHeightTexture();

		void SetTexture(SDL_Texture* Texture);

	private:
		// La texture en elle-même
		SDL_Texture* ATexture;

		// Dimensions de la texture
		int ATextureWidth; // à récupérer dans la SDL_Texture
		int ATextureHeight; // """"
	};

	// on créé une classe fille pour pouvoir gérer les textures en mouvement 
	// (qui ne seront pas nécessairement des acteurs)

	class CSubAnimatedTexture : public CSubTexture
	{
	public:

		CSubAnimatedTexture();

		~CSubAnimatedTexture();

		SDL_Rect* GetAnimatedTextureContainer();
		void SetAnimatedTexturePosition(SDL_Point* Point);
		void SetAnimatedTexturePosition(int x, int y);
		void SetupWidthAndHeightAnimatedTextureContainer();

	private:
		typedef CSubTexture Super;

		SDL_Rect* ATextureContainer;

	};
#endif