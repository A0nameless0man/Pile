#include<stdio.h>
/*
A :���������
ʱ������:  1000MS   �ռ�����:  32MB   �ύ��:  0   ͨ����:  0  
��Ŀ����

��Ŀ����

ũ���ֵ������ʼ��ֱ���������ǿ�ʼɪɪ�����������ǳ��˳Ժ�˯������ʲô�������ˡ�ũ���ֵ�ͻ�����룬���ĳֻ�������һ�������Զ�����ʱ�䳬�����һ������˯����ʱ�䣬��ô���ͻᱻ���ɿ������󣨿��ͣ�ʹ�úܴ������͵���⿷�������������������ᱻ���ɽл����󣨽л�����ճ����ʳ�İ��������������տ�����⿷���������������һ�������Զ�����ʱ���������һ������˯����ʱ�䣬���ͻᱻ�����տ��������������ũ���ֵܾ��������ǵ����ˡ�
��������

��Ŀ��������������ݡ���һ�а���һ��������T������������ݵ��������������������

��������T�У�ÿ�а���һ���������У�����һֻ�������Ϊ����һ������n��ʾ����Ժ�˯����ʱ�䣨1 <= n <= 100��������������1��2��ɡ�1�����������һ��ʱ��Ķ�����2��������˯��һ��ʱ��ľ���ÿ�����ֱ�ʾ�ĳԻ�˯��ʱ�䳤����ȡ�
�������

����ÿһ��������ݣ����һ���ַ����С�"kuanyou"��ʾ���������˿�������"jiaohua"��ʾ�����˽л�����"bbq"��ʾ�������տ�����
��������

1

8 2 2 1 1 2 1 1 1
�������

kuanyou
��������

�����������һ�������Զ�����ʱ��Ϊ3("1 1 1")�����һ������˯����ʱ��Ϊ2("2 2")���������ᱻ���ɿ�������
*/
int main(void)
{
	int behv[105]={0};
	int max_eat,max_sleep,current_stu,current_l,i,n;
	scanf("%*d");
	while(scanf("%d", &n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",behv+i);
		}
		behv[n]=0;
		max_eat=max_sleep=current_l=i=0;
		current_stu=behv[0];
		
		while(behv[i]!=0)
		{
			if(behv[i]==current_stu)
			{
				current_l++;
			}
			else
			{
				if(current_stu==1)
				{
					if(current_l>max_eat)
					{
						max_eat=current_l;
					}
				}
				else
				{
					if(current_l>max_sleep)
					{
						max_sleep=current_l;
					}
				}
				current_l=1;
				current_stu = behv[i];
			}
			i++;
		}
		if(current_stu==1)
		{
			if(current_l>max_eat)
			{
				max_eat=current_l;
			}
		}
		else
		{
			if(current_l>max_sleep)
			{
				max_sleep=current_l;
			}
		}
		if(max_sleep==max_eat)
		{
			printf("jiaohua\n");
		}
		else
		{
			if(max_sleep>max_eat)
			{
				printf("bbq\n");
			}
			else
			{
				printf("kuanyou\n");
			}
		}
	}
	return 0;
}
