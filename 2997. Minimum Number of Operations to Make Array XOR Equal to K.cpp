class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int result = 0;
        for (const int num : nums)
            k ^= num;
        for (; k; k &= (k - 1))
            ++result;
        return result;
    }
};
