class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        while (!s.empty())
            s.pop();
        int index = 0, size = pushed.size();
        for (int i = 0; i < size; ++i)
        {
            s.push(pushed[i]);
            while (!s.empty())
                if (s.top() == popped[index])
                {
                    s.pop();
                    ++index;
                }
                else
                    break;
        }
        return s.empty();
    }
};
