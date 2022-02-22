class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int result = 1;
        for (auto num : nums)
            if (num == result)
                ++result;
        return result;
    }
};
