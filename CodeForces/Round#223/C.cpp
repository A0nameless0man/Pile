#include <iostream>
#include <map>
struct Node
{
    enum Type
    {
        add,
        mul
    } type;
    long long v, c;
};
int main(void)
{
    long long m;
    while(std::cin >> m)
    {
        std::map<long long, Node, std::greater<long long> > map;
        long long                                           curpos = 1;
        for(long long i = 0; i < m; ++i)
        {
            long long op;
            std::cin >> op;
            switch(op)
            {
                case 1:
                {
                    long long buf;
                    std::cin >> buf;
                    map[curpos] = Node({ Node::Type::add, buf, 0 });
                    curpos += 1;
                };
                break;
                case 2:
                {
                    long long l, c;
                    std::cin >> l >> c;
                    map[curpos] = Node({ Node::Type::mul, l, c });
                    curpos += l * c;
                };
                break;
            }
        }
        long long n;
        std::cin >> n;
        for(long long i = 0; i < n; ++i)
        {
            long long pos;
            std::cin >> pos;
            auto iter = map.lower_bound(pos);
            while(iter->second.type == Node::Type::mul)
            {
                pos  = (pos - iter->first) % iter->second.v + 1;
                iter = map.lower_bound(pos);
            }
            std::cout << iter->second.v;
            if(i != n - 1)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << std::endl;
            }
        }
    }
}
