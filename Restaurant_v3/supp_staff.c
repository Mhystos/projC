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
int supp_staff(employe* *e_deb,int n_employe){

    /* Variables */
    int i, pos;

    /* Structure */
    employe *e_courant, *e_intercale;

    /* Code */

    printf("\nQuelle est la position de l'employe a retirer de la liste ?\n");
    printf("-----------------------------------------------------------\n");
    printf("Position : ");
    scanf("%d", &pos);

    if(pos >= 1 && pos <=n_employe)
    {
        if(pos == 1)
        {
            e_intercale = *e_deb;
            *e_deb = (*e_deb)->e_suivant;
            free(e_intercale);
        }
        else
        {
            e_courant = *e_deb;

            for(i=1;i<pos-1;i++)
            {
                e_courant = e_courant->e_suivant;
            }

            if(pos != n_employe)
            {
                e_intercale = e_courant->e_suivant;
                e_courant->e_suivant = e_intercale->e_suivant;
                free(e_intercale);
            }
            else
            {
                e_intercale = e_courant ->e_suivant;
                e_courant ->e_suivant = NULL;
                free(e_intercale);
            }
        }


        n_employe--;
        return n_employe;
        printf("\nAu revoir et bonne continuation\n");
        system("pause");
    }
    else
    {
        printf("\nVeuillez indiquer une position correct \n");
        return n_employe;
        system("pause");
    }

}
