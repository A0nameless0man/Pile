#include <algorithm>
#include <bit>
#include <iostream>
#include <queue>
#include <vector>

using ULL = unsigned long long;
using LL  = long long;

struct Node
{
    LL    sum    = 0;
    ULL   len    = 1;
    Node *son[2] = { nullptr, nullptr };
    LL    set(LL offset, LL len, LL val)
    {
        LL oldSum = sum;
        if(offset == 0 && len >= this->len)
        {
            sum = this->len * val;
        }
        else
        {
            ULL mid = this->len / 2;
            if(offset < mid)
            {
                sum += this->son[0]->set(offset, len, val);
            }
            if(offset + len > mid)
            {
                LL sonOffset =
                  offset > mid ? offset - mid : 0;
                ULL sonLen = offset + len - sonOffset - mid;
                sum +=
                  this->son[1]->set(sonOffset, sonLen, val);
            }
        }
        return sum - oldSum;
    }
    LL get(LL offset, LL len)
    {
        if(offset == 0 && len >= this->len)
        {
            return sum;
        }
        else
        {
            LL  ans = 0;
            ULL mid = this->len / 2;
            if(offset < mid)
            {
                ans += this->son[0]->get(offset, len);
            }
            if(offset + len > mid)
            {
                LL sonOffset =
                  offset > mid ? offset - mid : 0;
                ULL sonLen = offset + len - sonOffset - mid;
                ans += this->son[1]->get(sonOffset, sonLen);
            }
            return ans;
        }
    }
    Node* getChild(ULL offset, LL len)
    {

    }
    Node* swap(ULL offset,Node* ptr){
        
    }
};

struct Tree
{
    std::vector<Node> nodes;
    ULL               _len;
    Tree(LL n): nodes(2 * n), _len(n)
    {
#ifdef DEBUG
        std::cerr << "[Tree::Tree] Init with size " << n
                  << std::endl;
#endif  // DEBUG
        for(LL i = 1; i < n; ++i)
        {
            nodes[i] = {
                0,
                n / std::bit_floor(static_cast<ULL>(i)),
                { &nodes[i * 2], &nodes[i * 2 + 1] }
            };
        }

#ifdef DEBUG
        std::cerr << "[Tree::Tree] Inited with size " << n
                  << std::endl;
#endif  // DEBUG
    }
    LL set(ULL pos, ULL len, LL val)
    {
        return nodes[1].set(pos, len, val);
    }
    LL get(ULL pos, ULL len)
    {
        return nodes[1].get(pos, len);
    }
    LL swap(ULL pos1, ULL pos2, ULL len)
    {
        return len;
    }
};

int main()
{
    ULL n, m;
    while(std::cin >> n >> m)
    {
        Tree tree(n);
        for(ULL i = 0; i < n; ++i)
        {
            LL t;
            std::cin >> t;
            tree.set(i, 1, t);
        }
#ifdef DEBUG
        std::cout << tree.nodes[1].sum << std::endl;
#endif  // DEBUG
        for(ULL i = 0; i < m; ++i)
        {
            int op;
            std::cin >> op;
            switch(op)
            {
                case 1:
                {
                    ULL l, r, k;
                    std::cin >> l >> r >> k;
                    std::cout << (1ull << k)
                                   * tree.get(l, r - l + 1)
                              << "\n";
                }
                break;
                case 2:
                {
                    ULL l1, l2, r1, r2;
                    std::cin >> l1 >> r1 >> l2 >> r2;
                }
                break;
                default:
                    throw 0;
            }
        }
    }
}