#include "Ecran.hpp"

Ecran::Ecran(int largeur,int hauteur, string fond)
{
	largeurEcran=largeur;
	hauteurEcran=hauteur;
	fenetre=NULL;
    SDL_WM_SetCaption("StarRealms", NULL); //Titre de la fenêtre
    fenetre = SDL_SetVideoMode(largeurEcran, hauteurEcran, 32, SDL_HWSURFACE); // L'écran pointe vers la fenetre 640*480 ouverte par setVideoMode
    format = fenetre->format;
    ////////////////IMAGE DE FOND///////////////

    SDL_Rect positionFond;
    positionFond.x=0;
    positionFond.y=0;

    Image imageDeFond = Image(fond,0,2); //Chargement de l'image
    SDL_SetAlpha(imageDeFond.get_surface(imageDeFond), SDL_SRCALPHA, 128); //2e argument : soit SDL_SRCALPHA soit 0 pour désactiver la trasparence , 3e argument : degré de transparence 0-->255
    SDL_BlitSurface(imageDeFond.get_surface(imageDeFond) , NULL, fenetre, &positionFond); //On affiche la rotation de la surface image.
}

int Ecran::get_sizeX_ecran(Ecran ecran)
{
    return(ecran.largeurEcran);
}

int Ecran::get_sizeY_ecran(Ecran ecran)
{
    return(ecran.hauteurEcran);
}


SDL_Surface *Ecran::get_fenetre(Ecran ecran)
{
	return(ecran.fenetre);
}

int Ecran::corner_x(int x, int y)
{
	if ((x<=2*largeurBase) && (y>=(hauteurFenetre-6*hauteurBase)) && (y<=hauteurFenetre-(hauteurFenetre-6*hauteurBase))) //2 premieres colonnes
    {
        if(x<=largeurBase) //Prmeiere colonne a gauche
        {
            int j=(hauteurFenetre-6*hauteurBase);
            while(y>j+hauteurBase)
                {
                    j = j + hauteurBase;
                }
                return 0;
        }

        else //deuxieme colonne a gauche
		{
			int j=(hauteurFenetre-6*hauteurBase);
			while(y>j+hauteurBase)
			{
				j = j + hauteurBase;
			}
			return largeurBase;

        }

	}


	else if ((x>=largeurFenetre-2*largeurBase) && (y>=(hauteurFenetre-6*hauteurBase)) && (y<=hauteurFenetre-(hauteurFenetre-6*hauteurBase)))
    {
        if(x<=largeurFenetre-largeurBase)
        {
            int j=(hauteurFenetre-6*hauteurBase);
            while(y>j+hauteurBase)
            {
                j = j + hauteurBase;
            }
            return largeurFenetre-2*largeurBase;
        }

        else
        {
            int j=(hauteurFenetre-6*hauteurBase);
            while(y>j+hauteurBase)
            {
                j = j + hauteurBase;
            }
            return largeurFenetre-largeurBase;
        }
    }

    else
    {
    	return -1;
    }
}

int Ecran::corner_y(int x, int y)
{
	if ((x<=2*largeurBase) && (y>=(hauteurFenetre-6*hauteurBase)) && (y<=hauteurFenetre-(hauteurFenetre-6*hauteurBase))) //2 premieres colonnes
    {
        if(x<=largeurBase) //Prmeiere colonne a gauche
        {
            int j=(hauteurFenetre-6*hauteurBase);
            while(y>j+hauteurBase)
                {
                    j = j + hauteurBase;
                }
                return j;
        }

        else //deuxieme colonne a gauche
		{
			int j=(hauteurFenetre-6*hauteurBase);
			while(y>j+hauteurBase)
			{
				j = j + hauteurBase;
			}
			return j;

        }

	}


	else if ((x>=largeurFenetre-2*largeurBase) && (y>=(hauteurFenetre-6*hauteurBase)) && (y<=hauteurFenetre-(hauteurFenetre-6*hauteurBase)))
    {
        if(x<=largeurFenetre-largeurBase)
        {
            int j=(hauteurFenetre-6*hauteurBase);
            while(y>j+hauteurBase)
            {
                j = j + hauteurBase;
            }
            return j;
        }

        else
        {
            int j=(hauteurFenetre-6*hauteurBase);
            while(y>j+hauteurBase)
            {
                j = j + hauteurBase;
            }
            return j;
        }
    }

    else
    {
    	return -1;
    }		


}


