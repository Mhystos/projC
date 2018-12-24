/* ********************************************/
/*                                            */
/*   Fichier ayant pour but d'afficher la     */
/*   liste chainée de table                   */
/*                                            */
/*   By: François Mat & Geerts Quentin        */
/*                                            */
/*   Created: 2018/12/07                      */
/*   Updated: 2018/12/13                      */
/*                                            */
/* ********************************************/
#include "header.h"

void affiche_table(table *t_deb, int nt, int nr, int *nb_place_dispo){

    /* Variables */
    int i;

    /* Structure */
    table *t_courant,*t_suivant;

    printf("+-----------------------------------------------------+\n");
    printf("|                 Affichage des tables                |\n");
    printf("+-----------------------------------------------------+\n");
    printf("| Nombre de tables du restaurant :    %2d  au total    | \n",nt);
    printf("+-----------------------------------------------------+\n");
    printf("| Num | Nb Places |        Libre/Occupe               |\n");
    printf("+-----------------------------------------------------+\n");

    t_courant=t_deb;

    for(i=1;i<=nt;i++){
        printf("| %2d  |    %2d     |",t_courant->numero,t_courant->place);
        if (t_courant->libre ==0){
            printf("             Libre                 |\n");
        }
        else{
            printf("             Occupee               |\n");
        }
        t_courant=t_courant->t_suivant;
    }
    printf("+-----------------------------------------------------+\n");
    printf("| Nombre de places totales dans le restaurant :    %d |\n", nr);
    printf("| Places disponibles dans le restaurant :          %d |\n", *nb_place_dispo);
    printf("+-----------------------------------------------------+\n");


}
