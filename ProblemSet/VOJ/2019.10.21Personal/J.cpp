#include <iostream>
#include <map>
#include <string>
#include <vector>
size_t counter = 0;
int    main(void)
{
    std::map<std::string, size_t> val = { { "__int128", 16 },    { "char", 1 },  { "int", 4 },
                                          { "long long", 8 },    { "float", 4 }, { "double", 8 },
                                          { "long double", 16 }, { "bool", 1 } };
    int                           t;
    std::cin >> t;
    for(int i = 0; i < t; i++)
    {
        int    n;
        size_t ans = 0;
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            size_t                   size;
            size_t                   count = 0;
            std::vector<std::string> buffer;
            std::string              buf;
            std::getline(std::cin, buf);
            if(buf.length() < 1)
            {
                i--;
                continue;
            }
            // std::cout<<buf<<"#"<<std::endl;
            size_t k = buf.length() - 1;
            while(buf[k] != ';')
                k--;
            for(; k != -1; k--)
            {
                if(buf[k] == ' ')
                {
                    size     = val[buf.substr(0, k)];
                    size_t i = k;
                    while(i < buf.length() && !isdigit(buf[i]))
                        i++;
                    while(i < buf.length() && isdigit(buf[i]))
                    {
                        count *= 10;
                        count += buf[i] - '0';
                        i++;
                        // std::cout<<buf[i]<<'#'<<count<<std::endl;
                    }
                    if(i == buf.length())
                        count = 1;
                    break;
                }
            }
            // std::cout<<size<<std::endl;
            ans += size * count;
        }
        ans = (ans + 1023) / 1024;
        std::cout << "Case #" << ++counter << ": " << ans << std::endl;
    }
}