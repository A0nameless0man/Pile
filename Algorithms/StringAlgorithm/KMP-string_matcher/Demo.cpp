#include <iostream> //stream
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <thread>
//#include <unistd.h>
using namespace std;
const int wide = 2;
const char placeHolder = ' ';
const int sleepBase = 1;

template <class T>
static void autoPrint(T &t)
{
    for (auto i : t)
    {
        std::cout << std::setw(wide) << std::setfill(placeHolder) << i;
    }
}

static vector<size_t> KMP_string_matcher(const string &target, const string &key, const vector<size_t> &next)
{
    vector<size_t> ans;
    size_t j = 0;
    autoPrint(target);
    std::cout << std::endl;
    for (size_t i = 0; i < target.length(); i++)
    {
        while (j != 0 && target[i] != key[j])
        {
            j = next[j - 1];
        }
        std::string outputPrefix(wide * (i), placeHolder);
        std::cout << outputPrefix;
        auto ss = key.substr(j);
        autoPrint(ss);
        //Sleep(sleepBase);
        std::this_thread::sleep_for(std::chrono::seconds(sleepBase));
        std::cout << '\r' << std::flush;
        if (target[i] == key[j])
        {
            j++;
        }
        if (j == key.length())
        {
            ans.push_back(i - j + 1);
            std::cout << string(wide * (i + j + 1), ' ');
            std::cout << std::endl;
            std::cout << "found at " << i - j + 1 << ":" << std::endl;
            autoPrint(target);
            std::cout << endl;
            std::cout << string(wide * (i - j + 1), placeHolder);
            autoPrint(key);
            std::cout << endl;
            autoPrint(target);
            std::cout << std::endl;
            j = next[j - 1];
        }
    }
    std::cout << string(wide * (key.length() + target.length() + 1), ' ') << '\r';
    return ans;
}
static vector<size_t> &caculateNext(const string &key, vector<size_t> &next)
{
    //vector<int> next;
    next.clear();
    next.resize(key.length(), 0);
    size_t j = 0;
    for (size_t i = 1; i < key.length(); i++)
    {
        while (j != 0 && key[j] != key[i])
        {
            j = next[j - 1];
        }
        if (key[j] == key[i])
        {
            ++j;
        }
        next[i] = j;
    }
    return next;
}
static vector<size_t> caculateNext(const string &key)
{
    vector<size_t> next;
    caculateNext(key, next);
    return next;
}
int main(void)
{
    string key, target;
    vector<size_t> pi;
    vector<size_t> result;
    //std::string stringHolder(placeHolder, wide - 1);
    while (std::cin >> key >> target)
    {
        pi = caculateNext(key);
        result = KMP_string_matcher(target, key, pi);
        autoPrint(pi);
        std::cout << std::endl;
        autoPrint(key);
        std::cout << std::endl;
        //for (auto u : result)
        // {
        //     cout << u << endl;
        // }
    }
    return 0;
}
/*
abcabcad
abbababababababbbsbabcbabcbabcsbbdbdbcabsdbbcasdbcbasdbcbasdbcbasdbcsbad
*/
/*
ababcab
abababcababcabcbababcbabababcabcababcab
aaa
aaaaaaaaaaabaaaaaaaaa

*/