class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int size = nums.size();
        int result = 0, tmp = 0;
        for (int i = 1; i <= size; ++i)
            tmp ^= i;
        for (int &num : nums)
            result ^= num;
        return result ^ tmp;
    }
};
