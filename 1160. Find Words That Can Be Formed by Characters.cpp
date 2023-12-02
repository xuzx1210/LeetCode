class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int result = 0;
        vector<int> charCount(26, 0);
        for (const char c : chars)
            ++charCount[c - 'a'];
        for (const string &word : words)
        {
            vector<int> count(charCount);
            bool ok = true;
            for (const char c : word)
                if (--count[c - 'a'] < 0)
                {
                    ok = false;
                    break;
                }
            if (ok)
                result += word.length();
        }
        return result;
    }
};
