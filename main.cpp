#include "Ecran.hpp"
#include "Image.hpp"

#define largeurFenetre 1600
#define hauteurFenetre 1000

int main(int argc, char const *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1) //On teste que la fenetre s'ouvre bien
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL");
        exit(EXIT_FAILURE);
    }
    
    int i=0;
    while(i<2)
    {
        // Menu
        Ecran menu(800,800, "noir.jpeg");
        menu.emplacements(menu,0);
        menu.ecrire_texte(menu,"CONTINUE",65,"AlphaWood.ttf",300,250,255,0,255);
        menu.ecrire_texte(menu,"ESCAPE",65,"AlphaWood.ttf",325,350,255,0,255);
        menu.ecrire_texte(menu,"SETTINGS",65,"AlphaWood.ttf",300,450,255,0,255);
        int flag = menu.interaction(menu,0); // On s'occupe de tous les évenements


        if (flag ==1)
        {
            // Table de jeu
            cout<<"Ecran"<<endl;
            Ecran ecran(largeurFenetre,hauteurFenetre,"fond.jpg");
            cout<<"Empalvements"<<endl;
            ecran.emplacements(ecran,flag);
            //ecran.compteur_score1(3, ecran);
            //ecran.compteur_score2(1, ecran);
            //ecran.compteur_attack(2,ecran);
            //ecran.compteur_argent(3, ecran);
            //ecran.compteur_vie(4, ecran);
            cout<<"Flip"<<endl;
            SDL_Flip(ecran.get_fenetre(ecran)); //On réactualise l'écran
            
            cout<<"interaction"<<endl;
            ecran.interaction(ecran, flag); // On s'occupe de tous les évenements
            cout<<"TailleX de l'écran : "<<ecran.get_sizeX_ecran(ecran)<<endl;
            cout<<"TailleY de l'écran : "<<ecran.get_sizeY_ecran(ecran)<<endl;
            i=i+2;
        }
    

        if (flag==2) //On est dans les settings
        {
            Ecran settings(1000,1000,"fond.jpg");
            settings.ecrire_texte(settings,"Ecrire les settings",30,"angelina.TTF",300,250,255,0,255);
            settings.ecrire_texte(settings,"Retour",65,"AlphaWood.ttf",300,450,255,0,255);
            SDL_Flip(settings.get_fenetre(settings)); //On réactualise l'écran
            settings.interaction(settings, flag); // On s'occupe de tous les évenements
            i++;
            

        }
    



        if (flag ==0)
        {
            SDL_Quit(); // Arrêt de la SDL
            i=i+2;
        }


    }
    



 

    return EXIT_SUCCESS; // Fermeture du programme
}