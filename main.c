#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "linked_list.h"
#include "starter.h"

int main(void)
{

	
	pokemon_t* list;

	list = start_menu();
	pokedex_menu(list);
	 
	
	return 0;
}