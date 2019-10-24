#include<iostream>
#include<vector>
#include<map>
size_t n;
std::vector<size_t> raw;
std::vector<size_t> next;//next[l] is the number of r that raw[l:r) is leagel
std::vector<size_t> nxt;//nex[l] is the smallest 
void doNext(void)
{
    next.clear();
    next.resize(n,-1);
}