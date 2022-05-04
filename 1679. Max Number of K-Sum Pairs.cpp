class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int result = 0;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum < k)
                ++left;
            else if (sum > k)
                --right;
            else
            {
                ++left;
                --right;
                ++result;
            }
        }
        return result;
    }
};
