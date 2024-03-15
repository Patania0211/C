#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// Definition des couleurs ASCII
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define BRW "\e[0;43m"

#define FULLPUR "\e[0;45m"
#define FULLRED "\e[0;101m"
#define FULLWHT "\e[0;107m"

#define FULLYEL "\e[0;103m"
// CODE RESET ASCII
#define reset "\e[0m"

//nbr aléatoire
int randominrange(int max, int min) 
{
    return (rand() % (max - min + 1)) + min;
}

void ajouter_indentation(int taille) 
{
    for (int i = 0; i < taille; i++) 
    {
        printf(" ");
    }
}

// liste pour ajouter les couleurs
void ajouter_(int taille, char *color) 
{
    char deco[3] = "O@#";
    char *colors[8] = {BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT};

    for (int i = 0; i < taille; i++) {
        if (randominrange(9, 0) < 2 && i != 0 && i != taille - 1) 
        {
            printf("%s%c%s", colors[randominrange(7, 0)], deco[randominrange(2, 0)], reset);
        } 
        else 
        {
            printf("%s*%s", color, reset);
        }
    }
}
// ajouter le tronc 
void ajouter_tronc(int taille) 
{
    for (int i = 0; i < taille; i++) 
    {
        printf("%s %s", FULLYEL, reset);
    }
}
//configurer les étages 
void ajouter_etage(int taille, int fin, int taille_max) 
{
    int i;
    for (i = taille; i < taille + fin; i += 2) 
    {
        ajouter_indentation(taille_max - i/2);
        if (i == 1) 
        {
            ajouter_(i, YEL);
        } 
        else 
        {
            ajouter_(i, GRN);
        }
        printf("\n");
    }
}
int main() 
{
    int taille = 13;
    taille = 4;

//interaction avec l'utilisateur 
    do{
        printf("Entrez la largeur du sapin: ");
        if(scanf("%d", & taille) != 1)
            printf("Erreur : Veuillez entrer un nombre.\n"); 
            while(getchar() != '\n'){
                
            }
        
        }
        while (taille<= 0); 
    
    do{
        printf("Entrez le nombre d'étages du sapin: ");
        if (scanf("%d", &taille) != 1)
            printf("Erreur : Veuillez entrer un nombre.\n");
            while(getchar() != '\n'){}
        }
        while (taille <= 0);
    
    printf("Vous avez entre la largeur du sapin : %d\n", taille);
    printf("Vous avez entre le nombre d'etages du sapin : %d\n", taille); 
    
    
    int decalage = 1;
    int decompte_base = 8;
    
    
    for (int i = 1; i < taille + 1; i++) 
    {
        ajouter_etage(decalage, decompte_base, 15);
        decalage += decompte_base;
        decalage -= 4;
        decompte_base += 2;
    }



    taille = (taille % 2 == 0) ? taille + 1 : taille;
    for (int j = 1; j < taille; j++) 
    {
        ajouter_indentation(15 - taille / 2);
        ajouter_tronc(taille);
        printf("\n");
    }
    while (1) 
    {
            int decalage = 1;
            int decompte_base = 8;
            
            
            for (int i = 1; i < taille + 1; i++) 
            {
                ajouter_etage(decalage, decompte_base, 15);
                decalage += decompte_base;
                decalage -= 4;
                decompte_base += 2;
            }
            
    
    
            int taille_ = (taille % 2 == 0) ? taille + 1 : taille;
            for (int j = 1; j < taille_; j++) 
            {
                ajouter_indentation(15 - taille / 2);
                ajouter_tronc(taille);
                printf("\n");
            }
    
            sleep(1); // on fait la petite animation sympatique :3 
            system("cls");
        }
        
    }
    
