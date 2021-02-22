#include<stdio.h>
#include<stdlib.h>

void charger_cle(char clef[26],char *nom_fic_cle)
{
    int i;
    FILE *fic = fopen("cle.txt","r");
    if(fic == NULL)
    {
        printf("error\n");
        exit(-1);
    }
    for(i = 0; i < 26; i++)
    {
        clef[i] = fgetc(fic);
    }

    fclose(fic);
}
void chiff_mono_alpha(char clef[26], char *nom_fic_clair, char *nom_fic_chiff)
{
    char C,l;
    FILE *fic_clair = fopen("clair.txt", "r");
    FILE *fic_chiff = fopen("chiff.txt", "w");
    if(fic_clair == NULL || nom_fic_chiff == NULL)
    {
        printf("error\n");
        exit(-1);
    }
    while((l = fgetc(fic_clair)) != EOF)
    {
        if(l >= 'a' && l <= 'z')
        {
            C = clef[l-'a'];
            fprintf(fic_chiff, "%c", C);
        }
    }
    printf("\n");
    fclose(fic_chiff);
    fclose(fic_clair);
}
void  dechiff_mono_alpha(char clef[26], char *nom_fic_chiff,char *nom_fic_dechiff)
{
    char C,l;
    FILE *fic_chiff = fopen("chiff.txt", "r");
    FILE *fic_dechiff = fopen("dechiff.txt", "w");
    if(nom_fic_chiff == NULL)
    {
        printf("error\n");
        exit(-1);
    }
    while((l = fgetc(fic_chiff)) != EOF)
    {
        if(l >= 'a' && l <= 'z')
        {
            fprintf(fic_dechiff, "%c", C);
        }
    }
}
int main(int argc,char **argv)
{
    char clef[26];
    int i;
    charger_cle(clef, argv[1]);
    for(i = 0;i < 26; i++)
    {
        printf("%c", clef[i]);
    }
    printf("\n");
    chiff_mono_alpha(clef,argv[1],argv[2]);
    dechiff_mono_alpha(clef,argv[2], argv[3]);
    return(0);
}