class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int result = -1;
        vector<pair<int, int>> range(26, {300, -1});
        for (int i = s.length() - 1; i >= 0; --i)
        {
            const int index = s[i] - 'a';
            range[index].first = min(range[index].first, i);
            range[index].second = max(range[index].second, i);
        }
        for (int i = 0; i < 26; ++i)
        {
            const int diff = range[i].second - range[i].first - 1;
            if (0 <= diff)
                result = max(result, diff);
        }
        return result;
    }
};
