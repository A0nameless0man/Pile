#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using LL = int;

const LL MAX_N = 10000007;
char     s[MAX_N];

int main(void)
{
    while(scanf("%s", s) != EOF)
    {
        int q;
        scanf("%d", &q);
        for(int i = 0; i < q; ++i)
        {
            int l, k;
            scanf("%d%d", &l, &k);
            std::cout << l << "#" << k << std::endl;

            std::string      q(s + l - 1);
            std::vector<int> vec;
            std::stack<int>  stc;
            std::string      best      = q;
            int              bestPos   = 0;
            int              updatePos = k;
            bool             search    = true;
            vec.resize(k);
            vec.push_back(q.length());
            while(search)
            {
                search = false;
                for(size_t i = 1; i < vec.size();++i)
                {
                    if(vec[i]< q.length())
                    {
                        search = true;
                        break;
                    }
                }

                std::string worst;
                int         worstPos;
                for(size_t i = 1; i < vec.size(); ++i)
                {
                    int better  = 0;
                    int pointer = vec[i - 1];
                    int ref     = 0;
                    while(pointer < vec[i] && ref < worst.length() && better == 0)
                    {
                        if(q[pointer] == worst[ref])
                        {
                            ++pointer;
                            ++ref;
                        }
                        else
                        {
                            if(q[pointer] < worst[ref])
                            {
                                better = 1;
                            }
                            else
                            {
                                better = -1;
                            }
                            break;
                        }
                    }
                    if(better == -1 || ref == worst.length() && pointer != vec[i])
                    {
                        worst.clear();
                        worstPos = vec[i - 1];
                        for(int j = vec[i - 1]; j < vec[i]; ++j)
                        {
                            worst.push_back(q[j]);
                        }
                        if(worst > best)
                        {
                            break;
                        }
                    }
                }
                if(worst < best||worst==best&&worstPos<bestPos)
                {
                    best    = worst;
                    bestPos = worstPos;
                }

                {
                    std::stack<size_t> rev;
                    for(size_t i = vec.size() - 2; i; --i)
                    {
                        if(vec[i] < q.length())
                        {
                            ++vec[i];
                            break;
                        }
                        else
                        {
                            // vec[i] =vec[i - 1] + 1 ;
                            rev.push(i);
                        }
                    }
                    if(!rev.empty())
                    vec[rev.top()] = vec[rev.top() - 1] + 1;
                    while(!rev.empty())
                    {
                        auto i = rev.top();
                        rev.pop();
                        vec[i] = vec[i - 1];
                    }
                }
            }
            std::cout << bestPos+l << " " << bestPos + best.length()+l-1<< std::endl;
        }
    }
    return 0;
}
//bababab 1 1 2
/*
bababab 1 1 2
bababab 1 2 2
abaababa 1 2 2
abaababa 1 2 2
abaababa 1 2 2
*/