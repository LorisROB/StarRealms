#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <string.h>

using namespace std;

class Rectangle
{
	private: //Attributs
	SDL_Surface* rect;
	int largeurRectangle;
	int hauteurRectangle;


	/*string nom; // Nom unique de la forme "Rectx-y"
	int x; // x et y du corner gauche
	int y;
	int is_image; // vaut 0 si il y a une image et 1 sinon*/


	public :
	//Rectangle();
	Rectangle(int hauteur, int largeur); // Facteur par lequel on veut agrandir l'image
	SDL_Surface *get_rect();
	//string get_nom();
	//int get_x(Rectangle *R);
	//int get_y(Rectangle *R);
	//int get_is_image(Rectangle *R);
	//void set_is_image(Rectangle *R,int is_im);

	~Rectangle();
};
#endif