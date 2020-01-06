#define _CRT_SECURE_NO_WARNINGS
#include <array>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
const char MIN_C = 'a';
const char MAX_C = 'z';
class standLowerCaseCharHasher
{
private:
public:
    const static size_t RANGE;
    inline size_t       operator()(char c) const
    {
        return c - 'a';
    }
};
const size_t standLowerCaseCharHasher::RANGE = 26;
template <class Hasher = standLowerCaseCharHasher, class StringVec = std::vector<std::string> >
struct node
{
    std::array<node *, Hasher::RANGE> next    = { NULL };
    node *                            fail    = NULL;
    node *                            parent  = NULL;
    size_t                            counter = 0;
    size_t                            id      = -1;
};
struct ACmachineMatchRes
{
    size_t endPos;
    size_t id;
    size_t count;
};
template <class Hasher = standLowerCaseCharHasher, class StringVec = std::vector<std::string> >
class ACmachine
{
private:
    mutable node<Hasher, StringVec> root;
    bool                            allowConflict;
    Hasher                          hash;

public:
    ACmachine(const StringVec &vec = {}, bool allowConflict = false);
    ~ACmachine();
    bool                           contains(const std::string &str) const;
    bool                           erase(const std::string &str);
    bool                           insert(const std::string &str, size_t id = 0);
    bool                           buildFailTree();
    bool                           removeFailTree();
    std::vector<ACmachineMatchRes> match(const std::string &str);
};
template <class Hasher, class StringVec>
ACmachine<Hasher, StringVec>::ACmachine(const StringVec &vec, bool allowConflict):
    allowConflict(allowConflict)
{
    size_t i = 0;
    for(auto s: vec)
    {
        insert(s, i++);
    }
}
template <class Hasher, class StringVec>
bool ACmachine<Hasher, StringVec>::insert(const std::string &str, size_t id)
{
    if(!allowConflict && contains(str))
    {
        return false;
    }
    node<Hasher, StringVec> *current = &root;
    for(auto c: str)
    {
        size_t                    index = hash(c);
        node<Hasher, StringVec> *&next  = current->next[index];
        if(next == NULL)
        {
            next         = new node<Hasher, StringVec>;
            next->parent = current;
        }
        current = next;
    }
    current->counter++;
    current->id = id;
    return true;
}
template <class Hasher, class StringVec>
bool ACmachine<Hasher, StringVec>::contains(const std::string &str) const
{
    node<Hasher, StringVec> *current = &root;
    for(auto c: str)
    {
        size_t                    index = hash(c);
        node<Hasher, StringVec> *&next  = current->next[index];
        if(next == NULL)
        {
            return false;
        }
        current = next;
    }
    return current->counter != 0;
}
template <class Hasher, class StringVec>
bool ACmachine<Hasher, StringVec>::erase(const std::string &str)
{
    node<Hasher, StringVec> *current = &root;
    for(auto c: str)
    {
        size_t                    index = hash(c);
        node<Hasher, StringVec> *&next  = current->next[(hash(c))];
        if(next == NULL)
        {
            return false;
        }
        current = next;
    }
    if(current->counter != 0)
    {
        --(current->counter);
        return true;
    }
    else
    {
        return false;
    }
}

template <class Hasher, class StringVec>
ACmachine<Hasher, StringVec>::~ACmachine()
{
    std::stack<node<Hasher, StringVec> *> stack;
    for(size_t i = 0; i < Hasher::RANGE; i++)
    {
        if(root.next[i] != NULL)
        {
            stack.push(root.next[i]);
        }
    }
    while(!stack.empty())
    {
        node<Hasher, StringVec> *c = stack.top();
        stack.pop();
        for(size_t i = 0; i < Hasher::RANGE; i++)
        {
            if(c->next[i] != NULL)
            {
                stack.push(c->next[i]);
            }
        }
        delete c;
    }
}
template <class Hasher, class StringVec>
bool ACmachine<Hasher, StringVec>::removeFailTree()
{
    if(root.fail == NULL)
    {
        return false;
    }
    else
    {
        root.fail = NULL;
    }
    std::stack<node<Hasher, StringVec> *> stack;
    for(size_t i = 0; i < Hasher::RANGE; i++)
    {
        if(root.next[i] != NULL)
        {
            stack.push(root.next[i]);
        }
    }
    while(!stack.empty())
    {
        node<Hasher, StringVec> *c = stack.top();
        stack.pop();
        for(size_t i = 0; i < Hasher::RANGE; i++)
        {
            if(c->next[i] != NULL)
            {
                stack.push(c->next[i]);
            }
        }
        // delete c;
        c->fail = NULL;
    }
    return true;
}

