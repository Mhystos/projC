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
    float addition;
//    struct client cl;
    struct table *t_suivant;
}table;

/*Structure d'un client */

typedef struct client{
    int nb_client;
    char lb_entree[37];
    char lb_plat[37];
    char lb_dessert[37];
    struct client *c_suivant;
    int heures; // En heure
}client;

/* Appel des différents prototypes */

    int init_table(table *t_deb, int *nb_tab);
    int init_carte(plat **p_deb);
    void affiche_carte(plat *p_deb, int n);
    void clean_buffer(int integer);

#endif // HEADER_H_INCLUDED
