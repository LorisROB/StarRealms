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
        int flag = menu.interaction(menu,0); // On s'occupe de tous les évenements


        if (flag ==1)
        {
            // Table de jeu
            Ecran ecran(largeurFenetre,hauteurFenetre,"noir.jpeg");
            ecran.emplacements(ecran,flag);
            int nb, p=0;
            ecran.compteur_score1(56, ecran);
            ecran.compteur_score2(99, ecran);
            ecran.compteur_attack(99,ecran);
            ecran.compteur_argent(3, ecran);
            ecran.compteur_vie(4, ecran);
            SDL_Flip(ecran.get_fenetre(ecran)); //On réactualise l'écran
            ecran.interaction(ecran, flag); // On s'occupe de tous les évenements
            cout<<"TailleX de l'écran : "<<ecran.get_sizeX_ecran(ecran)<<endl;
            cout<<"TailleY de l'écran : "<<ecran.get_sizeY_ecran(ecran)<<endl;
            i=i+2;
        }
    

        if (flag==2) //On est dans le help
        {
            Ecran help(800,800,"noir.jpeg");
            help.emplacements(help,flag);
            //help.ecrire_texte(help,"Ecrire les help",30,"angelina.TTF",300,250,255,0,255);
            //help.ecrire_texte(help,"Retour",65,"AlphaWood.ttf",300,450,255,0,255);
            SDL_Flip(help.get_fenetre(help)); //On réactualise l'écran
            help.interaction(help, flag); // On s'occupe de tous les évenements
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