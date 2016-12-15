#include<stdio.h>
#include<sys/ioctl.h> 
#include<stdlib.h> 
#include<string.h> 
#include<time.h> 
#include<unistd.h>
void gotoxy (int x , int y ) 
{
	printf("%c[%d;%df",0x1B,x , y );  // prototype de fonction qui permet de  déplacer le curseur sur l'ecran afin d'écrire en récupérant les valeurs en x et en y 
}


int main (void) 
{ 
	int heures, minutes, secondes; 
	FILE* hist = NULL;
	int  h  ;
	system("clear");     // commande pour nettoyer l'ecran avant l'affichage 
	while (1)     // boucle infinie pour que l'horloge ce répète 
{
	
	
	
	FILE* heure = NULL ; 
	FILE* heuruni = NULL; 
	FILE* minute = NULL;
	FILE* minutesuni = NULL;           //  les pointeurs qui pointeront vers les différents fichiers  à afficher 
	FILE* seconde = NULL;
	FILE* secondeuni = NULL;
	FILE* point1 = NULL;
	FILE* point2 = NULL;

	int ca , cb , cc , cd , ce , cf , cg , ch;    // variable associée au fichier à ouvrir
	int pout = 255 ;                              // numéro en caractere asci pour afficher un espace
	int pet = 178 ;                               // numéro en caractère asci pour afficher un carré blanc
	int  t ; 
	int i, a ;   				      //  initialisation des variables associées au gotoxy

	i= 10 ;                                       // attribution des premières valeurs pour afficher la deuxieme image 
	a = 7 ; 
	h=0 ;                                         // initialisation de h pour la boucle d'affichage en fin de programme 


	time_t date_heures_actuelles = time(NULL); 
	struct tm *temps_humain = localtime (&date_heures_actuelles);     // structure de la bibliothéque  du <time.h> qui permet de récupérer l'heure
                        
	int heures, minutes, secondes; 				          // en associant une variable aux heures , une aux minutes et la dernière aux secondes  
	heures = temps_humain->tm_hour; 
	minutes = temps_humain->tm_min;
	secondes = temps_humain->tm_sec; 


	int uniheur ;                                                     // initialisation de la varible qui va servir à afficher l'image de l'unité des heures qui sera le  modulo 10 de l'heure
	uniheur = heures%10;                                              //    dans la structure qui récupére  l'heure
	int uniminutes ;
	uniminutes = minutes%10;					 // de même initialisation de la variable associée aux unités des minutes  modulo 10 de minutes
	int unisecondes;
	unisecondes = secondes%10;                                       // de méme initialisation de la variable associée au unités des secondes modulo 10 de minutes

	
		if( heures < 10 )
		{ 
			heure = fopen("Exiasaver2_PBM/0.pbm","r"); 
		}

		else if (heures < 20) 
		{        
			heure =fopen("Exiasaver2_PBM/1.pbm","r");   //  condition qui permet de determiner, pour le chiffre des dizaines des heures, le fichier contenant l'image dois etre ouvert
		}   

		else 
		{ 
			heure= fopen("Exiasaver2_PBM/2.pbm" ,"r"); 
		} 

		fseek (heure, 4,SEEK_SET); // cette ligne permet de se placer dans le fichier ouvert, de placer le curseur apres les 4 premiers caractéres de la ligne pour pas lire le mots #P1
	 

		if (uniheur == 0) 
		{ 
			heuruni = fopen("Exiasaver2_PBM/0.pbm" , "r") ; 
		} 

		else if (uniheur == 1 ) 
		{ 
			heuruni = fopen("Exiasaver2_PBM/1.pbm" , "r") ; 
		}
	 
		else if (uniheur == 2) 
		{ 	
			heuruni = fopen("Exiasaver2_PBM/2.pbm" , "r") ; 
		} 

		else if (uniheur == 3) 
		{ 
			heuruni = fopen("Exiasaver2_PBM/3.pbm" , "r") ; // condition qui permet de determiner, pour le chiffre des unités de l'heure, le fichier contenant l'image doit etre ouvert 
		} 
		

		else if (uniheur == 4) 
		{ 
			heuruni = fopen("Exiasaver2_PBM/4.pbm" , "r") ;

		} 
		else if (uniheur == 5) 
		{ 
			heuruni = fopen("Exiasaver2_PBM/5.pbm" , "r") ; 
		}
		else if (uniheur == 6) 
		{ 
			heuruni = fopen("Exiasaver2_PBM/6.pbm" , "r") ; 
		} 
		else if (uniheur == 7) 
		{
	 		heuruni = fopen("Exiasaver2_PBM/7.pbm" , "r") ; 
		} 
		else if (uniheur == 8) 
		{ 
			heuruni = fopen("Exiasaver2_PBM/8.pbm" , "r") ; 
		} 
		else if (uniheur == 9) 
		{ 
			heuruni = fopen("Exiasaver2_PBM/9.pbm" , "r") ; 
		} 

		fseek (heuruni, 4,SEEK_SET);        // cette ligne permet de se placer dans le fichier ouvert de placer le curseur apres les 4 premiers caractére de la ligne pour pas lire le mots #P1
		point1 = fopen("Exiasaver2_PBM/2p.pbm" , "r");  // ouverture du fichier contenant les 2 points 
		fseek (point1, 4,SEEK_SET);                    //  cette ligne permet de se placer dans le fichier ouvert de placer le curseur apres les 4 premiers caractére de la ligne dans le but de ne 								      // ne pas lire le mots P1
		a=7;
		i=0;
		gotoxy (a , i ) ;      // valeur donnée au gotoxy pour commencer à écrire à cette position

		do 
		{
			ca = fgetc(heure);                           // do while  qui tant qu'il y a des caractère, vas les lire un par un 
		
			if ( ca  == 48) 
			{ 
				printf("%c", (char)pout);           // condition qui fait que si un caractére = 48 c'est à dire  correspond à la valeur 0 va afficher  le caractère correspondant c'est à dire espace 
			}
	 
			if (ca == 49) 
			{ 
				printf("%c" , (char)pet );// condition qui fait que si un caractére = 49 c'est a dire  corespond a la valeur 1 va afficher le caractère correspondant c'est a dire carré blanc
			} 
	
			if (ca == 10)
			{
				printf("\n");    // condition qui permet de détecter les passages à la ligne 
			}

			}while ( ca  != EOF);

	 
		gotoxy ( a , i );

		a=7;
		i=10;

		gotoxy (a , i ) ;  // valeur donnée à la fonction gotoxy pour placer le curseur à une position afin d'écrire

		do                                  // do while qui tant qu'il y a des caractères vas les lire un par un
		{
			cb = fgetc(heuruni);        // valeur associée au caractére du fichier ouvert , fgetc du fichier ouvert afin de lire les caractère 
	
			if ( cb == 48) 
			{ 
				printf("%c", (char)pout);   // condition qui fait que si un caractère = 48 c'est à dire  correspond à la valeur 0 va afficher  le caractère correspondant c'est à dire espace 
			} 

			if (cb == 49) 
			{ 
				printf("%c" , (char)pet );   // condition qui fait que si un caractère = 49 c'est à dire  correspond à la valeur 1 va afficher  le caractère correspondant c'est a dire carré blanc   
			} 

		 	if (cb== 10)                        // condition qui permet de détecter les passage a la ligne

			{
				printf("\n");
				a++ ; 
				gotoxy (a , i ) ;    // incrementation du gotoxy afin que chaque ligne de l'image s'écrive les unes en dessous des autres 

			}

		} while  (cb != EOF); 

		a=7;
		i=20;                // réinitialisation du gotoxy  afin qu'il débute l'affichage de l'image suivant à la bonne place 
		gotoxy (a , i ) ;
	 
		do
		{
			cc = fgetc(point1);
	
			if ( cc == 48) 
			{ 
				printf("%c", (char)pout);
			} 

			if (cc == 49) 
			{ 
				printf("%c" , (char)pet ); 
		        }

			if (cc== 10)
			{
				printf("\n");
				a++ ; 
				gotoxy (a , i ) ; 
			}
			
			

		} while  (cc != EOF);

		fclose(heure);
		fclose(heuruni);   // fermeture des fichiers de l'affichage de l'heure 

	 //CODE DES MINUTE //

		if( minutes < 10 )
		{ 
			minute = fopen("Exiasaver2_PBM/0.pbm","r"); 
		}

		else if (minutes < 20) 
		{ 
			minute =fopen("Exiasaver2_PBM/1.pbm","r");
		}
	 
		else if (minutes < 30) 
		{ 
			minute =fopen("Exiasaver2_PBM/2.pbm","r");    //  condition qui permet de déterminer pour le chiffre des dizaines, des minutes, quel fichier contenant l'image doit etre ouvert
		}

		else if (minutes < 40) 
		{ 
			minute =fopen("Exiasaver2_PBM/3.pbm","r");
		}

		else if (minutes < 50) 
		{ 
			minute =fopen("Exiasaver2_PBM/4.pbm","r");
		}

		else  
		{ 
			minute = fopen("Exiasaver2_PBM/5.pbm" ,"r"); 
		} 

		fseek (minute, 4,SEEK_SET);
	 

		if (uniminutes == 0) 
		{ 
			minutesuni = fopen("Exiasaver2_PBM/0.pbm" , "r") ; 
		}

		else if (uniminutes == 1 ) 
		{ 
			minutesuni = fopen("Exiasaver2_PBM/1.pbm" , "r") ; 
		} 

		else if (uniminutes == 2) 
		{ 
			minutesuni = fopen("Exiasaver2_PBM/2.pbm" , "r") ; 
		} 

		else if (uniminutes == 3) 
		{ 
			minutesuni = fopen("Exiasaver2_PBM/3.pbm" , "r") ; 
		} 

		else if (uniminutes == 4) 
		{ 
			minutesuni = fopen("Exiasaver2_PBM/4.pbm" , "r") ;
		} 

		else if (uniminutes == 5) 
		{ 
			minutesuni = fopen("Exiasaver2_PBM/5.pbm" , "r") ;  // condition qui permet de déterminer pour le chiffre des unités, des minutes, quel fichier contenant l'image doit être ouvert
		}

		else if (uniminutes == 6) 
		{ 
			minutesuni = fopen("Exiasaver2_PBM/6.pbm" , "r") ; 
		} 

		else if (uniminutes == 7) 
		{
		 	minutesuni = fopen("Exiasaver2_PBM/7.pbm" , "r") ; 
		} 

		else if (uniminutes == 8) 
		{ 
			minutesuni = fopen("Exiasaver2_PBM/8.pbm" , "r") ; 
		} 

		else if (uniminutes == 9) 
		{ 
			minutesuni = fopen("Exiasaver2_PBM/9.pbm" , "r") ; 
		} 

		fseek (minutesuni, 4,SEEK_SET);
		point2 = fopen("Exiasaver2_PBM/2p.pbm" , "r");
		fseek (point2, 4,SEEK_SET);

		a=7;
		i= 30 ;

		gotoxy ( a , i );
	
		do 
		{
			cd = fgetc(minute); 
			
			if ( cd  == 48) 
			{ 
				printf("%c", (char)pout); 
			} 
	
			if (cd == 49) 
			{ 
				printf("%c" , (char)pet ); 
			} 
	
			if (cd == 10)
			{
				printf("\n");
				a++;

				gotoxy ( a , i );
	 		}

		} while ( cd  != EOF);


		a =7 ;
	 	i= 40 ;

		gotoxy ( a , i );
	
		do
		{

			ce = fgetc(minutesuni);
	
		 	if ( ce == 48) 
			{ 
				printf("%c", (char)pout);
			} 
	
			if (ce == 49) 
			{ 
				printf("%c" , (char)pet ); 
		        
			} 
	
			if (ce== 10)
			{
				printf("\n");
				a++ ; 
				gotoxy (a , i ) ; 
		        }

		} while  (ce != EOF);

		a=7;
		i=50;

		gotoxy (a , i ) ;

		do
		{ 
			cf = fgetc(point2);
	
			if ( cf == 48) 
			{ 
				printf("%c", (char)pout);
			} 
	
			if (cf == 49) 
			{ 
				printf("%c" , (char)pet ); 
		      	}
	 
			if (cf== 10)
			{
				printf("\n");
				a++ ; 
				gotoxy (a , i ) ; 
		        }

			

		} while  (cf != EOF);

		fclose(minute);
		fclose(minutesuni);	 

	//CODE DES SECONDES

		if( secondes < 10 )
		{ 
			seconde = fopen("Exiasaver2_PBM/0.pbm","r"); 
		}
	
		else if (secondes < 20) 
		{ 
			seconde =fopen("Exiasaver2_PBM/1.pbm","r");
		} 

		else if (secondes < 30) 
		{ 
			seconde =fopen("Exiasaver2_PBM/2.pbm","r");
		}

		else if (secondes < 40) 
		{ 
			seconde =fopen("Exiasaver2_PBM/3.pbm","r");
		}

		else if (secondes < 50) 
		{ 
			seconde =fopen("Exiasaver2_PBM/4.pbm","r");
		}

		else  
		{ 
			seconde = fopen("Exiasaver2_PBM/5.pbm" ,"r"); 
		} 

		fseek (seconde, 4,SEEK_SET);
	 
		if (unisecondes == 0) 
		{ 
			secondeuni = fopen("Exiasaver2_PBM/0.pbm" , "r") ; 
		} 

		else if (unisecondes == 1 ) 
		{ 
			secondeuni = fopen("Exiasaver2_PBM/1.pbm" , "r") ; 
		} 

		else if (unisecondes == 2) 
		{ 
			secondeuni = fopen("Exiasaver2_PBM/2.pbm" , "r") ; 
		} 

		else if (unisecondes == 3) 
		{ 
			secondeuni = fopen("Exiasaver2_PBM/3.pbm" , "r") ; 
		} 

		else if (unisecondes == 4) 
		{ 
			secondeuni = fopen("Exiasaver2_PBM/4.pbm" , "r") ;
		} 

		else if (unisecondes == 5) 
		{ 
			secondeuni = fopen("Exiasaver2_PBM/5.pbm" , "r") ; 
		}

		else if (unisecondes == 6) 
		{ 
			secondeuni = fopen("Exiasaver2_PBM/6.pbm" , "r") ; 
		} 

		else if (unisecondes == 7) 
		{
		 	secondeuni = fopen("Exiasaver2_PBM/7.pbm" , "r") ; 
		} 
	
		else if (unisecondes == 8) 
		{ 
			secondeuni = fopen("Exiasaver2_PBM/8.pbm" , "r") ; 
		} 

		else if (unisecondes == 9) 
		{ 
			secondeuni = fopen("Exiasaver2_PBM/9.pbm" , "r") ; 
		} 

		fseek (secondeuni, 4,SEEK_SET);

		a=7;
		i= 60 ;

		gotoxy ( a , i );

		do 
		{
			cg = fgetc(seconde); 
			
			if ( cg  == 48) 
			{ 
				printf("%c", (char)pout); 
			} 
	
			if (cg == 49) 
			{ 
				printf("%c" , (char)pet ); 
			} 
	
	   		if (cg == 10)
			{
				printf("\n");
				a++;

				gotoxy ( a , i );
	 		}

		} while ( cg  != EOF);


		a =7 ;
		i= 70 ;

		gotoxy ( a , i );
	
		do
		{
			ch = fgetc(secondeuni);
	
	 		if ( ch == 48) 
			{ 
				printf("%c", (char)pout);
			} 
	
			if (ch == 49) 
			{ 
				printf("%c" , (char)pet );                 
			} 
		  
			if (ch == 10)
			{
				printf("\n");
				a++ ; 
				gotoxy (a , i ) ;                   
		        }
		}
		

		while  (ch != EOF); 
	
		fclose(seconde);
		fclose(secondeuni);


gotoxy( 20 ,10 );
printf(" l'image vas s'actualiser dans : ");
for (h; h<7 ; h++)        //  boucle  qui   fait une pause toute les s  et qui afficher un point a l'ecran à chaque seconde
{
sleep(1);
printf (".");

fflush(stdout);   // fonction pour forcer l'actualisation 

}
system("clear");  // nettoyage de la console 
 

hist = fopen("past.txt", "a") ;
	fprintf(hist, "2		     		   					%dh %dm %ds \n" , heures, minutes , secondes  );
	fclose(hist);

		



}
	
	return 0; 

} 


