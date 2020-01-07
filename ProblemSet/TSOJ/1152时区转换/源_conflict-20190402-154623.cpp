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
#define C(a) std::cout << #a << " is :" << (a) << ";" << std::endl;
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
using LL        = long long;
using ULL       = unsigned long long;
const int MAX_N = 10007;
int       n, m, a, b, j, k;
string    timez[]       = { "UTC", "GMT",  "BST",  "IST",  "WET",  "WEST", "CET",  "CEST",
                   "EET", "EEST", "MSK",  "MSD",  "AST",  "ADT",  "NST",  "NDT",
                   "EST", "EDT",  "CST",  "CDT",  "MST",  "MDT",  "PST",  "PDT",
                   "HST", "AKST", "AKDT", "AEST", "AEDT", "ACST", "ACDT", "AWST" };
int       time_offset[] = { 0,    0,    60,   60,   0,    60,   60,   120,  120,  180,  180,
                      240,  -240, -180, -210, -150, -300, -240, -360, -300, -420, -360,
                      -480, -420, -600, -540, -480, 600,  660,  570,  630,  480 };
int       main(void)
{
#ifdef DEBUG
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // DEBUG
    std::map<string, int> translate;
    for(int i = 0; i < 32; i++)
    {
        translate.insert(pair<string, int>(timez[i], time_offset[i]));
    }
    while(std::cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            int    h, m;
            string ap, from, to;
            while(!isalnum(std::cin.peek()))
            {
                std::cin.get();
            }
            if(isdigit(std::cin.peek()))
            {
                std::cin >> h;
                if(std::cin.peek() == ':')
                {
                    std::cin.get();
                }
                std::cin >> m >> ap;
            }
            else
            {
                string spe;
                std::cin >> spe;
                if(spe == "noon" || spe == "midnight")
                {
                    if(spe != "noon")
                    {
                        ap = "a.m.";
                    }
                    else
                    {
                        ap = "p.m.";
                    }
                    h = 0;
                    m = 0;
                }
                else
                {
                    throw std::invalid_argument("not");
                }
            }
            std::cin >> from >> to;
            int time = 60 * (h % 12) + m - translate[from];
            time += ((ap == "p.m.") ? 60 * 12 : 0);
            time += translate[to];
            time = (time - 1 + 60 * 24 * 3) % (60 * 24) + 1;
            if(time % (12 * 60) == 0)
            {
                if(time % (24 * 60) != 0)
                {
                    std::cout << "noon" << std::endl;
                }
                else
                {
                    std::cout << "midnight" << std::endl;
                }
            }
            else
            {
                h = time / 60 % 12;
                h = (h + 24 - 1) % 12 + 1;
                m = time % 60;
                if(time > 12 * 60 && time != 24 * 60)
                {
                    ap = "p.m.";
                }
                else
                {
                    ap = "a.m.";
                }
                std::cout << h << ':' << m << ' ' << ap << std::endl;
            }
        }
    }
#ifdef DEBUG
    system("pause");
    Sleep(-1);
#endif  // DEBUG
    return 0;
}
