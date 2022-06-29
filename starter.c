#include <stdlib.h>
#include <stdio.h>
#include "list_chain.h"


pokemon_t *salameche(void){

	pokemon_t* salameche = malloc(sizeof(pokemon_t));
	salameche->name = "salameche";
	salameche->type = "feu";
	salameche->nb_pokemon= 1;
	salameche->next = NULL;

	printf("Vous avez choisi %s\n", salameche->name); 

	return salameche;

}


pokemon_t *carapuce(void){

	pokemon_t* carapuce = malloc(sizeof(pokemon_t));
	carapuce->name = "carapuce";
	carapuce->type = "eau";
	carapuce->nb_pokemon= 1;
	carapuce->next = NULL;

	printf("Vous avez choisi %s\n", carapuce->name); 

	return carapuce;

}


pokemon_t *bulbizarre(void){

	pokemon_t* bulbizarre = malloc(sizeof(pokemon_t));
	bulbizarre->name = "bulbizarre";
	bulbizarre->type = "plante";
	bulbizarre->nb_pokemon= 1;
	bulbizarre->next = NULL;

	printf("Vous avez choisi %s\n", bulbizarre->name); 

	return bulbizarre;
}

pokemon_t *start_menu(void){

	int i = 0;

	printf("Bienvenue jeune dresseur !\nAvant de commencer l'aventure tu dois choisir ton premier Pokemon ! \n");
	printf("Tu dois choisir parmis ces 3 pokemon\n");
	printf("Salameche : 0\n");
	printf("Carapuce : 1\n");
	printf("Bulbizarre : 2\n");
	printf("Quel est ton choix : \n");

	scanf("%d", &i);

	pokemon_t *(*array_fptr[3])(void);
	array_fptr[0] = &salameche;
	array_fptr[1] = &carapuce;
	array_fptr[2] = &bulbizarre;

	pokemon_t *linked_list = array_fptr[i]();


	return linked_list;

}


