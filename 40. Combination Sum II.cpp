class Solution
{
public:
    vector<vector<int>> result;
    vector<int> cur;
    void dfs(vector<int> &candidates, int remain, int index)
    {
        if (remain == 0)
        {
            result.push_back(cur);
            return;
        }
        for (int i = index; i < candidates.size(); ++i)
        {
            if (index != i && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > remain)
                break;
            cur.push_back(candidates[i]);
            dfs(candidates, remain - candidates[i], i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        result.clear();
        cur.clear();
        dfs(candidates, target, 0);
        return result;
    }
};
