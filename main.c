#include <stdlib.h>
#include <stdio.h>
#include "dictionnary.h"

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    FILE* file = NULL;
    char buffer[BUFFER_SIZE];
    char * fileLink = argv[1];
    
    Dict dictionnary;
    int loop = 1;
    int choice;
    
    if (argc == 2)
    {
        file = fopen(fileLink, "r");
        
        if (file != NULL)
        {
            fread (buffer, 1, BUFFER_SIZE, file);
            
            dictionnary = createDict(buffer); /* Creation du dictionnaire avec le contenu du fichier */
            
            fclose(file);
        }
        else
        {
            printf("Impossible d'ouvrir le fichier %s", fileLink);
            dictionnary = createEmptyDict();
        }
    }
    else
    {
        dictionnary = createEmptyDict();
    }
    
    while (loop)
    {
        printf("\n*** MENU *** \n\n");
        printf("1 - Ajouter mot \n");
        printf("2 - Afficher dictionnaire \n");
        printf("3 - Quitter \n\n");
        printf("Choix : ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("\nAjouter mot\n\n");
                printf("Votre mot : ");
                scanf("%s", buffer);
                insertWord(&dictionnary, buffer);
                break;
                
            case 2:
                printf("\nAfficher dictionnaire\n\n");
                printDict(dictionnary);
                break;
                
            case 3:
                loop = 0;
                break;
                
            default:
                printf("\nErreur caractere\n\n");
                break;
        }
        
    }
    
    return 0;
}
