#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Status
{
    int n, a, b, c, d;
    // n my
    // a normal
    // b sheld
    // c mock
    // d sheld&&mock
    std::vector<int> poison;
    int              best(void)
    {
        int cnt = 0;
        int aa = a, bb = b, cc = c, dd = d;
        for(auto i: poison)
        {
            if(i)//I'm poison
            {
                if(cc || dd)//any mock
                {
                    if(cc)//there is nosheld mock
                    {
                        --cc;//kill
                        ++cnt;//cnt kill
                    }
                    else//every mock is shelded
                    {
                        ++cc;//mock increase
                        --dd;//sheld decrease
                    }
                }
                else if(aa || bb)//no mock
                {
                    if(aa)//ther is normal
                    {
                        --aa;//kill normal
                        ++cnt;//cnt that
                    }
                    else//sheld only
                    {
                        ++aa;//normal increase
                        --bb;//sheld decrease
                    }
                }
                else
                {
                    return cnt;  // Killed all;
                }
            }
            else
            {//I'm not poison
                if(cc || dd)//mock in game
                {
                    if(dd)//any sheld
                    {
                        ++cc;//decrease sheld
                        --dd;
                    }
                    else
                    {
                        ;//useless
                    }
                }
                else if(aa || bb)
                {
                    if(bb)  // any sheld
                    {
                        ++aa;  // decrease sheld
                        --bb;
                    }
                    else
                    {
                        ;//useless
                    }
                }
                else
                {
                    return cnt;  // Killed all;
                }
            }
        }
        return cnt;
    }

    int worest(void)
    {
        int cnt = 0;
        int aa = a, bb = b, cc = c, dd = d;
        for(auto i: poison)
        {
            if(i)//I'm Posion
            {
                if(cc || dd)//mock
                {
                    if(dd)//if sheld
                    {
                        ++cc;//sheld--
                        --dd;
                    }
                    else//no sheld
                    {
                        --cc;//got kill
                        ++cnt;
                    }
                }
                else if(aa || bb)//no mock
                {
                    if(bb)//any sheld
                    {
                        ++aa;//sheld --
                        --bb;
                    }
                    else
                    {
                        --aa;//kill
                        ++cnt;
                    }
                }
                else
                {
                    return cnt;  // Killed all;
                }
            }
            else
            {//not poison
                if(cc || dd)//mock
                {
                    if(cc)//no sheld
                    {
                        ;
                    }
                    else
                    {//get sheld
                        --dd;
                        ++cc;
                    }
                }
                else if(aa || bb)//no mock
                {
                    if(aa)//normal
                    {
                        ;
                    }
                    else
                    {//sheld
                        --bb;
                        ++aa;
                    }
                }
                else
                {
                    return cnt;  // Killed all;
                }
            }
        }
        return cnt;
    }
};

int main(void)
{
    int    t;
    while(std::cin>>t)
    {
        for(int i = 0; i < t;++i)
        {
            std::string buf;
            Status s;
            std::cin >> s.n >> s.a >> s.b >> s.c >> s.d;
            s.poison.clear();
            std::cin >> buf;
            for(auto c:buf)
            {
                s.poison.push_back(c - '0');
            }
            std::cout << s.best() << " " << s.worest() << std::endl;
        }
    }
}