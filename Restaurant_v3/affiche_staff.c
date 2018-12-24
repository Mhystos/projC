/* ********************************************/
/*                                            */
/*   Fichier ayant pour but d'afficher la     */
/*   liste chainée du personnel               */
/*                                            */
/*   By: François Mat & Geerts Quentin        */
/*                                            */
/*   Created: 2018/12/07                      */
/*   Updated: 2018/12/13                      */
/*                                            */
/* ********************************************/
#include "header.h"
void affiche_staff(employe *e_deb, int n_employe){

    /* Variables */
    int i;

    /* Structure */
    employe *e_courant,*e_suivant;
    printf("+-----------------------------------------------------+\n");
    printf("|                 Affichage des employes              |\n");
    printf("+-----------------------------------------------------+\n");
    printf("| Nombre d'employes du restaurant :           %2d      |\n",n_employe);
    printf("+-----------------------------------------------------+\n");
    printf("|         NOM        |      PRENOM        |   ROLE    |\n");
    printf("+-----------------------------------------------------+\n");

    e_courant=e_deb;
    for(i=1;i<=n_employe;i++){
        printf("|%-20s|%-20s|%-10s |\n",e_courant->nom,e_courant->prenom,e_courant->role);
        e_courant=e_courant->e_suivant;
    }
    printf("+-----------------------------------------------------+\n");

}
