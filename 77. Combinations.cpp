class Solution
{
public:
    vector<int> numStack;
    vector<vector<int>> result;
    int range;
    void dfs(int index, int remain)
    {
        if (remain == 0)
        {
            result.push_back(numStack);
            return;
        }
        for (int i = index; i <= range - remain; ++i)
        {
            numStack.push_back(i + 1);
            dfs(i + 1, remain - 1);
            numStack.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        range = n;
        numStack.clear();
        result.clear();
        dfs(0, k);
        return result;
    }
};
