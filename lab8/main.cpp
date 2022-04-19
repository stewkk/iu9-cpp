#include "int_stack.hpp"

int main()
{
    {
        IntStack<0, 5> test;
        test.push(2);
        test.push(3);
        std::cout << test.top() << ' ';
        test.pop();
        std::cout << test.top() << '\n';
    }
    {
        IntStack<0, 10000> test;
        test.push(300);
        test.push(400);
        std::cout << test.top() << ' ';
        test.pop();
        std::cout << test.top() << '\n';
    }
    {
        IntStack<0, 123456789> test;
        test.push(999999);
        test.push(88888888);
        std::cout << test.top() << ' ';
        test.pop();
        std::cout << test.top() << '\n';
    }
    return 0;
}

