#include<stdio.h>
#include<stdlib.h>
/*
    1)  le cryptement de jules cesar prend un nombre et décale toutes les lettres
        de l'alphabet de ce nombre dans l'alphabet ce qui nous donne ainsi une
        clef de chiffrement et il ne nous reste plus qu'a l'utiliser pour chiffrer
        un message.
    2)  11.4 12.14.13.3.4 1.15.15.1.17.19.8.4.13.19 1 2.4.20.23 16.20.8 18.4 11.4.21.4.13.19 19.14.19
    4)  chaque caractere chiffre est toujours represente par le meme caractere, facile a force
    5)  cela signifie que les donnée ne doivent pas avoir été modifié une fois que l'on déchiffre
        le message chiffre
<<<<<<< HEAD
        nouveau contenu
=======
        nouveau
>>>>>>> cb811827fa0d4c7d4019ffaded6e6357515f10ea
*/
void chiff_cesar(int deplacement,char *nom_fic_clair,char *nom_fic_chiff)
{
    char c,d;
    int i;
 
    FILE *fic_clair = fopen("clair_cesar.txt", "r");
    if(fic_clair == NULL)
    {
        printf("error\n");
        exit(-1);
    }
    FILE *fic_chiff = fopen("chiff_cesar.txt", "w");
    if(fic_chiff == NULL)
    {
        printf("error\n");
        exit(-1);
    }
    while ((c = fgetc(fic_clair)) != EOF)
    {
        if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z'))
        {
            d = c;
            d = d + deplacement;
            fprintf(fic_chiff, "%c", d);
        }
        else
        {
            fprintf(fic_chiff, "%c", d);
        }
    }
    fclose(fic_clair);
    fclose(fic_chiff);
}
void dechiff_cesar(int deplacement, char *nom_fic_chiff,char *nom_fic_dechiff)
{
        char c,d;
    int i;
 
    FILE *fic_chiff = fopen("chiff_cesar.txt", "r");
    if(fic_chiff == NULL)
    {
        printf("error\n");
        exit(-1);
    }
    FILE *fic_dechiff = fopen("dechiff_cesar.txt", "w");
    if(fic_chiff == NULL)
    {
        printf("error\n");
        exit(-1);
    }
    while ((c = fgetc(fic_chiff)) != EOF)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            d = c;
            d = d - deplacement;
            fprintf(fic_dechiff, "%c", d);
        }
        else
        {
            fprintf(fic_chiff, "%c", d);
        }
    }
    fclose(fic_chiff);
    fclose(fic_dechiff);
}
int main(int argc,char **argv)
{
    int deplacement;
    printf("enter the deplacement you want :");
    scanf("%d", &deplacement);
    chiff_cesar(deplacement,argv[1],argv[2]);
    dechiff_cesar(deplacement,argv[1],argv[2]);
    return(0);
}
