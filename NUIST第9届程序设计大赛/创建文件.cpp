#include<stdio.h>
int main(void)
{
	char fn[]={"THE_A.cpp"};
	for(char a ='A';a<='H';a++)
	{
		fn[4]=a;
		FILE* f = fopen(fn,"w");
		fprintf(f,"#include<stdio.h>\n\nint main(void)\n{\n\n	while(scanf(\" \", )!=EOF)\n	{\n		\n	}\n	return 0;\n}");
		fclose(f);
	}
}
