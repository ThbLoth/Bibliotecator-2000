#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet2c.h"
#include <time.h>

bd_membre * creer_tab_membre_dyn(int taille) {
    bd_membre * tab;
    tab = (bd_membre*) malloc(taille * sizeof (bd_membre));
    if (tab == NULL) {
        printf("Mémoire non allouée");
        exit(0);
    }
    return tab;
}

livre_emp * creer_tab_livre_emp_dyn(int taille) {
    livre_emp * tab;
    tab = (livre_emp*) malloc(taille * sizeof (livre_emp));
    if (tab == NULL) {
        printf("Mémoire non allouée");
        exit(0);
    }
    return tab;
}

void remplir_tab_membre(bd_membre * m, int taille) {
    FILE *ptrFic = fopen("listemembre.txt", "r");
    char texte[256];
    int i, j, nombre, nombre2, nombre3;

    if(ptrFic==NULL)
    {
        printf("Erreur m%cmoire",130);
        exit(1);
    }

    for (i=0; i<taille; i++) {
        fgets(texte,30,ptrFic);
        strcpy(m[i].nom, texte);

        fgets(texte,30,ptrFic);
        strcpy(m[i].prenom, texte);

        fgets(texte,50,ptrFic);
        strcpy(m[i].adressepostale, texte);

        fgets(texte,50,ptrFic);
        strcpy(m[i].adressemail, texte);

        fgets(texte,30,ptrFic);
        strcpy(m[i].metier, texte);

        fscanf(ptrFic,"%d\n", &nombre);
        m[i].cb_livre = nombre;

        m[i].livre = creer_tab_livre_emp_dyn(m[i].cb_livre);
        for (j=0; j<m[i].cb_livre; j++) {
            fscanf(ptrFic,"%s %d %d %d\n",texte,&nombre,&nombre2,&nombre3);
            strcpy(m[i].livre[j].code, texte);
            m[i].livre[j].date_pret.jour = nombre;
            m[i].livre[j].date_pret.mois = nombre2;
            m[i].livre[j].date_pret.annee = nombre3;
        }

        fgets(texte,255,ptrFic);
    }
}

void afficher_tab_membre(bd_membre * m, int taille) {
    int i, j;
    for (i=0; i<taille; i++) {
        printf("%s",m[i].nom);
        printf("%s",m[i].prenom);
        printf("%s",m[i].adressepostale);
        printf("%s",m[i].adressemail);
        printf("%s",m[i].metier);
        printf("%d\n",m[i].cb_livre);
        for (j=0; j<m[i].cb_livre; j++) {
            printf("%s %d/%d/%d\n",m[i].livre[j].code,m[i].livre[j].date_pret.jour,m[i].livre[j].date_pret.mois,m[i].livre[j].date_pret.annee);
        }
        printf("\n");
    }
}

bd_livre * creer_tab_livre_dyn(int taille) {
    bd_livre * tab;
    tab = (bd_livre*) malloc(taille * sizeof (bd_livre));
    if (tab == NULL) {
        printf("Mémoire non allouée");
        exit(0);
    }
    return tab;
}

void remplir_tab_livre(bd_livre * l, int taille) {
    FILE *ptrFic = fopen("listelivre.txt", "r");
    char texte[256];
    int nombre;
    int i;

    if(ptrFic==NULL)
    {
        printf("Erreur m%cmoire",130);
        exit(1);
    }

    for (i=0; i<taille; i++) {
        fgets(texte,8,ptrFic);
        strcpy(l[i].code, texte);
        fgets(texte,255,ptrFic);

        fgets(texte,50,ptrFic);
        strcpy(l[i].titre, texte);

        fgets(texte,30,ptrFic);
        strcpy(l[i].auteur, texte);

        fscanf(ptrFic,"%d\n", &nombre);
        l[i].nbexp = nombre;

        fscanf(ptrFic,"%d\n", &nombre);
        l[i].nbprete = nombre;

        fgets(texte,255,ptrFic);

    }
}

void afficher_tab_livre(bd_livre * l, int taille) {
    int i;
    for (i=0; i<taille; i++) {
        printf("%s\n",l[i].code);
        printf("%s",l[i].titre);
        printf("%s",l[i].auteur);
        printf("%d\n",l[i].nbexp);
        printf("%d\n",l[i].nbprete);
        printf("\n");
    }
}

