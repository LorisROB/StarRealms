#ifndef ECRAN_HPP
#define ECRAN_HPP

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

#include "Image.hpp"
#include "Rectangle.hpp"

using namespace std;

#define largeurFenetre 1600
#define hauteurFenetre 1000
#define largeurBase 200 
#define hauteurBase 150
#define largeurAchat 150
#define hauteurAchat 200
#define largeurMain 150
#define hauteurMain 200

class Ecran
{
	private : //Attributs
	int largeurEcran;
	int hauteurEcran;
	SDL_Surface *fenetre;
	SDL_PixelFormat *format;

	


	public :
	Ecran(int largeur, int hauteur, string fond);
	int get_sizeX_ecran(Ecran ecran);
	int get_sizeY_ecran(Ecran ecran);

	int interaction(Ecran ecran, int flag);
	//SDL_PixelFormat get_format();
	SDL_Surface *get_fenetre(Ecran ecran);
	void emplacements(Ecran ecran,int flag);
	void dessiner_rectangle(int x, int y, int largeur, int hauteur, int r, int g, int b, Ecran ecran);
	int corner_x(int x, int y);
	int corner_y(int x, int y);
	void coller_image(int x, int y, Image imageAcoller, Ecran ecran, int transparence, int rotation , int echelle);
	void ecrire_texte(Ecran ecran , string Phrase, int taillePolice , string Font, int x, int y,int red, int green, int blue);
	void effacer_texte(SDL_Surface *texte);
	void compteur_score1(int score, Ecran ecran);
	void compteur_score2(int score, Ecran ecran);
	void compteur_attack(int points, Ecran ecran);
	void compteur_argent(int points, Ecran ecran);
	void compteur_vie(int points, Ecran ecran);
	~Ecran();
};
#endif