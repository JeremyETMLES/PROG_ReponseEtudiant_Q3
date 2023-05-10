#define _CRT_SECURE_NO_WARNINGS // D�finit une directive de pr�processeur pour supprimer les avertissements de s�curit� li�s � l'utilisation de certaines fonctions dans Visual Studio.
#include <stdio.h>              // Inclut la biblioth�que standard d'entr�e-sortie en C.
#include <stdlib.h>             // Inclut la biblioth�que standard de fonctions g�n�rales en C.
#include <string.h>             // Inclut la biblioth�que standard de manipulation de cha�nes de caract�res en C.
#include <stdint.h>             // Inclut la biblioth�que standard de types entiers en C.

#define TITRE "TEST"            // D�finit une macro qui remplace toutes les occurrences de "TITRE" par "TEST" dans le code.

int main() {
    const char* pt_message = TITRE;                 // D�clare un pointeur constant vers une cha�ne de caract�res "TITRE".
    char tbMSG[] = { 0x53, 0x4c, 0x4F, '\0' };      // Initialise un tableau de caract�res avec les valeurs hexad�cimales 0x53, 0x4c, 0x4F et un caract�re nul (\0).
    char tbMSGComplet[15];                          // D�clare un tableau de caract�res de taille 15 pour stocker le message final.
    int annee = 2022;                               // Initialise une variable enti�re avec la valeur 2022.
    int8_t version = 0x33;                          // Initialise une variable enti�re de 8 bits avec la valeur hexad�cimale 0x33.

    // Convertit l'ann�e en une cha�ne de caract�res.
    char anneeStr[5];
    _itoa(annee, anneeStr, 10);

    // Copie la premi�re partie du message dans tbMSGComplet.
    strcpy(tbMSGComplet, pt_message);

    // Concat�ne le num�ro de version � tbMSGComplet.
    char versionStr[10];
    _itoa(version, versionStr, 10);
    strcat(tbMSGComplet, versionStr);

    // Concat�ne la deuxi�me partie du message � tbMSGComplet.
    strcat(tbMSGComplet, tbMSG);

    // Concat�ne l'ann�e � tbMSGComplet.
    strcat(tbMSGComplet, anneeStr);

    // Affiche le message final.
    printf("%s\n", tbMSGComplet);

    // Appelle strlen explicitement pour obtenir la longueur de tbMSGComplet.
    size_t msgLen = strlen(tbMSGComplet);
    printf("Le message final a %zu caract�res.\n", msgLen);

    return 0;
}

