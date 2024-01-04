class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int result = 0;
        unordered_map<int, int> counter{};
        for (const int num : nums)
            ++counter[num];
        for (const auto &[num, cnt] : counter)
        {
            if (cnt == 1)
                return -1;
            const auto [quot, rem] = div(cnt, 3);
            result += quot;
            if (rem)
                ++result;
        }
        return result;
    }
};
