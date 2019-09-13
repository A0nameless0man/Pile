#include<stdio.h>
#include<math.h>
bool prime_number_test(long long int input)
{
	for (size_t i = 2; i <= 0.5 + pow(input, 0.5); i++)
	{
		if ((input % i) == 0)
		{
			/*-利用求余和循环判断是否是素数-*/
			return false;

		}
	}
	return true;
}
int main(void)
{
	int a = 0;
	int b = 2;
	while (scanf("%d", &a) != EOF)
	{
		for (size_t i = 3; i < a; i++)
		{
			if (prime_number_test(i))
			{
				b += i;
			}
		}
		printf("%d\n", b);
		b = 2;
	}
}
