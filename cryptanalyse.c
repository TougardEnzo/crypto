#include<stdio.h>
#include<stdlib.h>

void calc_freq_lettres_alpha(float alpha[26],char *nom_fic)
{
    char a;
    int i,ind_plus_grande_freq;
    int compt = 0;
    float freq,somme_freq,plus_grande_freq;
    FILE *fic_crypta = fopen("clair_crypta.txt", "r");
    if(fic_crypta == NULL)
    {
        printf("error\n");
        exit(-1);
    }
    for(i = 0;i < 26;i++)
    {
        alpha[i] = 0;
    }
    while ((a = fgetc(fic_crypta)) != EOF)
    {
        if(a=='a')
        {
            alpha[0] = alpha[0] + 1;
        }
        if(a == 'b')
        {
            alpha[1] = alpha[1] + 1;
        }
        if(a == 'c')
        {
            alpha[2] = alpha[2] + 1;
        }
        if(a == 'd')
        {
            alpha[3] = alpha[3] + 1;
        }
        if(a == 'e')
        {
            alpha[4] = alpha[4] + 1;
        }
        if(a == 'f')
        {
            alpha[5] = alpha[5] + 1;
        }
        if(a == 'g')
        {
            alpha[6] = alpha[6] + 1;
        }
        if(a == 'h')
        {
            alpha[7] = alpha[7] + 1;
        }
        if(a == 'i')
        {
            alpha[8] = alpha[8] + 1;
        }
        if(a == 'j')
        {
            alpha[9] = alpha[9] + 1;
        }
        if(a == 'k')
        {
            alpha[10] = alpha[10] + 1;
        }
        if(a == 'l')
        {
            alpha[11] = alpha[11] + 1;
        }
        if(a == 'm')
        {
            alpha[12] = alpha[12] + 1;
        }
        if(a == 'n')
        {
            alpha[13] = alpha[13] + 1;
        }
        if(a == 'o')
        {
            alpha[14] = alpha[14] + 1;
        }
        if(a == 'p')
        {
            alpha[15] = alpha[15] + 1;
        }
        if(a == 'q')
        {
            alpha[16] = alpha[16] + 1;
        }
        if(a == 'r')
        {
            alpha[17] = alpha[17] + 1;
        }
        if(a == 's')
        {
            alpha[18] = alpha[18] + 1;
        }
        if(a == 't')
        {
            alpha[19] = alpha[19] + 1;
        }
        if(a == 'u')
        {
            alpha[20] = alpha[20] + 1;
        }
        if(a == 'v')
        {
            alpha[21] = alpha[21] + 1;
        }
        if(a == 'w')
        {
            alpha[22] = alpha[22] + 1;
        }
        if(a == 'x')
        {
            alpha[23] = alpha[23] + 1;
        }
        if(a == 'y')
        {
            alpha[24] = alpha[24] + 1;
        }
        if(a == 'z')
        {
            alpha[25] = alpha[25] + 1;
        }
        compt++;
    }
    for(i = 0;i < 26;i++)
    {
        freq = (alpha[i]/compt);
        printf("la frequence d'apparition de %c est : %f\n",97+i,freq);
        somme_freq = somme_freq + freq;
        if(plus_grande_freq < freq)
        {
            plus_grande_freq = freq;
            ind_plus_grande_freq = i;
        }
        freq =0;
        //printf("le nombre d'apparition de %c est : %d\n", 97+i,alpha[i]);
    }
    printf("%f\n", somme_freq);
    printf("la plus grande frequence est %f est appartient a la lettre %c\n", plus_grande_freq, 97+ind_plus_grande_freq);
    fclose(fic_crypta);
}
void recherche_exhaustive(char *fic_chiffre,char *fic_dechiffre)
{
    char c,d;
    int decalage = 0;
    FILE *fic_chiff = fopen("chiffre2.txt", "r");
    FILE *fic_dechiff = fopen("dechiffre2.txt", "w");
    for(decalage = 0;decalage <25;decalage++)
    {
        FILE *fic_chiff = fopen("chiffre2.txt", "r");
        while ((c = fgetc(fic_chiff)) != EOF)
        {
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                d = c - 'a';
                d = (d + decalage)%26;
                d = d + 'a';
                fprintf(fic_dechiff, "%c", d);
            }
        }
        fclose(fic_chiff);
        fprintf(fic_dechiff, "\n");
    }
    
    fclose(fic_chiff);
    fclose(fic_dechiff);
}
int main(int argc,char **argv)
{
    float alpha[26];
    //calc_freq_lettres_alpha(alpha,argv[1]);
    recherche_exhaustive(argv[1],argv[2]);
    return(0);
}