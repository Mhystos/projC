#include "header.h"

int init_carte(plat **p_deb){

<<<<<<< HEAD
    /* Ouverture du fichier de lecture */
    FILE *fdat_carte;
    fdat_carte=fopen("carte.dat","r");

    /* Variables */
    int i, nb_plat=0;
    char car[2];

    /* Structure */
    plat *p_courant,*p_suivant;

    p_deb = malloc(sizeof(plat));
    p_courant = p_deb;

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
    /*p_courant = p_deb;
    for(i=1;i<nb_plat;i++){
        p_courant=p_courant->p_suivant;
    }
    p_courant->p_suivant=NULL;*/
    free(p_suivant);

    /* On retourne le nombre de plat */
    return nb_plat;
=======
	/* Ouverture du fichier de lecture */
	FILE *fdat_carte;
	fdat_carte=fopen("carte.dat","r");
	
	/* Variables */
	int i, nb_plat=0;
	char car[2];
	char buffer[37];

	/* Structure */
	plat *p_courant,*p_suivant, *first;

	p_deb = malloc(sizeof(plat));
	p_courant = p_deb;
	first = p_courant;
	fscanf(fdat_carte,"%d",&nb_plat);
	fgets(car,2,fdat_carte);
	for(i=1;i<=nb_plat;i++){
		//fgets(p_courant->intitule,36,fdat_carte);
		fgets(buffer, 36, fdat_carte);
		strncpy(p_courant->intitule,buffer,36 );
		fscanf(fdat_carte,"%5f",&p_courant->prix);
		fgets(car,2,fdat_carte);
		p_courant->num_plats=i;
		//printf("%2d %37s %5.2f\n",p_courant->num_plats,p_courant->intitule,p_courant->prix);
		p_suivant = malloc(sizeof(plat));
		p_courant->p_suivant=p_suivant;
		p_courant=p_suivant;
	}

	/* On termine la liste avec l'adresse NULL */
	/*p_courant = p_deb;
	for(i=1;i<nb_plat;i++){
		p_courant=p_courant->p_suivant;
	}
	p_courant->p_suivant=NULL;
	free(p_suivant);
*/
	/* On retourne le nombre de plat */
	p_deb = first;
	printf("First : %d   %s", p_deb -> num_plats, p_deb -> intitule);
	printf("\nnbPlat:%d", nb_plat);
	return nb_plat;
>>>>>>> 92dcac326ac0e317519ee8c56f7a808c69c4e0c5
}
