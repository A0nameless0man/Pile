#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
template <class T>
class 最大子数列
{
public:
    最大子数列(T *dat)
    {
        tags[0] = tags[1] = 0;
        data              = dat;
        value             = 0;
    }
    ~最大子数列() {}
    size_t     tags[2];
    T          value;
    最大子数列 find_max_sub_arry(void)
    {
        return *this = find_max_sub_arry(*this);
    }

private:
    T *        data;
    最大子数列 find_max_sub_arry(最大子数列 input)
    {
        if(input.tags[1] == input.tags[0])
        {
            最大子数列<T> r(input.data);
            r.tags[0] = r.tags[1] = input.tags[0];
            r.value               = r.data[r.tags[0]];
            return r;
        }
        else
        {
            const size_t  mid = input.mid(), step[2] = { -1, 1 };
            T             sum[2] = { 0 }, max[2] = { input.data[mid], input.data[mid + 1] };
            size_t        tags[2] = { mid, mid + 1 };
            最大子数列<T> r(input.data), r_l(input.data), r_r(input.data);
            for(size_t i = 0; i < 2; i++)
            {
                for(size_t j = r.tags[i] = mid + i; j != input.tags[i] + step[i]; j += step[i])
                {
                    if((sum[i] += input.data[j]) > max[i])
                    {
                        max[i]    = sum[i];
                        r.tags[i] = j;
                    }
                }
            }
            r.value     = max[0] + max[1];
            r_l.tags[0] = input.tags[0];
            r_l.tags[1] = mid;
            r_r.tags[0] = mid + 1;
            r_r.tags[1] = input.tags[1];
            r_l.find_max_sub_arry();
            r_r.find_max_sub_arry();
            if(r.value >= r_l.value && r.value >= r_r.value)
            {
                return r;
            }
            else
            {
                return (r_l.value >= r_r.value) ? r_l : r_r;
            }
        }
    }
    inline size_t mid()
    {
        return (tags[0] + tags[1]) / 2;
    }
};
int n, a[100000];

int main(void)
{
    printf("请输入数据个数:");
    scanf("%d", &n);
    printf("\n请输入数据\n");
    for(size_t i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    最大子数列<int> t(a);
    t.tags[1] = n - 1;
    t.find_max_sub_arry();
    printf("从第%d个数据到第%d个数据，共%d。\n", t.tags[0] + 1, t.tags[1] + 1, t.value);
    system("pause");
    return 0;
}
