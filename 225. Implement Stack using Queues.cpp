class MyStack
{
private:
    queue<int> s;

public:
    MyStack()
    {
        s = {};
    }
    void push(int x)
    {
        int size = s.size();
        s.push(x);
        for (int i = 0; i < size; ++i)
        {
            s.push(s.front());
            s.pop();
        }
    }
    int pop()
    {
        int result = s.front();
        s.pop();
        return result;
    }
    int top()
    {
        return s.front();
    }
    bool empty()
    {
        return s.empty();
    }
};
