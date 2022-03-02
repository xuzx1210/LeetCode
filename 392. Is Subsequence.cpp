class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        while (!s.empty() && !t.empty())
        {
            if (s[0] == t[0])
                s.erase(s.begin());
            t.erase(t.begin());
        }
        return s.empty();
    }
};
