#include <cstdio>
#include <vector>
#include <array>
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
        int counter = 0;
    } root;
    bool allowConflict;
    Hasher hash;

public:
    TireTree(const StringVec &vec, bool allowConflict = false);
    ~TireTree();
    bool contains(const std::string &str);
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
        }
        current = next;
    }
    current->counter++;
    return true;
}
template <class Hasher, class StringVec>
bool TireTree<Hasher, StringVec>::contains(const std::string &str)
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