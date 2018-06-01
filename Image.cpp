#include "Image.hpp"

Image::Image(string Nom, int rotation, int zoom)
{
	nom = Nom;
	string argument = Nom;
    char * arg = new char[nom.size() + 1]; // La fonction prend des char* en argument
	copy(nom.begin(), nom.end(), arg); // Permet de convertir un string en char*
	arg[nom.size()] = '\0';

    surface = IMG_Load(arg);
    surface = rotozoomSurface(surface, rotation, zoom, 1); //2e argument : rotation degré   ,   3e argument : coef zoom 
}

int Image::get_sizeX(Image image)
{
	return image.surface->w;
}

int Image::get_sizeY(Image image)
{
	return image.surface->h;
}

SDL_Surface *Image::get_surface(Image image)
{
	return image.surface;
}

int Image::get_x(Image image)
{
	return image.x;
}


int Image::get_y(Image image)
{
	return image.y;
}


void Image::set_x(Image image, int pos_x)
{
	image.x = pos_x;
}


void Image::set_y(Image image,int pos_y)
{
	image.y = pos_y;
}



Image::~Image()
{
	cout<<"Destructeur Image"<<endl;
}