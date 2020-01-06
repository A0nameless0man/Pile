#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%*d");
    while(scanf("%d%d%d", &a, &b, &c) != EOF)
    {

        if(a + b <= c || b + c <= a || a + c <= b || a <= 0 || b <= 0 || c <= 0)
        {
            printf("Not ");
            /* code */
        }
        else
        {

            switch((a == b) + (b == c) + (c == a))
            {
                case 1 /* constant-expression */:
                    printf("Isosceles "); /* code */
                    break;
                case 3:
                    printf("Regular ");
                    break;
                default:
                    break;
            }
            /* code */
        }
        printf("Triangle\n");
        /* code */
    }

    return 0;
}
