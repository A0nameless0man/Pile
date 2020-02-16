#include<iostream>
#include<cstdio>

int main(void)
{
    int n;
    while(std::cin>>n)
    {
        int p=0,a=0;
        for(int i = 0; i < n;++i)
        {
            int event;
            scanf("%d", &event);
            if(event!=-1)
            {
                p += event;
            }
            else
            {
                if(p)
                {
                    --p;
                }
                else
                {
                    ++a;
                }
                
            }
        }
        std::cout << a << std::endl;
    }
}