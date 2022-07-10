#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "linked_list.h"
#include "starter.h"

int main(void)
{


	pokemon_t* list = open_file();
	pokedex_menu(list);
	 
	
	return 0;
}