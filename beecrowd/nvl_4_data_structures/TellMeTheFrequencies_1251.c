#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Frequency {
    char letter;
    int times;
}Frequency;

char* charArrExclusive(char* arr, int size, int* newSize){
    char* exclusive = malloc(size*sizeof(char));
    for(int i = 0; i < size; i++)
    {
        int added = 0;
        for(int j = 0; j < *newSize; j++)
        {
            if(exclusive[j] == arr[i]){
                added = 1;
                break;
            }
        }
        if(!added){
            exclusive[(*newSize)++] = arr[i];
        }
    }
    exclusive[(*newSize)] = '\0';
    exclusive = realloc(exclusive, (*newSize)*sizeof(char));
    return exclusive;
}


void tellTheFrequency(Frequency* fr, int size, char* input, int input_size) {
    for(int i = 0; i < size; i++)
    {
        int count = 0;
        for(int j = 0; j < input_size; j++)
        {
            if(fr[i].letter == input[j]){
                count++;
            }
        }
        fr[i].times = count;
    }
}

void sort(Frequency* arr, int size){
    for(int i = 1; i < size; i++){
        int j = i-1;
        Frequency piv = arr[i];
        while ((j >= 0) && (arr[j].times > piv.times))
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = piv;
        
    }
}

void output(Frequency* fr, int size) {
    sort(fr, size);
    for(int i = 0; i < size; i++){
        printf("%d %d\n", (int)fr[i].letter, fr[i].times);
    }
}

int main() {
    char input[31];

    scanf("%s", input);

    int size = strlen(input);

    int newSize = 0;
    char* arrExclusive = charArrExclusive(input, size, &newSize);

    Frequency frequency[newSize];

    for(int i = 0; i < newSize; i++){
        frequency[i].letter = arrExclusive[i];
    }
    
    tellTheFrequency(frequency, newSize, input, size);
    output(frequency, newSize);

    return 0;
}