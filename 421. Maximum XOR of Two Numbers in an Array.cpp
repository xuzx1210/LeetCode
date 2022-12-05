class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int result = 0, mask = 0;
        for (int i = 30; i >= 0; --i)
        {
            const int cur = 1 << i;
            mask |= cur;
            unordered_set<int> prefixes{};
            for (int &num : nums)
                prefixes.insert(num & mask);
            const int candidate = result | cur;
            for (int prefix : prefixes)
                if (prefixes.find(prefix ^ candidate) != prefixes.end())
                {
                    result = candidate;
                    break;
                }
        }
        return result;
    }
};
