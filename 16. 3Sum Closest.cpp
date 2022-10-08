class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int result = 100000, minDiff = 100000 - target, size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; ++i)
        {
            int left = i + 1, right = size - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                int diff;
                if (sum < target)
                {
                    diff = target - sum;
                    ++left;
                }
                else if (sum > target)
                {
                    diff = sum - target;
                    --right;
                }
                else
                    return target;
                if (diff < minDiff)
                {
                    result = sum;
                    minDiff = diff;
                }
            }
        }
        return result;
    }
};
