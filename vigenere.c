#include<stdio.h>
#include<stdlib.h>

/*
    1)  on utilise une clef de chiffrement d'une taille n une fois chaque element
        de cette clef est utilise pour chiffre une lettre et une fois toute la clef
        utilise on recommence au debut de la clef jusqu'a la fin du chiffrement
    2)  
    3   le message "cryptographie symetrique" une fois coder avec la clef "Ivry"
        donne "kmpnbjxpikygm jwuzkpqllc"
    4) le message chiffre "xzmsrmwlisrgufrik" chiffre avec la clef "esiea" donne
        "theorie des nombres"
    5) 
    6) Par rapport au chiffrement de cesar le chiffrement de vigenere empeche
        rend difficile le dechiffrement par analyse des frequences
    7)  le dechiffrement de messsage chiffre avec le chiffrement de vigenere
        est simple une fois la longueur de la clef est connu car nous pouvons
        découpe le message chiffre par segment de la taille de la clef puis
        ensuite utiliser une analyse de frequence.
*/

int determ_long_text(char *nom_fic)
{
    int compteur;
    char c;
    FILE *long_fic = fopen("clef_vigenere.txt", "r");
    if(long_fic == NULL)
    {
        printf("error\n");
        exit(-1);
    }
    while ((c = fgetc(long_fic)) != EOF)
    {
        if(c >= 'a'&&c <= 'z')
        {
            compteur++;
        }
    }
    return(compteur);
    printf("%d\n", compteur);
    fclose(long_fic);
}

void charger_clef(int T,char clef[T],char *nom_fic_clef)
{
    int compteur;
    int lettre;
    char c;
    int i;
    FILE *fic_clef = fopen("clef_vigenere.txt", "r");
    while((c = fgetc(fic_clef)) != EOF && (compteur<T))
    {
        if(c >= 'a'&&c <= 'z')
        {
            clef[compteur] = c;
            compteur++;
        }
    }
    fclose(fic_clef);
}

void chiff_vigenere(int T,char clef[T],char *nom_fic_claire,char *nom_fic_chiff)
{
    char c;
    char d;
    int i = 0;
    int stock;
    FILE *fic_clair_vigenere = fopen("claire_vigenere.txt", "r");
    if(fic_clair_vigenere == NULL)
    {
        printf("ERROR\n");
        exit(-1);
    }
     FILE *fic_chiff_vigenere = fopen("chiff_vigenere.txt", "w");
     if(fic_clair_vigenere == NULL)
    {
        printf("ERROR\n");
        exit(-1);
    }
    while((c = fgetc(fic_clair_vigenere)) != EOF)
    {
        if (c >= 'a' && c <= 'z'||c>= 'A' && c<= 'Z')
        {
            d = c;
            stock = clef[i] - 'a';
            d += stock;
            fprintf(fic_chiff_vigenere, "%c", d);
            i = (i + 1)%T;
        }
    }
    fclose(fic_chiff_vigenere);
    fclose(fic_clair_vigenere);
}

int main(int argc,char **argv)
{
    int T = 12;
    char clef[T];
    charger_clef(T,clef,argv[1]);
    chiff_vigenere(T,clef,argv[1],argv[2]);
    return(0);
}