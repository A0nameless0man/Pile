#include <algorithm>
#include <iostream>

int main(void)
{
    int l, r, x;
    while(std::cin >> l >> r >> x)
    {
        l = std::min(l, r + x);
        r = std::min(r, l + x);
        std::cout << (l + r + x) / 2 * 2 << std::endl;
    }
}