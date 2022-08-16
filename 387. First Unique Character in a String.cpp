class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> counter(26, 0);
        for (char &c : s)
            ++counter[c - 'a'];
        int length = s.length();
        for (int i = 0; i < length; ++i)
            if (counter[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};
