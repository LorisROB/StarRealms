#ifndef IMAGE_HPP
#define IMAGE_HPP

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

using namespace std;

class Image
{
	private : //Attributs
	string nom; // nom de l'image
	SDL_Surface *surface;
	int x; //position
	int y;

	public :
	Image(string Nom,int rotation, int zoom); // Facteur par lequel on veut agrandir l'image
	int get_sizeX(Image image);
	int get_sizeY(Image image);
	int get_x(Image image);
	int get_y(Image image);
	void set_x(Image image,int pos_x);
	void set_y(Image image,int pos_y);
	SDL_Surface *get_surface(Image image);
	//SDL_PixelFormat get_format();
	~Image();
};
#endif