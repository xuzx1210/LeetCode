class Solution
{
public:
    int jump(vector<int> &nums)
    {
        const int n = nums.size();
        int result = 0;
        for (int i = 0, end = 0, far = 0; i < n - 1; ++i)
        {
            far = max(far, i + nums[i]);
            if (i == end)
            {
                ++result;
                end = far;
            }
        }
        return result;
    }
};
