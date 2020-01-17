#include<iostream>
#include<iomanip>

void binout(long long i)
{
    while(i)
    {
        std::cout << (i & 1);
        i >>= 1;
    }
    std::cout << std::endl;
}

int main(void)
{
    long long l,r,x;
    while(std::cin>>l>>r>>x)
    {
        binout(l);
        binout(r);
        binout(x);
        for(long long i = l; i <= r;++i)
        {
            std::cout << (i ^ x) << std::endl;
            // binout(i ^ x);
        }
    }
    return 0;
}