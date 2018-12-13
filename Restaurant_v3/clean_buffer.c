#include "header.h"

/* vider le buffer clavier consiste à consommer tous les caractères présents dans ce buffer jusqu'à ce qu'il soit vide */

void clean_buffer(int integer) {

    if(integer != '\n' && integer != EOF) {
        int clean;
        while((clean = getchar()) != '\n' && clean != EOF);
    }
}
