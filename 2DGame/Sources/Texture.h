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

		// D�sallocation de la m�moire
		~CSubTexture();

		// Chargement d'une texture via un fichier
		SDL_Texture* LoadTextureFromFile(SDL_Renderer* Renderer, std::string path);

		// Lib�ration de la m�moire de ladite texture
		void FreeTexture();

		// Fait le rendu de la texture � une certaine position donn�e
		void RenderTexture(SDL_Renderer* Renderer, int x, int y, SDL_Rect* Container = NULL, double Angle = 0.f, SDL_Point* CenterPosition = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

		// Nos Getters
		SDL_Texture* GetSDLTexture();
		int GetWidthTexture();
		int GetHeightTexture();

		void SetTexture(SDL_Texture* Texture);

	private:
		// La texture en elle-m�me
		SDL_Texture* ATexture;

		// Dimensions de la texture
		int ATextureWidth; // � r�cup�rer dans la SDL_Texture
		int ATextureHeight; // """"
	};

	// on cr�� une classe fille pour pouvoir g�rer les textures en mouvement 
	// (qui ne seront pas n�cessairement des acteurs)

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