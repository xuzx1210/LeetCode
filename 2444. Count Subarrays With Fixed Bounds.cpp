class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long result = 0;
        const int size = nums.size();
        int outside = -1, minimum = -1, maximum = -1; // index
        for (int i = 0; i < size; ++i)
        {
            if (nums[i] < minK || maxK < nums[i])
                outside = i;
            if (nums[i] == minK)
                minimum = i;
            if (nums[i] == maxK)
                maximum = i;
            result += max(0, min(minimum, maximum) - outside);
        }
        return result;
    }
};
