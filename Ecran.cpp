#include "Ecran.hpp"

Rectangle *R[40] = {NULL};
int compteur_rect = 0;

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
	if ((x<=largeurBase) && (y>=(hauteurFenetre-6*hauteurBase)) && (y<=hauteurFenetre-(hauteurFenetre-6*hauteurBase))) //premiere colonne
    {
        int j=(hauteurFenetre-6*hauteurBase);
        while(y>j+hauteurBase)
        {
            j = j + hauteurBase;
        }
        return 0;

	}


	else if ((x>=largeurFenetre-largeurBase) && (y>=(hauteurFenetre-6*hauteurBase)) && (y<=hauteurFenetre-(hauteurFenetre-6*hauteurBase)))
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
    	return -1;
    }

}

int Ecran::corner_y(int x, int y)
{
	if ((x<=largeurBase) && (y>=(hauteurFenetre-6*hauteurBase)) && (y<=hauteurFenetre-(hauteurFenetre-6*hauteurBase))) //premiere colonne
    {
    
        int j=(hauteurFenetre-6*hauteurBase);
        while(y>j+hauteurBase)
        {
            j = j + hauteurBase;
        }
        return j;
       

	}


	else if ((x>=largeurFenetre-largeurBase) && (y>=(hauteurFenetre-6*hauteurBase)) && (y<=hauteurFenetre-(hauteurFenetre-6*hauteurBase)))
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
    ecran.dessiner_rectangle(largeurBase+10,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,50, 50, 255, 0, 0, ecran);
    ecrire_texte(ecran, str,35,"LongTime.ttf",largeurBase+10,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25+2,0,0,0);
}

void Ecran::compteur_score2(int score, Ecran ecran)
{
    std::stringstream ss;
    ss << score;
    std::string str = ss.str();
    ecran.dessiner_rectangle(ecran.get_sizeX_ecran(ecran)-largeurBase-60,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,50, 50, 0, 0, 255, ecran);
    ecrire_texte(ecran, str,35,"LongTime.ttf",ecran.get_sizeX_ecran(ecran)-largeurBase-60+5,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25+2,0,0,0);
}

void Ecran::compteur_attack(int points, Ecran ecran)
{
    std::stringstream ss;
    ss << points;
    std::string str = ss.str();
    ecran.dessiner_rectangle(2.5*largeurMain-25+largeurBase+(ecran.get_sizeX_ecran(ecran)-2*largeurBase-5*largeurMain)/2,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,50, 50, 255, 0, 0, ecran); //Carré Attack
    ecrire_texte(ecran, str,35,"LongTime.ttf",5+2.5*largeurMain-25+largeurBase+(ecran.get_sizeX_ecran(ecran)-2*largeurBase-5*largeurMain)/2,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,0,0,0);
}

void Ecran::compteur_argent(int points, Ecran ecran)
{
    std::stringstream ss;
    ss << points;
    std::string str = ss.str();
    ecran.dessiner_rectangle(3.5*largeurMain-25+largeurBase+(ecran.get_sizeX_ecran(ecran)-2*largeurBase-5*largeurMain)/2,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,50, 50, 255, 255, 0, ecran); //Carré Argent
    ecrire_texte(ecran, str,35,"LongTime.ttf",5+3.5*largeurMain-25+largeurBase+(ecran.get_sizeX_ecran(ecran)-2*largeurBase-5*largeurMain)/2,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,0,0,0);
}


