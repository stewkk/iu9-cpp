#ifndef LAB8_INT_STACK_HPP_
#define LAB8_INT_STACK_HPP_

#include <iostream>
#include <limits>
#include <stack>
#include <type_traits>

template <int L, int R,
    typename T = typename std::conditional<R - L <= std::numeric_limits<unsigned char>::max(),
        unsigned char,
        typename std::conditional<R - L <= std::numeric_limits<unsigned short>::max(),
            unsigned short,
            int>::type>::type>
class IntStack {
private:
    std::stack<T> stack;

public:
    void push(const int v);
    int top();
    void pop();
};

template <int L, int R, typename T>
void IntStack<L, R, T>::push(int v)
{
    stack.push(static_cast<T>(v - L));
}

template <int L, int R, typename T>
int IntStack<L, R, T>::top()
{
    return stack.top() + L;
}

template <int L, int R, typename T>
void IntStack<L, R, T>::pop()
{
    stack.pop();
}

template <int L, int R>
class IntStack<L, R, int> {
private:
    std::stack<int> stack;

public:
    void push(int v);
    int top();
    void pop();
};

template <int L, int R>
void IntStack<L, R, int>::push(int v)
{
    stack.push(v);
}

template <int L, int R>
void IntStack<L, R, int>::pop()
{
    stack.pop();
}

template <int L, int R>
int IntStack<L, R, int>::top()
{
    return stack.top();
}

#endif // LAB8_INT_STACK_HPP_