void logoaccueil(){ //logo bibliotÈcator a mettre PARTOUT

    int i;
    int longlogo = 23;

    printf("\t\t\t\t\t%c",201);

    for(i=0;i<longlogo;i++)
    {
        printf("%c",205);
    }
    printf("%c\n",187);

    printf("\t\t\t\t\t%c  Blibliot%ccator 2000  %c\n",186,130,186);

    printf("\t\t\t\t\t%c",200);

    for(i=0;i<longlogo;i++)
    {
        printf("%c",205);
    }

    printf("%c\n",188);
}

int menuaccueil(){ //menu du dÈbut, ou l'on choisit parmi enregistrer un nvel utilisateur ou de voir des infos

    int choix;

    do
    {
        system("cls");
        logoaccueil();

        printf("Bienvenue sur le Bibliot%cator 2000, programme de gestion de librarie !\n",130);
        printf("\n");
        printf("Que souhaitez-vous faire ?\n") ;
        printf("(1) Informations sur les membres, les livres, les emprunts...\n");
        printf("(2) Enregistrer une nouvelle donn%ce.\n",130);
        printf("(3) Quitter le programme.\n");
        printf("\n");

        printf("Entrer votre choix ici : ");
        scanf("%d",&choix);

    }while(choix<1 || choix>4);


    return choix;

}

void finlogiciel(){

    system("cls");
    logoaccueil();
    printf("Merci d'avoir utils%c notre logiciel, %c bientot !",130,133);
    exit(0);

}

int menuinfo(){ //menu en lecture seule, ou l'on voit toutes les infos

    int choix;

    do{

    system("cls");
    logoaccueil();

    printf("\n");
    printf("Que souhaitez-vous consulter ?\n");
    printf("\n");
    printf("(1) Consulter la liste des membres enregistr%cs.\n",130);
    printf("(2) Consulter la liste des livres enregistr%cs.\n",130);
    printf("(3) Chercher des informations sur un livre.\n");
    printf("(4) Voir les livres non rendus et en retard.\n");
    printf("(5) Retour au menu principal.\n");
    printf("\n");

    printf("Entrer votre choix ici : \n");
    scanf("%d",&choix);

    }while(choix<1 || choix>5);

    return choix;
}

int menuenregistrement(){ //menu en Ècriture, ou l'on enregistre une nvelle donnÈe

    int choix = 0;

    do{

        system("cls");
        logoaccueil();

        printf("\n");
        printf("Que souhaitez-vous consulter ?\n");
        printf("\n");
        printf("(1) Ajouter un nouveau membre.\n");
        printf("(2) Ajouter un nouveau livre.\n");
        printf("(3) D%csinscrire un membre de nos listes\n",130);
        printf("(4) Supprimer un livre\n");
        printf("(5) Enregistrer un emprunt.\n");
        printf("(6) Retour d'un livre emprunt%c.\n",130);
        printf("(7) Retour au menu principal.\n");
        printf("\n");

        printf("Entrer votre choix ici : \n");
        //while( getchar() != '\n');
        scanf("%d",&choix);

    }while(choix<1 || choix>7);

    return choix;
}

int listemembres(bd_membre *m, int nb_membre) {

    int i,j;
    char transi[50];
    int choix;
    char** tab;

    tab = (char**) malloc(nb_membre * sizeof(char*));

    if (tab == NULL)
    {
        printf("Erreur m%cmoire",130);
        exit(1);
    }

    do
    {
        system("cls");

        logoaccueil();

        printf("\n");
        printf("Liste des membres enregistr%cs :\n",130);

        for(i=0;i<nb_membre;i++)
        {
            tab[i] = m[i].nom;
        }

        for(i=0;i<nb_membre;i++)
        {
            for(j=(i+1);j<nb_membre;j++)
            {
                if (strcmp(tab[i],tab[j]) < 0)
                {
                    strcpy(transi,tab[i]);
                    strcpy(tab[i],tab[j]);
                    strcpy(tab[j],transi);
                }
            }
        }

        for(i=nb_membre-1;i>=0;i--)
            printf("%s\n",tab[i]);

        printf("\n");

        printf("Que souhaitez-vous faire ?\n");
        printf("(1) Retourner au menu d'informations.\n");
        printf("(2) Quitter le programme.\n");
        printf("\n");
        printf("Entrer votre choix ici : ");
        scanf("%d",&choix);
    }while(choix<1 || choix>2);

    free(tab);
    return choix;
}


