#include <stdio.h>

struct class {
    int hallg_azon;
    char veznev[30];
    char kernev[30];
    char szak[4];
    char neptunk[7];
}Hallg;

void display(struct class class_record[3])
{
    int i, len = 3;
       for (i = 0; i < len; i++) {
        printf("Hallgato azonosito : %d\n",
               class_record[i].hallg_azon);
        printf("Vezeteknev : %s\n",
               class_record[i].veznev);
        printf("Keresztnev : %s\n",
               class_record[i].kernev);
        printf("Szak : %s\n",
               class_record[i].szak);
        printf("Neptunkod : %s\n",
               class_record[i].neptunk);
        printf("\n");
    }
}

int main()
{
    struct class fajlbolTomb[3];
    // Tömbfeltötlés
    struct class class_record[3] = { { 1, "Sarosi", "Bence", "GUI", "WX3RG6" },{ 2, "Kiss", "Katoka", "GDE" , "BL2YX1" },{ 3, "Nemoda", "Buda", "VIL" , "LAQ1GH" } };
    display(class_record);
    fajlFeltoltSzoveg(class_record, 3);
    fajlbeolvasSzoveg(class_record);
    return 0;
}

void fajlFeltoltSzoveg(struct class class_record[], int darab){
    FILE* fp;
    /* Létrehozzuk a fájlt, w = write = írni fogunk bele. */
    fp = fopen("sarosi.txt", "w");
    if (fp != NULL) {
        for (int i = 0; i < darab; ++i){
            fprintf(fp, "%d %s %s %s %s\n", class_record[i].hallg_azon, class_record[i].veznev, class_record[i].kernev, class_record[i].szak, class_record[i].neptunk);
        }
        fclose(fp);                 /* file-close */
    }
    else {
        perror("Nem sikerült megnyitni a fájlt");
    }
}


int fajlbeolvasSzoveg(struct class class_record[]){
    FILE *fp;
    char fajlnev[20],c,ch;
    int sorokszama=0;
    printf("\nKerem a fajl nevet (vezeteknev.txt) : ");
    do{
        scanf("%s",&fajlnev);
    }while((c=getchar()) != '\n');
        fp = fopen(fajlnev, "r");
        if (fp != NULL) {
            while((ch = fgetc(fp)) != EOF) {
                if(ch == '\n'){
                    sorokszama++;
//                  printf(" No: %d",sorokszama);
                }
            }
                rewind(fp);
                for (int i=0; i<sorokszama; i++) {
//                  printf("\n A sor szama: %d",i);
                    fscanf(fp, "%d %s %s %s %s", &class_record[i].hallg_azon, class_record[i].veznev, class_record[i].kernev, class_record[i].szak, class_record[i].neptunk);
                    printf("\n %d. %d %s %s %s %s\n", i+1, class_record[i].hallg_azon, class_record[i].veznev, class_record[i].kernev, class_record[i].szak, class_record[i].neptunk);
                }
                fclose(fp); //fájl lezárása
            }
            else {
                perror("Nem sikerult megnyitni a fajlt \n");
            }
            fclose(fp);
    return sorokszama;
}
