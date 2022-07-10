#ifndef __STARTER__
#define __STARTER__

#include <stddef.h>
#include <stdio.h>
#include <time.h>

/* Prototypes */

pokemon_t *open_file(void);
pokemon_t *bulbizarre(void);
pokemon_t *carapuce(void);
pokemon_t *salameche(void);
pokemon_t *start_menu(void);
char* get_date(void);
void pokedex_menu(pokemon_t* linked_list);
void print_menu(pokemon_t* linked_list);
void adding_pokemon(pokemon_t* linked_list);
void delete_pokemon(pokemon_t *linked_list);
void save(pokemon_t *linked_list);


#endif /*  __STARTER__ */