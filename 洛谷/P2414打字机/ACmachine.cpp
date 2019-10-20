#include <cstdio>
#include <iostream>
#include <vector>
#include <array>
#include <stack>
#include <string>
const char MIN_C = 'a';
const char MAX_C = 'z';
class standLowerCaseCharHasher
{
private:
public:
    const static size_t RANGE;
    inline size_t operator()(char c)
    {
        return c - 'a';
    }
};
const size_t standLowerCaseCharHasher::RANGE = 26;

template <class Hasher = standLowerCaseCharHasher, class StringVec = std::vector<std::string &>>
class TireTree
{
private:
    struct node
    {
        std::array<node *, Hasher::RANGE> next = {NULL};
        node *fail = NULL;
        node *parent = NULL;
        int counter = 0;
    } root;
    bool allowConflict;
    Hasher hash;

public:
    TireTree(const StringVec &vec = {}, bool allowConflict = false);
    ~TireTree();
    bool contains(const std::string &str)const;
    bool erase(const std::string &str);
    bool insert(const std::string &str);
};
template <class Hasher, class StringVec>
TireTree<Hasher, StringVec>::TireTree(const StringVec &vec, bool allowConflict) : allowConflict(allowConflict)
{
    for (auto s : vec)
    {
        insert(s);
    }
}
template <class Hasher, class StringVec>
bool TireTree<Hasher, StringVec>::insert(const std::string &str)
{
    if (!allowConflict && contains(str))
    {
        return false;
    }
    node *current = &root;
    for (auto c : str)
    {
        size_t index = hash(c);
        node *&next = current->next[(hash(c))];
        if (next == NULL)
        {
            next = new node;
            next->parent = current;
        }
        current = next;
    }
    current->counter++;
    return true;
}
template <class Hasher, class StringVec>
bool TireTree<Hasher, StringVec>::contains(const std::string &str)const
{
    node *current = &root;
    for (auto c : str)
    {
        size_t index = hash(c);
        node *&next = current->next[(hash(c))];
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
    node *current = &root;
    for (auto c : str)
    {
        size_t index = hash(c);
        node *&next = current->next[(hash(c))];
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
    std::stack<node *> stack;
    for (size_t i = 0; i < Hasher::RANGE; i++)
    {
        if (root.next[i] != NULL)
        {
            stack.push(root.next[i]);
        }
    }
    while (!stack.empty())
    {
        node *c = stack.top();
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

template <class Hasher = standLowerCaseCharHasher, class StringVec = std::vector<std::string &>>
class ACmachine: public TireTree<Hasher,StringVec>;
{
public:
ACmachine(const StringVec &vec = {}, bool allowConflict = false);
bool buildFailTree();
}
template <class Hasher = standLowerCaseCharHasher, class StringVec = std::vector<std::string &>>
ACmachine

int main(void)
{
    TireTree tree(std::vector<std::string>({"a", "abc", "cde"}));
    std::cout << tree.contains("nams") << std::endl;
    std::cout << tree.contains("ab") << std::endl;
    std::cout << tree.contains("abc") << std::endl;
    return 0;
}