class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long result = 0;
        int lastNotZero = nums.size();
        for (int i = lastNotZero - 1; i >= 0; --i)
            if (nums[i])
                lastNotZero = i;
            else
                result += (lastNotZero - i);
        return result;
    }
};
