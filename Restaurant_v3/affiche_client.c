/*   Fichier ayant pour but d'afficher la     */
/*   liste chainée de plat                    */
/*                                            */
/*   By: François Mat & Geerts Quentin        */
/*                                            */
/*   Created: 2018/12/07                      */
/*   Updated: 2018/12/16                      */
/*                                            */
/* ********************************************/
#include "header.h"

void affiche_client(client *c_deb, int n_client){

    /* Variables */
    int i,j,k;

    /* Structure */
    client *c_courant, *c_suivant;

    printf("+-----------------------------------------------------+\n");
    printf("|              Affichage des clients                  |\n");
    printf("+-----------------------------------------------------+\n");
    printf("| Nombre de clients du restaurant :           %2d      |\n",n_client);
    printf("+-----------------------------------------------------+\n");
    printf("|  NUM  |  TABLE  |  NOMBRE  |  RESERVATION  | HEURE  |\n");
    printf("+-----------------------------------------------------+\n");

    if(n_client != 0) {


        c_courant = c_deb;
        for(i=1;i<=n_client;i++){

            printf("\n");
            printf("+-----------------------------------------------------+\n");

            printf("|   %2d  |    %2d   |     %2d   |",i,c_courant->numt, c_courant->nombre);

            printf("  %-11s  | %-7s|\n", (c_courant->reservation == 1)?"Reservation":"Walk-in", c_courant->heures);

            for(j=1;j<=c_courant->nombre;j++){
                printf("+-----------------------------------------------------+\n");
                printf("|Choix du menu de la %2d e personne                    |\n",j);
                printf("+-----------------------------------------------------+\n");
                printf("| ENTREE : %-35s %5.2fe |\n",c_courant->entree[j], c_courant->prix[j][1]);
                printf("| PLAT   : %-35s %5.2fe |\n",c_courant->platP[j], c_courant->prix[j][2]);
                printf("| DESSERT: %-35s %5.2fe |\n",c_courant->dessert[j], c_courant->prix[j][3]);
                printf("| BOISSON: %-35s %5.2fe |\n",c_courant->boisson[j], c_courant->prix[j][4]);
            }
            printf("+-----------------------------------------------------+\n");
            c_courant = c_courant->c_suivant;

        }
    }
    else {
        printf("|Il n'y a actuellement aucun client                   |\n",j);
        printf("+-----------------------------------------------------+\n");
    }

}
