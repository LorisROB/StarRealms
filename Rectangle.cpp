#include "Rectangle.hpp"
using namespace std;

Rectangle::Rectangle(int largeur, int hauteur)
{
	/*x = corner_x;
	y = corner_y;
	nom = "Rect" + to_string(x) +"-" + to_string(y);
	is_image = 1; // N'a pas d'image à la création
	SDL_Rect positionRect;*/
	hauteurRectangle = hauteur;
	largeurRectangle=largeur;
    rect = SDL_CreateRGBSurface(SDL_HWSURFACE, largeurRectangle, hauteurRectangle, 32, 0, 0, 0, 0); //rectangle des bases, 4 derniers param inutiles
}


SDL_Surface *Rectangle::get_rect()
{
	return rect;
}
/*
int get_x(Rectangle *R)
{
	return R->x;
	
}

int get_y(Rectangle *R)
{
	return R->y;
}

int get_is_image(Rectangle* R)
{
	return R->is_image;
}

void set_is_image(Rectangle* R, int is_im)
{
	R->is_image = is_im;
}*/

Rectangle::~Rectangle()
{
	cout<<"Destructeur Rectangle"<<endl;
}