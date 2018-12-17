/* ********************************************/
/*                                            */
/*   Fichier ayant pour but d'ajouter à la    */
/*   liste chainée un employe                 */
/*                                            */
/*   By: François Mat & Geerts Quentin        */
/*                                            */
/*   Created: 2018/12/07                      */
/*   Updated: 2018/12/14                      */
/*                                            */
/* ********************************************/
#include "header.h"
int ajout_staff(employe* *e_deb, int n_employe){

    /* Variables */
    int i, pos;

    /* Structure */
    employe *e_intercale,*e_courant;

    /* Code */

    printf("+------------------------------------------+\n");
    printf("|Ajout d'un employe en quelle position ?   |\n");
    printf("+------------------------------------------+\n");
    printf("Choix : ");
    scanf("%d", &pos);
    printf("\n");
    if(pos >=1 && pos<= n_employe+1)
    {
        e_intercale = malloc(sizeof(employe));
        if(pos !=1)
        {
            e_courant = *e_deb;

            for(i=1; i< pos -1; i++)
            {
                e_courant = e_courant -> e_suivant;
            }
            /* On insere intercale */
            e_intercale ->e_suivant = e_courant ->e_suivant;
            e_courant-> e_suivant = e_intercale;
        }
        else{
            /* Intercale est en première position */
            e_intercale->e_suivant = *e_deb;
            *e_deb = e_intercale;
        }
        printf("Veuillez entrez le nom du nouveau membre du personnel    \n");
        printf("---------------------------------------------------------\n");
        printf("Nom : ");
        scanf("%s", &e_intercale->nom);
        printf("\n");

        printf("Veuillez entrez le prenom du nouveau membre du personnel \n");
        printf("---------------------------------------------------------\n");
        printf("Prenom : ");
        scanf("%s", &e_intercale->prenom);
        printf("\n");


        printf("Veuillez entrez le role du nouveau membre du staff\n");
        printf("---------------------------------------------------------\n");
        printf("Role : ");
        scanf("%s", &e_intercale->role);
        printf("\n");

        n_employe++;
        return n_employe;
        printf("\nBravo et bienvenue dans notre equipe! \n");
        system("pause");

    }
    else{
        printf("\nVeuillez indiquer une position correct \n");
        return n_employe;
        system("pause");
    }

}

