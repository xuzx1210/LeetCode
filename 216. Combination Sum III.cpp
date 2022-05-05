class Solution
{
private:
    vector<vector<int>> result;
    vector<int> cur;
    void dfs(int index, int remain, int start)
    {
        if (index == 1)
        {
            if (remain > start && remain <= 9)
            {
                cur.push_back(remain);
                result.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        int upper_bound = (remain - (index * (index - 1) >> 1)) / index;
        for (int i = start + 1; i <= min(upper_bound, 9); ++i)
        {
            cur.push_back(i);
            dfs(index - 1, remain - i, i);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        result.clear();
        cur.clear();
        dfs(k, n, 0);
        return result;
    }
};
