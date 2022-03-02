class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, tLength = t.length();
        for (int j = 0; j < tLength; ++j)
            if (s[i] == t[j])
                ++i;
        return i == s.length();
    }
};
