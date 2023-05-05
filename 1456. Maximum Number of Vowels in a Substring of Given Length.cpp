class Solution
{
private:
    bool isVowel(char c)
    {
        return (0x208222 >> (c & 0x1F)) & 1;
    }

public:
    int maxVowels(string s, int k)
    {
        int result = 0;
        for (int i = 0; i < k; ++i)
            if (isVowel(s[i]))
                ++result;
        int vowels = result;
        const int length = s.length();
        for (int i = k; i < length; ++i)
        {
            if (isVowel(s[i]))
                ++vowels;
            if (isVowel(s[i - k]))
                --vowels;
            result = max(result, vowels);
        }
        return result;
    }
};
