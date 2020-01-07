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
using LL        = long long;
using ULL       = unsigned long long;
const int MAX_N = 10007;
int       n, m, a, b, j, k;
string    buffer;
bool      isInt(const string &in)
{
    if(in.size() == 0 || in.find('.') != string::npos)
    {
        return false;
    }
    else
    {
        string buf;
        if(in[0] == '-' || in[0] == '+')
        {
            buf = in.substr(1, string::npos);
        }
        else
        {
            buf = in;
        }
        for(char u: buf)
        {
            if(!isdigit(u))
            {
                return false;
            }
        }
        return true;
    }
}
bool isFloat(const string &in)
{
    if(in.size() == 0 || in.find('.') == string::npos)
    {
        return false;
    }
    else
    {
        if(in.find('.') != string::npos && in.size() != 1)  //有小数点但不仅有小数点
        {
            size_t fid = in.find_first_of(".");
            return ((fid == in.size() - 1 || (isInt(in.substr(fid + 1, string::npos)))) &&
                    (fid == 0 || isInt(in.substr(0, fid))));
        }
    }
}
int main(void)
{
#ifdef DEBUG
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // DEBUG
    cin >> n;
    while(std::cin >> buffer)
    {
        bool k;
        if(buffer.find_first_of("eE") != string::npos)
        {
            size_t fid = buffer.find_first_of("eE");
            k          = ((isFloat(buffer.substr(0, fid)) || isInt(buffer.substr(0, fid))) &&
                 isInt(buffer.substr(fid + 1, string::npos)));
        }
        else
        {
            if(buffer.find('.') != string::npos && buffer.size() != 1)  //有小数点但不仅有小数点
            {
                size_t fid = buffer.find_first_of(".");
                k = ((fid == buffer.size() - 1 || (isInt(buffer.substr(fid + 1, string::npos)))) &&
                     (fid == 0 || isInt(buffer.substr(0, fid))));
            }
            else
            {
                k = false;
            }
        }
        if(k)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }

        // if (buffer.find('e') == string::npos && buffer.find('E') == string::npos &&
        // buffer.find('.') == string::npos)
        //{
        //	cout << "No" << endl;
        //	continue;
        //}
        // stringstream buf;
        // buf << buffer;
        // float a;
        // buf >> a;
        // if (a != 0.0)
        //{
        //	if (buf.eof())
        //	{
        //		cout << "Yes" << endl;
        //		cout << a << endl;
        //	}
        //	else
        //	{
        //		cout << "No" << endl;
        //	}
        //}
        // else
        //{
        //	int cont = 0;
        //	for (char c : buffer)
        //	{
        //		if (c == '.')
        //		{
        //			cont++;
        //		}
        //		else if (c != '0')
        //		{
        //			cont = 10;
        //			break;
        //		}
        //	}
        //	if (cont == 0 || cont == 1)
        //	{
        //		cout << "Yes" << endl;
        //	}
        //	else
        //	{
        //		cout << "No" << endl;
        //	}
        //	}
    }
#ifdef DEBUG
    system("pause");
    Sleep(-1);
#endif  // DEBUG
    return 0;
}
