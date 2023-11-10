#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define POMEKON_AVAILABLE 151

char** pomekonsFound(char** pomekons, int tam, int* newTam){

    char** exclusives = malloc(tam*sizeof(char*));
    int index = 0;

    for(int i = 0; i < tam; i++)
    {
        int unique = 1;
        for(int j = 0; j < index; j++)
        {
            if(strcmp(pomekons[i], exclusives[j]) == 0) {
                unique = 0;
                break;
            }
        }
        if(unique){
            exclusives[index] = malloc(31*sizeof(char));
            strcpy(exclusives[index++], pomekons[i]);
        }
    }
    *newTam = index;
    exclusives = realloc(exclusives, index+1*sizeof(char*));
    exclusives[index] = NULL;
    return exclusives;
}


int main(){
    int N;
    scanf("%d", &N);
    char** pomekons = malloc(N*sizeof(char*));
    for(int i = 0; i < N; i++)
    {
        pomekons[i] = malloc(31 * sizeof(char));
        scanf("%s", pomekons[i]);
    }

    int qnt;
    char** found = pomekonsFound(pomekons, N, &qnt);

    printf("Falta(m) %d pomekon(s).", POMEKON_AVAILABLE - qnt);

// ---- DESALOCAR MEMORIA -------------
    for(int i = 0; i < N; i++) { free(pomekons[i]); }
    for(int i = 0; i != qnt; i++) { free(found[i]); }
    free(pomekons);
    free(found);
    return 0;
}