template <class Hasher, class StringVec>
bool ACmachine<Hasher, StringVec>::buildFailTree()
{
    removeFailTree();
    root.fail = &root;
    std::queue<node<Hasher, StringVec> *> que;
    que.push(&root);
    // std::cout<<&root<<"--fail-->"<<root.fail<<std::endl;
    while(!que.empty())
    {
        node<Hasher, StringVec> *cur = que.front();  // build cur's child's fail
        que.pop();
        for(size_t i = 0; i < Hasher::RANGE; i++)
        {
            if(cur->next[i] != NULL)  // I have this child
            {
                node<Hasher, StringVec> *fail = cur->fail;  // my fail ptr
                do
                {
                    if(fail->next[i] != NULL)
                    {
                        if(fail != cur)
                            fail = fail->next[i];
                        break;
                    }
                    else
                    {
                        fail = fail->fail;
                    }

                } while(fail != &root);
                cur->next[i]->fail = fail;
                // std::cout<<cur->next[i]<<"--fail-->"<<cur->next[i]->fail<<std::endl;
                // std::cout<<cur<<"--chile"<<char('a'+i)<<"-->"<<cur->next[i]<<std::endl;
                que.push(cur->next[i]);
            }
        }
    }
    return true;
}
template <class Hasher, class StringVec>
std::vector<ACmachineMatchRes> ACmachine<Hasher, StringVec>::match(const std::string &str)
{
    if(root.fail == NULL)
        buildFailTree();
    std::vector<ACmachineMatchRes> res;
    size_t                         pos = 0;
    // size_t step = 0;//"<<step++<<"
    node<Hasher, StringVec> *cur = &root;
    while(pos < str.size())
    {
        // std::cout<<"Debug:"<<std::endl;
        // std::cout<<"Pos:\t"<<pos<<" "<<str[pos]<<std::endl;
        // std::cout<<"Id:\t"<<cur->id<<std::endl;
        // std::cout<<"Cur:\t"<<cur<<std::endl;
        // std::cout<<cur<<"--fail-->"<<cur->fail<<std::endl;

        // std::cout<<"Fail:\t"<<cur->fail<<std::endl;;

        if(cur->next[hash(str[pos])] != NULL)
        {
            // std::cout<<cur<<"-."<<step++<<"match'"<<str[pos]<<"'.->"<<cur->next[hash(str[pos])]<<std::endl;
            cur = cur->next[hash(str[pos])];
            pos++;
            // cur = cur->next[hash(str[pos])];
            // std::cout<<"Match:\t"<<cur<<std::endl;;
        }
        else
        {
            // std::cout<<cur<<"-."<<step++<<"fail'"<<str[pos]<<"'.->"<<cur->fail<<std::endl;
            if(cur != &root)
                cur = cur->fail;
            else
                pos++;
        }
        if(cur->counter)
            res.push_back({ pos, cur->id, cur->counter });
        // std::cout<<std::endl;
    }
    return res;
}
char buf[2000007];
bool flag[2000007];
int  n, m;
int  main(void)
{
    scanf("%d%d", &n, &m);
    // std::vector<std::string> c;
    ACmachine           mac;
    std::vector<size_t> lens;
    int                 i = 0;
    while(n--)
    {
        scanf("%s", buf);
        mac.insert(std::string(buf), i++);
        lens.push_back(strlen(buf));
    }
    while(m--)
    {
        scanf("%s", buf);
        std::string f(buf);
        // auto res = mac.match(std::string(buf));
        // size_t ans = 0;
        int ans = 0;
        int len = f.length();
        // std::set<size_t> set;
        // set.insert(0);
        for(int pos = 0; pos < len; pos++)
            flag[pos] = false;
        flag[0] = true;
        std::priority_queue<int, std::vector<int>, std::greater<int> > q;
        q.push(0);
        for(int pos = 0; pos < len; pos++)
        // while(!q.empty())
        {
            if(!flag[pos])
            {
                continue;
            }
            // int pos = q.top();
            // q.pop();
            // while(q.top()==pos)
            // {
            //     q.pop();
            // }
            // if(flag[pos])
            {
                // bool update = false;
                // for(int i = 0;i<=10&&i+pos<=len;i++)
                // {

                //     //std::cout<<f.substr(pos,i)<<std::endl;
                //     if(mac.contains(f.substr(pos,i)))
                //     {
                //         //update = flag[pos+i]=true;
                //         q.push(pos+i);
                //         if(pos+i>ans)
                //             ans = pos+i;
                //     }
                // }
                // if(!update)break;
                auto res = mac.match(f.substr(pos, 10));
                for(auto r: res)
                {
                    if(r.endPos == lens[r.id])
                    {

                        flag[pos + r.endPos] = true;
                        if(pos + r.endPos > ans)
                            ans = pos + r.endPos;
                    }
                }
            }
        }
        // for(auto i :set)
        // {
        //     std::cout<<i<<std::endl;
        // }
        // for(auto r:res)
        // {
        //     std::cout<<r.id<<" "<<r.endPos<<std::endl;
        //     if(set.find(r.endPos-lens[r.id])!=set.end())
        //     {
        //         set.insert(r.endPos);
        //         pos = r.endPos;
        //     }
        // }
        printf("%d\n", ans);
    }
    return 0;
}