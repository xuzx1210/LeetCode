class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        int result = 0;
        const int size = arr.size();
        vector<int> dp{0};
        for (const string &word : arr)
        {
            int alphabet = 0, duplicate = 0;
            for (const char c : word)
            {
                const int mask = 1 << (c - 'a');
                duplicate |= alphabet & mask;
                alphabet |= mask;
            }
            if (duplicate)
                continue;
            for (int i = dp.size() - 1; i >= 0; --i)
            {
                if (dp[i] & alphabet)
                    continue;
                const int s = dp[i] | alphabet;
                dp.emplace_back(s);
                result = max(result, __popcount(s));
            }
        }
        return result;
    }
};
