#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stddef.h>
#include <stdio.h>

/* definition d'une liste */ 

typedef struct pokemon
{	
	char *name;
	char *type; 
	int pokemon_niveau;
	int nb_pokemon;
	struct pokemon *next;
}pokemon_t;

/* Prototype */

void print_list(pokemon_t *linked_list);
void print_specific_pokemon(pokemon_t *linked_list);
int add_pokemon(pokemon_t* linked_list, char *name, char *type,int pokemon_niveau, int nb_pokemon);
void print_specific_pokemon(pokemon_t *linked_list);



#endif /*__LINKED_LIST__ */