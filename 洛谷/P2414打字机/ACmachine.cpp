#include <cstdio>
#include <iostream>
#include <vector>
#include <array>
#include <stack>
#include <queue>
#include <string>
const char MIN_C = 'a';
const char MAX_C = 'z';
class standLowerCaseCharHasher
{
private:
public:
    const static size_t RANGE;
    inline size_t operator()(char c)const
    {
        return c - 'a';
    }
};
const size_t standLowerCaseCharHasher::RANGE = 26;
template <class Hasher = standLowerCaseCharHasher, class StringVec = std::vector<std::string &>>
struct node
{
    std::array<node *, Hasher::RANGE> next = {NULL};
    node *fail = NULL;
    node *parent = NULL;
    size_t counter = 0;
    size_t id = -1;
};
struct ACmachineMatchRes
{
    size_t endPos;
    size_t id;
};
template <class Hasher = standLowerCaseCharHasher, class StringVec = std::vector<std::string &>>
class ACmachine
{
private:
    mutable node<Hasher, StringVec> root;
    bool allowConflict;
    Hasher hash;
public:
    ACmachine(const StringVec &vec = {}, bool allowConflict = false);
    ~ACmachine();
    bool contains(const std::string &str) const;
    bool erase(const std::string &str);
    bool insert(const std::string &str, size_t id = 0);
    bool buildFailTree();
    bool removeFailTree();
    std::vector<ACmachineMatchRes> match(const std::string &str);
};
template <class Hasher, class StringVec>
ACmachine<Hasher, StringVec>::ACmachine(const StringVec &vec, bool allowConflict) : allowConflict(allowConflict)
{
    size_t i = 0;
    for (auto s : vec)
    {
        insert(s, i++);
    }
}
template <class Hasher, class StringVec>
bool ACmachine<Hasher, StringVec>::insert(const std::string &str, size_t id)
{
    if (!allowConflict && contains(str))
    {
        return false;
    }
    node<Hasher, StringVec> *current = &root;
    for (auto c : str)
    {
        size_t index = hash(c);
        node<Hasher, StringVec> *&next = current->next[index];
        if (next == NULL)
        {
            next = new node<Hasher, StringVec>;
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
    for (auto c : str)
    {
        size_t index = hash(c);
        node<Hasher, StringVec> *&next = current->next[index];
        if (next == NULL)
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
    for (auto c : str)
    {
        size_t index = hash(c);
        node<Hasher, StringVec> *&next = current->next[(hash(c))];
        if (next == NULL)
        {
            return false;
        }
        current = next;
    }
    if (current->counter != 0)
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
    for (size_t i = 0; i < Hasher::RANGE; i++)
    {
        if (root.next[i] != NULL)
        {
            stack.push(root.next[i]);
        }
    }
    while (!stack.empty())
    {
        node<Hasher, StringVec> *c = stack.top();
        stack.pop();
        for (size_t i = 0; i < Hasher::RANGE; i++)
        {
            if (c->next[i] != NULL)
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
    if (root.fail == NULL)
    {
        return false;
    }
    else
    {
        root.fail = NULL;
    }
    std::stack<node<Hasher, StringVec> *> stack;
    for (size_t i = 0; i < Hasher::RANGE; i++)
    {
        if (root.next[i] != NULL)
        {
            stack.push(root.next[i]);
        }
    }
    while (!stack.empty())
    {
        node<Hasher, StringVec> *c = stack.top();
        stack.pop();
        for (size_t i = 0; i < Hasher::RANGE; i++)
        {
            if (c->next[i] != NULL)
            {
                stack.push(c->next[i]);
            }
        }
        //delete c;
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
    //std::cout<<&root<<"--fail-->"<<root.fail<<std::endl;
    while (!que.empty())
    {
        node<Hasher, StringVec> *cur = que.front(); //build cur's child's fail
        que.pop();
        for (size_t i = 0; i < Hasher::RANGE; i++)
        {
            if (cur->next[i] != NULL)//I have this child
            {
                node<Hasher, StringVec> *fail = cur->fail;//my fail ptr
                do
                {
                    if (fail->next[i] != NULL)
                    {
                        if(fail!=cur)
                            fail = fail->next[i];
                        break;
                    }
                    else
                    {
                        fail = fail->fail;
                    }

                }while (fail != &root);
                cur->next[i]->fail = fail;
                //std::cout<<cur->next[i]<<"--fail-->"<<cur->next[i]->fail<<std::endl;
                //std::cout<<cur<<"--chile"<<i<<"-->"<<cur->next[i]<<std::endl;
                que.push(cur->next[i]);
            }
        }
    }
    return true;
}
template <class Hasher, class StringVec>
std::vector<ACmachineMatchRes> ACmachine<Hasher, StringVec>::match(const std::string &str)
{
    if (root.fail == NULL)
        buildFailTree();
    std::vector<ACmachineMatchRes> res;
    size_t pos = 0;
    size_t step = 0;//"<<step++<<"
    node<Hasher, StringVec> *cur = &root;
    while (pos < str.size())
    {
        // std::cout<<"Debug:"<<std::endl;
        // std::cout<<"Pos:\t"<<pos<<" "<<str[pos]<<std::endl;
        // std::cout<<"Id:\t"<<cur->id<<std::endl;
        // std::cout<<"Cur:\t"<<cur<<std::endl;
        //std::cout<<cur<<"--fail-->"<<cur->fail<<std::endl;

        // std::cout<<"Fail:\t"<<cur->fail<<std::endl;;
        
        if (cur->counter)
            res.push_back({pos, cur->id});
        if (cur->next[hash(str[pos])] != NULL)
        {
            //std::cout<<cur<<"-."<<step++<<"match'"<<str[pos]<<"'.->"<<cur->next[hash(str[pos])]<<std::endl;
            cur = cur->next[hash(str[pos])];
            pos++;
            //cur = cur->next[hash(str[pos])];
            //std::cout<<"Match:\t"<<cur<<std::endl;;
        }
        else
        {
            //std::cout<<cur<<"-."<<step++<<"fail'"<<str[pos]<<"'.->"<<cur->fail<<std::endl;
            if(cur!=&root)
                cur = cur->fail;
            else
                pos++;
        }
        //std::cout<<std::endl;
    }
    return res;
}
int main(void)
{
    std::vector<std::string>
        testCase =
            {
                "abcdef",
                "abcd",
                "efg",
                "cdefg"},
        checkCaseA = testCase,
        checkCaseB =
            {
                "acdefg",
                "asdcadccssac",
                "cabcabdacbabdcbabdbcadfefgefgefde"
                "nams"},
        checkCaseC =
            {
                "abcdefgzefgzcdefg"
            };
    ACmachine tree(testCase);
    //std::cout<<"built"<<std::endl;
    auto res = tree.match(checkCaseC[0]);
    for(auto c:res)
    {
        std::cout<<c.endPos<<" "<<c.id<<std::endl;
    }
    return 0;
}