void Ecran::coller_image(int x, int y, Image imageAcoller, Ecran ecran, int transparence, int rotation, int echelle)
{
    SDL_Surface* surf_image = imageAcoller.get_surface(imageAcoller);
    SDL_Rect positionImage;
    positionImage.x = x;
    positionImage.y = y;
    if (transparence!=0)
        SDL_SetAlpha(surf_image, SDL_SRCALPHA, transparence);
    else
        SDL_SetAlpha(surf_image, 0, transparence);
    surf_image=rotozoomSurface(surf_image, rotation, echelle, 1); //2e argument : rotation degré   ,   3e argument : coef zoom 
    SDL_BlitSurface(surf_image, NULL, ecran.fenetre, &positionImage);
    SDL_Flip(ecran.get_fenetre(ecran)); //On réactualise l'écran
}







void Ecran::compteur_score1(int score, Ecran ecran)
{
    std::stringstream ss;
    ss << score;
    std::string str = ss.str();
    ecrire_texte(ecran, str,65,"angelina.TTF",10,10,255,255,255);
}

void Ecran::compteur_score2(int score, Ecran ecran)
{
    std::stringstream ss;
    ss << score;
    std::string str = ss.str();
    ecrire_texte(ecran, str,65,"angelina.TTF",ecran.get_sizeX_ecran(ecran)-60,10,255,255,255);
}

void Ecran::compteur_attack(int points, Ecran ecran)
{
    std::stringstream ss;
    ss << points;
    std::string str = ss.str();
    ecrire_texte(ecran, str,65,"angelina.TTF",(largeurFenetre-6*largeurAchat-10)/2 + 6.2*largeurAchat+20,20,255,255,255);
}

void Ecran::compteur_argent(int points, Ecran ecran)
{
    std::stringstream ss;
    ss << points;
    std::string str = ss.str();
    ecrire_texte(ecran, str,65,"angelina.TTF",(largeurFenetre-6*largeurAchat-10)/2 + 6.2*largeurAchat+20,80,255,255,255);
}


void Ecran::compteur_vie(int points, Ecran ecran)
{
    std::stringstream ss;
    ss << points;
    std::string str = ss.str();
    ecrire_texte(ecran, str,65,"angelina.TTF",(largeurFenetre-6*largeurAchat-10)/2 + 6.2*largeurAchat+20,140,255,255,255);
}




void Ecran::ecrire_texte(Ecran ecran, string Phrase, int taillePolice, string Font, int x, int y, int red, int green , int blue)
{

	SDL_Rect position;
	SDL_Surface *texte = NULL;
	TTF_Font *police = NULL;
	SDL_Color couleur = {red, green, blue};
	TTF_Init();

    string argument = Font;
    char *font = new char[argument.size() + 1]; // La fonction prend des char* en argument
    copy(argument.begin(), argument.end(), font); // Permet de convertir un string en char*
    font[argument.size()] = '\0';

	police = TTF_OpenFont(font, taillePolice);
    //TTF_SetFontStyle(police, TTF_STYLE_ITALIC | TTF_STYLE_UNDERLINE); //Italic et surligné

	argument = Phrase;
    char *phrase = new char[argument.size() + 1]; // La fonction prend des char* en argument
	copy(argument.begin(), argument.end(), phrase); // Permet de convertir un string en char*
	phrase[argument.size()] = '\0';

    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, phrase, couleur);
    position.x = x;
    position.y = y;
    SDL_BlitSurface(texte, NULL, ecran.fenetre, &position); /* Blit du texte */

    

   
    SDL_Flip(ecran.get_fenetre(ecran)); //On réactualise l'écran

    TTF_CloseFont(police);
    TTF_Quit();
}




