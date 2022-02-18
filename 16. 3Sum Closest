class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int closet, m = INT_MAX;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int a = nums[i];
            for (int j = i + 1; j < nums.size() - 1; ++j)
            {
                int b = nums[j];
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    int sum = a + b + nums[k];
                    int diff = abs(sum - target);
                    if (diff < m)
                    {
                        closet = sum;
                        m = diff;
                    }
                }
            }
        }
        return closet;
    }
};
