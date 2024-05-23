class Solution
{
private:
    int k;
    unordered_map<int, int> counter;
    int dfs(int index, const vector<int> &nums)
    {
        if (index == 0)
            return 1;
        --index;
        int result = dfs(index, nums);
        const int num = nums[index];
        if (!counter[num - k] && !counter[num + k])
        {
            ++counter[num];
            result += dfs(index, nums);
            --counter[num];
        }
        return result;
    }

public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        this->k = k;
        counter.clear();
        return dfs(nums.size(), nums) - 1;
    }
};
