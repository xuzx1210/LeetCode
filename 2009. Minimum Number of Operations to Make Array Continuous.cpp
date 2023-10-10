class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        const int size = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        const int uniqueSize = nums.size();
        int left = 0, right = 0;
        for (; right < uniqueSize; ++right)
            if (nums[left] + size <= nums[right])
                ++left;
        return size - right + left;
    }
};
