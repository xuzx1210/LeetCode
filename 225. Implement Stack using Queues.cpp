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
        s.push(x);
    }

    int pop()
    {
        queue<int> tmp = {};
        int size = s.size();
        for (int i = 0; i < size - 1; ++i)
        {
            tmp.push(s.front());
            s.pop();
        }
        int result = s.front();
        s = tmp;
        return result;
    }
    int top()
    {
        int result = pop();
        s.push(result);
        return result;
    }
    bool empty()
    {
        return s.empty();
    }
};
