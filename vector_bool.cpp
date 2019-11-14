#include<iostream>
#include<vector>
int main(void)
{
    std::vector<int> veci;
    std::vector<bool> vecb;
    std::vector<std::vector<int>> vecv;
    veci.resize(10);
    vecb.resize(10);
    vecv.resize(10);

    int cnt = 0;
    for(auto i:veci)
    {
        i = cnt++;
    }
    for(auto i:veci)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    vecb[8] = 15;
    // for(auto i:vecb)
    // {
    //     i = cnt%2==0;
    //     cnt++;
    // }
    for(auto i:vecb)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

    
    return 0;
}
