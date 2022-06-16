class MyQueue
{
private:
    stack<int> q;

public:
    MyQueue()
    {
        q = {};
    }
    void push(int x)
    {
        stack<int> tmp = {};
        while (!q.empty())
        {
            tmp.push(q.top());
            q.pop();
        }
        q.push(x);
        while (!tmp.empty())
        {
            q.push(tmp.top());
            tmp.pop();
        }
    }
    int pop()
    {
        int result = q.top();
        q.pop();
        return result;
    }
    int peek()
    {
        return q.top();
    }
    bool empty()
    {
        return q.empty();
    }
};
