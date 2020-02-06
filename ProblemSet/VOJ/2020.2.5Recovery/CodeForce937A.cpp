#include <iostream>
#include <set>

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        std::set<int> bucket;
        for(int i = 0; i < n; ++i)
        {
            int buf;
            std::cin >> buf;
            if(buf != 0)
            {
                bucket.insert(buf);
            }
        }
        std::cout << bucket.size() << std::endl;
    }
}