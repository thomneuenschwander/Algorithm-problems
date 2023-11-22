#include <stdio.h>
#include <stdlib.h>

typedef struct HashTable{
    int* numbers;
    int qnt;
    int mod;
}HashTable;

HashTable* createHasTable(int tam, int maxNumbers){
    HashTable* new = malloc(tam*sizeof(HashTable));
    for(int i = 0; i < tam; i++){
        new[i].mod = i;
        new[i].numbers = malloc(maxNumbers*sizeof(int));
        new[i].qnt = 0;
    }
    return new;
}

void showHashTable(HashTable* hash, int M){
    for(int i = 0; i < M; i++)
        {
            printf("%d -> ", hash[i].mod);
            int tam = hash[i].qnt;

            if(tam > 0)
            {
                for(int j = 0; j < tam; j++)
                {
                    printf("%d -> ", hash[i].numbers[j]);
                }
            }
            printf("\\\n");
        }
}

int main(){

    int N;
    scanf("%d", &N);

    while(N--)
    {
        int M, C;
        scanf("%d %d", &M, &C);

        HashTable* hash = createHasTable(M, C);
        int numbers[C];

        for(int i = 0; i < C; i++)
        {
            scanf("%d", &numbers[i]);
        }

        for(int i = 0; i < M; i++) {
            for(int j = 0; j < C; j++)
            {
                int mod = numbers[j] % M;

                if(mod == hash[i].mod)
                {
                    hash[i].numbers[hash[i].qnt++] = numbers[j];
                }
            }
        }
        
        showHashTable(hash, M);
    }

    return 0;
}