class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> counter(26, 0), result{};
        const int sLength = s.length(), pLength = p.length();
        for (char c : p)
            ++counter[c - 'a'];
        for (int start = 0, end = 0; end < sLength; ++end)
        {
            --counter[s[end] - 'a'];
            while (counter[s[end] - 'a'] < 0)
                ++counter[s[start++] - 'a'];
            if (end - start + 1 == pLength)
                result.emplace_back(start);
        }
        return result;
    }
};
