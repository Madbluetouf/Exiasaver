#include <stdio.h>
#include <stdlib.h>
#include <time.h>																		/*On déclare les bibliothèques*/
#include <unistd.h>

int main ()
{

	int screen;
	const int  MAX = 3 , MIN = 1 ; 

	srand(time(NULL));
		
	screen = ( rand () % ( MAX - MIN + 1 )) + MIN; 

	switch(screen)
	{
		case 1:
		system("./exs1");
		break ;  
																										/*En fonction du random, le switch lance un des trois écrans*/
		case 2: 
		system("./plout"); 
		break ; 

		case 3:
		system ("clear");
		printf  ("/n Lancement de la Fenétre 3") ; 
		break ; 
	}

	return 0;	
}
