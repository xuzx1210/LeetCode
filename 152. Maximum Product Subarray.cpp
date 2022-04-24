class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int result = nums[0];
        int localMin = result, localMax = result;
        int size = nums.size();
        for (int i = 1; i < size; ++i)
        {
            int cur = nums[i];
            if (cur < 0)
                swap(localMin, localMax);
            localMin = min(cur, localMin * cur);
            localMax = max(cur, localMax * cur);
            result = max(result, localMax);
        }
        return result;
    }
};
