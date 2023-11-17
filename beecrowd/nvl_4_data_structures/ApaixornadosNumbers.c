#include <stdio.h>
#include <stdlib.h>

int *apaixonadosNumbers(int *arr, int tam, int *newTam)
{
    int *apx = malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++)
    {
        int count = 0;
        for (int j = 0; j < tam; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count != 2)
        {
            int alreadyAdd = 0;
            for (int z = 0; z < (*newTam); z++)
            {
                if (apx[z] == arr[i])
                {
                    alreadyAdd = 1;
                    break;
                }
            }
            if (!alreadyAdd)
            {
                apx[(*newTam)++] = arr[i];
            }
        }
    }
    apx = realloc(apx, (*newTam) * sizeof(int));
    return apx;
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n != 0)
    {
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int newTam = 0;
        int *apaixonados = apaixonadosNumbers(arr, n, &newTam);
        for (int i = 0; i < newTam; i++)
        {
            printf("%d ", apaixonados[i]);
        }
        printf("\n");

        scanf("%d", &n);
    }
    return 0;
}