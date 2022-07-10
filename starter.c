#define  _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <stddef.h>
#include <malloc.h>
#include "linked_list.h"
#include "starter.h"


pokemon_t *open_file(void){

	FILE *CSV = fopen("./pokedex.csv", "r");

	pokemon_t *pokedex  = NULL;
	pokemon_t *tmp_pokemon = NULL;
	char *ligne = NULL;
	size_t cpt = 0;

	//Supprimme le header du CSV
	getline(&ligne, &cpt, CSV);
	free(ligne);
	ligne = NULL;
	cpt = 0;

	while(getline(&ligne, &cpt, CSV)!= -1)
	{
		//parse le CSV en liste chainée
		char *tmp;
		pokemon_t *new_node = malloc(sizeof(pokemon_t));
		//enlève des sauts de lignes en trop
		ligne[strlen(ligne) - 1] = 0;

		new_node->prev = tmp_pokemon;

		tmp = strtok(ligne, ";");
		new_node->name = malloc(strlen(tmp)+1);
		strcpy(new_node->name,tmp);
		
		tmp = strtok(NULL, ";");
		new_node->type = malloc(strlen(tmp)+1);
		strcpy(new_node->type,tmp);

		new_node->pokemon_niveau = atoi(strtok(NULL, ";"));
		new_node->nb_pokemon = atoi(strtok(NULL, ";"));
		
		tmp = strtok(NULL, ";");
		new_node->discover = malloc(strlen(tmp)+1);
		strcpy(new_node->discover,tmp);
		
		tmp = strtok(NULL, ";");
		new_node->capture = malloc(strlen(tmp)+1);
		strcpy(new_node->capture,tmp);
		
		new_node->next = NULL;
		
		if(tmp_pokemon!=NULL)
		{
			tmp_pokemon->next = new_node;
		}
		tmp_pokemon = new_node;

		if(pokedex == NULL)
		{
			pokedex = tmp_pokemon;
		}

		free(ligne);
		ligne = NULL;
		cpt = 0;
	}

	fclose(CSV);
	return pokedex;
}


void save(pokemon_t *linked_list)
{
	pokemon_t *tmp = linked_list;

	FILE* file = fopen("pokedex.csv", "w");
	
	if(file == NULL)
	{
		fprintf(stderr, "Erreur dans l'ouverture du fichier de sauvegarde\n");
	}

	//rajout du header du CSV
	fprintf(file,"name;type;pokemon_niveau;nb_pokemon;discover;capture\n");

	while(tmp != NULL)
	{
		fprintf(file, "%s;%s;%d;%d;%s;%s\n", tmp->name, tmp->type,tmp->pokemon_niveau, tmp->nb_pokemon, tmp->discover, tmp->capture);
		tmp = tmp->next;
	}

	fclose(file);
}




/*----------------------------------------------------------------------*/

char* get_date(void)
{

	time_t mytime = time(NULL);
    char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';

    return time_str;

}


/*----------------------------------------------------------------------*/

pokemon_t *salameche(void){

	char* current_time = get_date();

	pokemon_t* salameche_entry = malloc(sizeof(pokemon_t));
	salameche_entry->name = "Salameche";
	salameche_entry->type = "Feu";
	salameche_entry->pokemon_niveau = 5;
	salameche_entry->nb_pokemon = 1;
	salameche_entry->discover = current_time ;
	salameche_entry->capture = current_time ;
	salameche_entry->next = NULL;

	printf("\n");
	printf("Vous avez choisi %s ! \n", salameche_entry->name);  

	return salameche_entry;

}

/*----------------------------------------------------------------------*/

pokemon_t *carapuce(void){

	char* current_time = get_date();

	pokemon_t* carapuce_entry = malloc(sizeof(pokemon_t));
	carapuce_entry->name = "Carapuce";
	carapuce_entry->type = "Eau";
	carapuce_entry->pokemon_niveau = 5;
	carapuce_entry->nb_pokemon = 1;
	carapuce_entry->discover = current_time;
	carapuce_entry->capture = current_time;
	carapuce_entry->next = NULL;

	printf("\n");
	printf("Vous avez choisi %s ! \n", carapuce_entry->name); 

	return carapuce_entry;

}

/*----------------------------------------------------------------------*/

pokemon_t *bulbizarre(void){

	char* current_time = get_date();

	pokemon_t* bulbizarre_entry = malloc(sizeof(pokemon_t));
	bulbizarre_entry->name = "Bulbizarre";
	bulbizarre_entry->type = "Plante";
	bulbizarre_entry->pokemon_niveau = 5;
	bulbizarre_entry->nb_pokemon = 1;
	bulbizarre_entry->discover = current_time;
	bulbizarre_entry->capture = current_time;
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
	printf("Bulbizarre : 0\n");
	printf("Carapuce : 1\n");
	printf("Salameche : 2\n");
	printf("\n");
	printf("Quel est ton choix : ");

	scanf("%d", &i);

	pokemon_t *(*array_fptr[3])(void);
	array_fptr[0] = &bulbizarre;
	array_fptr[1] = &carapuce;
	array_fptr[2] = &salameche;

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

	void (*array_fptr[3])(pokemon_t* );
	array_fptr[0] = &print_list;
	array_fptr[1] = &print_specific_pokemon;
	array_fptr[2] = &pokedex_menu;	

	array_fptr[i](linked_list);	
	
}


