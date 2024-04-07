class Solution
{
private:
    bool parenthesesCheck(const string &s, const char right)
    {
        int parentheses = 0;
        for (const char c : s)
        {
            if (c == right && parentheses == 0)
                return false;
            if (c == right)
                --parentheses;
            else
                ++parentheses;
        }
        return true;
    }

public:
    bool checkValidString(string s)
    {
        if (!parenthesesCheck(s, ')'))
            return false;
        reverse(s.begin(), s.end());
        return parenthesesCheck(s, '(');
    }
};
