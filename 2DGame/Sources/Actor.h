#ifndef ACTOR
	#define ACTOR

	#include "SDL_headers.h"
	#include <iostream>

	class CSubTexture;

	class CActor
	{
	public:
		// Initialisation des variables
		CActor();

		// Désallocation de la mémoire
		~CActor();

		// Retourne l'objet texture de l'Actor
		CSubTexture* GetActorTextureObject();

		// Retourne la position absolu du centre de l'Actor
		SDL_Point* GetActorAbsolutePosition();

		// Retourne la position relative au Container du centre de l'Actor
		SDL_Point* GetActorCenterPositionInContainerGrid();

		// Retourne le container de texture de l'Actor
		SDL_Rect* GetActorTextureContainer();
	
		// Retourne l'angle d'inclinaison relatif à la normale (y) de l'actor en degrée
		double GetActorRelativeAngle();
		
		// Positionne le centre de l'actor à la position indiquée par X et Y
		void SetActorPosition(int CoordX, int CoordY);

		void SetActorTexture(SDL_Renderer* Renderer, std::string path);
		void SetActorTextureContainer(SDL_Rect*);

		// Incrémentation/Décrémentation de l'angle d'inclinaison de l'Actor
		void SetActorRotation(int);

	protected:
		// Re-calcule à chaque appel la position absolue du centre de l'actor
		void CalculateAbsoluteActorCenter(SDL_Point*);

		// Pointeur sur la texture de l'actor
		CSubTexture* ATextureObject;

		// Position absolu dans la grille 2D
		// Les champs x et y indiquent la position du centre de gravité de l'actor
		SDL_Point* AAbsolutePosition;
		
		SDL_Point* ACenterPositionInContainerGrid;

		/* Rectangle englobant la texture de l'acteur dans la grille 2D
		Descriptif des champs de cette structure :
		-> x : coordonnée en x du coin haut gauche du Container (rectangulaire)
		-> y : coordonnée en y du coin haut gauche du Container (rectangulaire)
		-> h : hauteur du rectangle
		-> w : largeur du rectangle
		Le container est fixe par rapport à theta */
		SDL_Rect* ATextureContainer;
		
		// Angle relatif à la normale (y), theta croissant -> sens des aiguilles d'une montre
		double ARelativeAngle;
	};

#endif // !ACTOR