/*----------------------------------------------------------------------*/


void adding_pokemon(pokemon_t* linked_list){
 
 	int i = 0;
 	int pokemon_niveau = 0 ; 
 	int nb_pokemon = 0 ;
 	char pokemon_name [15];
	char pokemon_type [15];
	char* current_time = get_date();
	char capture [7] = "none";

	int nb_index = get_lenght(linked_list);

	printf("\n");
	printf("#---Vous avez trouvé un nouveau pokemon ajouté le à votre pokedex !---#\n");
	printf("\n");
	printf("Souhaitez vous l'attrapper ?\n");
	printf("Oui : 0\n");
	printf("Non : 1\n");

	scanf("%d",&i);

	printf("Saisissez son nom : \n");
	scanf("%s", pokemon_name);

	printf("Saisissez son type : \n");
	scanf("%s", pokemon_type);

	printf("Niveau du pokemon : \n");
	scanf("%d", &pokemon_niveau);

	int exist = exist_pokemon(linked_list,pokemon_name);


	if(i == 0){

		if(exist == 1 ){

			printf("le pokemon %s\n exist",pokemon_name);

			int index_pokemon = get_index(linked_list,nb_index, pokemon_name);

			while(linked_list != NULL){

				char* pokemon_pokedex = linked_list->name;
				
				if(strcmp(pokemon_name, pokemon_pokedex) == 0){

					nb_pokemon = linked_list->nb_pokemon + 1;
					update_element(linked_list, index_pokemon , linked_list->nb_pokemon, nb_pokemon);	
				}
				
			linked_list = linked_list->next;

			}
		}	
	
		else{	

			nb_pokemon = 1;
			add_pokemon(linked_list,pokemon_name,pokemon_type,pokemon_niveau,nb_pokemon,current_time,current_time);
		}	
	}
	else if( i == 1){

		nb_pokemon = 0 ;
		add_pokemon(linked_list,pokemon_name,pokemon_type,pokemon_niveau,nb_pokemon,current_time,capture);
	}

	else{

		printf("Mauvaise saisie \n");
		adding_pokemon(linked_list);
	}

	


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
		printf("Supprimer un pokemon : 2\n");
		printf("sauvegarder les pokemons : 3\n");


		scanf("%d", &i);

		if((i == 0) || (i==1) || (i==2) || (i==3)){

			void (*array_fptr[4])(pokemon_t* linked_list);
			array_fptr[0] = &adding_pokemon; 
			array_fptr[1] = &print_menu;
			array_fptr[2] = &delete_pokemon;
			array_fptr[3] = &save;

			array_fptr[i](linked_list);
		}
		else {

			break;
		}	
	}	

}


/*----------------------------------------------------------------------*/


void delete_pokemon(pokemon_t *linked_list)
{
	char pokemon_search [15];
	int nb_suppression; 
	pokemon_t *list = linked_list;

	int nb_index = get_lenght(linked_list);
	printf("Taille de la liste %d\n", nb_index);
	
	printf("Saisissez le nom du pokemon a suprimer : \n");
	scanf("%s", pokemon_search);

	int index_pokemon = get_index(linked_list,nb_index, pokemon_search);
	printf("index pokemon: %d\n", index_pokemon);


	while(linked_list != NULL){

		char* pokemon_pokedex = linked_list->name;

			
		if(strcmp(pokemon_search, pokemon_pokedex) == 0){

			int statue = linked_list->nb_pokemon;

			if(statue == 0 ){

				printf("Le pokemon %s est oublié ! ", pokemon_search);
				delete_pokemon_node(list,index_pokemon);	
				
			}	

			else if (statue == 1 ){

				printf("Le pokemon %s que vous posséder en 1 exemplaire sera oublié !",pokemon_search);
				delete_pokemon_node(list,index_pokemon);
				
			}

			else{

				printf("Vous possédez ce pokemon en plusieurs exemplaire : %d",statue);
				printf("Saisissez le nombre de pokemon a supprimer\n");
				scanf("%d",&nb_suppression);

				if(nb_suppression >= statue){

					printf("Le pokemon %s sera oublié",pokemon_search);
				}
				else{

					printf("update du nombre de pokemon ");
				}
			}	
		}
			
		linked_list = linked_list->next;
	}
}

