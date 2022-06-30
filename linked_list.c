#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

/*----------------------------------------------------------------------*/

void print_list(pokemon_t *linked_list){

	while(linked_list != NULL){
		printf("%s\n",linked_list->name);
		printf("%s\n",linked_list->type);
		printf("%d\n",linked_list->nb_pokemon);
		linked_list = linked_list->next;
	}
}


/*----------------------------------------------------------------------*/

void print_specific_pokemon(pokemon_t *linked_list){

	while(linked_list != NULL)
	{
		printf("TeST");
	}
}
