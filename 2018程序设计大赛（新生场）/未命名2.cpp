#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	int t, n, ex, ey, ez, x, y, z;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int *step = (int *)malloc(100 * 100 * 100 * sizeof(int));
		bool barrier[100][100][100];
		//ini
		for (int a = 0; a < 100; a++)
		{
			for (int b = 0; b < 100; b++)
			{
				for (int c = 0; c < 100; c++)
				{
					*(step + 10000 * a + 100 * b + c) = 0;
					barrier[a][b][c] = false;
				}
			}
		}
		scanf("%d%d%d%d", &n, &ex, &ey, &ez);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &x, &y, &z);
			barrier[x][y][z] = true;
		}
		*step = 1;
		for (int i = 0; i <= 2 * ex + 2 * ey + 2 * ez; i++)
		{
			for (int a = 0; a < ex + 1; a++)
			{
				for (int b = 0; b < ey + 1; b++)
				{
					for (int c = 0; c < ez + 1; c++)
					{
						if (barrier[a][b][c] != true)
						{
							if (a != 0 && *(step + (a - 1) * 10000 + b * 100 + c) != 0 && (*(step + (a - 1) * 10000 + b * 100 + c) < *(step + (a)*10000 + b * 100 + c) || *(step + (a)*10000 + b * 100 + c) == 0))
							{
								*(step + (a)*10000 + b * 100 + c) = *(step + (a - 1) * 10000 + b * 100 + c) + 1;
							}
							if (a != ex && *(step + (a + 1) * 10000 + b * 100 + c) != 0 && (*(step + (a + 1) * 10000 + b * 100 + c) < *(step + (a)*10000 + b * 100 + c) || *(step + (a)*10000 + b * 100 + c) == 0))
							{
								*(step + (a)*10000 + b * 100 + c) = *(step + (a + 1) * 10000 + b * 100 + c) + 1;
							}
							if (b != 0 && *(step + a * 10000 + 100 * b + c - 100) != 0 && (*(step + a * 10000 + 100 * b + c - 100) < *(step + (a)*10000 + b * 100 + c) || *(step + (a)*10000 + b * 100 + c) == 0))
							{
								*(step + (a)*10000 + b * 100 + c) = *(step + a * 10000 + 100 * b + c - 100) + 1;
							}
							if (b != ey && *(step + a * 10000 + 100 * b + c + 100) != 0 && (*(step + a * 10000 + 100 * b + c + 100) < *(step + (a)*10000 + b * 100 + c) || *(step + (a)*10000 + b * 100 + c) == 0))
							{
								*(step + (a)*10000 + b * 100 + c) = *(step + a * 10000 + 100 * b + c + 100) + 1;
							}
							if (c != 0 && *(step + a * 10000 + 100 * b + c - 1) != 0 && (*(step + a * 10000 + 100 * b + c - 1) < *(step + (a)*10000 + b * 100 + c) || *(step + (a)*10000 + b * 100 + c) == 0))
							{
								*(step + 10000 * a + 100 * b + c) = *(step + a * 10000 + 100 * b + c - 1) + 1;
							}
							if (c != ez && *(step + a * 10000 + 100 * b + c + 1) != 0 && (*(step + a * 10000 + 100 * b + c + 1) < *(step + (a)*10000 + b * 100 + c) || *(step + (a)*10000 + b * 100 + c) == 0))
							{
								*(step + (a)*10000 + b * 100 + c) = *(step + a * 10000 + 100 * b + c + 1) + 1;
							}
						}
					}
				}
			}
		}
<<<<<<< HEAD
	}	
	if(*(step+10000*ex+100*ey+ez)==0)
	{
		printf("Impossible\n");
	}else{
		printf("%d\n",*(step+10000*ex+100*ey+ez)-1);
	}
	free(step);
}
=======
		if (*(step + 10000 * ex + 100 * ey + ez) == 0)
		{
			printf("Impossible\n");
		}
		else
		{
			printf("%d\n", *(step + 10000 * ex + 100 * ey + ez) - 1);
		}
		free(step);
	}
>>>>>>> adefaf18482ff71dce4c133b46b1075f72f09434
	return 0;
}
