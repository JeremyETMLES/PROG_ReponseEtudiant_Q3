// M�lissa Perret, SLO1

#include <stdio.h>
#include <string.h>   //pour strcpy, strcat et strlen 
#include <stdlib.h>   //pour itoa 
#include <stdint.h>   //pour les librairies int8_t



//-- d�claration de constantes --// 
#define TITRE	"TEST"


void main()
{
	const char* pt_message = TITRE;
	const char tbMSG[] = { 0x53, 0x4C, 0x4F };   //Affichage SLO 
	char tbMSGComplet[15];
	int annee = 2023;
	int8_t version = 0x33;  //Affichage 3 

	strcpy(tbMSGComplet, pt_message); // on copie pt_message dans tbMSGComplet => "TEST"

	// on utilise strncat pour pouvoir indiquer le nombre de caract�res � ajouter
	// impossible d'utiliser strcat car version ne se termine pas par '\0'
	strncat(tbMSGComplet, &version, 1); // on ajoute version � tbMSGComplet => "TEST3"

	// note: quand on d�finie une string avec les guillemets " " le caract�re de fin de string '\0' est ajout� automatique � la fin
	strcat(tbMSGComplet, " "); // on ajoute un espace � tbMSGComplet => "TEST3 "

	// pour ajouter tbMSG, le plus simple c'est d'utiliser strncat en indiquant la taille de tbMSG directement
	// mais si on on change tbMSG alors il faut penser � mettre la valeur 3 � jour ici aussi
	//strncat(tbMSGComplet, tbMSG, 3);

	// au lieu d'utiliser la valeur en dur, on la calcule grace � sizeof
	// le nombre de case du tableau est �gale � sa taille totale divis�e par la taille d'une case
	strncat(tbMSGComplet, tbMSG, sizeof(tbMSG) / sizeof(char)); // on ajoute tbMSG � tbMSGComplet => "TEST3 SLO"

	// on utilise itoa pour convert le nombre d�cimal annee en string et l'ajouter � tbMSGComplet
	//itoa(annee, &tbMSGComplet[9], 10);
	itoa(annee, &tbMSGComplet[strlen(tbMSGComplet)], 10);

	printf("%s", tbMSGComplet);
}

//strlen  = Permet de calculer la longueur, exprim�e en caract�re 
//strcat  = Permet de rajouter � une chaine de caract�re d�j� existante le contenu d'une seconde. 
//strcpy = permet de copier le contenu d'une chaine de caract�re dans uen autre. 
//itoa =  La fonction convertit le nombre d'entr�e en sa string C correspondante en utilisant la base sp�cifi�e.