int Ecran::interaction(Ecran ecran,int flag) // flag vaut 0 si menu et 1 sinon
{
    int continuer = 1;
    SDL_Event event;

    int x,y;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT: //Evenement pour quitter a fenetre
                continuer = 0;
                break;

            case SDL_KEYDOWN:
            	//std::cout<<"Touche de clavier pressée"<<std::endl;
            	switch (event.key.keysym.sym)
				{
    				case SDLK_ESCAPE: //Appui sur la touche Echap
    					continuer = 0; // On quitte le jeu
                        flag = 0;
    					return flag;
    					break;
				}
				break;

            case SDL_MOUSEBUTTONUP: //evenement souris
            	if (flag==1)
            	{
                	if (event.button.button == SDL_BUTTON_RIGHT)
                    {
                        x = corner_x(event.button.x,event.button.y); //On récupère les coordonnées de l'angle de l'emplacement ou l'on clique
                        y = corner_y(event.button.x,event.button.y);
                        Image carte = Image("carte.jpg",0,1);
                        if (x>=0 && y >= 0) //Si on est bien sur l'une des cases
                        {
                            ecran.coller_image(500,500,carte,ecran,0,90,4);
                        }
                    }

					if (event.button.button == SDL_BUTTON_LEFT && flag == 1) // Pour table de jeu
                	{
                    	x = corner_x(event.button.x,event.button.y); //On récupère les coordonnées de l'angle de l'emplacement ou l'on clique
                    	y = corner_y(event.button.x,event.button.y);
                        Image carte = Image("carte.jpg",0,1);
                    	if (x>=0 && y >= 0) //Si on est bien sur l'une des cases
                    	{
    					   ecran.coller_image(x,y,carte,ecran,0,0,1);
    					}
                	}
					
				}
				if (flag==0) //on est dans le menu
				{
					if (event.button.button == SDL_BUTTON_LEFT) // Pour menu
                	{
                		x=event.button.x;
                		y=event.button.y;
                    	if (x>=300 && x <= 600 && y>=250 && y<=325) //Si on clique sur CONTINUE
                    	{
    						continuer=0;
    						return 1;
    					}

    					if (x>=325 && x<=565 && y>=350 && y<=425) //Si on clique sur ESCAP
    					{
    						continuer =0;
    						return flag;
    					}

                        if (x>=300 && x<=600 && y>=450 && y<=525)//Si on clique sur Settings
                        {
                            continuer=0;
                            return 2;
                        }
                	}
				}

                if (flag==2)
                {
                    if (event.button.button == SDL_BUTTON_LEFT) // Pour menu
                    {
                        x=event.button.x;
                        y=event.button.y;
                        
                        if (x>=300 && x<=500 && y>=450 && y<=525)
                        {
                            //continuer = 0;
                            return 0;
                        }
                    }
                }
        }

    }
    return EXIT_SUCCESS;

}

void Ecran::dessiner_rectangle(int x, int y, int largeur, int hauteur, int r, int g, int b, Ecran ecran)
{
    SDL_Surface* Rect;
    SDL_Rect positionRect;
    Rect = SDL_CreateRGBSurface(SDL_HWSURFACE, largeur, hauteur, 32, 0, 0, 0, 0); //rectangle des bases, 4 derniers param inutiles
    positionRect.x=x;
    positionRect.y=y;
    SDL_FillRect(Rect, NULL, SDL_MapRGB(ecran.format, r, g, b)); // Dessin
    SDL_BlitSurface(Rect, NULL, ecran.fenetre, &positionRect); // Collage
}


