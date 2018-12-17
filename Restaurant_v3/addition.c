/* ********************************************/
/*                                            */
/*   Fichier ayant pour but d'afficher        */
/*   l'addition et de retirer le client       */
/*                                            */
/*   By: François Mat & Geerts Quentin        */
/*                                            */
/*   Created: 2018/12/07                      */
/*   Updated: 2018/12/16                      */
/*                                            */
/* ********************************************/

/*
 * TODO : Repasser la table en libre après avoir supprimé le client.
 *
 */

#include "header.h"

void addition(client* *c_deb, int *n_client, table* *t_deb, int n_table) {

    /* FILE */
    FILE *fres = fopen("addition_client.txt", "w+");

    /* Structures */
    client *c_courant, *c_intercale;
    table *t_courant;

    /* Variables */
    int tmp_numero, i, j, k, tmp_n_table;
    float total_facture = 0;

    printf("+-----------------------------------------+\n");
    printf("|                 Addition                |\n");
    printf("+-----------------------------------------+\n");

    printf("\n");

    printf("|  Liste des clients  |\n");

    printf("\n");

    printf("Nombre de %s : %d\n", (*n_client > 1)?"clients":"client", *n_client);

    printf("\n");

    /* Parcours de la liste des clients */

    c_courant = *c_deb;
    printf("+---------------+----------+---------------+---------------+\n");
    printf("| Numero client | N. table | Nbre. personne| Heure arrivee |\n");
    printf("+---------------+----------+---------------+---------------+\n");

    for(i = 1 ; i <= *n_client ; i ++) {
        printf("|      %2d       |    %2d    |      %2d       |     %5s     |\n", i, c_courant->numt, c_courant->nombre, c_courant->heures);
        c_courant = c_courant->c_suivant;
    }

    printf("+---------------+----------+---------------+---------------+\n");

    printf("\n");

    printf("Selectionnez le numero d'un client\n");
    printf("----------------------------------\n");
    printf("Numero : ");
    scanf("%2d", &tmp_numero);

    if(tmp_numero  > 0 && tmp_numero <= *n_client) {

        /* Ecriture de la facture dans un fichier */

        /* Calcul du total à payer */

        c_courant = *c_deb;

        for(i = 1 ; i <= *n_client ; i ++) {
            if(tmp_numero == i) {
                for(j = 1 ; j <= c_courant->nombre ; j ++) {
                    for(k = 1 ; k <= 4 ; k ++) {
                        total_facture += c_courant->prix[j][k];
                    }
                }
                tmp_n_table = c_courant->numt;
            }
            c_courant = c_courant->c_suivant;
        }

        /*printf("Total a payer : %6.2fe\n", total_facture);*/
        printf("\nImpression du ticket en cours...\n");

        /* Impression du ticket */

        fprintf(fres, "+--------------------------------------------+\n");
        fprintf(fres, "|             Restaurant - Mons              |\n");
        fprintf(fres, "|                 Le FranTin                 |\n");
        fprintf(fres, "+---       ------------------------       ---+\n");

        fprintf(fres, "+---       ------------------------       ---+\n");

        // On se déplace jusqu'à la bonne adresse du client
        c_courant = *c_deb;
        for(i = 1 ; i <= tmp_numero ; i ++) {
            if( i == tmp_numero){
                fprintf(fres, "|                                            |\n");
                fprintf(fres, "| Table n. %2d                                |\n", c_courant->numt);
                fprintf(fres, "|                                            |\n");
                for(j = 1 ; j <= c_courant->nombre ; j ++) {
                    fprintf(fres, "| Commande pour la personne n. %2d/%2d         |\n", j, c_courant->nombre);
                    fprintf(fres, "|                                            |\n");

                    fprintf(fres, "| %-35s %5.2fe |\n", c_courant->entree[j], c_courant->prix[j][1]);
                    fprintf(fres, "| %-35s %5.2fe |\n", c_courant->platP[j], c_courant->prix[j][2]);
                    fprintf(fres, "| %-35s %5.2fe |\n", c_courant->dessert[j], c_courant->prix[j][3]);
                    fprintf(fres, "| %-35s %5.2fe |\n", c_courant->boisson[j], c_courant->prix[j][4]);
                    fprintf(fres, "|                                            |\n");
                }
            }
            c_courant = c_courant->c_suivant;
        }




        fprintf(fres, "|  Total a payer :                   %6.2fe |\n", total_facture);
        fprintf(fres, "|  Incl. TVA et Taxes                        |\n");
        fprintf(fres, "+---       ------------------------       ---+\n");


        fprintf(fres, "+---       ------------------------       ---+\n");
        fprintf(fres, "|           Chaussee de Binche 159,          |\n");
        fprintf(fres, "|                 7000 MONS                  |\n");
        fprintf(fres, "|                                            |\n");
        fprintf(fres, "|          Tel  :  069 / 23 . 51 . 01        |\n");
        fprintf(fres, "|           @   :  contact@frantin.be        |\n");
        fprintf(fres, "|            Merci de votre visite           |\n");
        fprintf(fres, "|                  A bientot !               |\n");
        fprintf(fres, "+--------------------------------------------+\n");

        /* Affichage écran du ticket */
        printf("+--------------------------------------------+\n");
        printf("|             Restaurant - Mons              |\n");
        printf("|                 Le FranTin                 |\n");
        printf("+---       ------------------------       ---+\n");

        printf("+---       ------------------------       ---+\n");

        // On se déplace jusqu'à la bonne adresse du client
        c_courant = *c_deb;
        for(i = 1 ; i <= tmp_numero ; i ++) {
            if( i == tmp_numero){
                printf("|                                            |\n");
                printf("| Table n. %2d                                |\n", c_courant->numt);
                printf("|                                            |\n");
                for(j = 1 ; j <= c_courant->nombre ; j ++) {
                    printf("| Commande pour la personne n. %2d/%2d         |\n", j, c_courant->nombre);
                    printf("|                                            |\n");

                    printf("| %-35s %5.2fe |\n", c_courant->entree[j], c_courant->prix[j][1]);
                    printf("| %-35s %5.2fe |\n", c_courant->platP[j], c_courant->prix[j][2]);
                    printf("| %-35s %5.2fe |\n", c_courant->dessert[j], c_courant->prix[j][3]);
                    printf("| %-35s %5.2fe |\n", c_courant->boisson[j], c_courant->prix[j][4]);
                    printf("|                                            |\n");
                }
            }
            c_courant = c_courant->c_suivant;
        }




        printf("|  Total a payer :                   %6.2fe |\n", total_facture);
        printf("|  Incl. TVA et Taxes                        |\n");
        printf("+---       ------------------------       ---+\n");


        printf("+---       ------------------------       ---+\n");
        printf("|           Chaussee de Binche 159,          |\n");
        printf("|                 7000 MONS                  |\n");
        printf("|                                            |\n");
        printf("|          Tel  :  069 / 23 . 51 . 01        |\n");
        printf("|           @   :  contact@frantin.be        |\n");
        printf("|            Merci de votre visite           |\n");
        printf("|                  A bientot !               |\n");
        printf("+--------------------------------------------+\n");

        /*
         *
         * Code de vérification de paiement du client
         *
         */

        /* Suppression du client après avoir payé */

        // On repasse la table utilisee en libre
        t_courant = *t_deb;
        for(i = 1 ; i <= n_table ; i ++){
            if(t_courant->numero == tmp_n_table){
                t_courant->libre = 0; // On passe la table en occupée
            }
            t_courant=t_courant->t_suivant;
        }

        // Supression du client dans la liste
        if(tmp_numero == 1) {
            c_intercale = *c_deb;
            *c_deb = (*c_deb)->c_suivant;
            free(c_intercale);
        }
        else {
            c_courant = *c_deb;

            for(i = 1 ; i < tmp_numero - 1 ; i ++) {
                // On se déplace jusqu'à la bonne adresse
                c_courant = c_courant->c_suivant;
            }

            if(tmp_numero != (*n_client)) {
                // On fait disparaître un maillon de la chaine
                c_intercale = c_courant->c_suivant;
                c_courant->c_suivant = c_intercale->c_suivant;
                free(c_intercale);
            }
            else {
                c_intercale = c_courant->c_suivant;
                c_courant->c_suivant = NULL;
                free(c_intercale);
            }

        }

        (*n_client) --;

        /* Parcours de la liste des clients */

        c_courant = *c_deb;
        printf("+---------------+----------+---------------+---------------+\n");
        printf("| Numero client | N. table | Nbre. personne| Heure arrivee |\n");
        printf("+---------------+----------+---------------+---------------+\n");

        for(i = 1 ; i <= *n_client ; i ++) {
            printf("|      %2d       |    %2d    |      %2d       |     %5s     |\n", i, c_courant->numt, c_courant->nombre, c_courant->heures);
            c_courant = c_courant->c_suivant;
        }

        printf("+---------------+----------+---------------+---------------+\n");

        printf("\n");

    }
    else {
        printf("Veuillez selectionner un numero propose dans la liste ci-dessus.\n");
    }

}
