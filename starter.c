#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "starter.h"

/*----------------------------------------------------------------------*/

pokemon_t *salameche(void){

	pokemon_t* salameche_entry = malloc(sizeof(pokemon_t));
	salameche_entry->name = "Salameche";
	salameche_entry->type = "Feu";
	salameche_entry->pokemon_niveau = 5;
	salameche_entry->nb_pokemon = 1;
	salameche_entry->next = NULL;

	printf("\n");
	printf("Vous avez choisi %s ! \n", salameche_entry->name);  

	return salameche_entry;

}

/*----------------------------------------------------------------------*/

pokemon_t *carapuce(void){

	pokemon_t* carapuce_entry = malloc(sizeof(pokemon_t));
	carapuce_entry->name = "Carapuce";
	carapuce_entry->type = "Eau";
	carapuce_entry->pokemon_niveau = 5;
	carapuce_entry->nb_pokemon = 1;
	carapuce_entry->next = NULL;

	printf("\n");
	printf("Vous avez choisi %s ! \n", carapuce_entry->name); 

	return carapuce_entry;

}

/*----------------------------------------------------------------------*/

pokemon_t *bulbizarre(void){

	pokemon_t* bulbizarre_entry = malloc(sizeof(pokemon_t));
	bulbizarre_entry->name = "Bulbizarre";
	bulbizarre_entry->type = "Plante";
	bulbizarre_entry->pokemon_niveau = 5;
	bulbizarre_entry->nb_pokemon = 1;
	bulbizarre_entry->next = NULL;

	printf("\n");
	printf("Vous avez choisi %s ! \n", bulbizarre_entry->name); 

	return bulbizarre_entry ;
}

/*----------------------------------------------------------------------*/

pokemon_t * start_menu(void){

	int i = 0;

	printf("\n");
	printf("#---Bienvenue jeune dresseur !---#\nAvant de commencer l'aventure tu dois choisir ton premier Pokemon !\n");
	printf("Tu dois choisir parmis ces 3 pokemon\n");
	printf("\n");
	printf("Salameche : 0\n");
	printf("Carapuce : 1\n");
	printf("Bulbizarre : 2\n");
	printf("\n");
	printf("Quel est ton choix : ");

	scanf("%d", &i);

	pokemon_t *(*array_fptr[3])(void);
	array_fptr[0] = &salameche;
	array_fptr[1] = &carapuce;
	array_fptr[2] = &bulbizarre;

	pokemon_t *linked_list = array_fptr[i]();


	return linked_list;
}

/*----------------------------------------------------------------------*/

void print_menu(pokemon_t* linked_list){

	int i = 0; 

	printf("\n");
	printf("/*----------------------------------------------------------------------*/\n");
	printf("\n");
	printf("Afficher tous le Pokedex : 0\n");
	printf("Afficher les informations d'un pokemon : 1\n");
	printf("Retour : 2\n");

	scanf("%d", &i);

	void (*array_fptr[3])(pokemon_t* linked_list);
	array_fptr[0] = &print_list;
	array_fptr[1] = &print_specific_pokemon;
	array_fptr[2] = &pokedex_menu;	

	array_fptr[i](linked_list);	
	
}


/*----------------------------------------------------------------------*/


void adding_pokemon(pokemon_t* linked_list){
 
 	int i = 0;
 	int pokemon_niveau = 0 ; 
 	char pokemon_name [15];
	char pokemon_type [15];


	printf("\n");
	printf("#---Vous avez trouvé un nouveau pokemon ajouté le à votre pokedex !---#\n");
	printf("\n");
	printf("Souhaitez vous l'attrapper ?\n");
	printf("Oui : 0\n");
	printf("Non : 1\n");

	scanf("%d",&i);

	if(i == 0){

		int nb_pokemon = 1;
		printf("Saisissez son nom : \n");
		scanf("%s", pokemon_name);

		printf("Saisissez son type : \n");
		scanf("%s", pokemon_type);

		printf("Niveau du pokemon : \n");
		scanf("%d", &pokemon_niveau);

		add_pokemon(linked_list,pokemon_name,pokemon_type,pokemon_niveau,nb_pokemon);

	}

	else{

		int nb_pokemon = 0; 

		printf("Saisissez son nom : \n");
		scanf("%s", pokemon_name);

		printf("Saisissez son type : \n");
		scanf("%s", pokemon_type);

		printf("Niveau du pokemon : \n");
		scanf("%d", &pokemon_niveau);

		add_pokemon(linked_list,pokemon_name,pokemon_type,pokemon_niveau,nb_pokemon);
	}

	pokedex_menu(linked_list);
		
}

/*----------------------------------------------------------------------*/

void pokedex_menu(pokemon_t* linked_list){


	while(1)
	{
		int i = 0 ;

		printf("\n");
		printf("/*----------------------------------------------------------------------*/\n");
		printf("\n");
		printf("Ajouter un pokemon : 0\n");
		printf("Afficher le pokedex : 1\n");

		scanf("%d", &i);

		if((i == 0) || (i==1)){

			void (*array_fptr[2])(pokemon_t* linked_list);
			array_fptr[0] = &adding_pokemon; 
			array_fptr[1] = &print_menu;

			array_fptr[i](linked_list);
		}
		else {

			break;
		}	
	}	

}


