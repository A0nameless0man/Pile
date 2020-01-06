// #include <iostream>
// #include <vector>
// #include <map>
// int main(void)
// {
//     int n, c;
//     while (std::cin >> n >> c)
//     {
//         std::vector<std::vector<int>> array;
//         std::map<int, int> ls;
//         array.resize(n);
//         for (int i = 0; i < n; i++)
//         {
//             int l, buf;
//             std::cin >> l;
//             ls.insert(std::pair(i, l));
//             for (int j = 0; j < l; j++)
//             {
//                 std::cin >> buf;
//                 array[i].push_back(buf);
//             }
//             //array[i].push_back(0);
//         }
//         int biggerThan = 0;
//         int smallerThan = c - 1;
//         int i = 0;
//         while (!ls.empty())
//         {
//             int from = -1, last = -1, circle = 0;
//             std::vector<int> toErase;
//             for (auto p : ls)
//             {
//                 if (p.second > i)
//                 {
//                     if (ls.find(p.first - 1) == ls.end() || i != 0 && array[p.first - 1][i - 1]
//                     != array[p.first][i - 1])
//                     {
//                         from = p.second;
//                         last = p.second;
//                         circle = 0;
//                     } //如果 找不到上一个串 或者 上一个串和本串的上一个字符不同 :
//                     说明已经断了,上一个串 与 当前串的字典序已经决定 else { //如果 上一个串存在 :
//                     则转动圈数应当使得 current >= last
//                         int current = array[p.first][i] + c * circle;
//                         if (current > last)
//                         {
//                         }
//                     }
//                 }
//                 else
//                 {
//                     toErase.push_back(p.first);
//                 }
//             }
//             for(auto p:toErase)
//             {
//                 ls.erase(p);
//             }
//             i++;
//         }
//     }
// }