class Solution
{
private:
    int diff;
    vector<int> result;
    void dfs(int index, int num)
    {
        if (!index)
        {
            result.emplace_back(num);
            return;
        }
        int last = num % 10;
        int next = last - diff;
        if (next >= 0)
            dfs(index - 1, num * 10 + next);
        if (!diff)
            return;
        next = last + diff;
        if (next <= 9)
            dfs(index - 1, num * 10 + next);
    }

public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        diff = k;
        result.clear();
        for (int i = 1; i <= 9; ++i)
            dfs(n - 1, i);
        return result;
    }
};
