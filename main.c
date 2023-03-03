#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HORIZ 0
#define VERT 1

/*
Pour l'exercice vous aurez besoin de generer des entiers aléatoire : rand() renvoit un entier aléatoire.
il s'utilise : rand() % NOMBREMAX + 1
Pour un entier aléatoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/






// Ecrire la fonction generer(), elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls

// Ce lien vous sera utile : https://www.geeksforgeeks.org/pass-2d-array-parameter-c/


/*Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée*/


/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
 Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/

/*
Écrire la fonction verifierRegion() qui prend en paramètre deux indices k et l qui correspondent à la région (k,l)
et qui renvoie 1 si la région est correctement remplie, 0 sinon.
*/

//Écrire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon


//Écrire le programme principal, en supposant que la seule condition d’arrêt est la réussite du sudoku (ce test ne devra être fait que si nécessaire)


//on demande a l'utilisateur de saisir les indices i et j et la valeur v a placer a l'emplacement (i,j)

//on verifie si la colonne est remplie correctement
int verifierLigneColonne(int tableauJoueur[9][9], int valeur, int sens) {
    int i;
    int array[9];
    if(sens == 0) {
        for(i = 0; i < 9; i++) {
            array[i] = tableauJoueur[i][valeur];
        }
    } else if(sens == 1) {
        for(i = 0; i < 9; i++) {
            array[i] = tableauJoueur[valeur][i];
        }
    }

    int somme = 0;
    for(i = 0; i < 9; i++) {
        somme += array[i];
    }

    if(somme == 45) { // 45 = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9
        return 0;
    } else {
        return 1;
    }
}
//on verifie si la region est remplie correctement
int verifierRegion(int tableauJoueur[9][9], int k, int l) {
    int i, j;
    int array[9];
    int index = 0;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            array[index] = tableauJoueur[i + k][j + l];
            index++;
        }
    }

    int somme = 0;
    for(i = 0; i < 9; i++) {
        somme += array[i];
    }

    if(somme == 45) { // 45 = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9
        return 0;
    } else {
        return 1;
    }
}
// on genere le tableau de jeu
void genererTableau(int tableauJoueur[9][9]) {
    int horrizontal, vertical;
    int nombreNonNuls = 0;

    for (horrizontal = 0; horrizontal < 9; horrizontal++) {
        for (vertical = 0; vertical < 9; vertical++) {
            if (tableauJoueur[horrizontal][vertical] != 0) {
                nombreNonNuls++;
            }
        }
    }

    for(horrizontal = 0;horrizontal < 9; ++horrizontal) {
        for(vertical = 0; vertical < 9; ++vertical) printf("%d ", tableauJoueur[horrizontal][vertical]); printf("\n");
    }

    printf("Nombre de case préremplit : %d\n", nombreNonNuls);
}
// on verifie si la grille est remplie correctement
int verifierGrille(int tableauJoueur[9][9]) {
    for (int i = 3; i < 9; i += 3) {
        for(int j = 3; j < 9; j += 3) {
            if (verifierRegion(tableauJoueur, i, j) == 0) {
                return 0;
            }
        }
    }

    for(int i = 0; i < 9; i++) {
        if(verifierLigneColonne(tableauJoueur, i, 0) == 0) {
            return 0;
        }
        if(verifierLigneColonne(tableauJoueur, i, 1) == 0) {
            return 0;
        }
    }
    return 1;
}
void entrerDonnée(int tableauJoueur[9][9]) {
    int i, j, v;
    printf("entrer le numero de ligne : \n"); // horizontale
    scanf ("%d", &i);
    printf("entrer le numero de colonne : \n"); // verticale
    scanf("%d", &j);
    printf("Valeur a placer : \n"); // valeur
    scanf("%d", &v);

    if(j < 0 || j > 8 || i < 0 || i > 8 || v < 1 || v > 9) { // si les indices ne sont pas valides
        printf("Nombre non valide\n");
    }
    else {
        if(tableauJoueur[i][j] == 0) { // si la case est vide
            tableauJoueur[i][j] = v;
        } else {
            printf("Case deja occuper\n");
        }
    }
}

int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    int solution[9][9];
    //printf("SOLUTION");
    // printf("\n");
    // printf("---------------------------------");
    // printf("\n");
    for(j=0;j<9; ++j)
    {
        for(i=0; i<9; ++i)
            solution[j][i] = (i + j*3 +j /3) %9 +1 ;
    }

    //for(i=0;i<9; ++i)

    //for(j=0; j<9; ++j)
    // printf("%d ", solution[i][j]);
    //printf("\n");

    // printf("---------------------------------");
    // printf("\n");

    //toucher le code entre les commentaires

    //modifie 25 cases de la grille solution pour obtenir la grille de départ
    int nombre_a_modifier   = 35;
    while (nombre_a_modifier > 0) {
        int horrizontal = rand() % 9;
        int vertical = rand() % 9;
        if (solution[horrizontal][vertical] != 0) {
            solution[horrizontal][vertical] = 0;}
            nombre_a_modifier--;
    }

    genererTableau(solution);

    // verifie que la grille est valide
    while (true) {
        int validation = 1;
        while (validation == 1) {
            entrerDonnée(solution);
            genererTableau(solution);
            validation = verifierGrille(solution);
        }
        printf("Bravo, vous avez gagne !\n");
    }

    //Ne pas toucher au code ci dessous
    getchar();
    return 0;
}

