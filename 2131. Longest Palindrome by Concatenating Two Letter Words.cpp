class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> diff, same;
        for (string &word : words)
            if (word[0] == word[1])
                ++same[word];
            else
                ++diff[word];
        int result = 0;
        for (auto &[key, value] : diff)
            if (value)
            {
                string tmp(key);
                swap(tmp[0], tmp[1]);
                int m = min(value, diff[tmp]);
                value -= m;
                diff[tmp] -= m;
                result += (m << 2);
            }
        for (auto &[key, value] : same)
        {
            int m = value >> 1;
            value -= (m << 1);
            result += (m << 2);
        }
        for (auto &[key, value] : same)
            if (value)
            {
                result += 2;
                break;
            }
        return result;
    }
};
