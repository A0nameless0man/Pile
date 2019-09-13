#include <iostream>
#include <string>
#include <stdio.h>
#include <iostream> //stream
#include <sstream>  //stringstream
#include <fstream>  //file
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
//STL
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
//STL
#ifdef DEBUG
#include <Windows.h> //sleep()
#include <stdlib.h>  //system("pause")
#endif               // DEBUG

//template <typename T> void swap(T &a, T &b)
//{
//	T t = a;
//	a = b;
//	b = t;
//}
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int MAX_N = 10007;
vector<size_t> KMP_string_matcher(const string &target, const string &key, const vector<size_t> &next)
{
    vector<size_t> ans;
    size_t j = 0;
    for (size_t i = 0; i < target.length(); i++)
    {
        while (j != 0 && target[i] != key[j])
        {
            j = next[j-1];
        }
        if (target[i] == key[j])
        {
            j++;
        }
        if (j == key.length())
        {
            ans.push_back(i - j + 1);
            j = next[j - 1];
        }
    }
    return ans;
}
vector<size_t> &caculateNext(const string &key, vector<size_t> &next)
{
    //vector<int> next;
    next.clear();
    next.resize(key.length());
    next[0] = 0;
    size_t j = 0;
    for (size_t i = 1; i < key.length(); i++)
    {
        while (j != 0 && key[j] != key[i])
        {
            j = next[j];
        }
        if (key[j] == key[i])
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
bool isSubStr(const string &key, const string &tar)
{
    return KMP_string_matcher(tar, key, caculateNext(key)).size() != 0;
}
int main(void)
{
    char buf[100007];
    scanf("%s",buf);
    std::string T(buf);
    int q;
    std::cin>>q;
    while (q--)
    {
        scanf("%s",buf);
        std::string S(buf);

        //std::cout<<T<<std::endl<<S<<std::endl;

        if (T.length() > S.length())
        {
            if (isSubStr(S,T))
            {
                std::cout << "my child!" << std::endl;
            }
            else
            {
                std::cout << "oh, child!" << std::endl;
            }
        }
        else
        {
            if (S.length() != T.length())
            {
                if (isSubStr(T,S))
                {
                    std::cout << "my teacher!" << std::endl;
                }
                else
                {
                    std::cout << "senior!" << std::endl;
                }
            }
            else
            {
                if(S==T)
                {
                    std::cout<<"jntm!"<<std::endl;
                }
                else
                {
                    std::cout<<"friend!"<<std::endl;
                }
            }
        }
    }
}