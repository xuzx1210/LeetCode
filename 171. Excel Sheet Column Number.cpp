class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;
        for (int i = 0; i < columnTitle.length(); ++i)
            result = result * 26 - 'A' + columnTitle[i] + 1;
        return result;
    }
};
