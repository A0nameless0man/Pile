#include <iostream>
#include <vector>

int main(void)
{
    int n, c;
    while (std::cin >> n >> c)
    {
        std::vector<std::vector<int>> array;
        array.resize(n);
        for (int i = 0; i < n; i++)
        {
            int l, buf;
            std::cin >> l;
            for (int j = 0; j < l; j++)
            {
                std::cin >> buf;
                array[i].push_back(buf);
            }
        }
        int biggerThan = 0;
        int smallerThan = c - 1;
        
    }
}