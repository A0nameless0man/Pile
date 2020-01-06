#include <iostream>
#include <string>
int main(void)
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int count[2] = { 0 };
    for(auto c: s)
    {
        switch(c)
        {
            case 'z':
                count[0]++;
                break;
            case 'n':
                count[1]++;
                break;
            default:
                break;
        }
    }
    for(int i = 0; i < count[1]; i++)
    {
        std::cout << 1 << " ";
    }
    for(int i = 0; i < count[0]; i++)
    {
        std::cout << 0 << " ";
    }
    std::cout << std::endl;
    return 0;
}