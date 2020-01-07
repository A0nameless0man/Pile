#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
const long long int MOD = 10e9 + 7;
char                n[100007];
// s（k)可以看作n个元素分成k组（每个元素都是1）
//如果n个元素分成k-1组，应当剩余n-k个间隙
//在这间隙划开即可分成一组
// s（k）=（n-k）*s（k-1）
//递推知道
// s（k）=（n-k）！
//