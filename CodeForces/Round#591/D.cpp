#include<iostream>
#include<vector>
#include<map>
size_t n;
std::vector<size_t> raw;
std::vector<size_t> next;//next[l] is the smallest r that raw[l:r] is leagel
void doNext(void)
{
    next.clear();
    next.resize(n,-1);
}