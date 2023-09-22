class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        const int sLength = s.length(), tLength = t.length();
        int i = 0;
        for (int j = 0; i < sLength && j < tLength; ++j)
            if (s[i] == t[j])
                ++i;
        return i == sLength;
    }
};
