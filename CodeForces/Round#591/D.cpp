#include<iostream>
#include<vector>
#include<map>
using NextX = std::map<  int ,  int >;
int main(void)
{
    int q;
    std::cin>>q;
    while(q--)
    {
        int  n;
        std::cin>>n;
        std::vector<int> raw;
        std::vector<int> next;//next[l] is the number of r that raw[l:r) is leagel
        std::vector<NextX> nextX;
        std::vector<int> count;
        count.resize(n+10);
        next.resize(n+10,-1);
        nextX.resize(n+10);
        for(int  i = 0 ;i<n;i++)
        {
            int buf;
            std::cin>>buf;
            raw.push_back(buf);
        }
        int i = n;
        while(i--)
        {
            if(i<n-1&&raw[i]==raw[i+1])
            {
                next[i]=i+2;
            }
            else
            {
                //next[i]=((nextX[i+1].count(raw[i]))?((nextX[i+1][raw[i]])+1):(-1));
                if(nextX[i+1].count(raw[i])!=0)
                {
                    next[i] = nextX[i+1][raw[i]]+1;
                }
            }
            if(next[i]!=-1)
            {
                std::swap(nextX[i],nextX[next[i]]);
                nextX[i][raw[next[i]]] = next[i];
            }
        }
        unsigned long long sum = 0;
        //for(  int  i = n-1 ;i>=0;i--)//sum+=(count[i]=(((next[i]!=-1))?(1+(count[next[i]])):0));
        i = n;
        while(i--)
        {
            if(next[i]!=-1)
            {
                count[i]=(count[next[i]]+1);
                sum+=count[i];
            }
        }
        //if(n==300000&&raw[0]==300000)
        //{
            // for(  int  i = 0 ;i<n;i++)std::cout<<i<<"\t";std::cout<<std::endl;
            // for(  int  i = 0 ;i<n;i++)std::cout<<raw[i]<<"\t";std::cout<<std::endl;
            // for(  int  i = 0 ;i<n;i++)std::cout<<next[i]<<"\t";std::cout<<std::endl;
            // for(  int  i = 0 ;i<n;i++)std::cout<<count[i]<<"\t";std::cout<<std::endl;
        //}
        //for(  int  i = 0 ;i<n;i++)sum+=(count[i]=(((next[i]!=-1))?(1+count[next[i]]):0));
        std::cout<<sum<<std::endl;
    }
    return 0;
}