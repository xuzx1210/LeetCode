class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int result = 0, depth = 0, length = s.length();
        for (int i = 0; i < length; ++i)
            if (s[i] == '(')
                ++depth;
            else
            {
                --depth;
                if (s[i - 1] == '(')
                    result += (1 << depth);
            }
        return result;
    }
};
