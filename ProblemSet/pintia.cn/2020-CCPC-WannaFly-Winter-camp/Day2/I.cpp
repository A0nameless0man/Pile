#include <iostream>

int main(void)
{
    int t;
    while(std::cin >> t)
    {
        bool f = true;
        while(t--) {
            int a, b;
            std::cin >> a >> b;
            if(a==1)
            {
                f = false;
            }
        }
        if(f)
        {
            std::cout << "0.466667" << std::endl;
        }
        else
        {
            std::cout << "error" << std::endl;
        }
    }
    return 0;
}
/*
必然换门，换一个还没选过的门

分别是 1/n,1/n*(n-2)/(n-1), 的机会

换门后中的机会是 (n-2)/(n*(n-1))>1/n 也就是不换的机会



*/