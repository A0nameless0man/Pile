#include <iostream>
const size_t MAX_N = 100007;
class Stack
{
private:
    char   data[MAX_N];
    size_t topPos;

public:
    Stack()
    {
        topPos = 0;
    }
    size_t size()
    {
        return topPos;
    }
    char top()
    {
        return data[topPos - 1];
    }
    void pop()
    {
        topPos--;
    }
    void push(char c)
    {
        data[topPos++] = c;
    }
};

int main(void)
{
    unsigned long long n;
    while(std::cin >> n)
    {
        auto  tmp = n;
        Stack stack;
        while(tmp)
        {
            char c = (((tmp % 16) > 9 ? 'a' - 10 : '0') + tmp % 16);
            stack.push(c);
            tmp /= 16;
        }
        std::cout << "Hex:";
        while(stack.size() != 0)
        {
            std::cout << stack.top() << " ";
            stack.pop();
        }
        std::cout << std::endl;
        tmp = n;
        while(tmp)
        {
            stack.push(tmp % 10 + '0');
            tmp /= 10;
        }
        std::cout << "Dec:";
        while(stack.size() != 0)
        {
            std::cout << stack.top() << " ";
            stack.pop();
        }
        std::cout << std::endl;
        tmp = n;
        while(tmp)
        {
            stack.push(tmp % 8 + '0');
            tmp /= 8;
        }
        std::cout << "Oct:";
        while(stack.size() != 0)
        {
            std::cout << stack.top() << " ";
            stack.pop();
        }
        std::cout << std::endl;
        tmp = n;
        while(tmp)
        {
            stack.push(tmp % 2 + '0');
            tmp /= 2;
        }
        std::cout << "Bin:";
        while(stack.size() != 0)
        {
            std::cout << stack.top() << " ";
            stack.pop();
        }
        std::cout << std::endl;
        tmp        = n;
        bool match = true;
        while(tmp)
        {
            stack.push(tmp % 10);
            tmp /= 10;
        }
        while(n)
        {
            if(match && ((n % 10) == stack.top()))
            {
                stack.pop();
                n /= 10;
            }
            else
            {
                match = false;
                break;
            }
        }
        if(match)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }
    return 0;
}