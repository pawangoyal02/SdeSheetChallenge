/*
POP Func-
1) Push element to Q2.
2) While Q1 is not empty, push Q1 top to Q2 and poop from Q1.
3) Swap Q1 & Q2.
*/

void push
{
    Q2.push(x);
    while(!Q1.empty())
    {
        Q2.push(Q1.front());
        Q1.pop();
    }
    swap(Q1,Q2);
}

void pop()
{
    Q1.pop();
}

int top()
{
    return Q1.front();
}