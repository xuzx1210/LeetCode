class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        const int size = nums.size();
        int remain = 1, left = 0;
        for (int right = 0; right < size; ++right)
        {
            if (nums[right] == 0)
                --remain;
            if (remain < 0 && nums[left++] == 0)
                ++remain;
        }
        return size - left - 1;
    }
};
