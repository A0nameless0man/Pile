#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
    char input[501] = { 0 }, *buffer = NULL, max[501] = { 0 }, min[501] = { 0 }, space[] = " ";
    for(size_t i = 0; i < 500; i++)
    {
        min[i] = 'a';
    }
    scanf("%[A-Za-z ]", input);
    buffer = strtok(input, space);
    do
    {
        if(strlen(buffer) > strlen(max))
        {
            strcpy(max, buffer);
        }
        if(strlen(buffer) < strlen(min))
        {
            strcpy(min, buffer);
        }

    } while((buffer = strtok(NULL, space)) != NULL);

    printf("%s\n%s\n", max, min);
    return 0;
}