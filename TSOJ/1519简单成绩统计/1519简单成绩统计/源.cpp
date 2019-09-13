#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	int buffer, sum = 0, max = -1, min = 10e7, n = 0;
	while (true)
	{
		scanf("%d", &buffer);
		if (buffer == -1)
		{
			break;
		}
		else
		{
			if (buffer > max)
			{
				max = buffer;
			}
			if (buffer < min)
			{
				min = buffer;
			}
			sum += buffer;
			n++;
		}
	}
	printf("%d,%.2f,%d,%d\n", n, (float)sum / n, max, min);
	return 0;
}
