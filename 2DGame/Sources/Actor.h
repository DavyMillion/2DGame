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

		// D�sallocation de la m�moire
		~CActor();

		// Retourne l'objet texture de l'Actor
		CSubTexture* GetActorTextureObject();

		// Retourne la position absolu du centre de l'Actor
		SDL_Point* GetActorAbsolutePosition();

		// Retourne la position relative au Container du centre de l'Actor
		SDL_Point* GetActorCenterPositionInContainerGrid();

		// Retourne le container de texture de l'Actor
		SDL_Rect* GetActorTextureContainer();
	
		// Retourne l'angle d'inclinaison relatif � la normale (y) de l'actor en degr�e
		double GetActorRelativeAngle();
		
		// Positionne le centre de l'actor � la position indiqu�e par X et Y
		void SetActorPosition(int CoordX, int CoordY);

		void SetActorTexture(SDL_Renderer* Renderer, std::string path);
		void SetActorTextureContainer(SDL_Rect*);

		// Incr�mentation/D�cr�mentation de l'angle d'inclinaison de l'Actor
		void SetActorRotation(int);

	protected:
		// Re-calcule � chaque appel la position absolue du centre de l'actor
		void CalculateAbsoluteActorCenter(SDL_Point*);

		// Pointeur sur la texture de l'actor
		CSubTexture* ATextureObject;

		// Position absolu dans la grille 2D
		// Les champs x et y indiquent la position du centre de gravit� de l'actor
		SDL_Point* AAbsolutePosition;
		
		SDL_Point* ACenterPositionInContainerGrid;

		/* Rectangle englobant la texture de l'acteur dans la grille 2D
		Descriptif des champs de cette structure :
		-> x : coordonn�e en x du coin haut gauche du Container (rectangulaire)
		-> y : coordonn�e en y du coin haut gauche du Container (rectangulaire)
		-> h : hauteur du rectangle
		-> w : largeur du rectangle
		Le container est fixe par rapport � theta */
		SDL_Rect* ATextureContainer;
		
		// Angle relatif � la normale (y), theta croissant -> sens des aiguilles d'une montre
		double ARelativeAngle;
	};

#endif // !ACTOR