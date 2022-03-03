class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;
        vector<int> delta(nums.size() - 1, 0);
        for (int i = 0; i < nums.size() - 1; ++i)
            delta[i] = nums[i + 1] - nums[i];
        vector<int> count({});
        int left = 0, right = 1;
        for (; right < delta.size(); ++right)
        {
            if (delta[right] == delta[left])
                continue;
            count.push_back(right - left);
            left = right;
        }
        count.push_back(right - left);
        int result = 0;
        for (int i = 0; i < count.size(); ++i)
        {
            int n = count[i];
            result += ((n * (n - 1)) >> 1);
        }
        return result;
    }
};
