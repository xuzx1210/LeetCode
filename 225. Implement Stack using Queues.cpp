class MyStack
{
private:
    queue<int> myStack;

public:
    MyStack()
    {
        myStack = {};
    }
    void push(int x)
    {
        int size = myStack.size();
        myStack.emplace(x);
        while (size--)
            myStack.emplace(pop());
    }
    int pop()
    {
        const int result = myStack.front();
        myStack.pop();
        return result;
    }
    int top()
    {
        return myStack.front();
    }
    bool empty()
    {
        return myStack.empty();
    }
};
