#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet2c.h"
#include "projet2c.c"
#include <time.h>

int main()
{


    int rtraccueil=1,rtrmenuinfo=0,rtrmenuenregi=0, rtrliste=0, i; //variables pour le retour des menus
    bd_membre * m;
    bd_membre * adresse_membre;
    bd_livre * l;
    bd_livre * adresse_livre;
    int nb_membre, nb_livre;

    rtraccueil = menuaccueil();

    do{

        printf("\n");

        nb_membre = nombre_membre();
        nb_livre = nombre_livre();

        m = creer_tab_membre_dyn(nb_membre);
        remplir_tab_membre(m, nb_membre);

        l = creer_tab_livre_dyn(nb_livre);
        remplir_tab_livre(l, nb_livre);

        switch(rtraccueil){

        case 1 :
            rtrmenuinfo=menuinfo();

            switch(rtrmenuinfo){

            case 1 :
                rtrliste=listemembres(m,nb_membre);
                break;

            case 2 :
                rtrliste=listelivres(l,nb_livre);
                break;

            case 3 :
                printf("info livre");
                break;

            case 4 :
                printf("retard livre");
                break;

            case 5 :
                rtraccueil=menuaccueil();
                break;

            }

        break;

        case 2 :

            rtrmenuenregi=menuenregistrement();

             switch(rtrmenuenregi){

            case 1 :
                ajoutmembres(m, nb_membre);
                break;

            case 2 :
                ajoutlivres(l, nb_livre);
                break;

            case 3 :
                adresse_membre = suppression_membre(m, nb_membre);
                if (adresse_membre != m) {
                    nb_membre = nb_membre - 1;
                }
                m = adresse_membre;
                ecriture_fichier_avec_struct(m, l, nb_membre, nb_livre);
                break;

            case 4 :
                adresse_livre = suppression_livre(l, nb_livre);
                if (adresse_livre != l) {
                    nb_livre = nb_livre - 1;
                }
                l = adresse_livre;
                ecriture_fichier_avec_struct(m, l, nb_membre, nb_livre);
                break;

            case 5 :
                nouvel_emprunt(m, l, nb_membre, nb_livre);
                ecriture_fichier_avec_struct(m, l, nb_membre, nb_livre);
                break;

            case 6 :
                restitution_emprunt(m, l, nb_membre, nb_livre);
                ecriture_fichier_avec_struct(m, l, nb_membre, nb_livre);
                break;

            case 7 :
                rtraccueil=menuaccueil();
                break;
            }

            break;

        break;

        case 3 :

            finlogiciel(); //permet de mettre un message de fin et de forcer l'arret

            break;

        case 4 :
                afficher_tab_membre(m,nb_membre);
                afficher_tab_livre(l, nb_livre);
                rtraccueil = menuaccueil();
    }

    if (rtrliste == 2) {
        rtraccueil = 3;
        finlogiciel();
    }

    free(m);
    free(l);
    for (i=0; i<nb_membre; i++) {
        if (m[i].cb_livre != 0) {
            free(m[i].livre);
        }
    }

    }while(rtraccueil != 3); //permet de faire un retour au menu principal

    return 0;
}
