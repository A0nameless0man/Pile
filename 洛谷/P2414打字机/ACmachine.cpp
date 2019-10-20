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
    size_t id;
};
template <class Hasher = standLowerCaseCharHasher, class StringVec = std::vector<std::string &>>
class TireTree
{
public:
    mutable node<Hasher, StringVec> root;
    bool allowConflict;
    Hasher hash;

public:
    TireTree(const StringVec &vec = {}, bool allowConflict = false);
    ~TireTree();
    bool contains(const std::string &str) const;
    bool erase(const std::string &str);
    bool insert(const std::string &str, size_t id = 0);
};
template <class Hasher, class StringVec>
TireTree<Hasher, StringVec>::TireTree(const StringVec &vec, bool allowConflict) : allowConflict(allowConflict)
{
    size_t i = 0;
    for (auto s : vec)
    {
        insert(s, i++);
    }
}
template <class Hasher, class StringVec>
bool TireTree<Hasher, StringVec>::insert(const std::string &str, size_t id)
{
    if (!allowConflict && contains(str))
    {
        return false;
    }
    node<Hasher, StringVec> *current = &root;
    for (auto c : str)
    {
        size_t index = hash(c);
        node<Hasher, StringVec> *&next = current->next[(hash(c))];
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
bool TireTree<Hasher, StringVec>::contains(const std::string &str) const
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
    return current->counter != 0;
}
template <class Hasher, class StringVec>
bool TireTree<Hasher, StringVec>::erase(const std::string &str)
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
TireTree<Hasher, StringVec>::~TireTree()
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

struct ACmachineMatchRes
{
    size_t endPos;
    size_t id;
};

template <class Hasher = standLowerCaseCharHasher, class StringVec = std::vector<std::string &>>
class ACmachine : public TireTree<Hasher, StringVec>
{
public:
    ACmachine(const StringVec &vec = {}, bool allowConflict = false);
    bool buildFailTree();
    bool removeFailTree();
    std::vector<ACmachineMatchRes> match(const std::string &str);
};
template <class Hasher, class StringVec>
ACmachine<Hasher, StringVec>::ACmachine(const StringVec &vec, bool allowConflict) : TireTree<Hasher, StringVec>(vec, allowConflict)
{
    buildFailTree();
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
        c.fail = NULL;
    }
    return true;
}

template <class Hasher, class StringVec>
bool ACmachine<Hasher, StringVec>::buildFailTree()
{
    removeFailTree();
    TireTree<Hasher, StringVec>::root.fail = &TireTree<Hasher, StringVec>::root;
    std::queue<node<Hasher, StringVec> *> que;
    que.push(&TireTree<Hasher, StringVec>::root);
    while (!que.empty())
    {
        node<Hasher, StringVec> *cur = que.top(); //build cur's child's fail
        que.pop();
        for (size_t i = 0; i < Hasher::RANGE; i++)
        {
            if (cur->next[i] != NULL)
            {
                node<Hasher, StringVec> fail = cur->fail;
                do
                {
                    if (fail.next[i] != NULL)
                    {
                        fail = fail.next[i];
                        break;
                    }
                    else
                    {
                        fail = fail.fail;
                    }

                } while (fail != &TireTree<Hasher, StringVec>::root);
                cur->next[i].fail = fail;
            }
        }
    }
    return true;
}
template <class Hasher, class StringVec>
std::vector<ACmachineMatchRes> ACmachine<Hasher, StringVec>::match(const std::string &str)
{
    if (TireTree<Hasher, StringVec>::root.fail == NULL)
        buildFailTree();
    std::vector<ACmachineMatchRes> res;
    size_t pos = 0;
    node<Hasher, StringVec> *cur = &TireTree<Hasher, StringVec>::root;
    while (pos < str.size())
    {
        if (cur->counter)
            res.push_back({pos, cur->id});
        if (cur->next[hash(str[pos])] != NULL)
        {
            pos++;
            cur = cur->next[hash(str[pos])];
        }
        else
        {
            if (cur == &TireTree<Hasher, StringVec>::root)
            {
                pos++;
            }
            else
            {
                cur = cur->fail;
            }
        }
    }
}
int main(void)
{
    std::vector<std::string>
        testCase =
            {
                "abcdefghijk",
                "abcd",
                "efg"
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
                "asvdjsakvrnlawneifnwjeanvfanvjfwanevawegvnwanvejfvwav"};
    ACmachine tree(testCase);auto res = tree.match(checkCaseC[0]);
    for(auto c:res)
    {
        std::cout<<c.endPos<<" "<<c.id<<std::endl;
    }
    return 0;
}