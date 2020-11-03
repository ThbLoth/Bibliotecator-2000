#ifndef PROJET2C_H_INCLUDED
#define PROJET2C_H_INCLUDED

/* DÈfinitions des diffÈrentes structures nÈcessaires */

typedef struct{

    int jour;
    int mois;
    int annee;
}date;

typedef struct {
    char code[9];
    date date_pret;
}livre_emp;

typedef struct{

    char code[9];
    char titre[50];
    char auteur[30];
    int nbexp;
    int nbprete;
}bd_livre;

typedef struct{

    char nom[30];
    char prenom[30];
    char adressepostale[50];
    char adressemail[50];
    char metier[30];
    int cb_livre;
    livre_emp * livre;

    //struct (bd_livre).code codelivrepret; //‡ rÈgler
    //date dateretour;
}bd_membre;

/* DÈfinitions des diffÈrents prototypes */

void logoaccueil(void);
int menuaccueil(void);
void finlogiciel(void);
int menuinfo(void);
int menuenregistrement(void);
int listemembres(bd_membre*, int);
int listelivres(bd_livre*, int);
void ajoutmembres(bd_membre*, int);
void ajoutlivres(bd_livre*, int);
bd_membre * creer_tab_membre_dyn(int);
void remplir_tab_membre(bd_membre*, int);
void afficher_tab_membre(bd_membre*, int);
bd_livre * creer_tab_livre_dyn(int);
void remplir_tab_livre(bd_livre*, int);
void afficher_tab_livre(bd_livre*, int);
int nombre_membre (void);
int nombre_livre (void);
int nouvel_emprunt(bd_membre*, bd_livre*, int, int);
int restitution_emprunt(bd_membre*, bd_livre*, int, int);
void ecriture_fichier_avec_struct(bd_membre*, bd_livre*, int, int);
bd_membre* suppression_membre(bd_membre*, int);
bd_livre * suppression_livre(bd_livre*, int);

#endif // PROJET2C_H_INCLUDED
