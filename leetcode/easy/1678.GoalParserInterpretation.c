#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    scanf("command = \"%[^\"]", input);

    int size = strlen(input);

    char *output = malloc(size * sizeof(char));
    int index = 0;

    for (int i = 0; i < size; i++)
    {
        if (input[i] == 'G')
            {
                output[index++] = 'G';
            }
            else if (i < size - 1  && input[i] == '(' && input[i+1] == ')')
            {
                output[index++] = 'o';
                i++;
            }
            else if (i < size - 3 && input[i] == '(' && input[i+1] == 'a' && input[i+2] == 'l' && input[i+3] == ')')
            {
                output[index++] = 'a';
                output[index++] = 'l';
                i++;
                i++;
            }
    }
    output[index] = '\0';
    output = realloc(output, index*sizeof(char));

    printf("%s\n", output);

    return 0;
}
