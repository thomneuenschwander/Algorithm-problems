#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareSubstring(char *string, char *substring)
{
    int str_size = strlen(string), substr_size = strlen(substring);

    int biggest = 0;

    for (int i = 0; i < str_size; i++)
    {
        for (int j = 0; j < substr_size; j++)
        {
            int curr = 0;
            if (substring[j] == string[i])
            {
                curr++;
                int k = i + 1;
                int z = j + 1;
                while (k < str_size && z < substr_size && string[k] == substring[z])
                {
                    k++;
                    z++;
                    curr++;
                }
            }
            if (curr > biggest)
            {
                biggest = curr;
            }
        }
    }

    return biggest;
}

int main()
{
    int output = 8;

    while (output--)
    {
        char str[51];
        char substr[51];

        scanf(" %[^\n]", str);
        scanf(" %[^\n]", substr);

        printf("%d\n", compareSubstring(str, substr));
    }

    return 0;
}