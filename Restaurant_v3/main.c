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

    /* Variable */
    int nb_place_dispo;
    int nb_place;
    int nb_plt;
    /* Pointer */
    int *nb_tab;

    /* Appel de fonction */
    /* Initialisation */
    nb_place = init_table(&t_deb, &nb_tab);
    nb_plt = init_carte(p_deb);
    clean_buffer(nb_place);
    nb_place_dispo = nb_place; // A ce moment-ci, après l'initialisation, ils sont égaux

    /* Tests des fonctions */

    affiche_carte(p_deb,nb_plt);
    //printf("%d %d", nb_place,nb_place_dispo);
    //affiche_carte(plt);




}
