#include "Segment_Tree.h"
#include <iostream>
#include <string>
int main(void)
{

    size_t t;
    std::cin >> t;
    for(size_t i = 1; i <= t; i++)
    {
        int n;
        std::cin >> n;
        S_tree::Segment_Tree S_t(n, 0);
        for(size_t i = 0; i < n; i++)
        {
            int a;
            std::cin >> a;
            S_t.set(i, i, a);
        }
        std::cout << "Case " << i << ":" << std::endl;
        std::string s;
        do
        {
            std::cin >> s;
            int a, b, c;

            switch(s[0])
            {
                case 'Q':
                    std::cin >> a >> b;
                    std::cout << S_t.sum(a - 1, b - 1) << std::endl;
                    break;
                case 'S':
                    std::cin >> a >> c;
                    S_t.add(a - 1, a - 1, -c);
                    break;
                case 'A':
                    std::cin >> a >> c;
                    S_t.add(a - 1, a - 1, c);
                    break;
                default:
                    break;
            }
        } while(s != "End");
    }
    // S_tree::MyClass<int> mc;
    return 0;
}
