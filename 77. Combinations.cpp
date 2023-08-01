class Solution
{
private:
    vector<vector<int>> result;
    vector<int> combination;
    int n;
    void dfs(const int index, const int remain)
    {
        if (remain == 0)
        {
            result.emplace_back(combination);
            return;
        }
        if (index + remain > n)
            return;
        combination.emplace_back(index + 1);
        dfs(index + 1, remain - 1);
        combination.pop_back();
        dfs(index + 1, remain);
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        result.clear();
        this->n = n;
        dfs(0, k);
        return result;
    }
};
