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

    /* Variable */
    int nb_place_dispo;
    int nb_place=0;
    int nb_table=0;

    int nb_plat=0;

    /* Compteur */
    int i;

    /* Pointer */


    /* Fichier dat */
    FILE *fdat_carte, *fdat_table;
    fdat_carte=fopen("carte.dat","r");
    fdat_table=fopen("table.dat","r");
    char car[2];

    /*******************************************************/
    /*                      PLAT                           */
    /*******************************************************/

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
        t_courant->addition =0.;

        t_suivant=malloc(sizeof(table));
        t_courant->t_suivant=t_suivant;
        t_courant=t_suivant;
    }

    /*On termine la liste avec l'adresse NULL */
    t_courant=t_deb;
    nb_place+=t_deb->place;
    for(i=1;i<nb_table;i++){
        t_courant=t_courant->t_suivant;
        nb_place+=t_courant->place;
    }
    t_courant->t_suivant=NULL;
    free(t_suivant);

    /*******************************************************/
    /*                      TESTS                          */
    /*******************************************************/


    nb_place_dispo = nb_place; // A ce moment-ci, après l'initialisation, ils sont égaux

    affiche_carte(p_deb,nb_plat);
    clean_buffer(nb_place);
    affiche_table(t_deb,nb_table,nb_place);











}
