class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int result = 0;
        for (long range = 1, index = 0; range <= n;)
            if (index < nums.size() && nums[index] <= range)
                range += nums[index++];
            else
            {
                range <<= 1;
                ++result;
            }
        return result;
    }
};