int listelivres(bd_livre *l, int nb_livre) {

    int choix;
    int a,i,j;
    char transi[50];
    char **tab;

    tab = (char**) malloc(nb_livre*sizeof(char*));

    if(tab == NULL)
    {
        printf("Erreur m%cmoire",130);
        exit(1);
    }


    do
    {
        system("cls");
        logoaccueil();
        printf("\n");
        printf("De quelle fa%con voulez-vous afficher la liste des livres ?\n",135);
        printf("(1)Par titre.\n(2)Par auteur.\n(3)Par code.\n");
        printf("Entrez votre choix ici : ");
        scanf("%d",&a);

    }while(a<1 || a>3);

    if(a==1){

        system("cls");
        logoaccueil();

        printf("Liste des livres par titre:\n\n");

        for(i=0;i<nb_livre;i++)
        {
            tab[i] = l[i].titre;
        }

        for(i=0;i<nb_livre;i++)
        {
            for(j=(i+1);j<nb_livre;j++)
            {
                if (strcmp(tab[i],tab[j]) < 0)
                {
                    strcpy(transi,tab[i]);
                    strcpy(tab[i],tab[j]);
                    strcpy(tab[j],transi);
                }
            }
        }

        for(i=nb_livre-1;i>=0;i--)
            printf("%s\n",tab[i]);

        do{
            printf("Que souhaitez-vous faire ?\n");
            printf("(1) Retourner au menu d'informations.\n");
            printf("(2) Quitter le programme.\n");
            printf("\n");
            printf("Entrer votre choix ici : ");
            scanf("%d",&choix);
        }while(choix<1 || choix>2);

        return choix;
    }

    else if (a==2){
        system("cls");
        logoaccueil();

        printf("Liste des livres par auteur:\n\n");

        for(i=0;i<nb_livre;i++)
        {
            tab[i] = l[i].auteur;
        }

        for(i=nb_livre-1;i>=0;i--)
                for(j=0;j<nb_livre;j++)
                {
                    if (strcmp(tab[j],l[i].auteur) ==   0)
                    {
                        printf("Les livres %ccrits par %s",130,tab[i]);
                        printf("%s\n",l[j].titre);
                    }



                }


        do{
            printf("Que souhaitez-vous faire ?\n");
            printf("(1) Retourner au menu d'informations.\n");
            printf("(2) Quitter le programme.\n");
            printf("\n");
            printf("Entrer votre choix ici : ");
            scanf("%d",&choix);
        }while(choix<1 || choix>2);

        return choix;
    }

    else if (a==3)
    {
        system("cls");
        logoaccueil();

        printf("Liste des livres par code:\n\n");

        for(i=0;i<nb_livre;i++)
        {
            tab[i] = l[i].code;
        }

        for(i=0;i<nb_livre;i++)
                for(j=0;j<nb_livre;j++)
                {
                    if (strcmp(tab[j],l[i].code) ==   0)
                    {
                        printf("CODE : %s\n",tab[i]);
                        printf("TITRE :%s\n",l[j].titre);
                    }


                }


        do{
            printf("Que souhaitez-vous faire ?\n");
            printf("(1) Retourner au menu d'informations.\n");
            printf("(2) Quitter le programme.\n");
            printf("\n");
            printf("Entrer votre choix ici : ");
            scanf("%d",&choix);
        }while(choix<1 || choix>2);

        return choix;
    }



}

