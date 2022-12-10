class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        const int length = s.length();
        int result = 0, maxFrequency = 0;
        vector<int> frequency(26, 0);
        for (int start = 0, end = 0; end < length; ++end)
        {
            maxFrequency = max(maxFrequency, ++frequency[s[end] - 'A']);
            if (end - start + 1 > maxFrequency + k)
                --frequency[s[start++] - 'A'];
            result = end - start + 1;
        }
        return result;
    }
};
