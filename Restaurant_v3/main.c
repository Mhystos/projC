/* Programme créer par Geerts Quentin Et Mat François
 * dans le cadre du cours de Language C organisé à la HELHa par
 * Monsieur Carpentier en deuxième année Informatique de Gestion
 * Travail à faire durant la période du 22-11-2018 au 19-12-2018
*/

#include "header.h"

main(){

    /* Structure */
    table *t_deb, *t_courant, *t_suivant;
    plat *p_deb, *p_courant, *p_suivant;
    employe *e_deb, *e_courant, *e_suivant, *e_precedent;
    //client *c_deb,*c_courant, *c_suivant, *c_intercale;

    /* Variable */
    int nb_place_dispo;
    int nb_resto=0;
    int nb_table=0;

    int nb_plat=0;
    int nb_employe=0;
    /* Compteur */
    int i;

    /* Pointer */
    int *nb_client;

    /* Fichier dat */
    FILE *fdat_carte, *fdat_table, *fdat_staff;
    fdat_carte=fopen("carte.dat","r");
    fdat_table=fopen("table.dat","r");
    fdat_staff=fopen("staff.dat","r");


    /*******************************************************/
    /*                      PLAT                           */
    /*******************************************************/
    char car[2]; // Pour le passage à la ligne

    /* Allocation de mémoire pour la liste chainée de plat */
    p_deb = malloc(sizeof(plat));
    p_courant = p_deb;

    /* Lecture de carte.dat */
    fscanf(fdat_carte,"%d",&nb_plat);
    fgets(car,2,fdat_carte);

    for(i=1;i<=nb_plat;i++){
        fgets(p_courant->intitule,36,fdat_carte);
        fscanf(fdat_carte,"%5f",&p_courant->prix);
        fgets(car,2,fdat_carte);
        p_courant->num_plats=i;
        //printf("%2d %37s %5.2f\n",p_courant->num_plats,p_courant->intitule,p_courant->prix);
        p_suivant = malloc(sizeof(plat));
        p_courant->p_suivant=p_suivant;
        p_courant=p_suivant;
    }
    /* On termine la liste avec l'adresse NULL */
    p_courant = p_deb;
    for(i=1;i<nb_plat;i++){
        p_courant=p_courant->p_suivant;
    }
    p_courant->p_suivant=NULL;
    free(p_suivant);

    /*******************************************************/
    /*                      TABLE                          */
    /*******************************************************/

    /* Allocation de mémoire pour la liste chainée de table*/
    t_deb=malloc(sizeof(table));
    t_courant=t_deb;

    /* Lecture de table.dat */
    fscanf(fdat_table,"%2d",&nb_table);

     for(i=1;i<=nb_table;i++){
        fscanf(fdat_table,"%2d%2d",&t_courant->numero,&t_courant->place);
        t_courant->libre = 0;

        t_suivant=malloc(sizeof(table));
        t_courant->t_suivant=t_suivant;
        t_courant=t_suivant;
    }

    /*On termine la liste avec l'adresse NULL */
    t_courant=t_deb;
    nb_resto+=t_deb->place;
    for(i=1;i<nb_table;i++){
        t_courant=t_courant->t_suivant;
        nb_resto+=t_courant->place;
    }
    t_courant->t_suivant=NULL;
    free(t_suivant);

    /*******************************************************/
    /*                      EMPLOYE                        */
    /*******************************************************/

    /*  Allocation de mémoire pour la liste des employes   */
    e_deb = malloc(sizeof(employe));
    e_courant=e_deb;

    /*Lecture de staff.dat*/
    fscanf(fdat_staff,"%20s",e_courant->nom);
    while (!feof(fdat_staff)){
        fscanf(fdat_staff,"%20s%10s",e_courant->prenom,e_courant->role);
        nb_employe++;

        e_suivant=malloc(sizeof(employe));
        e_courant->e_suivant=e_suivant;
        e_courant=e_suivant;

        fscanf(fdat_staff,"%20s",e_courant->nom);
    }


    /* On termine la liste avec l'adresse NULL*/
    e_courant=e_deb;
    for(i=1;i<nb_employe;i++){
        e_courant=e_courant->e_suivant;
    }
    e_courant->e_suivant=NULL;
    free(e_suivant);


    /*******************************************************/
    /*                      CLIENT                         */
    /*******************************************************/

    /* Allocation de mémoire pour la liste  de client      */
    //c_deb=malloc(sizeof(client));
    //c_courant=c_deb;

    /*******************************************************/
    /*                      TESTS                          */
    /*******************************************************/


    nb_place_dispo = nb_resto; // A ce moment-ci, après l'initialisation, ils sont égaux

    run (p_deb,t_deb,e_deb,nb_plat,nb_table,nb_resto,nb_employe);
    //affiche_carte(p_deb,nb_plat);
    //clean_buffer(nb_resto);
    //affiche_table(t_deb,nb_table,nb_resto);
    //affiche_staff(e_deb,nb_employe);










}
