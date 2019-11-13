#include <iostream>
const size_t MAX_N = 100007;
class Stack
{
private:
    char data[MAX_N];
    size_t topPos;
public:
    Stack()
    {
        topPos = 0;
    }
    size_t size() { return topPos; }
    char top() { return data[topPos]; }
    void pop() { topPos--; }
    void push(char c) { data[topPos++] = c; }
};

int main(void)
{
    unsigned long long n;
    while(std::cin>>n)
    {
        
    }
}