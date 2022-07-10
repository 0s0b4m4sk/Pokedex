#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stddef.h>
#include <stdio.h>

/* definition d'une liste */ 

typedef struct pokemon
{	
	struct pokemon *prev;
	char *name;
	char *type;
	int pokemon_niveau;
	int nb_pokemon;
	char *discover;
	char *capture;
	struct pokemon *next;

}pokemon_t ;



/* Prototype */

void print_list(pokemon_t *linked_list);
void print_specific_pokemon(pokemon_t *linked_list);
void print_specific_pokemon(pokemon_t *linked_list);
void delete_pokemon_node(pokemon_t *linked_list,int index);
void update_element(pokemon_t *linked_list, int index , int old_value, int new_value);
int add_pokemon(pokemon_t* linked_list, char *name, char *type,int pokemon_niveau, int nb_pokemon, char* discover, char* capture);
int add_pokemon_in_middle(pokemon_t* linked_list, char*before_name, char *name, char *type,int pokemon_niveau, int nb_pokemon);
int get_index(pokemon_t *linked_list, int lenght, char * name);
int get_lenght(pokemon_t * linked_list);
int exist_pokemon(pokemon_t *linked_list, char *name);



#endif /*__LINKED_LIST__ */