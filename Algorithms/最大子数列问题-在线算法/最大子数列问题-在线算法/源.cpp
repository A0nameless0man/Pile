#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
template <class T>
class max_sub_arry
{
public:
    max_sub_arry(T *dat)
    {
        tags[0] = tags[1] = 0;
        data              = dat;
        value             = 0;
    }
    ~max_sub_arry() {}
    size_t       tags[2];
    T            value;
    max_sub_arry find_max_sub_arry(void)
    {
        return *this = find_max_sub_arry(*this);
    }

private:
    T *          data;
    max_sub_arry find_max_sub_arry(max_sub_arry input)
    {
        max_sub_arry<T> current(data), potential(data);
    }
};

int main(void)
{
    int n, a[1000];
    printf("请输入数据个数:");
    scanf("%d", &n);
    printf("\n请输入数据\n");
    for(size_t i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    max_sub_arry<int> t(a);
    t.tags[1] = n - 1;
    t.find_max_sub_arry();
    printf("从第%d个数据到第%d个数据，共%d。\n", t.tags[0] + 1, t.tags[1] + 1, t.value);
    system("pause");
    return 0;
}