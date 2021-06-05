#include <bits/stdc++.h>

using namespace std;
class Stack
{
    int *arr;
    int capacity;
    int top;

public:
    Stack(int capacity);

    void push(int x); //* BigO(1)
    int pop();
    int peek();
    int size();
    bool isEmpty();
};
int main()
{
    stack<int> s; //* stack is a LAST IN FIRST OUT LIFO DS is a CONTAINERS ADAPTER
    s.push(10);
    s.push(20);
    s.push(03);
    s.push(55);
    cout << s.size() << "\n";  //* this will O/P 4 as there are only 4 elem in stack
    cout << s.top() << "\n";   //* this gives the TOP MOST elem in the stack which is 55 for this case
    cout << s.empty() << "\n"; //* this is a bool value tells if the stack is empty or not 0 or 1

    while (s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

void Stack ::push(int x)
{
    top++;
    arr[top] = x;
}
int Stack ::pop()
{
    int pop_elem = arr[top];
    top--;
    return pop_elem;
}
int Stack ::peek()
{
    return arr[top];
}
int Stack ::size()
{
    return top + 1;
}
bool Stack ::isEmpty()
{
    return (top == -1);
}

Stack::Stack(int capacity)
{
    this->capacity = capacity;
    this->arr = new int(capacity);
    top = -1;
}
