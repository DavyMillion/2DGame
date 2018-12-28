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

	/* 
	 Classe fille de CSubTexture qui nous permettra de g�rer les textures en mouvement 
	 (qui ne seront pas n�cessairement des acteurs), comme les textures du background, 
	 les lasers...
	*/
	
	class CSubAnimatedTexture : public CSubTexture
	{
	public:
		// Constructeur
		CSubAnimatedTexture();

		// Destructeur
		~CSubAnimatedTexture();

		// Retourne le Container de la texture
		SDL_Rect* GetAnimatedTextureContainer();

		/* Fonction surcharg�e permettant de saisir la 
		position � l'aide d'un SDL_Point ou de deux int */
		void SetAnimatedTexturePosition(SDL_Point* Point);
		void SetAnimatedTexturePosition(int x, int y);

		/* Permet de faire le lien � partir d'une texture
		entre ses donn�es bruts et le container */
		void SetupWidthAndHeightAnimatedTextureContainer();

	private:
		// Style de codage qui m'est propre
		typedef CSubTexture Super;

		// Le container de texture
		SDL_Rect* ATextureContainer;
	};

#endif