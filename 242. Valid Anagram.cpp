class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        vector<int> counts(26, 0);
        for (const char c : s)
            ++counts[c - 'a'];
        for (const char c : t)
            --counts[c - 'a'];
        for (const int count : counts)
            if (count)
                return false;
        return true;
    }
};
