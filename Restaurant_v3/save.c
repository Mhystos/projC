/* ********************************************/
/*                                            */
/*   Fichier ayant pour but de sauvegarder    */
/*   les differentes listes                   */
/*                                            */
/*   By: François Mat & Geerts Quentin        */
/*                                            */
/*   Created: 2018/12/07                      */
/*   Updated: 2018/12/16                      */
/*                                            */
/* ********************************************/
#include "header.h"

void save (FILE *fdat_table, FILE *fdat_staff, FILE *fdat_test, int n_client, int n_employe, int n_table, table *t_deb, employe *e_deb, client *c_deb){

    /* Variable */
    int i,j;

    /* Structure */
    table *t_courant, *t_suivant;
    employe *e_courant, *e_suivant;
    client *c_courant, *c_suivant;

    /* Table */
    remove("table.dat");
    fdat_table = fopen("table.dat","w");

    t_courant = t_deb;
    fprintf(fdat_table,"%2d\n",n_table);
    for (int i=1;i<=n_table;i++){
        fprintf(fdat_table,"%2d %2d %d\n",t_courant->numero, t_courant->place, t_courant->libre);
        t_courant=t_courant->t_suivant;
    }

    /* Employe */
    remove("staff.dat");
    fdat_staff = fopen("staff.dat","w");

    e_courant = e_deb;
    for (int i=1; i<= n_employe; i++){
        fprintf(fdat_staff,"%-20s%-20s%-9s\n",e_courant->nom,e_courant->prenom,e_courant->role);
        e_courant=e_courant->e_suivant;
    }

    /* Client */
    remove("client.dat");
    fdat_test = fopen("client.dat","w");
    c_courant = c_deb;
    fprintf(fdat_test,"%02d\n",n_client);
    for(i=1;i<=n_client;i++){
        fprintf(fdat_test,"%02d %02d %1d %-5s\n", c_courant->numt, c_courant->nombre, c_courant->reservation, c_courant->heures);
        for(j=1;j<=c_courant->nombre;j++){
            fprintf(fdat_test,"%-35s %5.2f\n",c_courant->entree[j],c_courant->prix[j][1]);
            fprintf(fdat_test,"%-35s %5.2f\n",c_courant->platP[j],c_courant->prix[j][2]);
            fprintf(fdat_test,"%-35s %5.2f\n",c_courant->dessert[j],c_courant->prix[j][3]);
            fprintf(fdat_test,"%-35s %5.2f\n",c_courant->boisson[j],c_courant->prix[j][4]);
        }
        c_courant=c_courant->c_suivant;
    }

    printf("La sauvegarde s'est bien effectuee.\n");

}
