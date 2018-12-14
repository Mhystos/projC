/* Programme créer par Geerts Quentin Et Mat François
 * dans le cadre du cours de Language C organisé à la HELHa par
 * Monsieur Carpentier en deuxième année Informatique de Gestion
 * Travail à faire durant la période du 22-11-2018 au 19-12-2018
*/

#include "header.h"

int main(){

    /* Structure */
    table *t_deb, *t_courant, *t_suivant;
    plat *p_deb, *p_courant, *p_suivant;

    /* Variable */
    int nb_place_dispo;
    int nb_place;
    int nb_plt;
    /* Pointer */
    int *nb_tab;

    /* Fichier dat */
    FILE *fdat_carte;
    fdat_carte=fopen("carte.dat","r");
    int i, nb_plat=0;
    char car[2];

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
        //printf("%2d %37s %5.2f\n",p_courant->num_plats,p_courant->intitule,p_courant->prix);
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

    /* Test */

    affiche_carte(p_deb,nb_plat);

    /* Initialisation */
<<<<<<< HEAD
    //nb_place = init_table(&t_deb, &nb_tab);
    //nb_plt = init_carte(&p_deb);
    //clean_buffer(nb_place);
    //nb_place_dispo = nb_place; // A ce moment-ci, après l'initialisation, ils sont égaux

    /* Tests des fonctions */
    //printf("\n!!!!Plat!!!!!: %s, %d", p_deb -> intitule, p_deb -> num_plats);
    //affiche_carte(&p_deb,nb_plt);
=======
    nb_place = init_table(&t_deb, &nb_tab);
    nb_plt = init_carte(p_deb);
    printf("\n!!!!Plat!!!!!: %s, %d", p_deb -> intitule, p_deb -> num_plats);
    //clean_buffer(nb_place);
  //  nb_place_dispo = nb_place; // A ce moment-ci, après l'initialisation, ils sont égaux

    /* Tests des fonctions */

//    affiche_carte(p_deb,nb_plt);
>>>>>>> 92dcac326ac0e317519ee8c56f7a808c69c4e0c5
    //printf("%d %d", nb_place,nb_place_dispo);
    //affiche_carte(plt);
}
