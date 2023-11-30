#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSubsequences(char* S, int size, char* str, int k){

    for(int i = 0; i < size-k; i++)
    {
        int count = 0;
        for(int j = 0; j < k; j++)
        {
            if(S[i+j] == str[j]){
                count++;
            }
        }
        if(count == k){
            return 1;
        }
    }
    return 0;
}

int main(){

    int N;
    scanf("%d", &N);

    while(N--)
    {
        char S[31];
        scanf("%s", S);
        int size = strlen(S);

        int Q;
        scanf("%d", &Q);

        while(Q--)
        {
            char str[31];
            scanf("%s", str);
            int k = strlen(str);

            if(isSubsequences(S, size, str, k)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }

    return 0;
}