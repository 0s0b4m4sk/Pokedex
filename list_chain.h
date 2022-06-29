#ifndef __LINKED_LIST__
#define __LINKED_LIST__



/* definition d'une liste */ 

typedef struct pokemon
{	
	char *name;
	char *type; 
	int nb_pokemon;
	struct pokemon *next;
}pokemon_t;

/* Prototype */



#endif /*__LINKED_LIST__ */