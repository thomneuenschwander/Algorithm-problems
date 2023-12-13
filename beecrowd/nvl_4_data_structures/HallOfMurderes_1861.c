#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LivingKillers {
    char* name;
    int kills;
}LivingKillers;

int amountKilled(char* killer, char killers[][11], int num_killers){
    int times = 0;

    for(int i = 0; i < num_killers; i++){
        if(strcmp(killers[i], killer) == 0){
            times++;
        }
    }
    
    return times;
}
void sort(LivingKillers* arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = (i+1); j < size; j++){
            if(strcmp(arr[i].name, arr[j].name) > 0){
                LivingKillers tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(){

    FILE* file = fopen("C:\\Users\\Pichau\\Desktop\\Algorithm-problems\\beecrowd\\nvl_4_data_structures\\arqs\\HallOfMurderes_1861.txt", "r");
    if(file == NULL){
        printf("FILE ERROR!!\n");
        return -1;
    }

    char killers[6][11];
    int num_killers = 0;

    char dead[6][11];
    int num_dead = 0;

    while(fscanf(file, "%10s %10s", killers[num_killers], dead[num_dead]) == 2){
        num_killers++;
        num_dead++;
    }

    LivingKillers* living = malloc(6*sizeof(LivingKillers));
    int index = 0;

    for(int i = 0; i < num_killers; i++)
    {
        int isDead = 0;
        for(int j = 0; j < num_dead; j++)
        {
            if(strcmp(killers[i], dead[j]) == 0){
                isDead = 1;
                break;
            }
        }
        int added = 0;
        for(int j = 0; j < index; j++){
            if(strcmp(killers[i], living[j].name) == 0){
                added = 1;
                break;
            }
        }

        if(!isDead && !added){
            living[index].name = malloc(11*sizeof(char));
            strcpy(living[index].name, killers[i]);
            living[index].kills = amountKilled(killers[i], killers, num_killers);\
            index++;
        }
    }
    sort(living, index);
    printf("\n");
    
    for(int i = 0; i < index; i++){
        printf("%s %d\n", living[i].name, living[i].kills);
    }

    fclose(file);
    return 0;
}