void ajoutmembres(bd_membre * m, int nb_membre) {

    int i, j, egalite;
    FILE *ptrFic = fopen("listemembre.txt", "a");
    char nom[30];
    char prenom[30];
    char adresse[30];
    char mail[30];
    char metier[30];

    if(ptrFic==NULL)
    {
        printf("Erreur m%cmoire",130);
        exit(1);
    }

    system("cls");
    logoaccueil();

    gets(nom);
    printf("Entrer le nom du nouveau membre :\n");
    gets(nom);

    printf("Entrer le pr%cnom du nouveau membre :\n",130);
    gets(prenom);

    for (i=0; i<nb_membre; i++) {
        egalite = 1;
        for (j=0; j<strlen(nom); j++) {
            if (nom[j] != m[i].nom[j]) {
                egalite = 0;
            }
        }
        for (j=0; j<strlen(prenom); j++) {
            if (prenom[j] != m[i].prenom[j]) {
                egalite = 0;
            }
        }
        if (egalite == 1) {
            printf("Le membre existe deja !\n");
            break;
        }
    }

    if (egalite == 0) {
        printf("Entrer l'adresse du nouveau membre :\n");
        gets(adresse);

        printf("Entrer l'adresse email du nouveau membre :\n");
        gets(mail);

        printf("Entrer la profession du nouveau membre :\n");
        gets(metier);

        fprintf(ptrFic,"%s\n%s\n%s\n%s\n%s\n0\n*\n",nom,prenom,adresse,mail,metier);
        fclose(ptrFic);

        printf("\n");
        printf("Le nouveau membre a bien %ct%c enregistr%c\n",130,130,130);

    }
}

void ajoutlivres(bd_livre * l, int nb_livre) {

    int choix, i, j, egalite, numero=-1, numero2;
    FILE *ptrFic = fopen("listelivre.txt", "a");
    char code[20];
    char titre[50];
    char auteur[20];
    char num_c[20];
    int nb_exp;

    if(ptrFic==NULL)
    {
        printf("Erreur m%cmoire",130);
        exit(1);
    }

    system("cls");
    logoaccueil();

    gets(titre);
    printf("Entrer le titre du livre :\n");
    gets(titre);
    printf("\n");

    for (i=0; i<nb_livre; i++) {
        egalite = 1;
        for (j=0; j<strlen(titre); j++) {
            if (titre[j] != l[i].titre[j]) {
                egalite = 0;
            }
        }
        if (egalite == 1) {
            printf("Le livre existe d%cj%c !\n",130,133);
            break;
        }
    }

    if (egalite == 0) {
        printf("Entrer le type du livre\n");
        printf("- ROM pour un roman\n");
        printf("- BAD pour une bande dessinée\n");
        printf("- POL pour un policier\n");
        gets(code);

        for (i=0; i<nb_livre; i++) {
            egalite = 1;
            for (j=0; j<3; j++) {
                if (code[j] != l[i].code[j]) {
                    egalite = 0;
                }
            }
            if (egalite == 1) {
                numero2 = 100 * (l[i].code[4] - 48) + 10 * (l[i].code[5] - 48) + l[i].code[6] - 48;
                if (numero<numero2) {
                    numero = numero2;
                }
            }
        }

        numero = numero + 1;
        sprintf(num_c, "%d", numero);
        code[3] = '-';

        if (numero<10) {
            code[4] = '0';
            code[5] = '0';
            code[6] = num_c[0];
        }

        else if (numero<100) {
            code[4] = '0';
            code[5] = num_c[0];
            code[6] = num_c[1];
        }

        else {
            code[4] = num_c[0];
            code[5] = num_c[1];
            code[6] = num_c[2];
        }

        printf("Entrer l'auteur du livre :\n");
        gets(auteur);

        printf("Entrer le nombre d'exemplaires du livre :\n");
        scanf("%d",&nb_exp);

        fprintf(ptrFic,"%s\n%s\n%s\n%d\n0\n*\n", code,titre,auteur,nb_exp);
        fclose(ptrFic);

        printf("\n");
        printf("Le nouveau livre a bien %ct%c enregistr%c\n",130,130,130,130);
    }
}

int nombre_membre (void) {
    FILE *ptrFic = fopen("listemembre.txt", "r");
    char texte[256];
    int nb_membre = 0;

    if(ptrFic==NULL)
    {
        printf("Erreur m%cmoire",130);
        exit(1);
    }

    while(fgets(texte,255,ptrFic) != NULL) {
        if (texte[0] == '*') {
            nb_membre = nb_membre + 1;
        }
    }
    fclose(ptrFic);
    return nb_membre;
}

