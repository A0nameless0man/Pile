#include <cstdio>
#include <vector>
#include <string>
class TireTree
{
private:
    struct node
    {
        node *childs[26] = {NULL};
        node *fail = NULL;
        int counter = 0;
    } root;

public:
    template <class StringVec = std::vector<std::string>>
    TireTree(StringVec vec,bool allowConflict = false);
    bool contains(std::string str);
    bool erase(std::string);
    bool insert(std::string);
};