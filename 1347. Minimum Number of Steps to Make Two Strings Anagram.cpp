class Solution
{
public:
    int minSteps(string s, string t)
    {
        int result = 0;
        vector<int> count(26, 0);
        for (const char c : s)
            ++count[c - 'a'];
        for (const char c : t)
            --count[c - 'a'];
        for (int i = 0; i < 26; ++i)
            result += (0 < count[i]) * count[i] - (count[i] < 0) * count[i];
        return result >> 1;
    }
};