int nombre_livre () {
    FILE *ptrFic = fopen("listelivre.txt", "r");
    char texte[256];
    int nb_livre = 0;

    if(ptrFic==NULL)
    {
        printf("Erreur m%cmoire",130);
        exit(1);
    }

    while(fgets(texte,255,ptrFic) != NULL) {
        if (texte[0] == '*') {
            nb_livre = nb_livre + 1;
        }
    }
    fclose(ptrFic);
    return nb_livre;
}

int nouvel_emprunt(bd_membre * m, bd_livre * l, int nb_membre, int nb_livre) {
    char nom[30], prenom[30], titre[50];
    int i, j, egalite, numero_mb = -1, numero_livre = -1;
    livre_emp * adresse;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    printf("Entrer le nom de l'emprunteur\n");
    scanf("%s",nom);
    printf("Entrer le pr%cnom de l'emprunteur\n",130);
    scanf("%s",prenom);

    for (i=0; i<nb_membre; i++) {
        egalite = 1;
        for (j=0; j<strlen(nom); j++) {
            if (nom[j] != m[i].nom[j]) {
                egalite = 0;
            }
        }
        for (j=0; j<strlen(prenom); j++) {
            if (prenom[j] != m[i].prenom[j]) {
                egalite = 0;
            }
        }
        if (egalite == 1) {
            numero_mb = i;
            break;
        }
    }

    if (numero_mb == -1) {
        printf("\nLe membre n'est pas r%cf%crenc%c dans la base de donn%ces\n",130,130,130,130);
        return 0;
    }

    if (m[numero_mb].cb_livre == 3) {
        printf("\nLe membre a d%cj%c emprunt%c 3 livres (pas plus de 3 livres emprunt%cs)\n",130,133,130,133);
        return 0;
    }

    gets(titre);
    printf("Entrer le titre du livre emprunt%c\n",130);
    gets(titre);

    for (i=0; i<nb_livre; i++) {
        egalite = 1;
        j = 0;
        for (j=0; j<strlen(titre); j++) {
            if (titre[j] != l[i].titre[j]) {
                egalite = 0;
            }
        }
        if (egalite == 1) {
            numero_livre = i;
            break;
        }
    }

    if (numero_livre == -1) {
        printf("\nLe livre n'est pas r%cf%crenc%c dans la base de donn%ces\n",130,130,130,130);
        return 0;
    }

    if (l[numero_livre].nbprete == l[numero_livre].nbexp) {
        printf("\nTous les exemplaires de ce livre ont été emprunt%cs\n",130);
        return 0;
    }

    m[numero_mb].cb_livre = m[numero_mb].cb_livre +1;
    l[numero_livre].nbprete = l[numero_livre].nbprete + 1;

    adresse = creer_tab_livre_emp_dyn(m[numero_mb].cb_livre);

    for (i=0; i< m[numero_mb].cb_livre - 1; i++) {
        strcpy(adresse[i].code, m[numero_mb].livre[i].code);
        adresse[i].date_pret.jour = m[numero_mb].livre[i].date_pret.jour;
        adresse[i].date_pret.mois = m[numero_mb].livre[i].date_pret.mois;
        adresse[i].date_pret.annee = m[numero_mb].livre[i].date_pret.annee;
    }

    strcpy(adresse[m[numero_mb].cb_livre - 1].code, l[numero_livre].code);
    adresse[m[numero_mb].cb_livre - 1].date_pret.jour = local->tm_mday;
    adresse[m[numero_mb].cb_livre - 1].date_pret.mois = local->tm_mon + 1;
    adresse[m[numero_mb].cb_livre - 1].date_pret.annee = local->tm_year + 1900;

    free(m[numero_mb].livre);
    m[numero_mb].livre = adresse;

    return 0;

}

