void insertCorrect(stack<int> &s, int x)
{
    if(s.size()==0 || s.top()<x)
    {
        s.push(x);
    }
    else
    {
        int a= s.top();
        s.pop();
        insertCorrect(s,x);
        s.push(a);
    }
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty()) return;
    int temp= stack.top();
    stack.pop();
    sortStack(stack);
    insertCorrect(stack,temp);
}