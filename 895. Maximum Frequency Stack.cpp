class FreqStack
{
public:
    unordered_map<int, int> frequency;
    unordered_map<int, stack<int>> group;
    int maxFrequency;
    FreqStack()
    {
        frequency.clear();
        group.clear();
        maxFrequency = 0;
    }
    void push(int val)
    {
        int f = ++frequency[val];
        maxFrequency = max(maxFrequency, f);
        group[f].push(val);
    }
    int pop()
    {
        auto &maxGroup = group[maxFrequency];
        int result = maxGroup.top();
        maxGroup.pop();
        --frequency[result];
        if (group[maxFrequency].empty())
            --maxFrequency;
        return result;
    }
};
