#include <stdio.h>
#include <stdlib.h>

int findTheKthOccurrence(int* arr, int tam, int k, int v){
    int location = 0;
    int occurrence = 0;
    for(int i = 0; i < tam; i++)
    {
        if(arr[i] == v){
            occurrence++;
        }
        if(occurrence == k){
            location = i+1;
            break;
        }
    }
    return location;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < m; i++)
    {
        int k, v;
        scanf("%d %d", &k, &v);
        printf("%d\n", findTheKthOccurrence(arr, n, k, v));
    }

    return 0;
}