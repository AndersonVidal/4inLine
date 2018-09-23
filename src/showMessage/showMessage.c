#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "showMessage.h"

void showMessage(char type){
    char ch, t[1000];
    FILE *arq;

    if (type == 'B') arq = fopen("./src/TextArchives/About.txt","r");
    else if (type == 'R') arq = fopen("./src/TextArchives/Rules.txt","r");
    else if (type == 'A') arq = fopen("./src/TextArchives/Apresentation.txt","r");
    else if (type == 'E') arq = fopen("./src/TextArchives/Goodbye.txt","r");

    if(arq == NULL) printf("A unexpected error occurred!\n");
    else {
        while(fgets(t,sizeof(t),arq) != NULL) printf("%s",t);
        fclose(arq);
    }

    printf("\n");
}
