/* ********************************************/
/*                                            */
/*   Fichier ayant pour but d'ajouter à la    */
/*   liste chainée un client                  */
/*                                            */
/*   By: François Mat & Geerts Quentin        */
/*                                            */
/*   Created: 2018/12/07                      */
/*   Updated: 2018/12/13                      */
/*                                            */
/* ********************************************/
#include "header.h"

int ajout_client(client* *c_deb, plat *p_deb, table* *t_deb, int reserve, int n_resto, int n_plat, int n_table, int n_client, int *nb_place_dispo){

    /* Si reserve vaut 1 alors c'est une réservation,
     * si reserve vaut 2 alors c'est un walk-in
     */

    /* Variables */
    int i, j, tmp_personne, tmp_table, tmp_plat, tmp_rep, tmp_rep1;

    /* Variable de sortie de cond */
    int cond1=0;
    int cond2=0;

    /* Structure */
    client *c_courant, *c_suivant, *c_intercale;
    table *t_courant,*t_suivant;
    plat *p_courant, *p_suivant;

    if(reserve == 1) {
        /* En cas d'une réservation */
        printf("+----------------------------------------+\n");
        printf("|               Reservation              |\n");
        printf("+----------------------------------------+\n");

        printf("\n");

        printf("Nombre de personnes voulant manger ?    (Max : 12)\n");
        printf("-------------------------------------------------\n");
        printf("Nombre de personnes: ");
        scanf("%d", &tmp_personne);

        /* On vérifie la disponibilité par rapport aux nombres de places disponibles
         * dans le restaurant ($nb_place_dispo) ainsi que le nombre de personnes
         * qui doit être supérieur à 0 et inférieur ou égal à 12
         * car il n'y a pas de table pour plus de 12 personnes
         */

        if(tmp_personne > 0 && tmp_personne <= *nb_place_dispo && tmp_personne<=12) {

            system("cls");
            printf("+----------------------------------------+\n");
            printf("| Nombre de personnes :                %2d|\n", tmp_personne);
            printf("+----------------------------------------+\n\n");

            /* On vérifie d'abord si la table demandé est bien dans la liste
             * Si elle se trouve dans la liste, on regarde si elle est libre
             * Si elle est libre, on la passe en "occupée" et on continue
             */
            do {
                affiche_table(*t_deb, n_table, n_resto,nb_place_dispo);
                printf("Choix de la table pour %d personne(s)\n", tmp_personne);
                printf("-------------------------------------\n");
                printf("Choix : ");
                scanf("%d", &tmp_table);

                if(tmp_table >0 && tmp_table<=n_table){
                    cond2=1; // La table est bien parmis la table
                    t_courant = *t_deb;
                    for(i=1;i<=n_table;i++){
                        if(t_courant->numero == tmp_table && t_courant->libre==0 && t_courant->place >= tmp_personne){
                            t_courant->libre =1; // On passe la table en occupée
                            cond1 = 1; //La table choisie est bien de la bonne taille et était non occupée
                            *nb_place_dispo -= t_courant -> place ; // on change le nombre de place disponible dans le restaurant
                        }
                        t_courant=t_courant->t_suivant;
                    }
                    if(cond1==0)
                        printf("La table que vous avez choisie est deja occupee ou celle-ci est trop petite pour vous.\nVeuillez choisir une table libre.\n");
                        system("cls");
                }
                else if(cond2==0){
                    printf("La table que vous avez choisie n'est pas dans la liste, veuillez choisir une table existante.\n");
                    system("cls");
                }

            }while(cond1!=1);

            /* Si on arrive la, c'est que la table a été correctement choisie */

            c_intercale = malloc(sizeof(client));

            system("cls");

            /* Initialisation */
            if(n_client != 0) {

                c_courant = *c_deb;
                if(n_client ==1){
                    c_intercale -> c_suivant = *c_deb;
                    (*c_deb)->c_suivant=c_intercale; // on se place en seconde position
                }
                else{
                    for(i = 1 ; i < n_client ; i ++) { /* Allez jusqu'au dernier client entré */
                        c_courant = c_courant->c_suivant;
                    }
                    c_intercale->c_suivant = c_courant->c_suivant;
                    c_courant->c_suivant = c_intercale;
                }

            }
            else { // Dans le cas où on aurait pas du tout de client
                c_intercale = *c_deb;
                (*c_deb) = c_intercale;
            }

            c_intercale->nombre = tmp_personne;
            c_intercale->numt = tmp_table;
            printf("Voulez-vous reserver vos plats des maintenant ? [0]oui/[1]non\n");
            scanf("%d",&tmp_rep1);
            printf("\n");
            if(tmp_rep1==0){
                system("cls");
                affiche_carte(p_deb, n_plat);
                printf("Voulez-vous commander le meme repas pour chaque personne ?[0]oui/[1]non\n");
                scanf("%d",&tmp_rep);
                printf("\n");
                if(tmp_rep==1){
                    for(i = 1 ; i <= tmp_personne ; i ++) {

                        printf("[Personne %d]Veuillez entrez le numero de l'entree\n", i);
                        printf("--------------------------------------------------\n");
                        printf("Numero : ");
                        scanf("%d", &tmp_plat);
                        printf("\n");
                        p_courant = p_deb;
                        for(j=1;j<=n_plat;j++){
                            if(p_courant->num_plats==tmp_plat){
                                strcpy(c_intercale->entree[i],p_courant->intitule);
                                c_intercale->prix[i][1] = p_courant->prix;
                                j=n_plat +1;
                            }
                            p_courant=p_courant->p_suivant;
                        }

                        printf("[Personne %d]Veuillez entrez le numero du plat\n", i);
                        printf("----------------------------------------------\n");
                        printf("Numero : ");
                        scanf("%d", &tmp_plat);
                        printf("\n");
                        p_courant = p_deb;
                        for(j=1;j<=n_plat;j++){
                            if(p_courant->num_plats==tmp_plat){
                                strcpy(c_intercale->platP[i],p_courant->intitule);
                                c_intercale->prix[i][2] = p_courant->prix;
                                j=n_plat +1;
                            }
                            p_courant=p_courant->p_suivant;
                        }

                        printf("[Personne %d]Veuillez entrez le numero du dessert\n", i);
                        printf("-------------------------------------------------\n");
                        printf("Numero : ");
                        scanf("%d", &tmp_plat);
                        printf("\n");
                        p_courant = p_deb;
                        for(j=1;j<=n_plat;j++){
                            if(p_courant->num_plats==tmp_plat){
                                strcpy(c_intercale->dessert[i],p_courant->intitule);
                                c_intercale->prix[i][3] = p_courant->prix;
                                j=n_plat +1;
                            }
                            p_courant=p_courant->p_suivant;
                        }

                        printf("[Personne %d]Veuillez entrez le numero de la boisson\n", i);
                        printf("----------------------------------------------------\n");
                        printf("Numero : ");
                        scanf("%d", &tmp_plat);
                        printf("\n");
                        p_courant = p_deb;
                        for(j=1;j<=n_plat;j++){
                            if(p_courant->num_plats==tmp_plat){
                                strcpy(c_intercale->boisson[i],p_courant->intitule);
                                c_intercale->prix[i][4] = p_courant->prix;
                                j=n_plat +1;
                            }
                            p_courant=p_courant->p_suivant;
                        }
                    }
                }
                else if (tmp_rep==0){
                    printf("Veuillez entrez le numero de l'entree pour la table\n");
                    printf("-----------------------------------------------------\n");
                    printf("Numero : ");
                    scanf("%d", &tmp_plat);
                    printf("\n");
                    p_courant = p_deb;
                    for(j=1;j<=n_plat;j++){
                        if(p_courant->num_plats==tmp_plat){
                            for(i=1;i<=tmp_personne;i++){
                                strcpy(c_intercale->entree[i],p_courant->intitule);
                                c_intercale->prix[i][1] = p_courant->prix;
                                j=n_plat +1;
                            }
                        }
                        p_courant=p_courant->p_suivant;
                    }

                    printf("Veuillez entrez le numero du plat pour la table\n");
                    printf("-----------------------------------------------------\n");
                    printf("Numero : ");
                    scanf("%d", &tmp_plat);
                    printf("\n");
                    p_courant = p_deb;
                    for(j=1;j<=n_plat;j++){
                        if(p_courant->num_plats==tmp_plat){
                            for(i=1;i<=tmp_personne;i++){
                                strcpy(c_intercale->platP[i],p_courant->intitule);
                                c_intercale->prix[i][2] = p_courant->prix;
                                j=n_plat +1;
                            }
                        }
                        p_courant=p_courant->p_suivant;
                    }

                    printf("Veuillez entrez le numero du dessert pour la table\n");
                    printf("-----------------------------------------------------\n");
                    printf("Numero : ");
                    scanf("%d", &tmp_plat);
                    printf("\n");
                    p_courant = p_deb;
                    for(j=1;j<=n_plat;j++){
                        if(p_courant->num_plats==tmp_plat){
                            for(i=1;i<=tmp_personne;i++){
                                strcpy(c_intercale->dessert[i],p_courant->intitule);
                                c_intercale->prix[i][3] = p_courant->prix;
                                j=n_plat +1;
                            }
                        }
                        p_courant=p_courant->p_suivant;
                    }

                    printf("Veuillez entrez le numero de la boisson pour la table\n");
                    printf("-----------------------------------------------------\n");
                    printf("Numero : ");
                    scanf("%d", &tmp_plat);
                    printf("\n");
                    p_courant = p_deb;
                    for(j=1;j<=n_plat;j++){
                        if(p_courant->num_plats==tmp_plat){
                            for(i=1;i<=tmp_personne;i++){
                                strcpy(c_intercale->boisson[i],p_courant->intitule);
                                c_intercale->prix[i][4] = p_courant->prix;
                                j=n_plat +1;
                            }
                        }
                        p_courant=p_courant->p_suivant;
                    }
            }

                n_client ++;
                c_intercale->reservation=reserve;

                printf("Pour quelle heure desirez-vous reserver la table ?\n");
                printf("----------------------------------------------------\n");
                printf("Heure d'arrivee (hh:mm) : ");
                scanf("%s",&c_intercale->heures);
                printf("\n");
            }
            else if (tmp_rep1==1){
                printf("Pas de soucis, nous prendrons les plats plus tard\n\n");
                n_client ++;
                c_intercale->reservation=reserve;

                printf("Pour quelle heure desirez-vous reserver la table ?\n");
                printf("----------------------------------------------------\n");
                printf("Heure d'arrivee (hh:mm) : ");
                scanf("%s",&c_intercale->heures);
                printf("\n");
            }

            /* Résumé de la commande en cours */

            system("cls");
            printf("+-----------------------------------------------------+\n");
            printf("|  NUM  |  TABLE  |  NOMBRE  |  RESERVATION  | HEURE  |\n");
            printf("+-----------------------------------------------------+\n");
            printf("|   %2d  |    %2d   |     %2d   |",n_client,c_intercale->numt, c_intercale->nombre);
            if (c_intercale->reservation == 1){
                printf("  Reservation  | %-7s|\n",c_intercale->heures);
            }
            else if (c_intercale->reservation == 2){
                printf("    Walk-in    | %-7s|\n",c_intercale->heures);
            }
            for(j=1;j<=c_intercale->nombre;j++){
                printf("+-----------------------------------------------------+\n");
                printf("|Choix du menu de la %2d e personne                    |\n",j);
                printf("+-----------------------------------------------------+\n");
                printf("| ENTREE : %-35s %5.2f e|\n",c_intercale->entree[j], c_intercale->prix[j][1]);
                printf("| PLAT   : %-35s %5.2f e|\n",c_intercale->platP[j], c_intercale->prix[j][2]);
                printf("| DESSERT: %-35s %5.2f e|\n",c_intercale->dessert[j], c_intercale->prix[j][3]);
                printf("| BOISSON: %-35s %5.2f e|\n",c_intercale->boisson[j], c_intercale->prix[j][4]);
            }
            printf("+-----------------------------------------------------+\n");
            printf("Il reste maintenant %d places disponibles dans le restaurant\n",*nb_place_dispo);
        }
        else {
            printf("Malheureusement, il ne nous reste plus de places pour %2d.\n",tmp_personne);
        }
        return n_client;
    }

    else if(reserve == 2) {
        /* En cas d'un sur place */
        printf("+----------------------------------------+\n");
        printf("|                 Walk-in                |\n");
        printf("+----------------------------------------+\n");

        printf("\n");

        printf("Nombre de personnes voulant manger ?    (Max : 12)\n");
        printf("-------------------------------------------------\n");
        printf("Nombre de personnes : ");
        scanf("%d", &tmp_personne);

        /* On vérifie la disponibilité par rapport aux nombres de places disponibles
         * dans le restaurant ($nb_place_dispo) ainsi que le nombre de personnes
         * qui doit être supérieur à 0 et inférieur ou égal à 12
         * car il n'y a pas de table pour plus de 12 personnes
         */

        if(tmp_personne > 0 && tmp_personne <= *nb_place_dispo && tmp_personne<=12) {

            system("cls");
            printf("+----------------------------------------+\n");
            printf("| Nombre de personnes :                 %d|\n", tmp_personne);
            printf("+----------------------------------------+\n\n");

            /* On vérifie d'abord si la table demandé est bien dans la liste
             * Si elle se trouve dans la liste, on regarde si elle est libre
             * Si elle est libre, on la passe en "occupée" et on continue
             */
            do {
                affiche_table(*t_deb, n_table, n_resto, nb_place_dispo);
                printf("Choix de la table pour %d personne(s)\n", tmp_personne);
                printf("-------------------------------------\n");
                printf("Choix : ");
                scanf("%d", &tmp_table);

                if(tmp_table >0 && tmp_table<=n_table){
                    cond2=1; // La table est bien parmis la table
                    t_courant = *t_deb;
                    for(i=1;i<=n_table;i++){
                        if(t_courant->numero == tmp_table && t_courant->libre==0 && t_courant->place >= tmp_personne){
                            t_courant->libre =1; // On passe la table en occupée
                            cond1 = 1; //La table choisie est bien de la bonne taille et était non occupée
                            *nb_place_dispo -= t_courant -> place ; // on change le nombre de place disponible dans le restaurant
                        }
                        t_courant=t_courant->t_suivant;
                    }
                    if(cond1==0)
                        printf("La table que vous avez choisie est deja occupee ou celle-ci est trop petite pour vous.\nVeuillez choisir une table libre.\n");

                }
                else if(cond2==0){
                    printf("La table que vous avez choisie n'est pas dans la liste, veuillez choisir une table existante.\n");

                }

            }while(cond1!=1);

            /* Si on arrive la, c'est que la table a été correctement choisie */

            c_intercale = malloc(sizeof(client));

            system("cls");

            /* Initialisation */
            if(n_client != 0) {

                c_courant = *c_deb;
                if(n_client ==1){
                    c_intercale -> c_suivant = *c_deb;
                    (*c_deb)->c_suivant=c_intercale; // on se place en seconde position
                }
                else{
                    for(i = 1 ; i < n_client ; i ++) { /* Allez jusqu'au dernier client entré */
                        c_courant = c_courant->c_suivant;
                    }
                    c_intercale->c_suivant = c_courant->c_suivant;
                    c_courant->c_suivant = c_intercale;
                }

            }
            else { // Dans le cas où on aurait pas du tout de client
                c_intercale = *c_deb;
                (*c_deb) = c_intercale;
            }


                c_intercale->nombre = tmp_personne;
                c_intercale->numt = tmp_table;

                for(i = 1 ; i <= tmp_personne ; i ++) {
                    system("cls");
                    affiche_carte(p_deb, n_plat);

                    printf("[Personne %d/%d]Veuillez entrez le numero de l'entree\n", i, tmp_personne);
                    printf("--------------------------------------------------\n");
                    printf("Numero : ");
                    scanf("%d", &tmp_plat);
                    printf("\n");
                    p_courant = p_deb;
                    for(j=1;j<=n_plat;j++){
                        if(p_courant->num_plats==tmp_plat){
                            strcpy(c_intercale->entree[i],p_courant->intitule);
                            c_intercale->prix[i][1] = p_courant->prix;
                            j=n_plat +1;
                        }
                        p_courant=p_courant->p_suivant;
                    }

                    printf("[Personne %d/%d]Veuillez entrez le numero du plat\n", i, tmp_personne);
                    printf("----------------------------------------------\n");
                    printf("Numero : ");
                    scanf("%d", &tmp_plat);
                    printf("\n");
                    p_courant = p_deb;
                    for(j=1;j<=n_plat;j++){
                        if(p_courant->num_plats==tmp_plat){
                            strcpy(c_intercale->platP[i],p_courant->intitule);
                            c_intercale->prix[i][2] = p_courant->prix;
                            j=n_plat +1;
                        }
                        p_courant=p_courant->p_suivant;
                    }

                    printf("[Personne %d/%d]Veuillez entrez le numero du dessert\n", i, tmp_personne);
                    printf("-------------------------------------------------\n");
                    printf("Numero : ");
                    scanf("%d", &tmp_plat);
                    printf("\n");
                    p_courant = p_deb;
                    for(j=1;j<=n_plat;j++){
                        if(p_courant->num_plats==tmp_plat){
                            strcpy(c_intercale->dessert[i],p_courant->intitule);
                            c_intercale->prix[i][3] = p_courant->prix;
                            j=n_plat +1;
                        }
                        p_courant=p_courant->p_suivant;
                    }

                    printf("[Personne %d/%d]Veuillez entrez le numero de la boisson\n", i, tmp_personne);
                    printf("----------------------------------------------------\n");
                    printf("Numero : ");
                    scanf("%d", &tmp_plat);
                    printf("\n");
                    p_courant = p_deb;
                    for(j=1;j<=n_plat;j++){
                        if(p_courant->num_plats==tmp_plat){
                            strcpy(c_intercale->boisson[i],p_courant->intitule);
                            c_intercale->prix[i][4] = p_courant->prix;
                            j=n_plat +1;
                        }
                        p_courant=p_courant->p_suivant;
                    }
                }
                n_client ++;
                c_intercale->reservation=reserve;

                printf("A quelle heure le client est-il arrive ?\n");
                printf("----------------------------------------------------\n");
                printf("Heure d'arrivee (hh:mm) : ");
                scanf("%s",&c_intercale->heures);
                printf("\n");

                /* Résumé de la commande en cours */

                system("cls");
                printf("+-----------------------------------------------------+\n");
                printf("|  NUM  |  TABLE  |  NOMBRE  |  RESERVATION  | HEURE  |\n");
                printf("+-----------------------------------------------------+\n");
                printf("|   %2d  |    %2d   |     %2d   |",n_client,c_intercale->numt, c_intercale->nombre);
                if (c_intercale->reservation == 1){
                    printf("  Reservation  | %-7s|\n",c_intercale->heures);
                }
                else if (c_intercale->reservation == 2){
                    printf("    Walk-in    | %-7s|\n",c_intercale->heures);
                }
                for(j=1;j<=c_intercale->nombre;j++){
                    printf("+-----------------------------------------------------+\n");
                    printf("|Choix du menu de la %2d e personne                    |\n",j);
                    printf("+-----------------------------------------------------+\n");
                    printf("| ENTREE : %-35s %5.2f e|\n",c_intercale->entree[j], c_intercale->prix[j][1]);
                    printf("| PLAT   : %-35s %5.2f e|\n",c_intercale->platP[j], c_intercale->prix[j][2]);
                    printf("| DESSERT: %-35s %5.2f e|\n",c_intercale->dessert[j], c_intercale->prix[j][3]);
                    printf("| BOISSON: %-35s %5.2f e|\n",c_intercale->boisson[j], c_intercale->prix[j][4]);
                }
                printf("+-----------------------------------------------------+\n");
                printf("Il reste maintenant %d places disponibles dans le restaurant\n",*nb_place_dispo);
        }
        else {
            printf("Malheureusement, il ne nous reste plus de places pour %2d.\n",tmp_personne);
        }
    }
    return n_client;
}
