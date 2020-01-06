#include <iostream>

int count(int x);
int count(int x)
{
    int ans = 0;
    while(x)
    {
        if(x & 1)
            ++ans;
        x >>= 1;
    }
    return ans;
}
int main(void)
{
    int n, p;
    while(std::cin >> n >> p)
    {
        int i;
        for(i = 0; i < 32; i++)
        {
            int tmp = n - i * p;
            if(tmp >= 0 && i >= count(tmp) && i <= tmp)
            {
                break;
            }
        }
        if(i == 32)
        {
            i = -1;
        }
        std::cout << i << std::endl;
    }
}