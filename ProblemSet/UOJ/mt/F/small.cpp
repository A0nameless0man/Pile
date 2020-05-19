#include <iostream>
using namespace std;
int buf[1000];
int n;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> buf[i];
    }
    int result = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i + 1; j <= n; ++j)
        {
            if(buf[i] > buf[j])
            {
                result += (i ^ j);
            }
        }
    }
    cout << result << endl;
}
