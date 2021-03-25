// 给定一个正整数组，对于每个元素，输出它右边最近的一个比它大的元素，找不到的话输出-1。
// Input:  2, 5, 7,  3,  6,  4, 10,   1
// ouput: 5, 7, 10, 6, 10, 10, -1, -1

#include<stack>
#include<vector>
#include<algorithm>
#include<iostream>
std::vector<int> fun(const std::vector<int>& input)
{
  std::stack<int> stack;
  std::vector<int> res;
  for(auto iter = input.rbegin();iter!=input.rend();++iter)
  {
    while(!stack.empty()&&stack.top()<=*iter)
    {
      stack.pop();
    }
    res.push_back(stack.empty()?-1:stack.top());
    stack.push(*iter);
  }
  std::reverse(res.begin(),res.end());
  return res;
}

int main(void)
{
    for(const auto val:fun({2, 5, 7,  3,  6,  4, 10,   1}))
    {
        std::cout<<val<<std::endl;
    }
}