int restitution_emprunt(bd_membre * m, bd_livre * l, int nb_membre, int nb_livre) {
    char nom[30], prenom[30], titre[50];
    int i, j, egalite, numero_mb = -1, numero_livre = -1, numero_livre_client = -1, retard = 0;
    int jour_retour, mois_retour, annee_retour;
    livre_emp * adresse;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    printf("Entrer le nom de l'emprunteur\n");
    scanf("%s",nom);
    printf("Entrer le pr%cnom de l'emprunteur\n",130);
    scanf("%s",prenom);

    for (i=0; i<nb_membre; i++) {
        egalite = 1;
        for (j=0; j<strlen(nom); j++) {
            if (nom[j] != m[i].nom[j]) {
                egalite = 0;
            }
        }
        for (j=0; j<strlen(prenom); j++) {
            if (prenom[j] != m[i].prenom[j]) {
                egalite = 0;
            }
        }
        if (egalite == 1) {
            numero_mb = i;
            break;
        }
    }

    if (numero_mb == -1) {
        printf("\nLe livre n'est pas r%cf%crenc%c dans la base de donn%ces\n",130,130,130,130);
        return 0;
    }

    gets(titre);
    printf("Entrer le titre du livre restitu%c\n",130);
    gets(titre);

    for (i=0; i<nb_livre; i++) {
        egalite = 1;
        for (j=0; j<strlen(titre); j++) {
            if (titre[j] != l[i].titre[j]) {
                egalite = 0;
            }
        }
        if (egalite == 1) {
            numero_livre = i;
            break;
        }
    }

    if (numero_livre == -1) {
        printf("\nLe livre n'est pas r%cf%crenc%c dans la base de donn%ces\n",130,130,130,130);
        return 0;
    }

    m[numero_mb].cb_livre = m[numero_mb].cb_livre - 1;
    l[numero_livre].nbprete = l[numero_livre].nbprete - 1;

    for (i=0; i<m[numero_mb].cb_livre + 1; i++) {
        egalite = 1;
        for (j=0; j<7; j++) {
            if (l[numero_livre].code[j] != m[numero_mb].livre[i].code[j]) {
                egalite = 0;
            }
        }
        if (egalite == 1) {
            numero_livre_client = i;
            break;
        }
    }

    if (numero_livre_client == -1) {
        printf("\nLe client n'a pas emprunt%c ce livre\n",130);
        return 0;
    }

    jour_retour = m[numero_mb].livre[numero_livre_client].date_pret.jour;
    mois_retour = m[numero_mb].livre[numero_livre_client].date_pret.mois;
    annee_retour = m[numero_mb].livre[numero_livre_client].date_pret.annee;

    jour_retour = (jour_retour + 10) % 30;
    if (jour_retour == 0) {
        jour_retour = 30;
    }
    if (jour_retour < 11) {
        mois_retour = mois_retour + 1;
        if (mois_retour == 13) {
            mois_retour = 1;
            annee_retour = annee_retour + 1;
        }
    }

    if (annee_retour < local->tm_year + 19#include <stdio.h>

int main(void) {

  int a,b,c,d;

  printf("Saisir 3 valeurs entières :\n");
  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);

  d = a*b*c;

  printf("%d",d);
  return 0;
}
00) {
        retard = 1;
    }
    if (mois_retour < local->tm_mon + 1 & annee_retour == local->tm_year + 1900) {
        retard = 1;
    }
    else if (jour_retour < local->tm_mday & mois_retour == local->tm_mon + 1 & annee_retour < local->tm_year + 1900) {
        retard = 1;
    }

    if (retard == 1) {
        printf("\nLe livre est en retard !\n");
    }

    adresse = creer_tab_livre_emp_dyn(m[numero_mb].cb_livre);

    for (i=0; i< m[numero_mb].cb_livre; i++) {
        j = i;
        if (i >= numero_livre_client) {
            j = j + 1;
        }
        strcpy(adresse[i].code, m[numero_mb].livre[j].code);
        adresse[i].date_pret.jour = m[numero_mb].livre[j].date_pret.jour;
        adresse[i].date_pret.mois = m[numero_mb].livre[j].date_pret.mois;
        adresse[i].date_pret.annee = m[numero_mb].livre[j].date_pret.annee;
    }

    free(m[numero_mb].livre);
    m[numero_mb].livre = adresse;

    printf("\nLe livre a bien %ct%c restitu%c\n",130,130,130);

    return 0;

}

