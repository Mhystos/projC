/* ********************************************/
/*                                            */
/*    Fichier ayant pour but d'afficher       */
/*    le menu du programme et de sélectionner */
/*    les différentes commandes               */
/*                                            */
/*   By: François Mat & Geerts Quentin        */
/*                                            */
/*   Created: 2018/12/07                      */
/*   Updated: 2018/12/13                      */
/*                                            */
/* ********************************************/
#include "header.h"

void run (plat *p_deb,table *t_deb, int n_plat, int n_table, int n_resto){

    /* Variable */
    int end=0, endSub, choix;

    /* Menu */

    do{
        system("cls");
        printf("+------------------------------------------+\n");
        printf("|          Bienvenue au restaurant         |\n");
        printf("|                Le FranTin                |\n");
        printf("+------------------------------------------+\n");
        printf("|              Menu du programme           |\n");
        printf("+------------------------------------------+\n");
        printf("|       Affichage des listes               |\n");
        printf("+------------------------------------------+\n");
        printf("|   1 - Carte du restaurant                |\n");
        printf("|   2 - Disposition des tables             |\n");
        printf("|   3 - Liste des employes                 |\n");
        printf("+------------------------------------------+\n");
        printf("|       Passer une commande                |\n");
        printf("+------------------------------------------+\n");
        printf("|   4 - Reservation                        |\n");
        printf("|   5 - Walk - in                          |\n");
        printf("+------------------------------------------+\n");
        printf("|       Ajout - Suppression                |\n");
        printf("+------------------------------------------+\n");
        printf("|   6 - Ajout d'un employe                 |\n");
        printf("|   7 - Suppression  d'un employe          |\n");
        printf("+------------------------------------------+\n");
        printf("|       Paiement et impression             |\n");
        printf("+------------------------------------------+\n");
        printf("|   8 - Afficher et payer l'addition       |\n");
        printf("+------------------------------------------+\n");
        printf("+   9 - Sauvegarder                        |\n");
    	printf("|   0 - Quitter le programme               |\n");
    	printf("+------------------------------------------+\n");
    	printf("|   Quel est votre choix?                  |\n");
    	printf("+------------------------------------------+\n");
        printf("Choix : ");
        choix = getchar();
        clean_buffer(choix);
        switch(choix){
            case '0':
                /* Sortir du programme */
                system("cls");
                printf("+------------------------------------------+\n");
                printf("|                                          |\n");
                printf("|          Merci de votre visite,          |\n");
                printf("|                                          |\n");
                printf("|                Au revoir                 |\n");
                printf("|                                          |\n");
                printf("+------------------------------------------+\n");

                end = 1;
                break;

            case '1' :
                /* Affichage de la carte du restaurant */
                system ("cls");
                affiche_carte(p_deb,n_plat);
                system("pause");
                break;
            case '2':
                /* Afficher la liste des tables */
                system("cls");
                affiche_table(t_deb,n_table,n_resto);
                system("pause");
                break;
            case '3':
                /* Afficher la liste des employes */
                system("cls");


                system("pause");
                break;
            case '4':
                /* Ajouter un client par réservation */
                system("cls");


                system("pause");
                break;
            case '5':
                /* Ajouter un client sur place */
                system("cls");


                system("pause");
                break;
            case '6':
                /* Ajouter un employe */
                system("cls");


                system("pause");
                break;
            case '7':
                /* Supprimer un employe */
                system("cls");


                system("pause");
                break;
            case '8':
                /* Ecrire l'addition et supprimer le client */
                system("cls");


                system("pause");
                break;
            case '9':
                /* Sauvegarder les informations */
                system("cls");


                system("pause");
                break;
            default:
                printf("Entrez un numero valide !\n\n");
                system("pause");
                system("cls");
        }

    }while(end != 1);

}
