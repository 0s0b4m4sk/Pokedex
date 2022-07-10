#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "starter.h"


/*----------------------------------------------------------------------*/

void print_list(pokemon_t *linked_list){

	if(linked_list == NULL){

		printf("la liste est vide");
	}

	else{

		while(linked_list != NULL){
			printf("\n");
			printf("#---Information sur le Pokemon---#\n");
			printf("\n");
			printf("Nom du Pokemeon : %s\n",linked_list->name);
			printf("Type du Pokemon : %s\n",linked_list->type);
			printf("Niveau du pokemon : %d\n",linked_list->pokemon_niveau);
			printf("Date de decouverte du pokemon : %s",linked_list->discover);
			printf("Date de capture du pokemon : %s", linked_list->capture);
			printf("Nombre de fois capturé : %d\n",linked_list->nb_pokemon);
			linked_list = linked_list->next;	
		}
	}
}



/*----------------------------------------------------------------------*/

void print_specific_pokemon(pokemon_t *linked_list){

	char pokemon_search [15];

	int i = 0;

	printf("Par nom : 0 \n");
	printf("Attrapé : 1\n");
	printf("Apercu : 2\n");
	printf("Retour : 3\n");

	scanf("%d",&i);

	if(i == 0){

		printf("Saisissez le nom du pokemon : ");
		scanf("%s",pokemon_search);
		printf("#----%s-----#\n",pokemon_search);

		while(linked_list != NULL){

		char* pokemon_pokedex = linked_list->name;

		printf("#----%s-----#\n",pokemon_pokedex);
			
		if(strcmp(pokemon_search, pokemon_pokedex) == 0){

			printf("Nom du Pokemon : %s\n",linked_list->name);
			printf("Type du Pokemon : %s\n",linked_list->type);
			printf("Niveau du pokemon : %d\n",linked_list->pokemon_niveau);
			printf("Date de decouverte du pokemon : %s\n",linked_list->discover);
			printf("Date de capture du pokemon : %s\n", linked_list->capture);
			printf("Nombre de fois capturé : %d\n",linked_list->nb_pokemon);		
		}
			
		linked_list = linked_list->next;

		}
	}

	else if(i == 1){

		int statue = 1 ;

		while(linked_list != NULL){

			int possede = linked_list->nb_pokemon;

			if(possede >= statue){

				printf("Nom du Pokemon : %s\n",linked_list->name);
				printf("Type du Pokemon : %s\n",linked_list->type);
				printf("Niveau du pokemon : %d\n",linked_list->pokemon_niveau);
				printf("Date de decouverte du pokemon : %s\n",linked_list->discover);
				printf("Date de capture du pokemon : %s\n", linked_list->capture);
				printf("Nombre de fois capturé : %d\n",linked_list->nb_pokemon);
			}

		linked_list = linked_list->next;

		}
	}

	else if(i == 2){

		int statue = 0 ;

		while(linked_list != NULL){

			int possede = linked_list->nb_pokemon;

			if(statue == possede){

				printf("Nom du Pokemon : %s\n",linked_list->name);
				printf("Type du Pokemon : %s\n",linked_list->type);
				printf("Niveau du pokemon : %d\n",linked_list->pokemon_niveau);
				
			}

		linked_list = linked_list->next;

		}
	}
	
}

/*----------------------------------------------------------------------*/

int add_pokemon(pokemon_t *linked_list, char *name, char *type, int pokemon_niveau ,int nb_pokemon, char* discover, char* capture){

	pokemon_t *tmp_current;
	pokemon_t *tmp_prev;  
	pokemon_t *new_pokemon = malloc(sizeof(*new_pokemon));

	new_pokemon->name = malloc(strlen(name) + 1);
	new_pokemon->type = malloc(strlen(type) + 1);
	new_pokemon->discover = malloc(strlen(discover) + 1);
	new_pokemon->capture = malloc(strlen(capture) + 1) ;

	if(new_pokemon->name == NULL || new_pokemon->type == NULL){

		fprintf(stderr, "Erreur : probléme d'allocation dynamqique \n" );
		exit(EXIT_FAILURE);
	}

	strcpy(new_pokemon->name,name);
	strcpy(new_pokemon->type,type);
	strcpy(new_pokemon->discover,discover);
	strcpy(new_pokemon->capture,capture);

	new_pokemon->pokemon_niveau = pokemon_niveau;
	new_pokemon->nb_pokemon = nb_pokemon;
	new_pokemon->next = NULL;

	if(!linked_list){
		linked_list = new_pokemon ; 
	}

	else{
		tmp_current = linked_list ;
		if(strcmp(name,tmp_current->name) < 0 ){

			printf("%s",name);
			printf("%s",tmp_current->name);
			printf("%d",strcmp(name,tmp_current->name));

			new_pokemon->next = linked_list;
			linked_list = new_pokemon;
			return(0);
		}
		else{
			tmp_prev = tmp_current; 
			while(tmp_current && strcmp(name,tmp_current->name) > 0){

				printf("%d",strcmp(name,tmp_current->name));

				tmp_prev = tmp_current;
				tmp_current = tmp_current->next;
			}
			if(!tmp_current){

				tmp_prev->next = new_pokemon;
				return(0);
			}
			else{

				new_pokemon->next = tmp_current;
				tmp_prev->next = new_pokemon;
				return(0);
			}
		}
	}

	print_list(linked_list);
	return(1);	
}	


/*----------------------------------------------------------------------*/

int get_lenght(pokemon_t * linked_list)
{

	int count;

	while(linked_list != NULL){

		linked_list = linked_list->next;
		count ++ ; 
	} 

	return count - 1;
}

/*----------------------------------------------------------------------*/

int get_index(pokemon_t *linked_list, int lenght, char * pokemon_search)
{
	int index = 0; 

	for(int i = 0; i < lenght && linked_list != NULL; i++){

		char * pokemon_pokedex = linked_list->name;

		if(strcmp(pokemon_pokedex,pokemon_search) == 0 ){

				index = i;
						
		}
		
		
		linked_list = linked_list->next;
	}


	return index;
}

/*----------------------------------------------------------------------*/

void delete_pokemon_node(pokemon_t *linked_list, int index )
{

	pokemon_t *head = NULL;
	pokemon_t *tmp = linked_list;

	if(index == 0){

		head=head->next;
		tmp->next= NULL;
		free(tmp);
	}

	else{
		for(int i = 0; index-1; i++){

			tmp=tmp->next;
		}

		pokemon_t *del = tmp->next;
		tmp->next = tmp->next->next;
		del->next = NULL;
		free(del);
	}

	pokedex_menu(linked_list);

}

/*----------------------------------------------------------------------*/

void update_element(pokemon_t *linked_list, int index , int old_value, int new_value)
{
	

	pokemon_t *head = linked_list ;
	pokemon_t *current = NULL;

	int position = 0; 

	if(head == NULL){

		return;
	}

	current = head;

	for(int i = 0; index; i++){	
		if(current->nb_pokemon == old_value)
		{
			current->nb_pokemon = new_value;
			return;
		}

		current = current->next;
		position ++ ;
	} 

	pokedex_menu(linked_list);


}

/*----------------------------------------------------------------------*/

int exist_pokemon(pokemon_t *linked_list, char *name)
{

	while(linked_list != NULL){

		char* pokemon_pokedex = linked_list->name;

		printf("#----%s-----#\n",pokemon_pokedex);
			
		if(strcmp(name, pokemon_pokedex) == 0){

			return(1);		
		}
		
		linked_list = linked_list->next;		
	}

	return(0);
}










