#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//#include<math.h>
#include<algorithm>
 inline long long sqrt(long long n)
{
	register long long l = 0, r = n,mid;
	while (l<r)
	{
		mid = (l + r) / 2;
		if (mid*mid<n)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	return l;
}
long long max(long long a, long long b)
{
	return a > b ? a : b;
}

long long those[1000007];

int main(void)
{
	register long long n,a,b,i;
	while (scanf("%lld%lld",&a,&b)!=EOF)
	{
		bool first = true;
		if (a>b)
		{
			long long  t = a;
			a = b;
			b = t;
		}
		register long long lim =sqrt(a);
		n = 0;
		for (i = 1; i <= lim; i++)
		{
			if (a%i==0)
			{
				those[n++] = i;
			}
		}
		register long long _n = n;
		for ( i = _n-1; i >= 0; i--)
		{
			if (those[i]*those[i]!=a)
			{
				those[n++] = a / those[i];
			}
		}
		for ( i = 0; i < n; i++)
		{
			if (b%those[i]==0)
			{
				if (first)
				{
					first = !first;
				}
				else
				{
					putchar(' ');
				}
				printf("%lld",those[ i]);
			}
		}
		putchar('\n');
	}
	//putchar('\n');
	return 0;
}
