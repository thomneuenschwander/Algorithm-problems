#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = tolower((unsigned char)str[i]);
    }
}
void sort(char** m, int words){
    for(int i = 0; i < words; i++){
        for(int j = (i+1); j < words; j++){
            if(strcmp(m[i], m[j]) > 0){
                char tmp[101];
                strcpy(tmp, m[i]);
                strcpy(m[i], m[j]);
                strcpy(m[j], tmp);
            }
        }
    }
}

int main(){
    int max = 24;

    char input[max][101];
    int input_index = 0;

    FILE* file = fopen("C:\\Users\\Pichau\\Desktop\\Algorithm-problems\\beecrowd\\nvl_4_data_structures\\arqs\\AndyFirstDictionary_1215.txt", "r");
    if(file == NULL){
        printf("FILE ERROR!!\n");
        return -1;
    }

    while(fscanf(file, "%10s", input[input_index]) == 1){
        input_index++;
        if (input_index >= max) {
            break; 
        }
    }
    // for(int i = 0; i < input_index; i++){
    //     printf("%s\n", input[i]);
    // }

    char dictionary[max][101];
    int l = 0;

    for(int i = 0; i < input_index; i++)
    {
        int c = 0;
        for(int j = 0; input[i][j] != '\0'; j++)
        {
            if(input[i][j] != '(' && input[i][j] != '$' && input[i][j] != '.' && input[i][j] != '"' && input[i][j] != ':'&& input[i][j] != '#'&& input[i][j] != '*'){
                dictionary[l][c] = input[i][j];
                c++;
            }
        }
        dictionary[l][c] = '\0';
        l++;
    }
    for(int i = 0; i < l; i++){
        toLowerCase(dictionary[i]);
    }

    char** excl = malloc(l*sizeof(char*));
    int index = 0;

    for(int i = 0; i < l; i++)
    {
        int added = 0;

        for(int j = 0; j < index; j++){
            if(strcmp(excl[j], dictionary[i]) == 0){
                added = 1;
                break;
            }
        }

        if(!added){
            excl[index] = malloc(31*sizeof(char));

            strcpy(excl[index], dictionary[i]);
            index++;
        }
    }
    sort(excl, index);

    for(int i = 0; i < index; i++){
        printf("%s\n", excl[i]);
    }

    fclose(file);
    return 0;
}
