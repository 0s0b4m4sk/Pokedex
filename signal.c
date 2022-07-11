#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "linked_list.h"
#include "starter.h"

extern pokemon_t *final_linked_list;

/*----------------------------------------------------------------------*/


void quit_signal(int sig){

	int i = 0; 

	signal(sig, SIG_IGN);
	signal(SIGINT, quit_signal);

	printf("Voulez vous vraiment quitter le programe \n");
	printf("Oui : 0\n");
	printf("Non : 1\n");

	scanf("%d",&i);

	if( i == 0){
		quit(final_linked_list);
	}

	else{

		return;
	}

	raise(SIGINT);

}

/*----------------------------------------------------------------------*/

void save_auto(int sig){

	signal(sig, SIG_IGN);
	signal(SIGUSR1, save_auto);

	save(final_linked_list);

	raise(SIGUSR1);
}

/*----------------------------------------------------------------------*/