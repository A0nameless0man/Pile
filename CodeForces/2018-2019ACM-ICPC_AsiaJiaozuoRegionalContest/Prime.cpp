#include<iostream>
bool prime[1007];
int main(void)
{
    for(int i = 0;i<1000;i++)
    {
        prime[i]=true;
    }
    for(int i = 2;i<1000;i++)
    {
        if(prime[i])
        {
            int t = 2;
            while(i*t<1000)
            {
                prime[i*t]=false;
                t++;
            }
        }
    }
    for(int i = 1;i<1000;i++)
    {
        if(prime[i])
        {
            std::cout<<i<<",";
        }
    }
}