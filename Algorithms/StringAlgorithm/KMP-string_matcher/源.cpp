#define _CRT_SECURE_NO_WARNINGS  // shut up MS//NOT fo CPP//scanf VS. scanf_s
//#define DEBUG
#include <algorithm>
#include <ctype.h>
#include <fstream>   //file
#include <iostream>  //stream
#include <math.h>
#include <sstream>  //stringstream
#include <stdio.h>
#include <string.h>
#include <string>
// STL
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
// STL
#ifdef DEBUG
#    include <Windows.h>  //sleep()
#    include <stdlib.h>   //system("pause")
#endif                    // DEBUG

// template <typename T> void swap(T &a, T &b)
//{
//	T t = a;
//	a = b;
//	b = t;
//}
using namespace std;
using LL             = long long;
using ULL            = unsigned long long;
const int      MAX_N = 10007;
string         key, target;
vector<size_t> pi;
vector<size_t> result;
vector<size_t>
KMP_string_matcher(const string &target, const string &key, const vector<size_t> &next)
{
    vector<size_t> ans;
    size_t         j = 0;
    for(size_t i = 0; i < target.length(); i++)
    {
        while(j != 0 && target[i] != key[j])
        {
            j = next[j - 1];
        }
        if(target[i] == key[j])
        {
            j++;
        }
        if(j == key.length())
        {
            ans.push_back(i - j + 1);
            j = next[j - 1];
        }
    }
    return ans;
}
vector<size_t> Plain_string_matcher(const string &target, const string &key)
{
    vector<size_t> ans;
    for(size_t i = 0; i <= target.length() - key.length(); i++)
    {
        for(size_t j = 0; j < key.length(); j++)
        {
            if(target[j + i] != key[j])
            {
                break;
            }
            else
            {
                if(j == key.length() - 1)
                {
                    ans.push_back(i);
                }
                else
                {
                    continue;
                }
            }
        }
    }
    return ans;
}
vector<size_t> &caculateNext(const string &key, vector<size_t> &next)
{
    // vector<int> next;
    next.clear();
    next.resize(key.length());
    next[0]  = 0;
    size_t j = 0;
    for(size_t i = 1; i < key.length(); i++)
    {
        while(j != 0 && key[j] != key[i])
        {
            j = next[j];
        }
        if(key[j] == key[i])
        {
            ++j;
        }
        next[i] = j;
    }
    return next;
}
vector<size_t> caculateNext(const string &key)
{
    vector<size_t> next;
    caculateNext(key, next);
    return next;
}
int n, m, a, b, j, k;
int main(void)
{
#ifdef DEBUG
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // DEBUG

    while(std::cin >> key >> target)
    {
        pi     = caculateNext(key);
        result = KMP_string_matcher(target, key, pi);
        for(auto u: result)
        {
            cout << u << endl;
        }
    }
#ifdef DEBUG
    system("pause");
    Sleep(-1);
#endif  // DEBUG
    return 0;
}