void ecriture_fichier_avec_struct(bd_membre * m, bd_livre * l, int nb_membre, int nb_livre) {

    int i, j;
    FILE *ptrFic = fopen("listemembre.txt", "w");
    FILE *ptrFic2 = fopen("listelivre.txt", "w");

    if(ptrFic==NULL)
    {
        printf("Erreur m%cmoire",130);
        exit(1);
    }

    for (i=0; i<nb_membre; i++) {
        fprintf(ptrFic,"%s%s%s%s%s%d\n",m[i].nom,m[i].prenom,m[i].adressepostale,m[i].adressemail,m[i].metier,m[i].cb_livre);
        for (j=0; j<m[i].cb_livre; j++) {
            fprintf(ptrFic,"%s %d %d %d\n",m[i].livre[j].code,m[i].livre[j].date_pret.jour,m[i].livre[j].date_pret.mois,m[i].livre[j].date_pret.annee);
        }
        fprintf(ptrFic,"*\n");
    }


    if(ptrFic2==NULL)
    {
        printf("Erreur m%cmoire",130);
        exit(1);
    }

    for (i=0; i<nb_livre; i++) {
        fprintf(ptrFic2,"%s\n%s%s%d\n%d\n*\n",l[i].code,l[i].titre,l[i].auteur,l[i].nbexp,l[i].nbprete);
    }

    fclose(ptrFic);
    fclose(ptrFic2);

}

bd_membre * suppression_membre(bd_membre * m, int nb_membre) {
    char nom[30], prenom[30];
    int i, j, egalite, numero_mb = -1;
    bd_membre * adresse;

    printf("Entrer le nom du membre %c supprimer\n",133);
    scanf("%s",nom);
    printf("Entrer le prenom du membre %c supprimer\n",133);
    scanf("%s",prenom);

    for (i=0; i<nb_membre; i++) {
        egalite = 1;
        for (j=0; j<strlen(nom); j++) {
            if (nom[j] != m[i].nom[j]) {
                egalite = 0;
            }
        }
        for (j=0; j<strlen(prenom); j++) {
            if (prenom[j] != m[i].prenom[j]) {
                egalite = 0;
            }
        }
        if (egalite == 1) {
            numero_mb = i;
            break;
        }
    }

    if (numero_mb == -1) {
        printf("\nLe membre n'est pas r%cf%crenc%c dans la base de donn%ces\n",130,130,130,130);
        return m;
    }

    if (m[numero_mb].cb_livre != 0) {
        printf("\nLe membre poss%cde des livres non rendus, il ne peut pas être supprim%c\n",138,133);
        return m;
    }

    adresse = creer_tab_membre_dyn(nb_membre-1);

    for (i=0; i<nb_membre-1 ; i++) {
        j = i;
        if (i >= numero_mb) {
            j = j + 1;
        }
        adresse[i] = m[j];
    }

    printf("\nLe membre a bien %ct%c supprim%c\n",130,130,130);
    return adresse;

}

bd_livre * suppression_livre(bd_livre * l, int nb_livre) {
    char titre[50];
    int i, j, egalite, numero_livre = -1;
    bd_livre * adresse;

    gets(titre);
    printf("Entrer le titre du livre %c supprimer\n",133);
    gets(titre);

    for (i=0; i<nb_livre; i++) {
        egalite = 1;
        for (j=0; j<strlen(titre); j++) {
            if (titre[j] != l[i].titre[j]) {
                egalite = 0;
            }
        }
        if (egalite == 1) {
            numero_livre = i;
            break;
        }
    }

    if (numero_livre == -1) {
        printf("\nLe livre n'est pas r%cf%crenc%c dans la base de donn%ces\n",130,130,130,130);
        return l;
    }

    if (l[numero_livre].nbprete != 0) {
        printf("\nCertains exemplaires de ce livre n'ont pas %ct%c rendus, il ne peut pas %ctre supprim%c\n",130,130,136,130);
        return l;
    }

    adresse = creer_tab_livre_dyn(nb_livre-1);

    for (i=0; i<nb_livre-1 ; i++) {
        j = i;
        if (i >= numero_livre) {
            j = j + 1;
        }
        adresse[i] = l[j];
    }

    printf("\nLe livre a bien %ct%c supprim%c\n",130,130,130);
    return adresse;

}
