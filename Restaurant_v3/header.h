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

/*typedef struct client
    int num_table;
    int nombre;
    char lb_entree[37];
    char lb_plat[37];
    char lb_dessert[37];
    struct client *c_suivant;
    int heures; // En heure
}client;*/

/* Appel des différents prototypes */

    void run (plat *p_deb,table *t_deb, int n_plat, int n_table, int n_resto);
    void affiche_carte(plat *p_deb, int n);
    void affiche_table(table *t_deb, int nt, int nr);
    void affiche_staff(employe *e_deb, int n_employe);
    void clean_buffer(int integer);

#endif // HEADER_H_INCLUDED
