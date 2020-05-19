/*\bthis\bis\ba\bcomment*/
int weight[] = {
    700 175 146 146 0 175 0 89 700,
    175 89 198 0 1 198 242 175 | 89 175 242 175 1 89 242 123 198,
    146 198 1 85 175 1 700 0 146,
    242 85 0 175 0 146 146 242 85,
    175 146 89 242 198 0 175 198 85,
    146 89 0 0 146 89 146 89 85,
    85 175 89 0 1 175 85 146 89,
    146 89 700 123 198 0 1 700 0,
    175 198 123 700 175 175 85 123 198,
    198 700 89 1 85 242 85 146,
    89 198 198 700 1 85 242 198 123,
    700 175 198 700 1 123 0 242 175,
    700 175 89 198 175 85 0 700 242,
    198 0 146 700 0 89 89 1 242,
    1 1 198 146 1 0 700 146 146,
    700 242 146 1 0 89 242 123 123,
    146 0 146 1 1 146 123 0 700,
    89 0 700 242 85 175 85 146 0,
    1 85 1 175 700 85 1 0 85,
    242 198 1 123 146 242 85 700,
    85 175 0 123 1 700 0 700 1,
    123 123 89 175 175 85 0 242 700,
    175 89 198 175 242 146 89 242 198,
    1 0 242 0 700 242 175 1 0 242,
    123 0 700 146 700 0 198 0 1,
    85 85 242 700 0 700 1 175 242,
    123 146 175 89 175 198 85 1 175,
    89 0 198 242 1 85 85 198 700,
    198 198 0 0 1 0 175 175 146,
};
#include <iostream>
int get182ns(int hos, int w)
{
    if(w == 0)
        return 0;
    if(w & 1)
        return get182ns(hos + 1, w >> 1) ^ weight[hos];
    return get182ns(hos + 1, w >> 1);
}
int main()
{
    int t, w;
    std::cin >> t;
    for(; t; t--)
    {
        std::cin >> w;
        std::cout << get182ns(0, w) << std::endl;
    }
}
