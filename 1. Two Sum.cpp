class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> index;
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            int another = index[target - nums[i]];
            if (another)
                return {another - 1, i};
            index[nums[i]] = i + 1;
        }
        return {};
    }
};
