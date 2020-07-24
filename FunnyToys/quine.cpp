#include <cstdio>
#include <string>

std::string s = "#include<cstdio>%c#include <string>%c%cstd::string s=%c%s%c;%c%cint main(void)%c{%c  printf(s.c_str(), 10, 10, 10, 34, s.c_str(), 34, 10, 10, 10, 10, 10);%c}";

int main(void)
{
    printf(s.c_str(), 10, 10, 10, 34, s.c_str(), 34, 10, 10, 10, 10, 10);
}