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
    employe *e_deb, *e_courant, *e_suivant, *e_precedent;
    client *c_deb,*c_courant, *c_suivant, *c_intercale;

    /* Variable */
    int nb_resto=0;
    int nb_table=0;

    int nb_client =0;
    int nb_plat=0;
    int nb_employe=0;

    int end=0, choix;

    /* Compteur */
    int i;

    /* Pointeur */
    int *nb_place_dispo;

    /* Fichier dat */
    FILE *fdat_carte, *fdat_table, *fdat_staff;
    fdat_carte=fopen("carte.dat","r");
    fdat_table=fopen("table.dat","r");
    fdat_staff=fopen("staff.dat","r");


    /*******************************************************/
    /*                      PLAT                           */
    /*******************************************************/
    char car[2]; // Pour le passage à la ligne

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
        fscanf(fdat_table,"%2d%2d%1d",&t_courant->numero,&t_courant->place, &t_courant->libre);

        t_suivant=malloc(sizeof(table));
        t_courant->t_suivant=t_suivant;
        t_courant=t_suivant;
    }

    /*On termine la liste avec l'adresse NULL */
    t_courant=t_deb;
    nb_resto+=t_deb->place;
    for(i=1;i<nb_table;i++){
        t_courant=t_courant->t_suivant;
        nb_resto+=t_courant->place;
    }
    t_courant->t_suivant=NULL;
    free(t_suivant);

    /*******************************************************/
    /*                      EMPLOYE                        */
    /*******************************************************/

    /*  Allocation de mémoire pour la liste des employes   */
    e_deb = malloc(sizeof(employe));
    e_courant=e_deb;

    /*Lecture de staff.dat*/
    fscanf(fdat_staff,"%20s",e_courant->nom);
    while (!feof(fdat_staff)){
        fscanf(fdat_staff,"%20s%10s",e_courant->prenom,e_courant->role);
        nb_employe++;

        e_suivant=malloc(sizeof(employe));
        e_courant->e_suivant=e_suivant;
        e_courant=e_suivant;

        fscanf(fdat_staff,"%20s",e_courant->nom);
    }


    /* On termine la liste avec l'adresse NULL*/
    e_courant=e_deb;
    for(i=1;i<nb_employe;i++){
        e_courant=e_courant->e_suivant;
    }
    e_courant->e_suivant=NULL;
    free(e_suivant);


    /*******************************************************/
    /*                      CLIENT                         */
    /*******************************************************/

    /* Allocation de mémoire pour la liste  de client      */
    c_deb=malloc(sizeof(client));
    c_courant=c_deb;

    /* On termine la liste avec l'adresse NULL */
    for(i = 1 ; i < nb_client ; i ++){
        c_courant = c_courant -> c_suivant;
    }
    c_courant->c_suivant = NULL;
    free(c_suivant);



    /*******************************************************/
    /*                       RUN                           */
    /*******************************************************/
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
                affiche_carte(p_deb,nb_plat);
                system("pause");
                break;
            case '2':
                /* Afficher la liste des tables */
                system("cls");
                affiche_table(t_deb,nb_table,nb_resto);
                system("pause");
                break;
            case '3':
                /* Afficher la liste des employes */
                system("cls");
                affiche_staff(e_deb,nb_employe);
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
                affiche_staff(e_deb,nb_employe);
                nb_employe = ajout_staff(&e_deb,nb_employe);
                affiche_staff(e_deb,nb_employe);
                system("pause");
                break;
            case '7':
                /* Supprimer un employe */
                system("cls");
                affiche_staff(e_deb,nb_employe);
                nb_employe = supp_staff(&e_deb,nb_employe);
                affiche_staff(e_deb,nb_employe);
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
                //printf("Entrez un numero valide !\n\n");
                //system("pause");
                system("cls");
        }

    }while(end != 1);




    /*******************************************************/
    /*                      TESTS                          */
    /*******************************************************/


    //run (p_deb,t_deb,e_deb,nb_plat,nb_table,nb_resto,nb_employe);
    //affiche_carte(p_deb,nb_plat);
    //clean_buffer(nb_resto);
    //affiche_table(t_deb,nb_table,nb_resto);
    //affiche_staff(e_deb,nb_employe);










}
