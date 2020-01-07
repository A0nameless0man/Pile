#include <algorithm>
#include <iostream>
#include <string>
int main(void)
{
    // int n;
    // std::cin>>n;
    std::string s;
    std::cin >> s;
    int m = 0xff;
    for(auto c: s)
    {
        m = std::min(m, (int) c);
        if((int) c > m)
        {
            std::cout << "Ann\n";
        }
        else
        {
            std::cout << "Mike\n";
        }
    }
    // std::cout<<std::fls;
    return 0;
}