#include <iostream>
#include <vector>
/*
Time: 2020-01-23 11:19:47
Describe: accepted after I realize that n==2 <==> ans == [1,1]
Statue: ACCEPTED
*/
int main(void)
{
    int n;
    while(std::cin >> n)
    {  // std::cin>>n;
        std::vector<std::vector<int>> m;
        m.resize(n);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int buf;
                std::cin >> buf;
                m[i].push_back(buf);
            }
        }
        if(n>2)
        {
            for(int i = 0; i < n; ++i)
            {
                int ij = m[i][(i + 1) % n];
                int ik = m[i][(i + 2) % n];
                int jk = m[(i + 1) % n][(i + 2) % n];
                std::cout << (ij + ik - jk) / 2;
                if(i != n - 1)
                {
                    std::cout << " ";
                }
                else
                {
                    std::cout << '\n';
                }
            }
        }
        else
        {
            std::cout << "1 1\n";
        }
    }
    return 0;
}