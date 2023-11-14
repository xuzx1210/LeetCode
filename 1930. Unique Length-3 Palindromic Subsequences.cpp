class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int result = 0;
        const int length = s.length();
        vector<pair<int, int>> range(26, {length, -1});
        for (int i = 0; i < length; ++i)
            range[s[i] - 'a'].second = i;
        for (int i = length - 1; i >= 0; --i)
            range[s[i] - 'a'].first = i;
        for (int alphabet = 0; alphabet < 26; ++alphabet)
        {
            vector<bool> found(26, false);
            for (int i = range[alphabet].first + 1; i < range[alphabet].second; ++i)
                found[s[i] - 'a'] = true;
            for (int i = 0; i < 26; ++i)
                if (found[i])
                    ++result;
        }
        return result;
    }
};
