class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int result = 0;
        vector<int> counter(100, 0);
        for (const int num : nums)
            ++counter[num - 1];
        for (int i = 0; i < 100; ++i)
            result += (counter[i] * (counter[i] - 1) >> 1);
        return result;
    }
};
