#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h> /*Bibliothèque permettant l'utilisation de chaîne de caractère */
#include <time.h>	/*Bibliothèque permettant l'utilisation d'un random */
#include <unistd.h> 	/*Bibliothèque permettant l'utilisation de primitives propre à Linux */

int main() 
{ 
	struct winsize w ;								/*structure permettant de récupérer la taille de la fenêtre*/

	ioctl (0, TIOCGWINSZ, &w); 
	system("clear"); 

	int image ; 
	const int max = 5 , min = 1 ;

	srand(time(NULL)); 								/*On fait un random pour */ 

	image = ( rand () % ( max - min + 1 )) + min; 

	FILE* fichier = NULL;								/*On va initialiser des pointeurs de fichier*/
	FILE* fichier2 = NULL;

	int ca = 0; 
	int pout = 255; 
	int pet = 178; 
	int colonne, ligne; 								/*On déclare les variables*/
	int p , t  ;
	int x , y ; 

	time_t date_heures_actuelles = time(NULL); 
	struct tm *temps_humain = localtime (&date_heures_actuelles); 
	int heures, minutes, secondes; 														/*On récupère les  valeurs du temps réel*/
	heures = temps_humain->tm_hour; 
	minutes = temps_humain->tm_min;
	secondes = temps_humain->tm_sec; 
	 
	if (image == 1 ) 
	{
		fichier = fopen("Exiasaver1_PBM/pop.pbm" , "r");
		fichier2 = fopen("past.txt", "a") ;
		if (fichier !=  NULL)
		{
			fprintf(fichier2, "1		Toad		   pop.pbm		   %dh %dm %ds \n" , heures, minutes , secondes  );
		}
	} 

	if (image == 2)
	{ 
		fichier = fopen("Exiasaver1_PBM/pip.pbm" , "r") ; 
		fichier2 = fopen("past.txt", "a") ;
		if (fichier !=  NULL)
		{
			fprintf(fichier2, "1		Bill-Ball		   pip.pbm		   %dh %dm %ds \n" , heures, minutes , secondes  );
		}
	} 

	if (image == 3 ) 
	{
		fichier = fopen("Exiasaver1_PBM/pap.pbm" , "r");
		fichier2 = fopen("past.txt", "a") ;
		if (fichier !=  NULL)
		{
			fprintf(fichier2, "1		Panda		   pap.pbm		   %dh %dm %ds \n" , heures, minutes , secondes  );
		}
	} 																																	/*Ce grand morceau sert en fonction du résultat du random*/
																																		/*Et ensuite il écrit sur l'historique*/
	if (image == 4 ) 
	{
		fichier = fopen("Exiasaver1_PBM/pup.pbm" , "r");
		fichier2 = fopen("past.txt", "a") ;
		if (fichier !=  NULL)
		{
			fprintf(fichier2, "1		Harmonie	   pup.pbm		   %dh %dm %ds \n" , heures, minutes , secondes  );
		}
	} 

	if (image == 5 ) 
	{
		fichier = fopen("Exiasaver1_PBM/pep.pbm" , "r");
		fichier2 = fopen("past.txt", "a") ;
		if (fichier !=  NULL)
		{
			fprintf(fichier2, "1		Stark		   pep.pbm		   %dh %dm %ds \n" , heures, minutes , secondes  );
		}
	} 

	fseek(fichier , 4 , SEEK_SET) ; 									/*fseek = modifiler l'emplacement du curseur dans le fichier ouvert*/
	fscanf(fichier , "%d %d" , &x , &y) ;							/*Récupère les dimensions du fichiers images*/
	

	colonne = (w.ws_col - x) ; 									
	colonne = colonne/2; 
																/*Place l'image au centre de la fenètre*/
	ligne = ( w.ws_row - y); 
	ligne = ligne /2; 

	for ( t =0 ; t < ligne ; t++) 
	{ 
		printf("\n"); 
	} 

	for ( p=0 ; p < colonne ; p++) 
	{ 
		putchar(' ') ; 
	}

	if ( fichier != NULL) 
	{ 
		do 																			/*Ce do...while permet */
		{ 																			/*traduire les fichiers pbm qui sont en binaire*/
			ca = fgetc(fichier); 	/*Fgets = Lire une chaine de cararctère*/				/*en caractère ASCII selon la table des valeurs*/
			if ( ca == 48) 	
			{ 
				printf("%c", (char)pet); 
			} 

			if (ca == 49) 
			{ 
				printf("%c" , (char)pout ); 
			} 

			if (ca== 10) 				
			{ 
				printf("\n");
 
				for (p = 0;p < colonne ; p++) 
				{ 
					putchar(' ') ; 
				} 
			} 
		} while (ca != EOF); 				/*EOF = End Of the File*/
	}
	 for (t = 0 ; t < ligne ; t++) 
	{ 
		printf("\n"); 
	}

	fclose(fichier); 				/*Fermer le fichier utiliser*/
	fclose(fichier2);
	system("stty cbreak -echo") ;	/*Ces 4 lignes de codes */
	getchar() ;					/*permettent d'arrêter le programme*/
	system("stty cooked echo") ;	 /* en appuyant sur n'importe quelle touche */
	system("clear") ;
	
	return 0;
}
