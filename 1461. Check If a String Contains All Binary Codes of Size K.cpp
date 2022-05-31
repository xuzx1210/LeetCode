class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        unordered_map<string, int> substrings = {};
        for (int end = k; end <= s.length(); ++end)
            substrings[string(s, end - k, k)] = 0;
        return substrings.size() == (1 << k);
    }
};
