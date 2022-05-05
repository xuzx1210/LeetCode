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
        queue<int> tmp = {};
        tmp.push(x);
        while (!s.empty())
        {
            tmp.push(s.front());
            s.pop();
        }
        s = tmp;
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
