class Solution
{
public:
    int partitionString(string s)
    {
        int result = 1;
        vector<bool> letter(26, false);
        for (const char c : s)
        {
            if (letter[c - 'a'])
            {
                letter = vector<bool>(26, false);
                ++result;
            }
            letter[c - 'a'] = true;
        }
        return result;
    }
};
