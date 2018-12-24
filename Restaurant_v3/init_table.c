/* ********************************************/
/*                                            */
/*   Fichier ayant pour but d'initialiser la  */
/*   liste chainée de table                   */
/*                                            */
/*   By: François Mat & Geerts Quentin        */
/*                                            */
/*   Created: 2018/12/07                      */
/*   Updated: 2018/12/13                      */
/*                                            */
/* ********************************************/

#include "header.h"

int init_table(table *t_deb, int *nb_tab){

    FILE *fdat_table;
    fdat_table=fopen("table.dat","r");


     /* Variables */
    int i;
    int nb_place=0;
    int nb_table;
    table *t_courant, *t_suivant;

    /* Code */

    t_deb=malloc(sizeof(table));
    t_courant=t_deb;

    fscanf(fdat_table,"%2d",&nb_table);
    *nb_tab =nb_table;

    /*On lit les informations relatives aux nombres de tables et de places*/
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



    /*Impression de la liste*/
    t_courant=t_deb;
    printf("Nombre de tables : %2d\n",nb_table);
    for(i=1;i<=nb_table;i++){
        printf("Table numero %2d Places : %2d Reserve : %d Addition : %5.2f\n",t_courant->numero,t_courant->place,t_courant->libre,t_courant->addition);
        t_courant=t_courant->t_suivant;
    }
    printf("Place total dans le restaurant :%d", nb_place);

    /* On retourne le vecteur contenant les différents attributs */
    return nb_place;

}
