#include <algorithm>
//#include <bit>
#include <iostream>
#include <queue>
#include <vector>

using ULL = long long;
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
            if(offset < mid && this->son[0] != nullptr)
            {
                ans += this->son[0]->get(offset, len);
            }
            if(offset + len > mid
               && this->son[1] != nullptr)
            {
                LL sonOffset =
                  offset > mid ? offset - mid : 0;
                ULL sonLen = offset + len - sonOffset - mid;
                ans += this->son[1]->get(sonOffset, sonLen);
            }
            return ans;
        }
    }
    Node *getChild(ULL offset, LL len)
    {
        ULL mid = this->len / 2;
        if(offset == 0 && len >= mid)
        {
            if(this->son[0] != nullptr)
            {
                sum -= this->son[0]->sum;
                auto ans     = this->son[0];
                this->son[0] = nullptr;
                return ans;
            }
            else
            {
                return nullptr;
            }
        }
        else if(offset == mid && len >= mid)
        {
            if(this->son[1] != nullptr)
            {
                sum -= this->son[1]->sum;
                auto ans     = this->son[1];
                this->son[1] = nullptr;
                return ans;
            }
            else
            {
                return nullptr;
            }
        }
        else
        {
            if(offset < mid && this->son[0] != nullptr)
            {
                sum -= this->son[0]->sum;
                auto ans =
                  this->son[0]->getChild(offset, len);
                sum += this->son[0]->sum;
                return ans;
            }
            else if(offset >= mid
                    && this->son[1] != nullptr)
            {
                sum -= this->son[1]->sum;
                auto ans =
                  this->son[1]->getChild(offset - mid, len);
                sum += this->son[1]->sum;
                return ans;
            }
            else
            {
                return nullptr;
            }
        }
    }
    Node *swap(ULL offset, Node *ptr)
    {
        ULL mid = this->len / 2;
        if(offset == 0 && ptr->len == mid)
        {
            auto ans = this->son[0];
            if(this->son[0] != nullptr)
            {
                sum -= this->son[0]->sum;
                // return ans;
            }
            this->son[0] = ptr;
            sum += this->son[0]->sum;
            return ans;
        }
        else if(offset == mid && ptr->len == mid)
        {
            auto ans = this->son[1];
            if(this->son[1] != nullptr)
            {
                sum -= this->son[1]->sum;
                // return ans;
            }
            this->son[1] = ptr;
            sum += this->son[1]->sum;
            return ans;
        }
        else
        {
            if(offset < mid && this->son[0] != nullptr)
            {
                sum -= this->son[0]->sum;
                auto ans = this->son[0]->swap(offset, ptr);
                sum += this->son[0]->sum;
                return ans;
            }
            else if(offset >= mid
                    && this->son[1] != nullptr)
            {
                sum -= this->son[1]->sum;
                auto ans =
                  this->son[1]->swap(offset - mid, ptr);
                sum += this->son[1]->sum;
                return ans;
            }
            else
            {
                return nullptr;
                /*
                Time: 2020-12-10 15:37:58
                Describe: should new Node rather than this;
                Statue: TODO
                */
            }
        }
    }
};

ULL bitFloor(ULL n)
{
    n >>= 1;
    if(n)
    {
        ULL ans = 1;
        while(n)
        {
            n >>= 1;
            ans <<= 1;
        }
        return ans;
    }
    else
    {
        return 1;
    }
}

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
            nodes[i] = { 0,
                         n / bitFloor(static_cast<ULL>(i)),
                         { &nodes[i * 2],
                           &nodes[i * 2 + 1] } };
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
        auto tmp = nodes[1].getChild(pos1, len);
        tmp      = nodes[1].swap(pos2, tmp);
        nodes[1].swap(pos1, tmp);
        return len;
    }
};

int main()
{
    ULL n, m;
    // freopen("c:\\Users\\HuGuang\\Downloads\\P1672\\4.in",
    //         "r",
    //         stdin);
    // std::cin.sync_with_stdio(false);
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
                    --l;
                    --r;
                    std::cout << (1ull << k)
                                   * tree.get(l, r - l + 1)
                              << "\n";
                }
                break;
                case 2:
                {
                    ULL l1, l2, r1, r2;
                    std::cin >> l1 >> r1 >> l2 >> r2;
                    --l1;
                    --l2;
                    --r1;
                    --r2;
                    tree.swap(l1, l2, r1 - l1 + 1);
                }
                break;
                default:
                    throw 0;
            }
        }
    }
    return 0;
}