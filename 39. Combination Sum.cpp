class Solution
{
public:
    vector<vector<int>> result;
    vector<int> cur;
    void dfs(vector<int> &candidates, int remain, int index)
    {
        if (remain < 0)
            return;
        if (remain == 0)
        {
            result.push_back(cur);
            return;
        }
        for (int i = index; i < candidates.size(); ++i)
        {
            cur.push_back(candidates[i]);
            dfs(candidates, remain - candidates[i], i);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        result.clear();
        cur.clear();
        dfs(candidates, target, 0);
        return result;
    }
};
