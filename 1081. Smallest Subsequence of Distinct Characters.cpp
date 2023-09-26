class Solution
{
public:
    string smallestSubsequence(string s)
    {
        string result{};
        const int length = s.length();
        vector<int> last(26, -1);
        vector<bool> seen(26, false);
        for (int i = 0; i < length; ++i)
            last[s[i] - 'a'] = i;
        for (int i = 0; i < length; ++i)
        {
            const int index = s[i] - 'a';
            if (seen[index])
                continue;
            while (!result.empty() && s[i] < result.back() && i < last[result.back() - 'a'])
            {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            seen[index] = true;
            result.push_back(s[i]);
        }
        return result;
    }
};
