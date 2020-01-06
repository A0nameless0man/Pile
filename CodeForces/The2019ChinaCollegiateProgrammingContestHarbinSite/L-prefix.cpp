#include <iostream>
#include <set>
#include <vector>
const int        MAX_N = 20007 * 2 + 10;
const int        MAX_M = MAX_N;
int              n;
int              m;
int              tmp[MAX_N] = { 0 };
int              s[MAX_N]   = { 0 };
int              sa[MAX_N]  = { 0 };
int              r[MAX_N]   = { 0 };
int              h[MAX_N]   = { 0 };
int              cnt[MAX_N] = { 0 };
std::vector<int> x;
void             suf(int n, int m)
{
    int i, j, k;
    n++;
    for(i = 0; i < n * 2 + 5; i++)
        r[i] = sa[i] = h[i] = tmp[i] = 0;
    for(i = 0; i < m; i++)
        cnt[i] = 0;
    for(i = 0; i < n; i++)
        cnt[r[i] = s[i]]++;
    for(i = 1; i < m; i++)
        cnt[i] += cnt[i - 1];
    for(i = 0; i < n; i++)
        sa[--cnt[r[i]]] = i;
    for(k = 1; k <= n; k <<= 1)
    {
        for(i = 0; i < n; i++)
        {
            j = sa[i] - k;
            if(j < 0)
                j += n;
            tmp[cnt[r[j]]++] = j;
        }
        sa[tmp[cnt[0] = 0]] = j = 0;
        for(i = 1; i < n; i++)
        {
            if(r[tmp[i]] != r[tmp[i - 1]] || r[tmp[i] + k] != r[tmp[i - 1] + k])
                cnt[++j] = i;
            sa[tmp[i]] = j;
        }
        memcpy(r, sa, n * sizeof(int));
        memcpy(sa, tmp, n * sizeof(int));
        if(j >= n - 1)
            break;
    }
}
int check(int beg)
{
    int i = 0;
    while(beg + i < n && i < x.size() && s[beg + i] == x[i])
        i++;
    if(i == x.size())
    {
        return 0;
    }
    if(beg + i == n || s[beg + i] < x[i])
    {
        return -1;
    }
    return 1;
}
int main(void)
{
    // int n;
    /*
    std::cin>>n;
    for(int i =0;i<n;i++)
    {
        std::cin>>s[i];
    }
    suf(n,n);
    for(int i =1;i<=n;i++)
    {
        std::cout<<sa[i]<<" ";
    }
    std::cout<<std::endl;
    */
    int t;
    std::cin >> t;
    while(t--)
    {
        int q;
        std::cin >> n >> q;
        for(int i = 1; i <= n; i++)
        {
            std::cin >> s[n - i];
        }
        suf(n, n);
        for(int i = 0; i < q; i++)
        {
            int m;
            // bool ans = false;
            try
            {
                std::cin >> m;
                std::set<int> bucket;
                x.clear();
                // bucket.resize(m,0);
                bool mormal = true;
                for(int j = 0; j < m; j++)
                {
                    int buf;
                    std::cin >> buf;
                    if(mormal && buf)
                        x.push_back(buf);
                    else
                        mormal = false;
                }
                // x.push_back(0);
                for(auto j: x)
                {
                    if(bucket.find(j) != bucket.end())
                    {
                        throw false;
                    }
                    else
                    {
                        bucket.insert(j);
                    }
                }
                int l = 1;
                int r = n;
                while(l < r)
                {
                    // std::cout<<l<<"#"<<r<<std::endl;
                    int mid = (l + r) / 2;
                    int i   = 0;
                    int beg = sa[mid];
                    int res = check(beg);
                    if(res < 0)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid;
                    }
                }
                int beg = sa[l];
                if(x.size() == 0)
                    throw true;
                if(m != x.size() && n - beg != x.size())
                {
                    // std::cout<<"beg:"<<beg<<std::endl;
                    throw false;
                }
                throw check(beg) == 0;
            }
            catch(bool ans)
            {
                if(ans)
                {
                    std::cout << "Yes" << std::endl;
                }
                else
                {
                    std::cout << "No" << std::endl;
                }
            }
        }
    }
    return 0;
}
/*
1
7 15
4 3 4 2 3 1 4
1 0
2 0 0
1 4
2 3 4
2 3 0
2 4 0
3 3 4 0
4 3 4 0 0
4 3 2 4 0
4 4 1 3 2
1 4
2 2 3
3 3 2 1
4 4 1 3 2
4 3 4 0 0
  */
