class Solution
{
private:
    unordered_map<int, int> counter;
    size_t size;
    vector<vector<int>> result;
    vector<int> cur;
    void dfs(size_t index)
    {
        if (index == size)
        {
            result.push_back(cur);
            return;
        }
        for (auto &n : counter)
            if (n.second)
            {
                --n.second;
                cur.push_back(n.first);
                dfs(index + 1);
                cur.pop_back();
                ++n.second;
            }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        size = nums.size();
        result.clear();
        cur.clear();
        counter.clear();
        for (int num : nums)
            ++counter[num];
        dfs(0);
        return result;
    }
};