void Ecran::emplacements(Ecran ecran, int flag)
{
	if (flag==1) //Si on est dans l'écran de jeu
	{
    	//////////////////////PLACEMENTS DES RECTANGLES DES BASES A GAUCHE////////////////////
    	int k=0,l=0;
    	
        for (int j=(ecran.get_sizeY_ecran(ecran)-6*hauteurBase) ; j<=(ecran.get_sizeY_ecran(ecran)-6*hauteurBase)+5*hauteurBase ; j= j+hauteurBase)
        {
            ecran.dessiner_rectangle(0,j,largeurBase, hauteurBase, 255-k, 255-k, 255-k, ecran);
            k=k+30;
            l++;
        }

    	//////////////////////PLACEMENTS DES RECTANGLES DES BASES A DROITE////////////////////
    	l=20;k=105;
    	
        for (int j=(ecran.get_sizeY_ecran(ecran)-6*hauteurBase) ; j<=(ecran.get_sizeY_ecran(ecran)-6*hauteurBase)+5*hauteurBase ; j= j+hauteurBase)
        {
            ecran.dessiner_rectangle(largeurFenetre-largeurBase,j,largeurBase, hauteurBase, k, k, k, ecran);
            k=k+30;
            l++;
        }
    	

    	//////////POSITION DES ACHATS//////////////////
    	l=0;
    	k=0;
    	for(int i=(largeurFenetre-6*largeurAchat-6)/2 ; i<=(largeurFenetre-6*largeurAchat-6)/2+4*largeurAchat ; i=i+largeurAchat)
    	{
            ecran.dessiner_rectangle(i,0,largeurAchat, hauteurAchat, 255-k, 255-k, 255-k, ecran);
        	k=k+10;
        	l++;
    	}
        ecran.dessiner_rectangle((largeurFenetre-6*largeurAchat-10)/2 + 5*largeurAchat+10,0,largeurAchat, hauteurAchat, 255-k-10, 255-k-10, 255-k-10, ecran);


        ///////////POSITION DE la main///////////////
        l=0;
        k=0;
        for(int i=largeurBase + (largeurFenetre-2*largeurBase-5*largeurMain)/2 ; i<=4*largeurMain + largeurBase + (largeurFenetre-2*largeurBase-5*largeurMain)/2 ; i=i+largeurMain)
        {
            for(int j=hauteurFenetre-hauteurMain ; j>=hauteurFenetre-3*hauteurMain ; j=j-hauteurMain)
            {
                ecran.dessiner_rectangle(i,j,largeurMain, hauteurMain, 255-k, 255-k, 255-k, ecran);
                k=k+10;
                l++;
            }
        }

        ecran.dessiner_rectangle(10,10,70, 50, 238, 130, 238, ecran);
        ecran.dessiner_rectangle(largeurFenetre-60,10,70, 50, 255, 127, 80, ecran);
        ecran.dessiner_rectangle((largeurFenetre-6*largeurAchat-10)/2 + 6.2*largeurAchat+20,20,50, 50, 255, 0, 0, ecran); //Attack
        ecran.dessiner_rectangle((largeurFenetre-6*largeurAchat-10)/2 + 6.2*largeurAchat+20,80,50, 50, 255, 255, 0, ecran); //Argent
        ecran.dessiner_rectangle((largeurFenetre-6*largeurAchat-10)/2 + 6.2*largeurAchat+20,140,50, 50, 0, 255, 0, ecran); //Vie
       

    }

    /*else //on est dans le menu
    {
    	SDL_Rect position1, position2;
    	SDL_Surface *Button[2] = {NULL};
		Button[0] = SDL_CreateRGBSurface(SDL_HWSURFACE, 300, 75, 32, 0, 0, 0, 0);
		position1.x=300;
		position1.y=300;
		Button[1] = SDL_CreateRGBSurface(SDL_HWSURFACE, 240, 75, 32, 0, 0, 0, 0);
		position2.x=325;
		position2.y=400;
		SDL_FillRect(Button[0], NULL, SDL_MapRGB(ecran.format, 255, 255, 255)); // Dessin
		SDL_BlitSurface(Button[0], NULL, ecran.fenetre, &position1); // Collage
		SDL_BlitSurface(Button[1], NULL, ecran.fenetre, &position2); // Collage

    }*/
    
}


Ecran::~Ecran()
{
	cout<<"Destructeur Ecran"<<endl;
}