void Ecran::compteur_vie(int points, Ecran ecran)
{
    std::stringstream ss;
    ss << points;
    std::string str = ss.str();
    ecran.dessiner_rectangle(4.5*largeurMain-25+largeurBase+(ecran.get_sizeX_ecran(ecran)-2*largeurBase-5*largeurMain)/2,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,50, 50, 0, 255, 0, ecran); //Carré Vie
    ecrire_texte(ecran, str,35,"LongTime.ttf",5+4.5*largeurMain-25+largeurBase+(ecran.get_sizeX_ecran(ecran)-2*largeurBase-5*largeurMain)/2,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,0,0,0);
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
            	if (flag==1)//Dans le jeu
            	{
                	if (event.button.button == SDL_BUTTON_RIGHT)
                    {
                        x = corner_x(event.button.x,event.button.y); //On récupère les coordonnées de l'angle de l'emplacement ou l'on clique
                        y = corner_y(event.button.x,event.button.y);
                        /*for (int i = 0; i<compteur_rect; i++)
                        {
                            if (R[i]->x==x && R[i]->y==y)
                            {
                                if (R[i]->is_image==1) // Pas d'image 
                                {
                                    Image carte = Image("carte.jpg",0,1);
                                    if (x>=0 && y >= 0) //Si on est bien sur l'une des cases
                                    {
                                     ecran.coller_image(500,500,carte,ecran,0,90,4);
                                     R[i]->is_image = 0;
                                    }
                                } 
                                else
                                {
                                    cout << "Griser image" << endl;
                                }          
                            }
                        }*/
                        
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

                        if ((event.button.x>=0.6*largeurMain-25+largeurBase+(ecran.get_sizeX_ecran(ecran)-2*largeurBase-5*largeurMain)/2) && (event.button.x<=largeurMain+0.6*largeurMain-25+largeurBase+(ecran.get_sizeX_ecran(ecran)-2*largeurBase-5*largeurMain)/2) && (event.button.y>=hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25) && (event.button.y<=50+hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25))
                        {
                            cout<<"Tour fini !!"<<endl;
                        }

                	}
					
				}
				if (flag==0) //on est dans le menu
				{
					if (event.button.button == SDL_BUTTON_LEFT) // Pour menu
                	{
                		x=event.button.x;
                		y=event.button.y;
                    	if (x>=300 && x <= 510 && y>=250 && y<=325) //Si on clique sur CONTINUE
                    	{
    						continuer=0;
    						return 1;
    					}

    					if (x>=325 && x<=485 && y>=350 && y<=425) //Si on clique sur ESCAP
    					{
    						continuer =0;
    						return flag;
    					}

                        if (x>=200 && x<=620 && y>=460 && y<=510)//Si on clique sur les regles du jeu
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
                        
                        if (x>=300 && x<=500 && y>=740 && y<=790)
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
    Rectangle rectangle = Rectangle(largeur,hauteur);
    SDL_Rect positionRect;
    positionRect.x=x;
    positionRect.y=y;
    SDL_FillRect(rectangle.get_rect(), NULL, SDL_MapRGB(ecran.format, r, g, b)); // Dessin
    SDL_BlitSurface(rectangle.get_rect(), NULL, ecran.fenetre, &positionRect); // Collage
}


void Ecran::emplacements(Ecran ecran, int flag)
{
	if (flag==1) //Si on est dans l'écran de jeu
	{

        ecran.dessiner_rectangle(0, 0, largeurBase+10, hauteurFenetre, 255, 0, 0, ecran); //Fond rouge joueur 1
        ecran.dessiner_rectangle(ecran.get_sizeX_ecran(ecran)-largeurBase-10, 0, largeurBase+10, hauteurFenetre, 0, 0, 255, ecran); //Fond bleu joueur 2
        ecran.dessiner_rectangle(0.6*largeurMain-25+largeurBase+(ecran.get_sizeX_ecran(ecran)-2*largeurBase-5*largeurMain)/2,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,largeurMain,50,127,127,127, ecran);
        ecran.ecrire_texte(ecran, "Fin de tour", 30, "LongTime.ttf", 0.6*largeurMain-25+largeurBase+(ecran.get_sizeX_ecran(ecran)-2*largeurBase-5*largeurMain)/2,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25, 0, 0, 0);


    	//////////////////////PLACEMENTS DES RECTANGLES DES BASES A GAUCHE////////////////////
    	int k=0,l=0;
    	
        for (int j=(ecran.get_sizeY_ecran(ecran)-6*hauteurBase) ; j<=(ecran.get_sizeY_ecran(ecran)-6*hauteurBase)+5*hauteurBase ; j= j+hauteurBase)
        {
            ecran.dessiner_rectangle(0,j,largeurBase, hauteurBase, 255-k, 255-k, 255-k, ecran);
            k=k+30;
            l++;
            R[compteur_rect] = new Rectangle(0,j);
            compteur_rect++;
        }

    	//////////////////////PLACEMENTS DES RECTANGLES DES BASES A DROITE////////////////////
    	l=20;k=105;
    	
        for (int j=(ecran.get_sizeY_ecran(ecran)-6*hauteurBase) ; j<=(ecran.get_sizeY_ecran(ecran)-6*hauteurBase)+5*hauteurBase ; j= j+hauteurBase)
        {
            ecran.dessiner_rectangle(largeurFenetre-largeurBase,j,largeurBase, hauteurBase, k, k, k, ecran);
            k=k+30;
            l++;
            R[compteur_rect] = new Rectangle(largeurFenetre-largeurBase,j);
            compteur_rect++;
        }
    	

    	//////////POSITION DES ACHATS//////////////////
    	l=0;
    	k=0;
    	for(int i=(largeurFenetre-6*largeurAchat-6)/2 ; i<=(largeurFenetre-6*largeurAchat-6)/2+4*largeurAchat ; i=i+largeurAchat)
    	{
            ecran.dessiner_rectangle(i,0,largeurAchat, hauteurAchat, 255-k, 255-k, 255-k, ecran);
        	k=k+10;
        	l++;
            R[compteur_rect] = new Rectangle(i,0);
            compteur_rect++;
    	}
        ecran.dessiner_rectangle((largeurFenetre-6*largeurAchat-10)/2 + 5*largeurAchat+10,0,largeurAchat, hauteurAchat, 255-k-10, 255-k-10, 255-k-10, ecran);
        R[compteur_rect] = new Rectangle((largeurFenetre-6*largeurAchat-10)/2 + 5*largeurAchat+10,0);
        compteur_rect++;


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
                R[compteur_rect] = new Rectangle(i,j);
                compteur_rect++;
            }
        }

        ecran.dessiner_rectangle(largeurBase+10,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,50, 50, 255, 0, 0, ecran); //Carré Score joueur 1
        R[compteur_rect] = new Rectangle(10,10);
        compteur_rect++;
        ecran.dessiner_rectangle(ecran.get_sizeX_ecran(ecran)-largeurBase-60,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,50, 50, 0, 0, 255, ecran);//Carré Score joueur 2
        R[compteur_rect] = new Rectangle(largeurFenetre-60,10);
        compteur_rect++;
        ecran.dessiner_rectangle(2.5*largeurMain-25+largeurBase+(ecran.get_sizeX_ecran(ecran)-2*largeurBase-5*largeurMain)/2,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,50, 50, 255, 0, 0, ecran); //Carré Attack
        R[compteur_rect] = new Rectangle((largeurFenetre-6*largeurAchat-10)/2 + 6.2*largeurAchat+20,20);
        compteur_rect++;
        ecran.dessiner_rectangle(3.5*largeurMain-25+largeurBase+(ecran.get_sizeX_ecran(ecran)-2*largeurBase-5*largeurMain)/2,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,50, 50, 255, 255, 0, ecran); //Carré Argent
        R[compteur_rect] = new Rectangle((largeurFenetre-6*largeurAchat-10)/2 + 6.2*largeurAchat+20,80);
        compteur_rect++;
        ecran.dessiner_rectangle(4.5*largeurMain-25+largeurBase+(ecran.get_sizeX_ecran(ecran)-2*largeurBase-5*largeurMain)/2,hauteurAchat+(ecran.get_sizeY_ecran(ecran)-3*hauteurMain-hauteurAchat)/2-25,50, 50, 0, 255, 0, ecran); //Carré Vie
        R[compteur_rect] = new Rectangle((largeurFenetre-6*largeurAchat-10)/2 + 6.2*largeurAchat+20,140);
        compteur_rect++;


       

    }


    if (flag==0)
    {
        ecran.ecrire_texte(ecran,"CONTINUE",65,"BADABB__.TTF",300,250,255,255,0);
        ecran.ecrire_texte(ecran,"ESCAPE",65,"BADABB__.TTF",325,350,255,255,0);
        //ecran.dessiner_rectangle(200, 460, 420, 50,255,255,255, ecran);
        ecran.ecrire_texte(ecran,"RULES OF THE GAME",65,"BADABB__.TTF",200,450,255,255,0);

        /*SDL_Rect position1, position2;
        SDL_Surface *Button[2] = {NULL};
        Button[0] = SDL_CreateRGBSurface(SDL_HWSURFACE, 210, 75, 32, 0, 0, 0, 0);
        position1.x=300;
        position1.y=300;
        Button[1] = SDL_CreateRGBSurface(SDL_HWSURFACE, 160, 75, 32, 0, 0, 0, 0);
        position2.x=325;
        position2.y=400;
        SDL_FillRect(Button[0], NULL, SDL_MapRGB(ecran.format, 255, 255, 255)); // Dessin
        SDL_FillRect(Button[1], NULL, SDL_MapRGB(ecran.format, 255, 255, 255)); // Dessin
        SDL_BlitSurface(Button[0], NULL, ecran.fenetre, &position1); // Collage
        SDL_BlitSurface(Button[1], NULL, ecran.fenetre, &position2); // Collage */
    }

    if (flag==2)
    {

        Image rules = Image("Rules.png",0,1);
        ecran.coller_image(0, 0, rules, ecran, 0, 0 , 1);
        //ecran.dessiner_rectangle(300, 740, 200, 50, 255, 255, 255, ecran);

    }
    
}


Ecran::~Ecran()
{
	cout<<"Destructeur Ecran"<<endl;
}






