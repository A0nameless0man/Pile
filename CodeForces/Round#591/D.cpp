#include<iostream>
#include<vector>
#include<map>
size_t n;
using NextX = std::map<size_t,size_t>;
std::vector<size_t> raw;
std::vector<size_t> next;//next[l] is the number of r that raw[l:r) is leagel
std::vector<NextX> nextX
std::vector<size_t> count;
void doNext(void)
{
    size_t i = n;
    count.resize(n+1);
    next.resize(n+1);
    nextX.resize(n+1);
    while(i--)
    {
     next[i]=nextX[i+1].contains(raw[i])?(nextX[i+1][raw[i]]):-1;
     
    }
}