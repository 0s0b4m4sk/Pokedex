#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "starter.h"


/*----------------------------------------------------------------------*/

void print_list(pokemon_t *linked_list){

	while(linked_list != NULL){
		printf("\n");
		printf("#---Information sur le Pokemon---#\n");
		printf("\n");
		printf("Nom du Pokemeon : %s\n",linked_list->name);
		printf("Type du Pokemon : %s\n",linked_list->type);
		printf("Niveau du pokemon : %d\n",linked_list->pokemon_niveau);
		printf("Nombre de fois capturé : %d\n",linked_list->nb_pokemon);
		linked_list = linked_list->next;	
	}
}


/*----------------------------------------------------------------------*/

void print_specific_pokemon(pokemon_t *linked_list){

	char pokemon_search [15];


	int i = 0;

	printf("Par nom : 0 \n");
	printf("Retour : 2\n");

	scanf("%d",&i);

	if(i == 0){

		printf("Saisissez le nom du pokemon : ");
		scanf("%s",pokemon_search);
		printf("#----%s-----#\n",pokemon_search);
	}


	while(linked_list != NULL){

		char* pokemon_pokedex = linked_list->name;

		printf("#----%s-----#\n",pokemon_pokedex);
			
		if(strcmp(pokemon_search, pokemon_pokedex) == 0){

			printf("Nom du Pokemon : %s\n",linked_list->name);
			printf("Type du Pokemon : %s\n",linked_list->type);
			printf("Nombre de fois capturé : %d\n",linked_list->nb_pokemon);		
		}
			
	linked_list = linked_list->next;

	}
}

/*----------------------------------------------------------------------*/

int add_pokemon(pokemon_t *linked_list, char *name, char *type, int pokemon_niveau ,int nb_pokemon){


	pokemon_t *tmp = linked_list;
	pokemon_t *new_pokemon = malloc(sizeof(*new_pokemon));

	new_pokemon->name = malloc(strlen(name) + 1);
	new_pokemon->type = malloc(strlen(type) + 1);

	strcpy(new_pokemon->name,name);
	strcpy(new_pokemon->type,type);

	new_pokemon->pokemon_niveau = pokemon_niveau;
	new_pokemon->nb_pokemon = nb_pokemon;
	new_pokemon->next = NULL;

	while (tmp != NULL){
		if (tmp->next == NULL){

			tmp->next = new_pokemon;
			return(0);
		}
		tmp = tmp->next;
	}

	return(1);	
}	
