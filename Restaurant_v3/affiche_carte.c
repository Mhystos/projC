/* ********************************************/
/*                                            */
/*   Fichier ayant pour but d'afficher la     */
/*   liste chainée de plat                    */
/*                                            */
/*   By: François Mat & Geerts Quentin        */
/*                                            */
/*   Created: 2018/12/07                      */
/*   Updated: 2018/12/13                      */
/*                                            */
/* ********************************************/
#include "header.h"

/* Il a toujours un nombre identique d'entrées, de plats, de desserts et de boisson */

void affiche_carte(plat *p_deb, int n){

    /* Variables */
    int i,j;

    /* Structure */
    plat *p_courant,*p_suivant;

    j = n/4;
    printf("+-----------------------------------------------------+\n");
    printf("|                 Carte du restaurant                 |\n");
    printf("+-----------------------------------------------------+\n");
    printf("|                       Entrees                       |\n");
    printf("+-----------------------------------------------------+\n");

    p_courant = p_deb;
    //printf("|%2d |%-35s| %5.2f|\n",p_courant->num_plats,p_courant->intitule,p_courant->prix);
    for(i=1;i<=j;i++){
        printf("|%2d | %-35s      | %5.2f|\n",p_courant->num_plats,p_courant->intitule,p_courant->prix);
        p_courant=p_courant->p_suivant;
    }
    printf("+-----------------------------------------------------+\n");
    printf("|                        Plats                        |\n");
    printf("+-----------------------------------------------------+\n");
    for(i=1;i<=j;i++){
        printf("|%2d | %-35s      | %5.2f|\n",p_courant->num_plats,p_courant->intitule,p_courant->prix);
        p_courant=p_courant->p_suivant;
    }
    printf("+-----------------------------------------------------+\n");
    printf("|                      Desserts                       |\n");
    printf("+-----------------------------------------------------+\n");
    for(i=1;i<=j;i++){
        printf("|%2d | %-35s      | %5.2f|\n",p_courant->num_plats,p_courant->intitule,p_courant->prix);
        p_courant=p_courant->p_suivant;
    }
    printf("+-----------------------------------------------------+\n");
    printf("|                      Boissons                       |\n");
    printf("+-----------------------------------------------------+\n");
    for(i=1;i<=j;i++){
        printf("|%2d | %-35s      | %5.2f|\n",p_courant->num_plats,p_courant->intitule,p_courant->prix);
        p_courant=p_courant->p_suivant;
    }
    printf("+-----------------------------------------------------+\n");
}
