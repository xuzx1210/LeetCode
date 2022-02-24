class Solution
{
public:
    bool repeatSigned(string &s)
    {
        bool sign = false;
        while (s.length())
            if (s[0] == '+' || s[0] == '-')
            {
                s.erase(s.begin());
                if (sign)
                    return true;
                else
                    sign = true;
            }
            else
                break;
        return false;
    }
    bool onlyDigit(string s)
    {
        for (auto c : s)
            if (!isdigit(c))
                return false;
        return true;
    }
    bool isInteger(string s)
    {
        if (repeatSigned(s))
            return false;
        if (!s.length())
            return false;
        return onlyDigit(s);
    }
    bool isDecimal(string s)
    {
        if (repeatSigned(s))
            return false;
        bool point = false;
        int pointPos;
        for (int i = 0; i < s.length(); ++i)
            if (s[i] == '.')
            {
                if (point)
                    return false;
                else
                {
                    point = true;
                    pointPos = i;
                }
            }
        if (!point || s.length() < 2)
            return false;
        if (pointPos == 0)
        {
            s.erase(s.begin());
            return onlyDigit(s);
        }
        else if (pointPos == s.length() - 1)
        {
            s.pop_back();
            return onlyDigit(s);
        }
        string a(s, 0, pointPos), b(s, pointPos + 1, s.length() - pointPos - 1);
        return onlyDigit(a) && onlyDigit(b);
    }
    bool isNumber(string s)
    {
        if (!s.length())
            return false;
        bool isExp = false;
        int expPos;
        for (int i = 0; i < s.length(); ++i)
            if (s[i] == 'e' || s[i] == 'E')
            {
                if (i == 0 || i == s.length() - 1)
                    return false;
                if (isExp)
                    return false;
                else
                {
                    isExp = true;
                    expPos = i;
                }
            }
        if (!isExp)
            return isInteger(s) || isDecimal(s);
        string a(s, 0, expPos), b(s, expPos + 1, s.length() - expPos - 1);
        return (isInteger(a) || isDecimal(a)) && isInteger(b);
    }
};
