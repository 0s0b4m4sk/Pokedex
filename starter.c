#include <stdlib.h>
#include <stdio.h>
#include "list_chain.h"


pokemon_t *salameche(void){

	pokemon_t* salameche_entry = malloc(sizeof(pokemon_t));
	salameche_entry->name = "Salameche";
	salameche_entry->type = "feu";
	salameche_entry->nb_pokemon= 1;
	salameche_entry->next = NULL;

	printf("Vous avez choisi %s\n", salameche_entry->name);  

	return salameche_entry;

}


pokemon_t *carapuce(void){

	pokemon_t* carapuce_entry = malloc(sizeof(pokemon_t));
	carapuce_entry->name = "Carapuce";
	carapuce_entry->type = "eau";
	carapuce_entry->nb_pokemon= 1;
	carapuce_entry->next = NULL;

	printf("Vous avez choisi %s\n", carapuce_entry->name); 

	return carapuce_entry;

}


pokemon_t *bulbizarre(void){

	pokemon_t* bulbizarre_entry = malloc(sizeof(pokemon_t));
	bulbizarre_entry->name = "Bulbizarre";
	bulbizarre_entry->type = "plante";
	bulbizarre_entry->nb_pokemon= 1;
	bulbizarre_entry->next = NULL;

	printf("Vous avez choisi %s\n", bulbizarre_entry->name); 

	return bulbizarre_entry ;
}


/*
void *print_list(pokemon_t *linked_list){

	while(linked_list != NULL){
		printf("%s",linked_list->name);
		printf("%s",linked_list->type);
		printf("%d",linked_list->nb_pokemon);
		linked_list = linked_list->next;
	}
}
*/
void start_menu(void){

	int i = 0;

	printf("Bienvenue jeune dresseur !\nAvant de commencer l'aventure tu dois choisir ton premier Pokemon ! \n");
	printf("Tu dois choisir parmis ces 3 pokemon\n");
	printf("Salameche : 0\n");
	printf("Carapuce : 1\n");
	printf("Bulbizarre : 2\n");
	printf("Quel est ton choix : ");

	scanf("%d", &i);

	pokemon_t *(*array_fptr[3])(void);
	array_fptr[0] = &salameche;
	array_fptr[1] = &carapuce;
	array_fptr[2] = &bulbizarre;

	pokemon_t *linked_list = array_fptr[i]();


while(linked_list != NULL){
		printf("%s\n",linked_list->name);
		printf("%s\n",linked_list->type);
		printf("%d\n",linked_list->nb_pokemon);
		linked_list = linked_list->next;
	}

	
}


