#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
struct Node
{
    Node *l;
    Node *r;
    char  val;
    int   weight;
};
int main(void)
{
    std::string s;
    while(std::cout << "请输入要编码的字符串" << std::endl, std::cin >> s)
    {
        std::map<char, int> weightMap;
        for(auto &c: s)
        {
            weightMap[c]++;
        }
        auto cmp = [](Node *a, Node *b) -> bool {
            return a->weight > b->weight;
        };
        std::priority_queue<Node *, std::vector<Node *>, decltype(cmp)> que(cmp);
        for(auto &iter: weightMap)
        {
            std::cout << iter.first << "出现了" << iter.second << "次" << std::endl;
            que.push(new Node({ NULL, NULL, iter.first, iter.second }));
        }
        while(que.size() > 1)
        {
            auto a = que.top();
            que.pop();
            auto b = que.top();
            que.pop();
            que.push(new Node({ a, b, '\0', a->weight + b->weight }));
        }
        auto Hoffman_Tree = que.top();
        que.pop();
        std::map<std::string, char>                decodeMap;
        std::map<char, std::string>                encodeMap;
        std::stack<std::pair<Node *, std::string>> stc;
        stc.push({ Hoffman_Tree, "" });
        while(!stc.empty())
        {
            auto iter = stc.top();
            stc.pop();
            if(iter.first->val != '\0')
            {
                decodeMap[iter.second] = iter.first->val;
            }
            else
            {
                stc.push({ iter.first->l, iter.second + "0" });
                stc.push({ iter.first->r, iter.second + "1" });
            }
        }
        std::cout << "编码" << std::endl;
        for(auto &[s, c]: decodeMap)
        {
            encodeMap[c] = s;
            std::cout << s << ":" << c << std::endl;
        }
        std::cout << "编码结果" << std::endl;
        for(auto &c: s)
        {
            std::cout << encodeMap[c] << " ";
        }
        std::cout << std::endl;
        std::string toBedDecode;
        if(std::cout << "请输入想要解码的序列" << std::endl, std::cin >> toBedDecode)
        {
            auto cur = Hoffman_Tree;
            try
            {
                for(auto &c: toBedDecode)
                {
                    switch(c)
                    {
                        case '1':
                            cur = cur->r;
                            break;
                        case '0':
                            cur = cur->l;
                            break;
                        default:
                            cur = Hoffman_Tree;
                            throw std::invalid_argument("非法输入");
                            break;
                    }
                    if(cur->val != '\0')
                    {
                        std::cout << cur->val;
                        cur = Hoffman_Tree;
                    }
                }
            }
            catch(const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}