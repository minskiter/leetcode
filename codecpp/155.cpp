#include "header.h"

class MinStack
{
private:
    stack<int> _min;
    stack<int> _stack;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        if (_min.size() == 0 || x <= _min.top())
            _min.push(x);
        _stack.push(x);
    }

    void pop()
    {
        if (_min.top() == _stack.top())
            _min.pop();
        _stack.pop();
    }

    int top()
    {
        return _stack.top();
    }

    int getMin()
    {
        return _min.top();
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin();
    minStack.pop();
    cout << minStack.top();
    cout << minStack.getMin();

    return 0;
}