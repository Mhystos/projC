/* ********************************************/
/*                                            */
/*                                            */
/*   fichier.h                                */
/*                                            */
/*   By: François Mat & Geerts Quentin        */
/*                                            */
/*   Created: 2018/12/07                      */
/*   Updated: 2018/12/13                      */
/*                                            */
/* ********************************************/

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h> // Pour le isdigit()

/*Structure d'un plat*/
typedef struct plat{
    int num_plats;
    char intitule[37];
    float prix;
    struct plat *p_suivant;
} plat;

/*Structure d'une table*/
typedef struct table{
    int numero;
    int place;
    int libre;
    struct table *t_suivant;
}table;

/*Structure d'un membre du personnel*/
typedef struct employe{
    char nom[21];
    char prenom[21];
    char role[10];
    struct employe *e_suivant;
}employe;

/*Structure d'un client */
typedef struct client{
    int numt;
    int nombre;
    char entree[13][37];
    char platP[13][37];
    char dessert[13][37];
    char boisson[13][37];
    float prix[13][5];
    int reservation; // 1 = réservation ; 2 = walk-in
    char heures[6]; //hh:mm
    struct client *c_suivant;
}client;

/* Appel des différents prototypes */
    int ajout_staff(employe* *e_deb, int n_employe);
    int supp_staff(employe* *e_deb,int n_employe);

    int ajout_client(client* *c_deb, plat *p_deb, table* *t_deb, int reserve, int n_resto, int n_plat, int n_table, int n_client, int *nb_place_dispo);

    void affiche_carte(plat *p_deb, int n);
    void affiche_table(table *t_deb, int nt, int nr);
    void affiche_staff(employe *e_deb, int n_employe);
    void affiche_client(client *c_deb, int n_client);

    void clean_buffer(int integer);

#endif // HEADER_H_INCLUDED
