#include <stdio.h>
int main(void)
{
    int max = 0, input = 0;
    scanf("%d", &input);
    while(scanf("%d", &input) != EOF)
    {
        max = input > max ? input : max;
    }
    printf("%d", max);
    return 0;
}