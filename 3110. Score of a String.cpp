class Solution
{
public:
    int scoreOfString(string s)
    {
        int result = 0;
        for (int i = s.length() - 1; i; --i)
        {
            const char a = s[i], b = s[i - 1];
            result += (a > b) * (a - b) + (b > a) * (b - a);
        }
        return result;
    }
};
