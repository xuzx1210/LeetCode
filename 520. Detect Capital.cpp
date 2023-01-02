class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        const size_t length = word.length();
        if (length < 2)
            return true;
        if (islower(word[0]) && isupper(word[1]))
            return false;
        bool mode = islower(word[1]);
        for (size_t i = 2; i < length; ++i)
            if (mode != (bool)islower(word[i]))
                return false;
        return true;
    }
};
