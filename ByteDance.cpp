#include<tuple>
#include<vector>
#include<queue>
#include<iostream>

template<typename T>
std::vector<T> order(std::vector<std::vector<T>> vecs)
{
    struct Obj{
        std::vector<T> * vec;
        size_t pos=0;
       bool operator<(const Obj& rop)const
        {
            return this->vec->at(this->pos)>rop.vec->at(rop.pos);
        }
    };
    std::vector<T> res;
    std::priority_queue<Obj> heap;
    for( auto&vec:vecs)
    {
        heap.push((Obj){&vec,0});
    }
    while(!heap.empty())
    {
        auto tup = heap.top();
        heap.pop();
        if(res.empty()||tup.vec->at(tup.pos)!=*(res.rbegin()))
        {
            res.push_back(tup.vec->at(tup.pos));
        }
        ++(tup.pos);
        if(tup.pos<tup.vec->size())
        {
            heap.push(tup);
        }
    }
    return res;
}


int main(void)
{
    std::vector<std::vector<int>> vecs{{1,4,5},{1,3,4},{2,6}};
    auto res = order(vecs);
    for(const auto& n:res)
    {
        std::cout<<n<<" ";
    }
}













